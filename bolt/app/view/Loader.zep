namespace Bolt\App\View;

use Bolt\App\View\Context;
use Bolt\App\View\Exception;

class Loader
{
	protected _cache;
	protected _context;

	public function _construct(<Context> ctx)
	{
		this->_context = ctx;
	}

	public function load(name)
	{
		var templatePath, cachePath, cacheModifiedAt, templateModifiedAt, extension;
		let extension = this->_context->getExtension();

		//get template
		let templatePath = this->_context->getTemplateDir();
		let templatePath = templatePath . DIRECTORY_SEPARATOR . name . extension;

		if !is_readable(templatePath) {
			throw new Exception("Template file `" . name . "` not found in `" . templatePath . "`");
		}

		let templateModifiedAt = filemtime(templatePath);

		let cachePath = this->_context->getCacheDir();

		if cachePath {
			let cachePath = cachePath . name . ".php";
			if is_readable(cachePath) {
				let cacheModifiedAt = filemtime(cachePath);
			}

			if cacheModifiedAt > templateModifiedAt {
				require cachePath;
				return this->_getTemplateClassName(templatePath);
			}
		}

	}

	protected function _getTemplateClassName(path)
	{
		return "_BoltTemplate_" . md5(path);
	}
}