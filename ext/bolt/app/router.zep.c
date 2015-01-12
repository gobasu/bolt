
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
#include "kernel/memory.h"
#include "kernel/fcall.h"
#include "kernel/array.h"
#include "kernel/object.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/exception.h"
#include "kernel/operators.h"
#include "kernel/hash.h"

ZEPHIR_INIT_CLASS(Bolt_App_Router) {

	ZEPHIR_REGISTER_CLASS(Bolt\\App, Router, bolt, app_router, bolt_app_router_method_entry, 0);

	zend_declare_property_null(bolt_app_router_ce, SL("_routes"), ZEND_ACC_PROTECTED TSRMLS_CC);

	return SUCCESS;

}

PHP_METHOD(Bolt_App_Router, mount) {

	zephir_nts_static zephir_fcall_cache_entry *_4 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *_0;
	zval *route_param = NULL, *callback, *_1, *_2 = NULL, *_3 = NULL;
	zval *route = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &route_param, &callback);

	if (unlikely(Z_TYPE_P(route_param) != IS_STRING && Z_TYPE_P(route_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'route' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (likely(Z_TYPE_P(route_param) == IS_STRING)) {
		zephir_get_strval(route, route_param);
	} else {
		ZEPHIR_INIT_VAR(route);
		ZVAL_EMPTY_STRING(route);
	}


	ZEPHIR_INIT_VAR(_0);
	array_init_size(_0, 3);
	ZEPHIR_INIT_VAR(_1);
	object_init_ex(_1, bolt_app_router_route_ce);
	ZEPHIR_CALL_METHOD(NULL, _1, "__construct", NULL, route);
	zephir_check_call_status();
	zephir_array_update_string(&_0, SL("route"), &_1, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&_0, SL("callback"), &callback, PH_COPY | PH_SEPARATE);
	ZEPHIR_CALL_FUNCTION(&_3, "md5", &_4, route);
	zephir_check_call_status();
	zephir_update_property_array(this_ptr, SL("_routes"), _3, _0 TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Bolt_App_Router, unmount) {

	int ZEPHIR_LAST_CALL_STATUS;
	zephir_nts_static zephir_fcall_cache_entry *_3 = NULL;
	zval *route_param = NULL, *_0, *_1 = NULL, *_2 = NULL;
	zval *route = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &route_param);

	if (unlikely(Z_TYPE_P(route_param) != IS_STRING && Z_TYPE_P(route_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'route' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (likely(Z_TYPE_P(route_param) == IS_STRING)) {
		zephir_get_strval(route, route_param);
	} else {
		ZEPHIR_INIT_VAR(route);
		ZVAL_EMPTY_STRING(route);
	}


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_routes"), PH_NOISY_CC);
	ZEPHIR_CALL_FUNCTION(&_2, "md5", &_3, route);
	zephir_check_call_status();
	zephir_array_unset(&_0, _2, PH_SEPARATE);
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Bolt_App_Router, match) {

	int ZEPHIR_LAST_CALL_STATUS;
	HashTable *_2;
	HashPosition _1;
	zval *uri_param = NULL, *route = NULL, *_0, **_3, *_4, *_5 = NULL;
	zval *uri = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &uri_param);

	if (unlikely(Z_TYPE_P(uri_param) != IS_STRING && Z_TYPE_P(uri_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'uri' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (likely(Z_TYPE_P(uri_param) == IS_STRING)) {
		zephir_get_strval(uri, uri_param);
	} else {
		ZEPHIR_INIT_VAR(uri);
		ZVAL_EMPTY_STRING(uri);
	}


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_routes"), PH_NOISY_CC);
	zephir_is_iterable(_0, &_2, &_1, 0, 0, "bolt/app/Router.zep", 30);
	for (
	  ; zephir_hash_get_current_data_ex(_2, (void**) &_3, &_1) == SUCCESS
	  ; zephir_hash_move_forward_ex(_2, &_1)
	) {
		ZEPHIR_GET_HVALUE(route, _3);
		zephir_array_fetch_string(&_4, route, SL("route"), PH_NOISY | PH_READONLY, "bolt/app/Router.zep", 26 TSRMLS_CC);
		ZEPHIR_CALL_METHOD(&_5, _4, "match", NULL, uri);
		zephir_check_call_status();
		if (zephir_is_true(_5)) {
			RETURN_CCTOR(route);
		}
	}
	RETURN_MM_BOOL(0);

}

PHP_METHOD(Bolt_App_Router, __construct) {

	zval *_0;

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(_0);
	array_init(_0);
	zephir_update_property_this(this_ptr, SL("_routes"), _0 TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

