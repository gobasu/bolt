namespace Bolt\App\View;
use Bolt\App\View\Tokenizer;
use Bolt\App\View\Parser\Node;
use Bolt\App\View\Exception;

final class Parser
{
	protected _tokenizer;
	protected _tree;
	protected _fileName;
	protected _token;

	private _openExpressions = [];
	private _closedExpressions = [];
	private _openElements = [];
	private _closedElements = [];
	private _arrayDepth = 0;

	public function __construct(fileName)
	{
		let this->_fileName = fileName;
		let this->_tokenizer = new Tokenizer(file_get_contents(this->_fileName), this->_fileName);
	}

	public function getTokenizer()
	{
		return this->_tokenizer;
	}

	
	public function parse()
	{
		let this->_tree = new Node(Node::TYPE_NODE);

		if !is_readable(this->_fileName) {
			throw new Exception("No such file " . this->_fileName);
		}
		
		this->_tokenizer->scan();

		var tokens = null, cursor, token = null, nextToken = null, prevToken = null, length = null, expecting = null, notExpecting = null, current = null, next = null, tmp;
		boolean inExpression = false, inElement = false, inModifier = false;
		int propertyLength = 0;
		let tokens = this->_tokenizer->getTokens();
		let current = this->_tree;
		let length = count(tokens);

		let expecting = [Tokenizer::TYPE_TEXT, Tokenizer::TYPE_OPEN_ELEMENT, Tokenizer::TYPE_OPEN_EXPRESSION, Tokenizer::TYPE_OPEN_IGNORE, Tokenizer::TYPE_OPEN_COMMENT];

		for cursor, token in tokens {
			
			let this->_token = token;
			if cursor + 1 < length {
				let nextToken = tokens[cursor + 1];
			} else {
				let nextToken = null;
			}

			if cursor - 1 > 0 {
				let prevToken = tokens[cursor - 1];
			}

			if expecting {
				if typeof expecting == "array" && !in_array(token["type"], expecting) {
					throw new Exception("Unexpected token in " . this->_fileName . " on line " . token["line"] . "\n" . token["value"] . "\n");
				} elseif typeof expecting == "int" && expecting != token["type"] {
					throw new Exception("Unexpected token in " . this->_fileName . " on line " . token["line"] . "\n" . token["value"] . "\n");
				}
			}

			if notExpecting {
				if typeof notExpecting == "array" && in_array(token["type"], notExpecting) {
					throw new Exception("Unexpected token in " . this->_fileName . " on line " . token["line"]);
				} elseif typeof notExpecting == "int" && notExpecting == token["type"] {
					throw new Exception("Unexpected token in " . this->_fileName . " on line " . token["line"]);
				}
			}

			if next && next != token["type"] {
				continue;
			}

			let next = null;
			let expecting = null;
			let notExpecting = null;

			switch token["type"] {
				case Tokenizer::TYPE_TEXT:
					let expecting = [Tokenizer::TYPE_TEXT, Tokenizer::TYPE_OPEN_ELEMENT, Tokenizer::TYPE_OPEN_EXPRESSION, Tokenizer::TYPE_OPEN_IGNORE, Tokenizer::TYPE_OPEN_COMMENT];
					current->addChild(new Node(Node::TYPE_TEXT, token["value"]));
					break;

				case Tokenizer::TYPE_IGNORED:
					current->addChild(new Node(Node::TYPE_TEXT, token["value"]));
					break;

				case Tokenizer::TYPE_OPEN_EXPRESSION:
					let expecting = [Tokenizer::TYPE_PROPERTY, Tokenizer::TYPE_OPEN_ARRAY];
					let tmp = new Node(Node::TYPE_EXPRESSION, token["value"]);
					current->addChild(tmp);
					let current = tmp;
					let tmp = null;
					let inExpression = true;
					break;

				case Tokenizer::TYPE_OPEN_ELEMENT:
					let expecting = [Tokenizer::TYPE_PROPERTY, Tokenizer::TYPE_OPEN_ARRAY];
					let tmp = new Node(Node::TYPE_ELEMENT, token["value"]);
					current->addChild(tmp);
					let current = tmp;
					let tmp = null;
					let inElement = true;
					break;

				case Tokenizer::TYPE_PROPERTY:

					let tmp = new Node(Node::TYPE_PROPERTY, token["value"]);
					current->addProperty(tmp);
					if nextToken["type"] == Tokenizer::TYPE_MODIFIER || nextToken["type"] == Tokenizer::TYPE_OPEN_ARGUMENTS {
						let current = tmp;
					}
					let tmp = null;
					break;
				
				case Tokenizer::TYPE_MODIFIER:
					
					let tmp = new Node(Node::TYPE_MODIFIER, token["value"]);
					let inModifier = true;
					current->addModifier(tmp);

					
					if nextToken["type"] == Tokenizer::TYPE_PROPERTY || nextToken["type"] == Tokenizer::TYPE_CLOSE_EXPRESSION || nextToken["type"] == Tokenizer::TYPE_CLOSE_ELEMENT {
						let tmp = current->getParent();
						let current = tmp;
						let tmp = null;
						let inModifier = false;
					} elseif nextToken["type"] == Tokenizer::TYPE_OPEN_ARGUMENTS {
						let current = tmp;
					}
					let tmp = null;	
					break;

				case Tokenizer::TYPE_OPEN_ARGUMENTS:
					current->setAsFunction();
					break;

				case Tokenizer::TYPE_OPEN_ARRAY:
					let tmp = new Node(Node::TYPE_PROPERTY, token["value"]);
					if this->_arrayDepth > 0 {
						current->addChild(tmp);
					} else {
						current->addProperty(tmp);
					}
					tmp->setAsScalar();
					let current = tmp;
					let tmp = null;
					let this->_arrayDepth = this->_arrayDepth + 1;
					break;

				case Tokenizer::TYPE_ARGUMENT:
					if this->_arrayDepth > 0 {
						let tmp = new Node(Node::TYPE_PROPERTY, token["value"]);
						current->addChild(tmp);

						if prevToken["type"] == Tokenizer::TYPE_ARGUMENTS_NAME {
							tmp->addArgument(prevToken["value"]);
						}

						let tmp = null;
					} else {
						current->addArgument(token["value"]);
					}
					break;

				case Tokenizer::TYPE_CLOSE_ARRAY:
					let tmp = current->getParent();
					let current = tmp;
					let tmp = null;
					let this->_arrayDepth = this->_arrayDepth - 1;
					break;

				case Tokenizer::TYPE_CLOSE_ARGUMENTS:
					
					if inModifier && (nextToken["type"] == Tokenizer::TYPE_CLOSE_EXPRESSION || nextToken["type"] == Tokenizer::TYPE_CLOSE_ELEMENT || nextToken["type"] == Tokenizer::TYPE_PROPERTY) {
						let tmp = current->getParent()->getParent();
						let current = tmp;
						let tmp = null;
					} elseif inModifier && nextToken["type"] == Tokenizer::TYPE_MODIFIER {
						let tmp = current->getParent();
						let current = tmp;
						let tmp = null;
					} elseif !inModifier && (nextToken["type"] == Tokenizer::TYPE_CLOSE_EXPRESSION || nextToken["type"] == Tokenizer::TYPE_CLOSE_ELEMENT) {
						let tmp = current->getParent();
						let current = tmp;
						let tmp = null;
					}
					if inModifier {
						let inModifier = false;

					}
					break;
				case Tokenizer::TYPE_CLOSE_EXPRESSION:
					let tmp = current->getParent();
					let current = tmp;
					let tmp = null;
					let inExpression = false;
					break;

				case Tokenizer::TYPE_CLOSE_ELEMENT:
					let tmp = current->getParent();
					let current = tmp;
					let tmp = null;
					let inElement = false;
					break;
			}

			
		}

		return this->_tree;
	}



	public function _debugTree(node, indent = 0)
	{
		var mod, prop, ch;
		echo str_repeat(" ", indent) . "Node:" . this->_printFullName(node);
		if node->hasArguments() {
			echo str_repeat(" ", indent) . "Arguments: (" . implode(",", node->getArguments()) . ")";
		}
		
		if node->hasModifiers() {
			echo "\n";
			for mod in node->getModifiers() {
				this->_debugTree(mod, indent + 2);
			}
		}
		
		if node->hasProperties() {
			echo "\n";
			for prop in node->getProperties() {
				this->_debugTree(prop, indent + 2);
			}
		}

		
		if node->hasChildren() {
			echo "\n";
			for ch in node->getChildren() {
				
				this->_debugTree(ch, indent + 4);
			}
		}

		echo "\n\n";
	}

	private function _printFullName(node, str = "")
	{
		var val;
		let val = (string) node->getValue();
		let val = str_replace("\n", "", val);
		let str = node->getStringifiedType() . "( " . substr(val, 0, 10) . " )" . ">" . str;
		if !node->isRoot() {
			let str = this->_printFullName(node->getParent(), str);
		}
		return str;
	}
}