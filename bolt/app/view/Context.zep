namespace Bolt\App\View;

use Bolt\App\View\Exception;
use Bolt\App\View\Loader;

class Context
{
	protected _templateDir;
	protected _cacheDir;
	protected _filters;
	protected _extension = "html";
	protected _loader;


	public function __construct(string templateDir = null, string cacheDir = null)
	{
		if templateDir {
			this->setTemplateDir(templateDir);
		}

		if cacheDir {
			this->setCacheDir(cacheDir);
		}

		this->_registerDefaults();
		this->_loader = new Loader(this);
	}

	protected function _registerDefaults()
	{
		this->registerFilter("escape", "html_entity_encode");
		this->registerFilter("e", "html_entity_encode");
		this->registerFilter("trim", "trim");
		this->registerFilter("ltrim", "ltrim");
		this->registerFilter("lefttrim", "ltrim");
		this->registerFilter("rtrim", "rtrim");
		this->registerFilter("righttrim", "rtrim");
		this->registerFilter("capitalize", "ucwords");
		this->registerFilter("striptags", "striptags");
		this->registerFilter("stripslashes", "stripslashes");
	}

	public function setTemplateDir(string dir)
	{
		if !is_dir(dir) {
			throw new Exception("Template dir: `" . dir . "` does not exists or is not readable");
		}
		let this->_templateDir = dir;
	}

	public function getTemplateDir()
	{
		return this->_templateDir;
	}

	public function setCacheDir(string dir)
	{
		if !is_dir(dir) {
			throw new Exception("Cache dir: `" . dir . "` does not exists or is not readable");
		}
		let this->_cacheDir = dir;
	}

	public function getCacheDir()
	{
		return this->_cacheDir;
	}

	public function getExtension()
	{
		return this->_extension;
	}

	public function setExtension(ext)
	{
		let this->_extension = ext;
	}

	

	public function registerFilter(string name, var callback)
	{
		if !is_callable(callback) {
			throw new Exception("Filter `" . name . "` does not provide callable resource");
		}

		let this->_filters[name] = callback;
	}

	public function getFilter(string name)
	{
		if !isset this->_filters[name] {
			return null;
		}
		return this->_filters[name];
	}

	public function unregisterFilter(string name)
	{
		unset this->_filters[name];
	}

	public function unregisterAllFilters()
	{
		let this->_filters = [];
	}

	public function getRegisteredFilters()
	{
		return this->_filters;
	}

	public function factoryTemplate(string name)
	{
		var tplClassName;
		let tplClassName = this->_loader->load(name);
		return new {tplClassName}(this);
	}

}