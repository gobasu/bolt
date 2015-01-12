namespace Bolt\App\View;

use Bolt\App\View\Parser;
use Bolt\App\View\Exception;
use Bolt\App\View\Parser\Node;

class Compiler
{
	const VARNAME_REGEX = "/[a-z]([a-z0-9_]+)?/is";
	protected _parser;
	protected _output;
	protected _file = "string::";
	protected _tree;
	protected _elements = [];
	protected _buffer;
	protected _extends = "\\Bolt\\App\\View\\Template";
	protected _main = "";
	protected _blocks = [];
	protected _loops = [];
	protected _loopVariables = ["index": true, "key": true, "last": true, "first": true, "length": true, "item" : true];
	protected _currentBlock = "#";
	protected _dependencies = [];

	protected _expressionsHandlers = [];
	protected _elementsHandlers = ["open": [], "close": []];

	public function __construct (<Parser> parser, file = "string::")
	{
		let this->_parser = parser;
		let this->_file = file;
	}

	public function compile()
	{
		let this->_tree = this->_parser->parse();
		let this->_output = "";
		let this->_buffer = "";
		
		//expressions
		this->addExpressionHandler("parent", [this, "_compileParent"]);
		this->addExpressionHandler("continue", [this, "_compileContinue"]);
		this->addExpressionHandler("break", [this, "_compileBreak"]);
		this->addExpressionHandler("_", [this, "_compileI18n"]);

		//elements
		this->addElementHandler("block", [this, "_compileBlock"], "endblock", [this, "_compileEndBlock"]);
		this->addElementHandler("if", [this, "_compileIf"], "endif", [this, "_compileEndIf"]);
		this->addElementHandler("else", [this, "_compileElse"]);
		this->addElementHandler("for", [this, "_compileFor"], "endfor", [this, "_compileEndFor"]);
		this->addElementHandler("include", [this, "_compileInclude"]);
		this->addElementHandler("extends", [this, "_compileExtend"]);
		this->addElementHandler("extend", [this, "_compileExtend"]);

		this->_compileNode(this->_tree);
	}

	public function addExpressionHandler(string name, handler)
	{
		let this->_expressionsHandlers[name] = handler;
	}

	public function addElementHandler(string open, openHandler, string close = null, closeHandler = null)
	{
		let this->_elementsHandlers["open"][open] = openHandler;
		if close != null {
			let this->_elementsHandlers["close"][close] = closeHandler;
		}
	}

	public function _compileNode(<Node> node)
	{
		var child;
		switch node->getType() {
			case Node::TYPE_NODE:
				//just do nothing
				break;
			case Node::TYPE_TEXT:
				this->_compileText(node);
				break;
			case Node::TYPE_ELEMENT:
				this->_compileElement(node);
				break;
			case Node::TYPE_EXPRESSION:
				this->_compileExpression(node);
				break;
		}

		if node->hasChildren() {
			for child in node->getChildren() {
				this->_compileNode(child);
			}
		}		
	}

	protected function _compileText(<Node> node)
	{
		var str;
		let str = node->getValue();
		let str = str_replace("<?", "&lt;?", str);//remove php from template
		this->addToBlock(str);
	}

	public function addToBlock(string str)
	{
		if this->_currentBlock == "#" {
			let this->_main = this->_main . str;
		} else {
			if isset this->_blocks[this->_currentBlock] {
				let this->_blocks[this->_currentBlock] = this->_blocks[this->_currentBlock] . str; 
			} else {
				let this->_blocks[this->_currentBlock] = str;
			}
		}
	}

	public function addToMain(string str)
	{
		let this->_main = this->_main . str;
	}

	public function getCurrentLoop()
	{
		return end(this->_loops);
	}

	protected function _compileElement(<Node> node)
	{
		var prototype, name;
		let prototype = node->property(0);
		let name = prototype->getValue();

		if isset this->_elementsHandlers["open"][name] {
			call_user_func(this->_elementsHandlers["open"][name], this, node);
		}

		if isset this->_elementsHandlers["close"][name] {
			call_user_func(this->_elementsHandlers["close"][name], this, node);
		}

	}

