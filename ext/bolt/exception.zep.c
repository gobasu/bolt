
#ifdef HAVE_CONFIG_H
#include "../ext_config.h"
#endif

#include <php.h>
#include "../php_ext.h"
#include "../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/memory.h"
#include "kernel/string.h"
#include "kernel/fcall.h"
#include "kernel/operators.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/exception.h"
#include "kernel/array.h"


/**
 * All Framework Exceptions should extend this one.
 */
ZEPHIR_INIT_CLASS(Bolt_Exception) {

	ZEPHIR_REGISTER_CLASS_EX(Bolt, Exception, bolt, exception, zend_exception_get_default(TSRMLS_C), bolt_exception_method_entry, 0);

	return SUCCESS;

}

PHP_METHOD(Bolt_Exception, getExceptionStringWithPointer) {

	int ZEPHIR_LAST_CALL_STATUS;
	zephir_nts_static zephir_fcall_cache_entry *_4 = NULL;
	zval *str_param = NULL, *_0 = NULL, _1, _2, *_3 = NULL;
	zval *str = NULL, *message = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &str_param);

	if (unlikely(Z_TYPE_P(str_param) != IS_STRING && Z_TYPE_P(str_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'str' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (likely(Z_TYPE_P(str_param) == IS_STRING)) {
		zephir_get_strval(str, str_param);
	} else {
		ZEPHIR_INIT_VAR(str);
		ZVAL_EMPTY_STRING(str);
	}
	ZEPHIR_INIT_VAR(message);
	ZVAL_STRING(message, "", 1);


	ZEPHIR_CPY_WRT(message, str);
	zephir_concat_self_str(&message, "\n", sizeof("\n")-1 TSRMLS_CC);
	ZEPHIR_SINIT_VAR(_1);
	ZVAL_STRING(&_1, "-", 0);
	ZEPHIR_SINIT_VAR(_2);
	ZVAL_LONG(&_2, (zephir_fast_strlen_ev(str) - 1));
	ZEPHIR_CALL_FUNCTION(&_3, "str_repeat", &_4, &_1, &_2);
	zephir_check_call_status();
	zephir_concat_self(&message, _3 TSRMLS_CC);
	zephir_concat_self_str(&message, "^", sizeof("^")-1 TSRMLS_CC);
	RETURN_CTOR(message);

}

PHP_METHOD(Bolt_Exception, getErrorHintFromString) {

	zephir_nts_static zephir_fcall_cache_entry *_3 = NULL;
	int line, column, ZEPHIR_LAST_CALL_STATUS;
	zval *str_param = NULL, *line_param = NULL, *column_param = NULL, *strs, *message, _0, _1, *_2 = NULL;
	zval *str = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 0, &str_param, &line_param, &column_param);

	zephir_get_strval(str, str_param);
	if (unlikely(Z_TYPE_P(line_param) != IS_LONG)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'line' must be a long/integer") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	line = Z_LVAL_P(line_param);
	column = zephir_get_intval(column_param);


	ZEPHIR_INIT_VAR(strs);
	zephir_fast_explode_str(strs, SL("\n"), str, LONG_MAX TSRMLS_CC);
	ZEPHIR_OBS_VAR(message);
	zephir_array_fetch_long(&message, strs, (line - 1), PH_NOISY, "bolt/Exception.zep", 23 TSRMLS_CC);
	zephir_concat_self_str(&message, SL("\n") TSRMLS_CC);
	ZEPHIR_SINIT_VAR(_0);
	ZVAL_STRING(&_0, "-", 0);
	ZEPHIR_SINIT_VAR(_1);
	ZVAL_LONG(&_1, (column + 1));
	ZEPHIR_CALL_FUNCTION(&_2, "str_repeat", &_3, &_0, &_1);
	zephir_check_call_status();
	zephir_concat_self(&message, _2 TSRMLS_CC);
	zephir_concat_self_str(&message, SL("^") TSRMLS_CC);
	RETURN_CCTOR(message);

}

