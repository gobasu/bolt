namespace Bolt\App;

class View
{
	protected _context;

	public function __construct(<Context> context)
	{
		let this->_context = context;
	}

	public function render(string name, array data = null)
	{
		var tpl;
		tpl = this->_context->factoryTemplate(name);
		return tpl->display(data);
	}

}