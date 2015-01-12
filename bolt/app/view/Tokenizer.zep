namespace Bolt\App\View;

final class Tokenizer
{
	protected _text = "";
	protected _tokens = [];
	protected _token = "";
	protected _length = 0;
	protected _index = 0;
	protected _column = 0;
	protected _strDelimiter = "";
	protected _buffer = "";
	protected _state;
	protected _line = 0;
	protected _file = "string::";
	protected _inBlock = false;
	protected _inVar = false;
	protected _inArguments = false;
	protected _inModifier = false;
	protected _inArray = false;
	protected _hasArgumentNameAlready = false;
	protected _arrayLevel = 0;
	protected _escapeArrayArg = false;

	//tokens
	const T_START_ELEMENT 		= "{%";
	const T_END_ELEMENT 		= "%}";
	const T_START_EXPRESSION	= "{{";
	const T_END_EXPRESSION 		= "}}";
	const T_START_COMMENT		= "{#";
	const T_END_COMMENT			= "#}";
	const T_START_IGNORE		= "{!";
	const T_END_IGNORE			= "!}";

	const T_MODIFIER			= '|';
	const T_START_ARGS			= '(';
	const T_END_ARGS			= ')';
	const T_ARGS_SEPARATOR		= ',';
	const T_START_ARRAY			= '[';
	const T_END_ARRAY			= ']';

	//token types
	const TYPE_TEXT 			= 0;
	const TYPE_PROPERTY			= 1;
	const TYPE_OPEN_ELEMENT		= 2;
	const TYPE_CLOSE_ELEMENT	= 3;
	const TYPE_OPEN_EXPRESSION	= 4;
	const TYPE_CLOSE_EXPRESSION	= 5;
	const TYPE_OPEN_IGNORE  	= 6;
	const TYPE_CLOSE_IGNORE 	= 7;
	const TYPE_MODIFIER			= 8;
	const TYPE_OPEN_ARGUMENTS	= 9;
	const TYPE_CLOSE_ARGUMENTS	= 11;
	const TYPE_ARGUMENT			= 12;
	const TYPE_IGNORED			= 13;
	const TYPE_OPEN_COMMENT		= 14;
	const TYPE_CLOSE_COMMENT	= 15;
	const TYPE_COMMENTED		= 16;
	const TYPE_OPEN_ARRAY		= 17;
	const TYPE_CLOSE_ARRAY		= 18;
	const TYPE_ARGUMENTS_NAME	= 19;

	//states
	const S_TEXT		= 0;
	const S_TAG 		= 1;
	const S_PROPERTY	= 2;
	const S_STRING		= 3;
	const S_IGNORE  	= 4;
	const S_MODIFIER	= 5;
	const S_ARGUMENTS	= 6;
	const S_COMMENT 	= 7;
	const S_ARRAY 		= 8;


	public function __construct(string! text, string! filePath = "string::")
	{
		let this->_text = text;
		let this->_file = filePath;
	}

	public function scan()
	{

		let this->_length = strlen(this->_text);
		let this->_index = 0;
		let this->_column = 1;
		let this->_line = 1;
		let this->_token = "";
		let this->_tokens = [];
		let this->_state = Tokenizer::S_TEXT;

		while this->_index < this->_length {
			this->_handleMainState();
		}

		if this->_buffer {
			this->_addToken(Tokenizer::TYPE_TEXT, this->_buffer);
		}

	}

	public function getTokens()
	{
		return this->_tokens;
	}

	public function getText()
	{
		return this->_text;
	}

	public function getFile()
	{
		return this->_file;
	}

	protected function _addToken(type, value)
	{
		
		let this->_tokens[] = [
			"type": type,
			"value": (string) value,
			"column": (int) this->_column,
			"line": (int) this->_line,
			"index": (int) this->_index,
			"length": (int) strlen(value)
		];
	}

	protected function _isOpeningToken(string! token)
	{
		if token == Tokenizer::T_START_ELEMENT || token == Tokenizer::T_START_COMMENT || token == Tokenizer::T_START_EXPRESSION || token == Tokenizer::T_START_IGNORE {
			return true;
		}

		return false;
	}

