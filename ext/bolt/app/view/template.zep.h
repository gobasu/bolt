
extern zend_class_entry *bolt_app_view_template_ce;

ZEPHIR_INIT_CLASS(Bolt_App_View_Template);

PHP_METHOD(Bolt_App_View_Template, __construct);
PHP_METHOD(Bolt_App_View_Template, render);
PHP_METHOD(Bolt_App_View_Template, _filter);

ZEND_BEGIN_ARG_INFO_EX(arginfo_bolt_app_view_template_render, 0, 0, 0)
	ZEND_ARG_INFO(0, vars)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_bolt_app_view_template__filter, 0, 0, 3)
	ZEND_ARG_INFO(0, name)
	ZEND_ARG_INFO(0, args)
	ZEND_ARG_INFO(0, val)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(bolt_app_view_template_method_entry) {
	PHP_ME(Bolt_App_View_Template, __construct, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Bolt_App_View_Template, render, arginfo_bolt_app_view_template_render, ZEND_ACC_PUBLIC)
	PHP_ME(Bolt_App_View_Template, _filter, arginfo_bolt_app_view_template__filter, ZEND_ACC_PROTECTED)
  PHP_FE_END
};
