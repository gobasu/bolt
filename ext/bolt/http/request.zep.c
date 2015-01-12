
#ifdef HAVE_CONFIG_H
#include "../../ext_config.h"
#endif

#include <php.h>
#include "../../php_ext.h"
#include "../../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/object.h"
#include "kernel/operators.h"
#include "kernel/array.h"
#include "kernel/memory.h"

ZEPHIR_INIT_CLASS(Bolt_Http_Request) {

	ZEPHIR_REGISTER_CLASS(Bolt\\Http, Request, bolt, http_request, bolt_http_request_method_entry, 0);

	zend_declare_property_null(bolt_http_request_ce, SL("_query"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_string(bolt_http_request_ce, SL("_uri"), "/", ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_string(bolt_http_request_ce, SL("_host"), "", ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(bolt_http_request_ce, SL("_data"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(bolt_http_request_ce, SL("_method"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_bool(bolt_http_request_ce, SL("_isXHR"), 0, ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_string(bolt_http_request_ce, SL("_scheme"), "http", ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(bolt_http_request_ce, SL("_headers"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_bool(bolt_http_request_ce, SL("_verifyPeer"), 0, ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(bolt_http_request_ce, SL("_cookieJar"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(bolt_http_request_ce, SL("_caFile"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(bolt_http_request_ce, SL("_globalRequest"), ZEND_ACC_PROTECTED|ZEND_ACC_STATIC TSRMLS_CC);

	zend_declare_class_constant_string(bolt_http_request_ce, SL("METHOD_GET"), "GET" TSRMLS_CC);

	zend_declare_class_constant_string(bolt_http_request_ce, SL("METHOD_POST"), "POST" TSRMLS_CC);

	zend_declare_class_constant_string(bolt_http_request_ce, SL("METHOD_DELETE"), "DELETE" TSRMLS_CC);

	zend_declare_class_constant_string(bolt_http_request_ce, SL("METHOD_PUT"), "PUT" TSRMLS_CC);

	return SUCCESS;

}

PHP_METHOD(Bolt_Http_Request, get) {

	zval *_0, *_SERVER, *_1;


	_0 = zephir_fetch_static_property_ce(bolt_http_request_ce, SL("_globalRequest") TSRMLS_CC);
	if (Z_TYPE_P(_0) == IS_NULL) {
		zephir_get_global(&_SERVER, SS("_SERVER") TSRMLS_CC);
		if (zephir_array_isset_string(_SERVER, SS("REQUEST_METHOD"))) {
			zephir_update_static_property_ce(bolt_http_request_ce, SL("_globalRequest"), &(ZEPHIR_GLOBAL(global_false)) TSRMLS_CC);
			_1 = zephir_fetch_static_property_ce(bolt_http_request_ce, SL("_globalRequest") TSRMLS_CC);
			RETURN_CTORW(_1);
		}
	}

}

PHP_METHOD(Bolt_Http_Request, __construct) {

	zval *_0, *_1;

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(_0);
	array_init(_0);
	zephir_update_property_this(this_ptr, SL("_data"), _0 TSRMLS_CC);
	ZEPHIR_INIT_VAR(_1);
	array_init(_1);
	zephir_update_property_this(this_ptr, SL("_query"), _1 TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