	private function _handleMainState()
	{
		var prevCh, currentCh, nextCh;
		string text;
		var index, tmp;
		int tmpIndex;

		let text = (string) this->_text;
		let index = (int) this->_index;

		let this->_column = this->_column + 1;

		if index > 0 {
			let prevCh = text[index - 1];
		}
		let currentCh = text[index];


		if index + 1 < this->_length {
			let this->_token = substr(text, index, 2);
			let nextCh = text[index + 1];
		}

		if currentCh == '\n' {
			let this->_line = this->_line + 1;
			let this->_column = 1;
		}

		switch this->_state {
			case Tokenizer::S_TEXT: 

				if this->_isOpeningToken(this->_token) {
					this->_addToken(Tokenizer::TYPE_TEXT, this->_buffer);
					let this->_buffer = "";
				}

				switch this->_token {

					case Tokenizer::T_START_ELEMENT:
						let this->_state = Tokenizer::S_TAG;
						this->_addToken(Tokenizer::TYPE_OPEN_ELEMENT, this->_token);
						let this->_inBlock = true;
						let this->_index = index + 2;
						return;

					case Tokenizer::T_START_EXPRESSION:
						let this->_state = Tokenizer::S_TAG;
						this->_addToken(Tokenizer::TYPE_OPEN_EXPRESSION, this->_token);
						let this->_inVar = true;
						let this->_index = index + 2;
						return;

					case Tokenizer::T_START_COMMENT:

						let this->_state = Tokenizer::S_COMMENT;
						this->_addToken(Tokenizer::TYPE_OPEN_COMMENT, this->_token);
						let this->_index = index + 2;
						return;

					case Tokenizer::T_START_IGNORE:
						let this->_state = Tokenizer::S_IGNORE;
						this->_addToken(Tokenizer::TYPE_OPEN_IGNORE, this->_token);
						let this->_index = index + 2;
						return;
				}

				break;

			case Tokenizer::S_TAG:
				
				if ctype_space(currentCh) {
					let this->_index = index + 1;
					return;
				}

				if this->_inVar && this->_token == Tokenizer::T_END_EXPRESSION {
					this->_addToken(Tokenizer::TYPE_CLOSE_EXPRESSION, this->_token);
					let this->_inVar = false;
					let this->_inBlock = false;
					let this->_buffer = "";
					let this->_state = Tokenizer::S_TEXT;
					let this->_index = index + 2;
					return;
				}

				if this->_inBlock && this->_token == Tokenizer::T_END_ELEMENT {
					this->_addToken(Tokenizer::TYPE_CLOSE_ELEMENT, this->_token);
					let this->_inVar = false;
					let this->_inBlock = false;
					let this->_buffer = "";
					let this->_state = Tokenizer::S_TEXT;
					let this->_index = index + 2;
					return;
				}
				
				let this->_state = Tokenizer::S_PROPERTY;
				return;
			case Tokenizer::S_PROPERTY:
				
				if (currentCh == '"' || currentCh == '\'') && this->_buffer == "" {
					
					let this->_state = Tokenizer::S_STRING;
					let this->_strDelimiter = currentCh;
					let this->_buffer = "";
					let this->_index = index + 1;
					return;
				}

				if currentCh == '[' && this->_buffer == "" {
					let this->_state = Tokenizer::S_ARRAY;
					this->_addToken(self::TYPE_OPEN_ARRAY, "[");
					let this->_buffer = "";
					let this->_index = index + 1;
					let this->_inArray = true;
					let this->_arrayLevel = 1;
					return;
				}

				if currentCh == '"' || currentCh == '\'' {
					
					throw new Exception("Unexpected token Tokenizer::T_STRING in " . this->_file . " on line " . this->_line . "\n" . Exception::getErrorHintFromString(text, this->_line, this->_column));
				}


				if currentCh == '|' {
					if this->_buffer != "" {
                        this->_addToken(self::TYPE_PROPERTY, this->_buffer);
                    	let this->_buffer = "";
                    } elseif prevCh != ')' && prevCh != ']' {
                    	throw new Exception("Unexpected token Tokenizer::T_MODIFIER in " . this->_file . " on line " . this->_line . "\n" . Exception::getErrorHintFromString(text, this->_line, this->_column));
                    }
					let this->_state = Tokenizer::S_MODIFIER;
					let this->_index = index + 1;
					return;
				}

				if currentCh == '(' {
					this->_addToken(self::TYPE_PROPERTY, this->_buffer);
					this->_addToken(self::TYPE_OPEN_ARGUMENTS, "(");
					let this->_inArguments = true;
					let this->_state = Tokenizer::S_ARGUMENTS;
					let this->_index = index + 1;
					let this->_buffer = "";
					return;
				}

				if ctype_space(currentCh) {
					if this->_buffer != "" {
                    	this->_addToken(self::TYPE_PROPERTY, this->_buffer);
                    	let this->_buffer = "";
                    }
                    
                    let this->_state = self::S_TAG;
                    let this->_index = index + 1;
                    return;
                }

                if this->_inVar && this->_token == Tokenizer::T_END_EXPRESSION {

                	if trim(this->_buffer) != "" {
                        this->_addToken(self::TYPE_PROPERTY, this->_buffer);
                    	let this->_buffer = "";
                    }
					this->_addToken(Tokenizer::TYPE_CLOSE_EXPRESSION, this->_token);
					let this->_inVar = false;
					let this->_inBlock = false;
					let this->_buffer = "";
					let this->_state = Tokenizer::S_TEXT;
					let this->_index = index + 2;
					return;
				}

				if this->_inBlock && this->_token == Tokenizer::T_END_ELEMENT {
					if trim(this->_buffer) != "" {
                        this->_addToken(self::TYPE_PROPERTY, this->_buffer);
                    	let this->_buffer = "";
                    }

					this->_addToken(Tokenizer::TYPE_CLOSE_ELEMENT, this->_token);
					let this->_inVar = false;
					let this->_inBlock = false;
					let this->_buffer = "";
					let this->_state = Tokenizer::S_TEXT;
					let this->_index = index + 2;
					return;
				}

				break;
			case Tokenizer::S_ARGUMENTS:
				if currentCh == ')' {
					if this->_buffer {
						this->_addToken(Tokenizer::TYPE_ARGUMENT, this->_buffer);
						let this->_buffer = "";
					}
					this->_addToken(Tokenizer::TYPE_CLOSE_ARGUMENTS, ")");
					let this->_index = index + 1;
					let this->_inArguments = false;
					let this->_state = Tokenizer::S_PROPERTY;
					return;
				}

				if currentCh == ',' {
					if this->_buffer {
						this->_addToken(Tokenizer::TYPE_ARGUMENT, this->_buffer);
					} else {
						this->_addToken(Tokenizer::TYPE_ARGUMENT, "");
					}
					let this->_index = index + 1;
					let this->_buffer = "";
					return;
				}

				if currentCh == '"' || currentCh == '\'' {
					let this->_buffer = "";
					let this->_index = index + 1;
					let this->_state = Tokenizer::S_STRING;
					let this->_strDelimiter = currentCh;
					return;
				}

				if (currentCh >= 'a' && currentCh <= 'z') || (currentCh >= 'A' && currentCh <= 'Z') || (currentCh >= '0' && currentCh <='9') || currentCh == '_' || currentCh == '.' || currentCh == '[' || currentCh == ']' {
					break;
				}

				if ctype_space(currentCh) {
					let this->_index = index + 1;
					return;
				}

				throw new Exception("Unexpected character `" . currentCh . "` in " . this->_file . " on line " . this->_line . "\n" . Exception::getErrorHintFromString(text, this->_line, this->_column));
				
			case Tokenizer::S_STRING:
	
				
				if currentCh == this->_strDelimiter && prevCh != '\\' {

					if this->_inArray {
						this->_addToken(Tokenizer::TYPE_ARGUMENT, chr(this->_strDelimiter) . this->_buffer . chr(this->_strDelimiter));
						let this->_state = Tokenizer::S_ARRAY;
						if nextCh == ',' {
							let index++;
						}
					} elseif this->_inArguments {

						this->_addToken(Tokenizer::TYPE_ARGUMENT, chr(this->_strDelimiter) . this->_buffer . chr(this->_strDelimiter));
						let this->_state = Tokenizer::S_ARGUMENTS;
						if nextCh == ',' {
							let index++;
						}

					} else {
						this->_addToken(Tokenizer::TYPE_PROPERTY, chr(this->_strDelimiter) . this->_buffer . chr(this->_strDelimiter));
						let index = index + 1;
						if nextCh == Tokenizer::T_MODIFIER {
							let this->_state = Tokenizer::S_MODIFIER;
						} else {
							let this->_state = Tokenizer::S_TAG;
						}
					}	
					let this->_buffer = "";
					let this->_index = index + 1;
					return;

				}
				break;	

			case Tokenizer::S_MODIFIER:
				if ctype_space(currentCh) {
					this->_addToken(Tokenizer::TYPE_MODIFIER, this->_buffer);
					let this->_buffer = "";
					let this->_state = Tokenizer::S_TAG;
					let this->_index = index + 1;
					return;
				}

				if currentCh == '|' {
					this->_addToken(Tokenizer::TYPE_MODIFIER, this->_buffer);
					let this->_buffer = "";
					let this->_index = index + 1;
					return;
				}

				if currentCh == '(' {
					this->_addToken(Tokenizer::TYPE_MODIFIER, this->_buffer);
					this->_addToken(self::TYPE_OPEN_ARGUMENTS, "(");
					let this->_inArguments = true;
					let this->_state = Tokenizer::S_ARGUMENTS;
					let this->_index = index + 1;
					let this->_buffer = "";
					return;
				}

				if (currentCh >= 'a' && currentCh <= 'z') || (currentCh >= 'A' && currentCh <= 'Z') || (currentCh >= '0' && currentCh <='9') || currentCh == '_' {
					break;
				}

				if  this->_token == Tokenizer::T_END_EXPRESSION {
					this->_addToken(Tokenizer::TYPE_MODIFIER, this->_buffer);
					let this->_buffer = "";
                	let this->_state = Tokenizer::S_TAG;
					return;
				}


				throw new Exception("Unexpected character `" . chr(currentCh) . "` in " . this->_file . " on line " . this->_line . "\n" . Exception::getErrorHintFromString(text, this->_line, this->_column));

			case Tokenizer::S_COMMENT:
				if this->_token == Tokenizer::T_END_COMMENT {
					this->_addToken(Tokenizer::TYPE_COMMENTED, this->_buffer);
					let this->_buffer = "";
					this->_addToken(Tokenizer::TYPE_CLOSE_COMMENT, this->_token);
					let this->_state = Tokenizer::S_TEXT;
					let this->_index = index + 2;
					return;
				}
				break;

			case Tokenizer::S_IGNORE:


				if this->_token == Tokenizer::T_END_IGNORE {
					this->_addToken(Tokenizer::TYPE_IGNORED, this->_buffer);
					let this->_buffer = "";
					this->_addToken(Tokenizer::TYPE_CLOSE_IGNORE, this->_token);
					let this->_state = Tokenizer::S_TEXT;
					let this->_index = index + 2;
					return;
				}
				break;

			case Tokenizer::S_ARRAY:
				if currentCh == ']'  {
					if this->_buffer != "" {//check amount of [ and ] in string
						if substr_count(this->_buffer, "]") != substr_count(this->_buffer, "[") {
							return;
						}
					}

					if this->_buffer {
						this->_addToken(Tokenizer::TYPE_ARGUMENT, this->_buffer);
						let this->_buffer = "";
					}
					this->_addToken(Tokenizer::TYPE_CLOSE_ARRAY, "]");
					let this->_index = index + 1;

					if this->_arrayLevel == 1 {
						let this->_inArray = false;
						let this->_arrayLevel = 0;
						let this->_state = Tokenizer::S_PROPERTY;
					} else {
						let this->_arrayLevel = this->_arrayLevel - 1;
					}
					return;
				}

				if currentCh == '[' && this->_buffer == "" {
					this->_addToken(Tokenizer::TYPE_OPEN_ARRAY, "[");
					let this->_arrayLevel = this->_arrayLevel + 1;
					let this->_index = index + 1;
					return;
				}

				if currentCh == ',' {

					let this->_hasArgumentNameAlready = false;
					if this->_buffer {
						this->_addToken(Tokenizer::TYPE_ARGUMENT, this->_buffer);
					} else {
						let tmpIndex = index;
						let tmp = 0;
						while tmpIndex > 0 {
							if text[tmpIndex] == ',' {
								let tmp = tmp + 1;
							}

							if text[tmpIndex] == ']' {
								let this->_index = index + 1;// ],
								break;
							} elseif tmp == 2 {
								this->_addToken(Tokenizer::TYPE_ARGUMENT, "null");// , ,
								break;
							}
							let tmpIndex--;
						}
						let tmpIndex = null;
						let tmp = null;
					}
					let this->_index = index + 1;
					let this->_buffer = "";
					
					return;
				}

				if currentCh == ':' {
					if this->_hasArgumentNameAlready {
						throw new Exception("Argument has name already. Unexpected token `:` in " . this->_file . " on line " . this->_line . "\n" . Exception::getErrorHintFromString(text, this->_line, this->_column));
					}
					if this->_buffer {
						this->_addToken(Tokenizer::TYPE_ARGUMENTS_NAME, this->_buffer);
						let this->_hasArgumentNameAlready = true;
						let this->_buffer = "";
						let this->_index = index + 1;
						return;
					}
				}

				if currentCh == '"' || currentCh == '\'' {
					let this->_buffer = "";
					let this->_index = index + 1;
					let this->_state = Tokenizer::S_STRING;
					let this->_strDelimiter = currentCh;
					return;
				}

				if ctype_space(currentCh) {
					let this->_index = index + 1;
					return;
				}

				if this->_token == Tokenizer::T_END_EXPRESSION  || this->_token == Tokenizer::T_END_ELEMENT {
					throw new Exception("Unexpected end of input. Expected `]` in " . this->_file . " on line " . this->_line . "\n" . Exception::getErrorHintFromString(text, this->_line, this->_column));
				}

				break;

		}


		let this->_buffer = this->_buffer . substr(text, index, 1);
		let this->_index = index + 1;
	}


}