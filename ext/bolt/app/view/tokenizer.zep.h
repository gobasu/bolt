
extern zend_class_entry *bolt_app_view_tokenizer_ce;

ZEPHIR_INIT_CLASS(Bolt_App_View_Tokenizer);

PHP_METHOD(Bolt_App_View_Tokenizer, __construct);
PHP_METHOD(Bolt_App_View_Tokenizer, scan);
PHP_METHOD(Bolt_App_View_Tokenizer, getTokens);
PHP_METHOD(Bolt_App_View_Tokenizer, getText);
PHP_METHOD(Bolt_App_View_Tokenizer, getFile);
PHP_METHOD(Bolt_App_View_Tokenizer, _addToken);
PHP_METHOD(Bolt_App_View_Tokenizer, _isOpeningToken);
PHP_METHOD(Bolt_App_View_Tokenizer, _handleMainState);

ZEND_BEGIN_ARG_INFO_EX(arginfo_bolt_app_view_tokenizer___construct, 0, 0, 1)
	ZEND_ARG_INFO(0, text)
	ZEND_ARG_INFO(0, filePath)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_bolt_app_view_tokenizer__addtoken, 0, 0, 2)
	ZEND_ARG_INFO(0, type)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_bolt_app_view_tokenizer__isopeningtoken, 0, 0, 1)
	ZEND_ARG_INFO(0, token)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(bolt_app_view_tokenizer_method_entry) {
	PHP_ME(Bolt_App_View_Tokenizer, __construct, arginfo_bolt_app_view_tokenizer___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Bolt_App_View_Tokenizer, scan, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Bolt_App_View_Tokenizer, getTokens, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Bolt_App_View_Tokenizer, getText, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Bolt_App_View_Tokenizer, getFile, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Bolt_App_View_Tokenizer, _addToken, arginfo_bolt_app_view_tokenizer__addtoken, ZEND_ACC_PROTECTED)
	PHP_ME(Bolt_App_View_Tokenizer, _isOpeningToken, arginfo_bolt_app_view_tokenizer__isopeningtoken, ZEND_ACC_PROTECTED)
	PHP_ME(Bolt_App_View_Tokenizer, _handleMainState, NULL, ZEND_ACC_PRIVATE)
  PHP_FE_END
};