	public function _compileExpression(<Node> node)
	{
		var prototype, name, each, pos, loopName;


		let prototype = node->property(0);
		let name = prototype->getValue();

		if prototype->isFunction() && isset this->_expressionsHandlers[prototype->getValue()] {
			call_user_func(this->_expressionsHandlers[prototype->getValue()], this, node);
		} else {
			if substr(name, 0, 1) == "@" {
				let each = this->getCurrentLoop();

				if !each {
					throw new Exception("Cannot use loop variable outside the loop");
				} else {
					let loopName = each["name"];
					let name = substr(name, 1);
					let pos = strpos(name, ":");
					
					if pos > 0 {
						let loopName = substr(name, 0, pos);
						let name = substr(name, pos + 1);
					}

					if !isset this->_loopVariables[name] {
						throw new Exception("Undefined loop variable `" . name . "`, expected: index, key, length, last or first");
					}

					this->addToBlock("<?=$_loop_" . loopName . "_" . name . "?>");
				}
			} else {
				this->addToBlock("<?=" . this->compileProperty(prototype) . "?>");
			}
		}
	}

	public function compileProperty(<Node> node) -> string
	{
		string result = "";
		var modifiers, modifier, arguments, arg;
		int length, i;
		let modifiers = node->getModifiers();
		let length = (int) count(modifiers);
		if length > 0 {
			let i = 0;
			//$this->filter('name', array(), this->_varsvalue)
			for modifier in modifiers {
				let arguments = [];
				if modifier->hasArguments() {
					for arg in modifier->getArguments() {
						let arguments[] = this->_compileArgument(arg);
					}
				}

				let result  = result . "$this->_filter('" . modifier->getValue() . "', array(" . implode(",", arguments) . "), ";
				let i++;
			}

		}

		if node->isScalar() {
			let result .= this->_compileScalar(node);
		} else {
			let result .= this->_compileArgument(node->getValue());
		
		
			if node->hasArguments() {
				let arguments = [];
				let result .= "(";
				for arg in node->getArguments() {
					let arguments[] = this->_compileArgument(arg);
				}
				let result .= implode(",", arguments);

				let result .= ")";
			} elseif node->isFunction() {
				let result .= "()";
			}
		}

		if length > 0 {
			while i > 0 {
				let result = result . ")";
				let i--;
			}
		}

		return result;
	}

	public function _compileScalar(<Node> node)
	{
		string result;
		var child, values = [];
		let result = "array(";
		for child in node->getChildren() {

			if child->isScalar() {
				if child->hasArguments() {
					let values[] = "'" . child->argument(0) . "'=>" . this->_compileScalar(child);
				} else {
					let values[] = this->_compileScalar(child);
				}
			} else {
				if child->hasArguments() {
					let values[] = "'" . child->argument(0) . "'=>" . this->_compileArgument(child->getValue());
				} else {
					let values[] = this->_compileArgument(child->getValue());
				}
			}
		}
		return result . implode(",", values) . ")";
	}

	public function _compileModifiers(<Node> node, string param)
	{
		string result = "";
		var modifiers, modifier, arguments, arg;
		int length, i;
		let modifiers = node->getModifiers();
		let length = (int) count(modifiers);
		if length > 0 {
			let i = 0;
			for modifier in modifiers {
				let arguments = [];
				if modifier->hasArguments() {
					for arg in modifier->getArguments() {
						let arguments[] = this->_compileArgument(arg);
					}
				}
				let result  = result . "$this->_filter('" . modifier->getValue() . "', array(" . implode(",", arguments) . "), ";
				let i++;
			}
			
		}

		let result .= param;

		if length > 0 {
			while i > 0 {
				let result = result . ")";
				let i--;
			}
		}

		return result;
	}

