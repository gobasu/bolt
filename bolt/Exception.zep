namespace Bolt;
/**
 * All Framework Exceptions should extend this one.
 */
class Exception extends \Exception
{
	public static function getExceptionStringWithPointer(string! str) -> string
	{
		string message = "";
		let message = str;
		let message .= "\n";
		let message .= str_repeat("-", str->length() - 1);
		let message .= "^";

		return message;
	}

	public static function getErrorHintFromString(string str, int! line, int column) ->string
	{
		var strs;
		var message;
		let strs = explode("\n", str);
		let message = strs[line - 1];
		let message .= "\n";
		let message .= str_repeat("-", column + 1);
		let message .= "^";

		return message;
	}
}