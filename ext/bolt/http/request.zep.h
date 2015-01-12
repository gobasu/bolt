
extern zend_class_entry *bolt_http_request_ce;

ZEPHIR_INIT_CLASS(Bolt_Http_Request);

PHP_METHOD(Bolt_Http_Request, get);
PHP_METHOD(Bolt_Http_Request, __construct);

ZEPHIR_INIT_FUNCS(bolt_http_request_method_entry) {
	PHP_ME(Bolt_Http_Request, get, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Bolt_Http_Request, __construct, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
  PHP_FE_END
};
