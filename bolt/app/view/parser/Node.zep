namespace Bolt\App\View\Parser;
use Bolt\App\View\Exception;

class Node
{
	const TYPE_NODE 		= -1;
	const TYPE_TEXT 		= 0;
	const TYPE_ELEMENT 		= 1;
	const TYPE_EXPRESSION 	= 2;
	const TYPE_MODIFIER		= 3;
	const TYPE_PROPERTY 	= 4;
	

	protected _type = -1;
	protected _value = "";
	protected _arguments = [];
	protected _handler;
	protected _parent = null;
	protected _children = [];
	protected _modifiers = [];
	protected _properties = [];
	protected _isFunction = false;
	protected _isScalar = false;
	protected _key		= null;



	public function __construct(type = -1, value = null)
	{
		let this->_type = type;
		let this->_value = value;
	}

	public function isRoot()
	{
		return this->_parent == null;
	}

	public function getParent()
	{
		return this->_parent;
	}

	public function setParent(<Node> parent)
	{
		let this->_parent = parent;
	}

	public function addChild(<Node> child)
	{
		child->setParent(this);
		let this->_children[] = child;
	}

	public function addArgument(arg)
	{
		let this->_arguments[] = arg;
	}

	public function addModifier(<Node> modifier)
	{
		modifier->setParent(this);
		let this->_modifiers[] = modifier;
	}

	public function setHandler(handler) 
	{
		let this->_handler = handler;
	}

	public function addProperty(<Node> property)
	{
		property->setParent(this);
		let this->_properties[] = property;
	}

	public function hasProperties() 
	{
		return count(this->_properties) > 0 ? true : false;
	}

	public function hasModifiers() 
	{
		return count(this->_modifiers) > 0 ? true : false;
	}

	public function hasChildren() 
	{
		return count(this->_children) > 0 ? true : false;
	}

	public function hasArguments() 
	{
		return count(this->_arguments) > 0 ? true : false;
	}

	public function getProperties()
	{
		return this->_properties;
	}

	public function getModifiers()
	{
		return this->_modifiers;
	}

	public function getArguments()
	{
		return this->_arguments;
	}
	public function getChildren()
	{
		return this->_children;
	}

	public function setAsScalar()
	{
		let this->_isScalar = true;
	}

	public function isScalar()
	{
		return this->_isScalar;
	}

	public function child(int at)
	{
		return isset this->_children[at] ? this->_children[at] : null;
	}

	public function property(int at)
	{
		return isset this->_properties[at] ? this->_properties[at] : null;
	}

	public function argument(int at)
	{
		return isset this->_arguments[at] ? this->_arguments[at] : null;
	}

	public function getValue()
	{
		return this->_value;
	}

	public function getType()
	{
		return this->_type;
	}

	public function setAsFunction()
	{
		let this->_isFunction = true;
	}

	public function isFunction()
	{
		return this->_isFunction;
	}

	public function getStringifiedType()
	{
		switch this->_type {
			case -1:
				return "Node::TYPE_NODE";
			case 0:
				return "Node::TYPE_TEXT";
			case 1:
				return "Node::TYPE_ELEMENT";	
			case 2:
				return "Node::TYPE_EXPRESSION";
			case 3:
				return "Node::TYPE_MODIFIER";			
			case 4:
				return "Node::TYPE_PROPERTY";
		}

	}
}