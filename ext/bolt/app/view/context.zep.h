
extern zend_class_entry *bolt_app_view_context_ce;

ZEPHIR_INIT_CLASS(Bolt_App_View_Context);

PHP_METHOD(Bolt_App_View_Context, __construct);
PHP_METHOD(Bolt_App_View_Context, _registerDefaults);
PHP_METHOD(Bolt_App_View_Context, setTemplateDir);
PHP_METHOD(Bolt_App_View_Context, getTemplateDir);
PHP_METHOD(Bolt_App_View_Context, setCacheDir);
PHP_METHOD(Bolt_App_View_Context, getCacheDir);
PHP_METHOD(Bolt_App_View_Context, setData);
PHP_METHOD(Bolt_App_View_Context, getData);
PHP_METHOD(Bolt_App_View_Context, registerFilter);
PHP_METHOD(Bolt_App_View_Context, getFilter);
PHP_METHOD(Bolt_App_View_Context, unregisterFilter);
PHP_METHOD(Bolt_App_View_Context, unregisterAllFilters);
PHP_METHOD(Bolt_App_View_Context, getRegisteredFilters);
PHP_METHOD(Bolt_App_View_Context, filterDate);

ZEND_BEGIN_ARG_INFO_EX(arginfo_bolt_app_view_context___construct, 0, 0, 0)
	ZEND_ARG_INFO(0, templateDir)
	ZEND_ARG_INFO(0, cacheDir)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_bolt_app_view_context_settemplatedir, 0, 0, 1)
	ZEND_ARG_INFO(0, dir)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_bolt_app_view_context_setcachedir, 0, 0, 1)
	ZEND_ARG_INFO(0, dir)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_bolt_app_view_context_setdata, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, data, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_bolt_app_view_context_registerfilter, 0, 0, 2)
	ZEND_ARG_INFO(0, name)
	ZEND_ARG_INFO(0, callback)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_bolt_app_view_context_getfilter, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_bolt_app_view_context_unregisterfilter, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_bolt_app_view_context_filterdate, 0, 0, 2)
	ZEND_ARG_INFO(0, value)
	ZEND_ARG_INFO(0, args)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(bolt_app_view_context_method_entry) {
	PHP_ME(Bolt_App_View_Context, __construct, arginfo_bolt_app_view_context___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Bolt_App_View_Context, _registerDefaults, NULL, ZEND_ACC_PROTECTED)
	PHP_ME(Bolt_App_View_Context, setTemplateDir, arginfo_bolt_app_view_context_settemplatedir, ZEND_ACC_PUBLIC)
	PHP_ME(Bolt_App_View_Context, getTemplateDir, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Bolt_App_View_Context, setCacheDir, arginfo_bolt_app_view_context_setcachedir, ZEND_ACC_PUBLIC)
	PHP_ME(Bolt_App_View_Context, getCacheDir, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Bolt_App_View_Context, setData, arginfo_bolt_app_view_context_setdata, ZEND_ACC_PUBLIC)
	PHP_ME(Bolt_App_View_Context, getData, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Bolt_App_View_Context, registerFilter, arginfo_bolt_app_view_context_registerfilter, ZEND_ACC_PUBLIC)
	PHP_ME(Bolt_App_View_Context, getFilter, arginfo_bolt_app_view_context_getfilter, ZEND_ACC_PUBLIC)
	PHP_ME(Bolt_App_View_Context, unregisterFilter, arginfo_bolt_app_view_context_unregisterfilter, ZEND_ACC_PUBLIC)
	PHP_ME(Bolt_App_View_Context, unregisterAllFilters, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Bolt_App_View_Context, getRegisteredFilters, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Bolt_App_View_Context, filterDate, arginfo_bolt_app_view_context_filterdate, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
  PHP_FE_END
};
