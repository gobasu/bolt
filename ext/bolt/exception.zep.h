
extern zend_class_entry *bolt_exception_ce;

ZEPHIR_INIT_CLASS(Bolt_Exception);

PHP_METHOD(Bolt_Exception, getExceptionStringWithPointer);
PHP_METHOD(Bolt_Exception, getErrorHintFromString);

ZEND_BEGIN_ARG_INFO_EX(arginfo_bolt_exception_getexceptionstringwithpointer, 0, 0, 1)
	ZEND_ARG_INFO(0, str)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_bolt_exception_geterrorhintfromstring, 0, 0, 3)
	ZEND_ARG_INFO(0, str)
	ZEND_ARG_INFO(0, line)
	ZEND_ARG_INFO(0, column)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(bolt_exception_method_entry) {
	PHP_ME(Bolt_Exception, getExceptionStringWithPointer, arginfo_bolt_exception_getexceptionstringwithpointer, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Bolt_Exception, getErrorHintFromString, arginfo_bolt_exception_geterrorhintfromstring, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
  PHP_FE_END
};
