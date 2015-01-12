
extern zend_class_entry *bolt_app_router_route_ce;

ZEPHIR_INIT_CLASS(Bolt_App_Router_Route);

PHP_METHOD(Bolt_App_Router_Route, __construct);
PHP_METHOD(Bolt_App_Router_Route, _compilePattern);
PHP_METHOD(Bolt_App_Router_Route, getPattern);
PHP_METHOD(Bolt_App_Router_Route, getParamNames);
PHP_METHOD(Bolt_App_Router_Route, getParams);
PHP_METHOD(Bolt_App_Router_Route, getId);
PHP_METHOD(Bolt_App_Router_Route, match);

ZEND_BEGIN_ARG_INFO_EX(arginfo_bolt_app_router_route___construct, 0, 0, 1)
	ZEND_ARG_INFO(0, expression)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_bolt_app_router_route__compilepattern, 0, 0, 1)
	ZEND_ARG_INFO(0, expression)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_bolt_app_router_route_match, 0, 0, 1)
	ZEND_ARG_INFO(0, uri)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(bolt_app_router_route_method_entry) {
	PHP_ME(Bolt_App_Router_Route, __construct, arginfo_bolt_app_router_route___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Bolt_App_Router_Route, _compilePattern, arginfo_bolt_app_router_route__compilepattern, ZEND_ACC_PROTECTED)
	PHP_ME(Bolt_App_Router_Route, getPattern, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Bolt_App_Router_Route, getParamNames, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Bolt_App_Router_Route, getParams, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Bolt_App_Router_Route, getId, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Bolt_App_Router_Route, match, arginfo_bolt_app_router_route_match, ZEND_ACC_PUBLIC)
  PHP_FE_END
};