	public function _compileArgument(string item) -> string
	{
		var sub, search, replace;
		var dotPos, arrPos, pos;
		var map = [
			"/\\./": "->",
			"/\\[/": "['",
			"/\\]/": "']"
		];
		let search = array_keys(map), replace = array_values(map);

		if item[0] == '\'' || item[0] == '"' || is_numeric(item) {
			return item;
		}

		if item == "true" || item == "false" || item == "null" {
			return item;
		}

		let arrPos =  strpos(item, "[");
		let dotPos =  strpos(item, ".");

		echo "arrpos:"; var_dump(arrPos);
		echo "dotPos"; var_dump(dotPos);

		if arrPos === false && dotPos === false {
			return "$this->_vars['" . item . "']";
		} elseif arrPos !== false && arrPos >= 0 && dotPos !== false && dotPos >= 0 {
			if arrPos > dotPos {
				let pos = dotPos;
			} else {
				let pos = arrPos;
			}
		} elseif dotPos !== false {
			let pos = dotPos;
		} elseif arrPos !== false {
			let pos = arrPos;
		} 

		let sub = substr(item, 0, pos);
		let item = substr(item, pos);

		return "$this->_vars['" . sub . "']" . preg_replace(search, replace, (string) item);
	}

	public function _compileInclude(compiler, node)
	{
		if !node->property(1) {
			throw new Exception("{% include %} requires at least one property");
		}
		compiler->addToBlock("<?$this->_include(" . this->_compileArgument(node->property(1)) . ")?>");
	}

	public function _compileExtend(compiler, node)
	{
		string templateName;

		if !node->property(1) {
			throw new Exception("{% extends %} requires template name to be set");
		}
		let templateName = (string) node->property(1)->getValue();

		if templateName[0] != '\'' && templateName[0] != '"' {
			throw new Exception("{% extends %} requires template name to be constant string");
		}

		let templateName = substr(templateName, 1, -1);

		let this->_extends = md5(templateName);
		let this->_dependencies[] = templateName;
	}

	public function _compileI18n(compiler, node)
	{
		var arguments = [], arg;
		if node->property(0)->hasArguments() == false {
			throw new Exception("{{_}} requires at least one parameter");
		}

		for arg in node->property(0)->getArguments() {
			let arguments[] = this->_compileArgument(arg);
		}

		compiler->addToBlock("<?$this->_translate(" . implode(",", arguments) . ")?>");
	}

	public function _compileParent(compiler, node)
	{
		compiler->addToBlock("<?parent::" . this->_currentBlock . "()?>");
	}

	public function _compileContinue(compiler, node)
	{
		var each;
		let each =  this->getCurrentLoop();

		if !each {
			throw new Exception("Cannot use {{continue()}} outside the loop context");
		}
		compiler->addToBlock("<?continue?>");
	}

	public function _compileBreak(compiler, node)
	{
		var each;
		let each =  this->getCurrentLoop();

		if !each {
			throw new Exception("Cannot use {{break()}} outside the loop context");
		}
		compiler->addToBlock("<?break?>");
	}

	public function _compileBlock(compiler, node)
	{
		if this->_currentBlock != "#" {
			throw new Exception("Nested block are not allowed in " . this->_file);
		}
		var blockName;
		if !node->property(1) {
			throw new Exception("Block's name is not defined in " . this->_file);
		}
		let blockName = node->property(1)->getValue();

		if !preg_match(Compiler::VARNAME_REGEX, blockName) {
			throw new Exception("Invalid block name `" . blockName . "`. Valid name should match the pattern [a-z][a-z0-9_]+");
		}
		let this->_currentBlock = blockName;

		let this->_elements[] = [
			"type": "block"
		];
	}

	public function _compileEndBlock(compiler, node)
	{
		var element;
		compiler->addToMain("<?$this->block" . this->_currentBlock . "()?>");
		let this->_currentBlock = "#";

		let element = end(this->_elements);
		if element["type"] != "block" {
			throw new Exception("Nesting conflict expected {% end" . element["type"]  . " %} got {% endblock %}");
		}
		array_pop(this->_elements);
	}

