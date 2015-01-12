
#ifdef HAVE_CONFIG_H
#include "../../../ext_config.h"
#endif

#include <php.h>
#include "../../../php_ext.h"
#include "../../../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/memory.h"
#include "kernel/object.h"
#include "kernel/fcall.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/exception.h"
#include "kernel/operators.h"
#include "kernel/array.h"
#include "kernel/concat.h"
#include "kernel/string.h"

ZEPHIR_INIT_CLASS(Bolt_App_Router_Route) {

	ZEPHIR_REGISTER_CLASS(Bolt\\App\\Router, Route, bolt, app_router_route, bolt_app_router_route_method_entry, 0);

	zend_declare_property_null(bolt_app_router_route_ce, SL("_pattern"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(bolt_app_router_route_ce, SL("_params"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(bolt_app_router_route_ce, SL("_values"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(bolt_app_router_route_ce, SL("_id"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_class_constant_null(bolt_app_router_route_ce, SL("T_SEPARATOR") TSRMLS_CC);

	zend_declare_class_constant_null(bolt_app_router_route_ce, SL("T_OPENING_TAG") TSRMLS_CC);

	zend_declare_class_constant_null(bolt_app_router_route_ce, SL("T_CLOSING_TAG") TSRMLS_CC);

	zend_declare_class_constant_null(bolt_app_router_route_ce, SL("T_WILDCARD") TSRMLS_CC);

	zend_declare_class_constant_null(bolt_app_router_route_ce, SL("T_CONDITIONAL") TSRMLS_CC);

	return SUCCESS;

}

PHP_METHOD(Bolt_App_Router_Route, __construct) {

	zephir_nts_static zephir_fcall_cache_entry *_4 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *expression_param = NULL, *_0, *_1, *_2 = NULL, *_3 = NULL;
	zval *expression = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &expression_param);

	if (unlikely(Z_TYPE_P(expression_param) != IS_STRING && Z_TYPE_P(expression_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'expression' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (likely(Z_TYPE_P(expression_param) == IS_STRING)) {
		zephir_get_strval(expression, expression_param);
	} else {
		ZEPHIR_INIT_VAR(expression);
		ZVAL_EMPTY_STRING(expression);
	}


	ZEPHIR_INIT_VAR(_0);
	array_init(_0);
	zephir_update_property_this(this_ptr, SL("_values"), _0 TSRMLS_CC);
	ZEPHIR_INIT_VAR(_1);
	array_init(_1);
	zephir_update_property_this(this_ptr, SL("_params"), _1 TSRMLS_CC);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "_compilepattern", NULL, expression);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(&_3, "md5", &_4, expression);
	zephir_check_call_status();
	zephir_update_property_this(this_ptr, SL("_id"), _3 TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

/*
 * Compiles route pattern from {some}test/path/to/{be}?/{compiled}
 * into regular expression and named params
 */
PHP_METHOD(Bolt_App_Router_Route, _compilePattern) {

	unsigned char _19;
	zephir_fcall_cache_entry *_15 = NULL, *_18 = NULL;
	zephir_nts_static zephir_fcall_cache_entry *_4 = NULL;
	long _0;
	int cursor, ZEPHIR_LAST_CALL_STATUS;
	zend_bool inParentheses = 0, _6, _7, _8, _9, _10, _11, _12, _24, _25, _26, _27, _28;
	char ch;
	zval *expression_param = NULL, *names, *pattern, _1 = zval_used_for_init, _2 = zval_used_for_init, *_3 = NULL, *_13 = NULL, *_14 = NULL, *_16 = NULL, *_17 = NULL, *_21 = NULL, *_22 = NULL, *_23 = NULL;
	zval *expression = NULL, *tmp = NULL, *name = NULL, *cursorValue = NULL, *_5 = NULL, *_20 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &expression_param);

	if (unlikely(Z_TYPE_P(expression_param) != IS_STRING && Z_TYPE_P(expression_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'expression' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (likely(Z_TYPE_P(expression_param) == IS_STRING)) {
		zephir_get_strval(expression, expression_param);
	} else {
		ZEPHIR_INIT_VAR(expression);
		ZVAL_EMPTY_STRING(expression);
	}
	ZEPHIR_INIT_VAR(names);
	array_init(names);
	ZEPHIR_INIT_VAR(pattern);
	array_init(pattern);
	ZEPHIR_INIT_VAR(tmp);
	ZVAL_STRING(tmp, "", 1);
	ZEPHIR_INIT_VAR(name);
	ZVAL_STRING(name, "", 1);
	ZEPHIR_INIT_VAR(cursorValue);
	ZVAL_STRING(cursorValue, "", 1);


	for (_0 = 0; _0 < Z_STRLEN_P(expression); _0++) {
		cursor = _0; 
		ch = ZEPHIR_STRING_OFFSET(expression, _0);
		ZEPHIR_SINIT_NVAR(_1);
		ZVAL_LONG(&_1, cursor);
		ZEPHIR_SINIT_NVAR(_2);
		ZVAL_LONG(&_2, 1);
		ZEPHIR_CALL_FUNCTION(&_3, "substr", &_4, expression, &_1, &_2);
		zephir_check_call_status();
		zephir_get_strval(_5, _3);
		ZEPHIR_CPY_WRT(cursorValue, _5);
		if (inParentheses) {
			if (ch == '}') {
				zephir_array_append(&names, name, PH_SEPARATE, "bolt/app/router/Route.zep", 42);
				ZEPHIR_INIT_NVAR(name);
				ZVAL_EMPTY_STRING(name);
				inParentheses = 0;
				zephir_concat_self_str(&tmp, "([^/]+)", sizeof("([^/]+)")-1 TSRMLS_CC);
				continue;
			}
			_6 = ch >= 'a';
			if (_6) {
				_6 = ch <= 'z';
			}
			_7 = _6;
			if (!(_7)) {
				_8 = ch >= 'A';
				if (_8) {
					_8 = ch <= 'Z';
				}
				_7 = _8;
			}
			_9 = _7;
			if (!(_9)) {
				_10 = ch >= '0';
				if (_10) {
					_10 = ch <= '9';
				}
				_9 = _10;
			}
			_11 = _9;
			if (!(_11)) {
				_11 = ch == '-';
			}
			_12 = _11;
			if (!(_12)) {
				_12 = ch == '_';
			}
			if (_12) {
				zephir_concat_self(&name, cursorValue TSRMLS_CC);
				continue;
			}
			ZEPHIR_INIT_NVAR(_13);
			object_init_ex(_13, bolt_app_router_exception_ce);
			ZEPHIR_SINIT_NVAR(_1);
			ZVAL_LONG(&_1, 0);
			ZEPHIR_SINIT_NVAR(_2);
			ZVAL_LONG(&_2, (cursor + 1));
			ZEPHIR_CALL_FUNCTION(&_16, "substr", &_4, expression, &_1, &_2);
			zephir_check_call_status();
			ZEPHIR_CALL_CE_STATIC(&_14, bolt_app_router_exception_ce, "getexceptionstringwithpointer", &_15, _16);
			zephir_check_call_status();
			ZEPHIR_INIT_LNVAR(_17);
			ZEPHIR_CONCAT_SVSV(_17, "Unexpected character `", cursorValue, "` in param name. Valid param name should match [a-zA-Z0-9-_]+\n", _14);
			ZEPHIR_CALL_METHOD(NULL, _13, "__construct", &_18, _17);
			zephir_check_call_status();
			zephir_throw_exception_debug(_13, "bolt/app/router/Route.zep", 54 TSRMLS_CC);
			ZEPHIR_MM_RESTORE();
			return;
		} else {
			if (ch == '/') {
				zephir_array_append(&pattern, tmp, PH_SEPARATE, "bolt/app/router/Route.zep", 58);
				ZEPHIR_INIT_NVAR(tmp);
				ZVAL_EMPTY_STRING(tmp);
				continue;
			}
			if (ch == '{') {
				inParentheses = 1;
				continue;
			}
			if (ch == '?') {
				_6 = (cursor + 1) == zephir_fast_strlen_ev(expression);
				if (!(_6)) {
					_19 = ZEPHIR_STRING_OFFSET(expression, (cursor + 1));
					_6 = _19 == '/';
				}
				if (_6) {
					ZEPHIR_INIT_LNVAR(_20);
					ZEPHIR_CONCAT_SVS(_20, "(?:", tmp, ")?");
					ZEPHIR_CPY_WRT(tmp, _20);
					continue;
				} else {
					ZEPHIR_INIT_NVAR(_13);
					object_init_ex(_13, bolt_app_router_exception_ce);
					ZEPHIR_SINIT_NVAR(_1);
					ZVAL_LONG(&_1, 0);
					ZEPHIR_SINIT_NVAR(_2);
					ZVAL_LONG(&_2, (cursor + 1));
					ZEPHIR_CALL_FUNCTION(&_21, "substr", &_4, expression, &_1, &_2);
					zephir_check_call_status();
					ZEPHIR_CALL_CE_STATIC(&_16, bolt_app_router_exception_ce, "getexceptionstringwithpointer", &_15, _21);
					zephir_check_call_status();
					ZEPHIR_INIT_LNVAR(_17);
					ZEPHIR_CONCAT_SV(_17, "Unexpected \\Bolt\\App\\Router\\Route::T_CONDITIONAL token in:\n", _16);
					ZEPHIR_CALL_METHOD(NULL, _13, "__construct", &_18, _17);
					zephir_check_call_status();
					zephir_throw_exception_debug(_13, "bolt/app/router/Route.zep", 75 TSRMLS_CC);
					ZEPHIR_MM_RESTORE();
					return;
				}
			}
			if (ch == '*') {
				if ((cursor + 1) == zephir_fast_strlen_ev(expression)) {
					zephir_concat_self_str(&tmp, ".*", sizeof(".*")-1 TSRMLS_CC);
					break;
				} else {
					ZEPHIR_INIT_NVAR(_13);
					object_init_ex(_13, bolt_app_router_exception_ce);
					ZEPHIR_SINIT_NVAR(_1);
					ZVAL_LONG(&_1, 0);
					ZEPHIR_SINIT_NVAR(_2);
					ZVAL_LONG(&_2, (cursor + 1));
					ZEPHIR_CALL_FUNCTION(&_22, "substr", &_4, expression, &_1, &_2);
					zephir_check_call_status();
					ZEPHIR_CALL_CE_STATIC(&_21, bolt_app_router_exception_ce, "getexceptionstringwithpointer", &_15, _22);
					zephir_check_call_status();
					ZEPHIR_INIT_LNVAR(_23);
					ZEPHIR_CONCAT_SV(_23, "Unexpected \\Bolt\\App\\Router\\Route::T_WILDCARD token in:\n", _21);
					ZEPHIR_CALL_METHOD(NULL, _13, "__construct", &_18, _23);
					zephir_check_call_status();
					zephir_throw_exception_debug(_13, "bolt/app/router/Route.zep", 84 TSRMLS_CC);
					ZEPHIR_MM_RESTORE();
					return;
				}
			}
			_7 = ch == '[';
			if (!(_7)) {
				_7 = ch == ']';
			}
			_8 = _7;
			if (!(_8)) {
				_8 = ch == '.';
			}
			_9 = _8;
			if (!(_9)) {
				_9 = ch == '|';
			}
			_10 = _9;
			if (!(_10)) {
				_10 = ch == '^';
			}
			_11 = _10;
			if (!(_11)) {
				_11 = ch == '$';
			}
			_12 = _11;
			if (!(_12)) {
				_12 = ch == '(';
			}
			_24 = _12;
			if (!(_24)) {
				_24 = ch == ')';
			}
			_25 = _24;
			if (!(_25)) {
				_25 = ch == '+';
			}
			_26 = _25;
			if (!(_26)) {
				_26 = ch == '!';
			}
			_27 = _26;
			if (!(_27)) {
				_27 = ch == '&';
			}
			_28 = _27;
			if (!(_28)) {
				_28 = ch == '\\';
			}
			if (_28) {
				zephir_concat_self_str(&tmp, "\\", sizeof("\\")-1 TSRMLS_CC);
			}
			zephir_concat_self(&tmp, cursorValue TSRMLS_CC);
		}
	}
	if (inParentheses) {
		ZEPHIR_INIT_NVAR(_13);
		object_init_ex(_13, bolt_app_router_exception_ce);
		ZEPHIR_SINIT_NVAR(_1);
		ZVAL_LONG(&_1, 0);
		ZEPHIR_SINIT_NVAR(_2);
		ZVAL_LONG(&_2, (cursor + 1));
		ZEPHIR_CALL_FUNCTION(&_14, "substr", &_4, expression, &_1, &_2);
		zephir_check_call_status();
		ZEPHIR_CALL_CE_STATIC(&_3, bolt_app_router_exception_ce, "getexceptionstringwithpointer", &_15, _14);
		zephir_check_call_status();
		ZEPHIR_INIT_LNVAR(_17);
		ZEPHIR_CONCAT_SV(_17, "Unexpected end of route in:\n", _3);
		ZEPHIR_CALL_METHOD(NULL, _13, "__construct", &_18, _17);
		zephir_check_call_status();
		zephir_throw_exception_debug(_13, "bolt/app/router/Route.zep", 98 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (zephir_fast_strlen_ev(tmp) > 0) {
		zephir_array_append(&pattern, tmp, PH_SEPARATE, "bolt/app/router/Route.zep", 101);
	}
	ZEPHIR_INIT_NVAR(_13);
	zephir_fast_join_str(_13, SL("/"), pattern TSRMLS_CC);
	zephir_update_property_this(this_ptr, SL("_pattern"), _13 TSRMLS_CC);
	zephir_update_property_this(this_ptr, SL("_params"), names TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Bolt_App_Router_Route, getPattern) {


	RETURN_MEMBER(this_ptr, "_pattern");

}

PHP_METHOD(Bolt_App_Router_Route, getParamNames) {


	RETURN_MEMBER(this_ptr, "_params");

}

PHP_METHOD(Bolt_App_Router_Route, getParams) {


	RETURN_MEMBER(this_ptr, "_values");

}

PHP_METHOD(Bolt_App_Router_Route, getId) {


	RETURN_MEMBER(this_ptr, "_id");

}

PHP_METHOD(Bolt_App_Router_Route, match) {

	zephir_nts_static zephir_fcall_cache_entry *_2 = NULL;
	int i, length, ZEPHIR_LAST_CALL_STATUS;
	zval *uri_param = NULL, *matches, *matched = NULL, *_0, *_1, *_3, *_4, *_5 = NULL;
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
	ZEPHIR_INIT_VAR(matches);
	array_init(matches);


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_pattern"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(_1);
	ZEPHIR_CONCAT_SVS(_1, "#", _0, "#");
	Z_SET_ISREF_P(matches);
	ZEPHIR_CALL_FUNCTION(&matched, "preg_match", &_2, _1, uri, matches);
	Z_UNSET_ISREF_P(matches);
	zephir_check_call_status();
	if (ZEPHIR_IS_LONG(matched, 0)) {
		RETURN_MM_BOOL(0);
	}
	length = zephir_fast_count_int(matches TSRMLS_CC);
	i = 1;
	while (1) {
		if (!(i < length)) {
			break;
		}
		zephir_array_fetch_long(&_3, matches, i, PH_NOISY | PH_READONLY, "bolt/app/router/Route.zep", 139 TSRMLS_CC);
		_4 = zephir_fetch_nproperty_this(this_ptr, SL("_params"), PH_NOISY_CC);
		ZEPHIR_OBS_NVAR(_5);
		zephir_array_fetch_long(&_5, _4, (i - 1), PH_NOISY, "bolt/app/router/Route.zep", 139 TSRMLS_CC);
		zephir_update_property_array(this_ptr, SL("_values"), _5, _3 TSRMLS_CC);
		i++;
	}
	RETURN_MM_BOOL(1);

}

