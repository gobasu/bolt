
extern zend_class_entry *bolt_app_router_ce;

ZEPHIR_INIT_CLASS(Bolt_App_Router);

PHP_METHOD(Bolt_App_Router, mount);
PHP_METHOD(Bolt_App_Router, unmount);
PHP_METHOD(Bolt_App_Router, match);
PHP_METHOD(Bolt_App_Router, __construct);

ZEND_BEGIN_ARG_INFO_EX(arginfo_bolt_app_router_mount, 0, 0, 2)
	ZEND_ARG_INFO(0, route)
	ZEND_ARG_INFO(0, callback)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_bolt_app_router_unmount, 0, 0, 1)
	ZEND_ARG_INFO(0, route)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_bolt_app_router_match, 0, 0, 1)
	ZEND_ARG_INFO(0, uri)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(bolt_app_router_method_entry) {
	PHP_ME(Bolt_App_Router, mount, arginfo_bolt_app_router_mount, ZEND_ACC_PUBLIC)
	PHP_ME(Bolt_App_Router, unmount, arginfo_bolt_app_router_unmount, ZEND_ACC_PUBLIC)
	PHP_ME(Bolt_App_Router, match, arginfo_bolt_app_router_match, ZEND_ACC_PUBLIC)
	PHP_ME(Bolt_App_Router, __construct, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
  PHP_FE_END
};