	public function _compileFor(compiler, node)
	{
		var varName, loopName, index, length, key, first, last, each, item, keys, props, propsLength, tmp;
		let props = node->getProperties();
		let propsLength = count(props);

		if propsLength != 4 {
			throw new Exception("Invalid {% for %} expression");
		}

		if node->property(2)->getValue() != "in" {
			throw new Exception("Invalid {% for %} expression");
		}
		
		let varName = node->property(1)->getValue();
		let loopName = node->property(3)->getValue();

		if loopName == "[" {
			let tmp = strval(count(this->_loops));
			let loopName = "loop".tmp;
		}

		let each = "$_each_" . loopName;
		let index = each. "_index";
		let length = each . "_length";
		let key = each. "_key";
		let first = each . "_first";
		let last = each . "_last";
		let item = each . "_item";
		let keys = each . "_keys";

		this->addToBlock("<?" . each . " = " . this->compileProperty(node->property(3)) . "?>");
		this->addToBlock("<?if(" . each . "):?>");
		this->addToBlock("<?" . keys . " = array_keys(" . each . ")?>");
		this->addToBlock("<?" . length . " = count(" . keys . ")?>");


		
		this->addToBlock("<?for(" . index . " = 0; " . index . "<" . length . "; " . index . "++):?>");
		if node->property(1)->hasModifiers() {
			this->addToBlock("<?$this->_vars->" . varName . " = " . this->_compileModifiers(node->property(1), each . "[" . keys . "[" . index . "]]") . "?>");
		} else {
			this->addToBlock("<?$this->_vars->" . varName . " = " . each . "[" . keys . "[" . index . "]]?>");
		}
		this->addToBlock("<?" . key . " = " . keys . "[" . index . "]?>");
		this->addToBlock("<?" . first . "=" . index . " == 0 ? true : false?>");
		this->addToBlock("<?" . last . "=" . index . " == (" . length . " - 1) ? true : false?>");

		let this->_loops[] = ["name": loopName];
		let this->_elements[] = ["type": "for"];
	}

	public function _compileEndFor(compiler, node)
	{
		var element;
		let element = end(this->_elements);
		if element["type"] != "for" {
			throw new Exception("Nesting conflict expected {% end" . element["type"]  . " %} got {% endfor %}");
		}
		if !isset element["else"] {
			this->addToBlock("<?endfor?>");
		}
		this->addToBlock("<?endif?>");
		array_pop(this->_loops);
		array_pop(this->_elements);
	}	

	public function _compileElse(compiler, node)
	{
		var element;
		let element = end(this->_elements);

		if !element {
			throw new Exception("Cannot use {% else %} element outside {% for %}, {% if %} blocks context");
		}

		if element["type"] == "if" {
			compiler->addToBlock("<?else:?>");
		} elseif element["type"] == "for" {
			compiler->addToBlock("<?endfor?>");
			compiler->addToBlock("<?else:?>");
			let element["else"] = true;
			array_pop(this->_elements);
			let this->_elements[] = element;
		} else {
			throw new Exception("Cannot use {% else %} element outside {% for %}, {% if %} blocks context");
		}
		
	}

