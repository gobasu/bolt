namespace Bolt\Http;

class Request
{
	const METHOD_GET = "GET";
	const METHOD_POST = "POST";
	const METHOD_DELETE = "DELETE";
	const METHOD_PUT = "PUT";

	protected _query = [];

	protected _uri = "/";

	protected _host = "";

	protected _data = [];

	protected _method;

	protected _isXHR = false;

	protected _scheme = "http";

	protected _headers;

	protected _verifyPeer = false;

	protected _cookieJar;

	protected _caFile;

	protected static _globalRequest;

	public static function get()
	{
		if self::_globalRequest == null {
			if isset _SERVER["REQUEST_METHOD"] {//called from cli
                let self::_globalRequest = false;
                return self::_globalRequest;
            }
		}
	}
}