namespace Bolt\App\View;

use Bolt\App\View\Exception;

abstract class Template
{
	protected _vars = [];
	protected _filePath;
	protected _context;
	protected _templateFile;

	public function __construct(<Context> context)
	{
		let this->_context = context;
	}

	public function display(array vars = null) -> string
	{
		string tplString;
		let this->_vars = vars;
		ob_start();
		this->main();
		let tplString = ob_get_contents();
		ob_end_clean();

		return tplString;
	}

	protected function _filter(name, args, val)
	{
		var filter = this->_context->getFilter(name);
		if !filter {
			throw new Exception("Unknown filter `" . name . "` in template " . this->_templateFile);
		}

		return call_user_func(filter, val, args);
	}
}