	public function _compileIf(compiler, node)
	{
		var props, propsLength;
		string operator, type, not = "";
		
		let this->_elements[] = ["type" : "if"];
		let props = node->getProperties();
		let propsLength = (int) count(props);

		if propsLength == 1 {
			throw new Exception("{% if %} block requires a statement");
		} elseif propsLength == 2 { // if value
			this->addToBlock("<?if(" . this->compileProperty(props[1]) . "):?>");
		} elseif propsLength == 3 && props[1]->getValue() == "not" {// if not element, if 
			this->addToBlock("<?if(!" . this->compileProperty(props[2]) . "):?>");
		} elseif propsLength == 4 {
			//if element is val, if element eq val, if element in
			let operator = (string) props[2]->getValue();

			if operator == "is" || operator == "not" {
				let type = (string) props[3]->getValue();
				if operator == "not" {
					let not = "!";
				} else {
					let not = "";
				}

				if type == "numeric" {
					this->addToBlock("<?if(" . not . "is_numeric(" . this->compileProperty(props[1]) . ")):?>");
				} elseif type == "odd" {
					this->addToBlock("<?if(" . this->compileProperty(props[1]) . " % 2 " . (not ? "=" : "!") . "= 0)):?>");
				} elseif type == "even" {
					this->addToBlock("<?if(" . this->compileProperty(props[1]) . " % 2 " . (not ? "!" : "=") . "= 0)):?>");
				} elseif type == "empty" {
					this->addToBlock("<?if(" . not . "empty(" . this->compileProperty(props[1]) . ")):?>");
				} elseif type == "defined" {
					this->addToBlock("<?if(" . not . "isset(" . this->compileProperty(props[1]) . ")):?>");
				} elseif type == "email" { 
					this->addToBlock("<?if(" . not . "filter_var(" . this->compileProperty(props[1]) . ", FILTER_VALIDATE_EMAIL)):?>");
				} else {
					this->addToBlock("<?if(" . not . "(" . this->compileProperty(props[1]) . " instanceof " . type . ")):?>");
				}
				return;
			} elseif operator == "in" {
				this->addToBlock("<?if((is_array(" . this->compileProperty(props[3]) . ") && in_array(" . this->compileProperty(props[1]) . ", " . this->compileProperty(props[3]) . ")) || (is_string(" . this->compileProperty(props[3]) . ") && strpos(" . this->compileProperty(props[1]) . ", " . this->compileProperty(props[3]) . ") !== false)):?>");
				return;
			} elseif operator == "eq" {
				this->addToBlock("<?if(" . this->compileProperty(props[1]) . " == " . this->compileProperty(props[3]) . "):?>");
				return;
			} elseif operator == "neq" {
				this->addToBlock("<?if(" . this->compileProperty(props[1]) . " != " . this->compileProperty(props[3]) . "):?>");
				return;
			} elseif operator == "lt" {
				this->addToBlock("<?if(" . this->compileProperty(props[1]) . " < " . this->compileProperty(props[3]) . "):?>");
				return;
			} elseif operator == "lte" {
				this->addToBlock("<?if(" . this->compileProperty(props[1]) . " <= " . this->compileProperty(props[3]) . "):?>");
				return;
			} elseif operator == "gt" {
				this->addToBlock("<?if(" . this->compileProperty(props[1]) . " > " . this->compileProperty(props[3]) . "):?>");
				return;
			} elseif operator == "gte" {
				this->addToBlock("<?if(" . this->compileProperty(props[1]) . " >= " . this->compileProperty(props[3]) . "):?>");
				return;
			} elseif operator == "contains" { 
				this->addToBlock("<?if(strpos(" . this->compileProperty(props[1]) . ", " . this->compileProperty(props[3]) . ") !== false):?>");
				return;
			} elseif operator == "matches" {
				this->addToBlock("<?if(preg_match('" . props[3]->getValue() . "', " . this->compileProperty(props[1]) . ")):?>");
				return;
			} 
			throw new Exception("Unsupported operator `" . operator . "` in {% if %} block");

		} else {
			throw new Exception("Unsupported expression in {% if %} block");
		}

	}

	public function _compileEndIf(compiler, node)
	{
		var element;
		let element = end(this->_elements);
		if !element || element["type"] != "if" {
			throw new Exception("Cannot use {% endif %} element outside {% if %} context");
		}
		this->addToBlock("<?endif?>");
		array_pop(this->_elements);

	}

	public function getDependencies()
	{
		return this->_dependencies;
	}

	protected function _getHeader()
	{
		return "class _BoltTemplate_" . md5(this->_file) . " \n{\n";
	}

	protected function _getFooter()
	{
		return "\n}";
	}

	public function getBlocks()
	{
		return this->_blocks;
	}

	public function getMain()
	{
		return this->_main;
	}

	public function output()
	{
		return this->_getHeader() . "\npublic function render($context = null) {\n ?>" . this->getMain() . "<?\n}" . this->_getFooter();
	}
}