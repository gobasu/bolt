namespace Bolt\App\Router;

use Bolt\App\Router\Exception;


class Route
{
	protected _pattern;
	protected _params = [];
	protected _values = [];
	protected _id;

	const T_SEPARATOR 	= '/';
	const T_OPENING_TAG = '{';
	const T_CLOSING_TAG = '}';
	const T_WILDCARD	= '*';
	const T_CONDITIONAL = '?';

	
	public function __construct(string! expression)
	{
		this->_compilePattern(expression);
		let this->_id = expression->md5();
	}
	
	/*
	* Compiles route pattern from {some}test/path/to/{be}?/{compiled}
	* into regular expression and named params
	*/
	protected function _compilePattern(string! expression)
	{
		char ch;
		var names = [], pattern = [];
		boolean inParentheses = false;
		int cursor;
		string tmp = "", name = "", cursorValue = "";

		for cursor, ch in expression {
			let cursorValue = (string) substr(expression, cursor, 1);
			if inParentheses {
				if ch == Route::T_CLOSING_TAG {		
					let names[] = name;
					let name = "";	
					let inParentheses = false;
					let tmp .= "([^/]+)";
					continue;
				}

				if (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || (ch >= '0' && ch <='9') || ch == '-' || ch == '_' {
					let name .= cursorValue;
					continue;
				}
				
				throw new Exception("Unexpected character `" . cursorValue . "` in param name. Valid param name should match [a-zA-Z0-9-_]+\n" . Exception::getExceptionStringWithPointer(substr(expression, 0, cursor + 1)));

			} else {
				if ch == Route::T_SEPARATOR {//route part finished
					let pattern[] = tmp;
					let tmp = "";
					continue;
				}

				if ch == Route::T_OPENING_TAG { //set new named param

					let inParentheses = true;
					continue;
				}

				if ch == Route::T_CONDITIONAL {

					if  cursor + 1 == expression->length() || expression[cursor + 1] == Route::T_SEPARATOR {
						let tmp = "(?:" . tmp . ")?";
						continue;
					} else {
						throw new Exception("Unexpected \Bolt\App\Router\Route::T_CONDITIONAL token in:\n" . Exception::getExceptionStringWithPointer(substr(expression, 0, cursor + 1)));
					}
				}

				if ch == Route::T_WILDCARD {
					if  cursor + 1 == expression->length() {
						let tmp .= ".*";
						break;
					} else {
						throw new Exception("Unexpected \Bolt\App\Router\Route::T_WILDCARD token in:\n" .  Exception::getExceptionStringWithPointer(substr(expression, 0, cursor + 1)));
					}
				}

				//escape
				if ch == '[' || ch == ']' || ch == '.' || ch == '|' || ch == '^' || ch == '$' || ch == '(' || ch == ')' || ch == '+' || ch == '!' || ch == '&' || ch == '\\' {
					let tmp .= "\\";
				} 

				let tmp .= cursorValue;
			}
		}

		if inParentheses {
			throw new Exception("Unexpected end of route in:\n" .  Exception::getExceptionStringWithPointer(substr(expression, 0, cursor + 1)));
		}
		if tmp->length() > 0 {
			let pattern[] = tmp;
		}
		
		let this->_pattern 	= join("/", pattern);
		let this->_params	= names;
	}

	public function getPattern() -> string
	{
		return this->_pattern;
	}

	public function getParamNames() -> array
	{
		return this->_params;
	}

	public function getParams() -> array
	{
		return this->_values;
	}

	public function getId() -> string
	{
		return this->_id;
	}

	public function match(string! uri) -> boolean
	{
		var matches = [], matched;
		int i, length;
		let matched = preg_match("#" . this->_pattern . "#", uri, matches);
		if matched == 0 {
			return false;
		}
		let length = count(matches);
		let i = 1;
		while i < length {
			let this->_values[this->_params[ i - 1 ]] = matches[i];
			let i++;
		}

		return true;
	}

}