namespace Bolt\App;

use Bolt\App\Router\Route;

class Router
{	
	protected _routes = [];

	public function mount(string! route, var callback)
	{
		let this->_routes[route->md5()] = [
			"route": 	new Route(route),
			"callback": callback
		];
	}

	public function unmount(string! route)
	{
		unset this->_routes[route->md5()];
	}

	public function match(string! uri) -> array | boolean
	{
		var route;
		for route in this->_routes {
			if route["route"]->match(uri) {
				return route;
			}
		}
		return false;
	}
}