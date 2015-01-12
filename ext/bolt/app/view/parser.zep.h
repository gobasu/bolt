
extern zend_class_entry *bolt_app_view_parser_ce;

ZEPHIR_INIT_CLASS(Bolt_App_View_Parser);

PHP_METHOD(Bolt_App_View_Parser, __construct);
PHP_METHOD(Bolt_App_View_Parser, getTokenizer);
PHP_METHOD(Bolt_App_View_Parser, parse);
PHP_METHOD(Bolt_App_View_Parser, _debugTree);
PHP_METHOD(Bolt_App_View_Parser, _printFullName);

ZEND_BEGIN_ARG_INFO_EX(arginfo_bolt_app_view_parser___construct, 0, 0, 1)
	ZEND_ARG_INFO(0, fileName)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_bolt_app_view_parser__debugtree, 0, 0, 1)
	ZEND_ARG_INFO(0, node)
	ZEND_ARG_INFO(0, indent)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_bolt_app_view_parser__printfullname, 0, 0, 1)
	ZEND_ARG_INFO(0, node)
	ZEND_ARG_INFO(0, str)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(bolt_app_view_parser_method_entry) {
	PHP_ME(Bolt_App_View_Parser, __construct, arginfo_bolt_app_view_parser___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Bolt_App_View_Parser, getTokenizer, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Bolt_App_View_Parser, parse, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Bolt_App_View_Parser, _debugTree, arginfo_bolt_app_view_parser__debugtree, ZEND_ACC_PUBLIC)
	PHP_ME(Bolt_App_View_Parser, _printFullName, arginfo_bolt_app_view_parser__printfullname, ZEND_ACC_PRIVATE)
  PHP_FE_END
};
