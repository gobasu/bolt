
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
#include "kernel/file.h"
#include "kernel/operators.h"
#include "kernel/exception.h"
#include "kernel/concat.h"
#include "kernel/array.h"
#include "kernel/hash.h"
#include "kernel/string.h"

ZEPHIR_INIT_CLASS(Bolt_App_View_Parser) {

	ZEPHIR_REGISTER_CLASS(Bolt\\App\\View, Parser, bolt, app_view_parser, bolt_app_view_parser_method_entry, ZEND_ACC_FINAL_CLASS);

	zend_declare_property_null(bolt_app_view_parser_ce, SL("_tokenizer"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(bolt_app_view_parser_ce, SL("_tree"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(bolt_app_view_parser_ce, SL("_fileName"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(bolt_app_view_parser_ce, SL("_token"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(bolt_app_view_parser_ce, SL("_openExpressions"), ZEND_ACC_PRIVATE TSRMLS_CC);

	zend_declare_property_null(bolt_app_view_parser_ce, SL("_closedExpressions"), ZEND_ACC_PRIVATE TSRMLS_CC);

	zend_declare_property_null(bolt_app_view_parser_ce, SL("_openElements"), ZEND_ACC_PRIVATE TSRMLS_CC);

	zend_declare_property_null(bolt_app_view_parser_ce, SL("_closedElements"), ZEND_ACC_PRIVATE TSRMLS_CC);

	zend_declare_property_long(bolt_app_view_parser_ce, SL("_arrayDepth"), 0, ZEND_ACC_PRIVATE TSRMLS_CC);

	return SUCCESS;

}

PHP_METHOD(Bolt_App_View_Parser, __construct) {

	zephir_nts_static zephir_fcall_cache_entry *_8 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *fileName, *_0, *_1, *_2, *_3, *_4, *_5, *_6, *_7;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &fileName);



	ZEPHIR_INIT_VAR(_0);
	array_init(_0);
	zephir_update_property_this(this_ptr, SL("_closedElements"), _0 TSRMLS_CC);
	ZEPHIR_INIT_VAR(_1);
	array_init(_1);
	zephir_update_property_this(this_ptr, SL("_openElements"), _1 TSRMLS_CC);
	ZEPHIR_INIT_VAR(_2);
	array_init(_2);
	zephir_update_property_this(this_ptr, SL("_closedExpressions"), _2 TSRMLS_CC);
	ZEPHIR_INIT_VAR(_3);
	array_init(_3);
	zephir_update_property_this(this_ptr, SL("_openExpressions"), _3 TSRMLS_CC);
	zephir_update_property_this(this_ptr, SL("_fileName"), fileName TSRMLS_CC);
	ZEPHIR_INIT_VAR(_4);
	object_init_ex(_4, bolt_app_view_tokenizer_ce);
	ZEPHIR_INIT_VAR(_5);
	_6 = zephir_fetch_nproperty_this(this_ptr, SL("_fileName"), PH_NOISY_CC);
	zephir_file_get_contents(_5, _6 TSRMLS_CC);
	_7 = zephir_fetch_nproperty_this(this_ptr, SL("_fileName"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(NULL, _4, "__construct", &_8, _5, _7);
	zephir_check_call_status();
	zephir_update_property_this(this_ptr, SL("_tokenizer"), _4 TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Bolt_App_View_Parser, getTokenizer) {


	RETURN_MEMBER(this_ptr, "_tokenizer");

}

PHP_METHOD(Bolt_App_View_Parser, parse) {

	HashTable *_10;
	HashPosition _9;
	zend_bool inExpression = 0, inElement = 0, inModifier = 0, _12, _14, _32, _33, _34, _35;
	zephir_nts_static zephir_fcall_cache_entry *_5 = NULL;
	zephir_fcall_cache_entry *_2 = NULL, *_19 = NULL, *_23 = NULL, *_24 = NULL, *_25 = NULL, *_27 = NULL, *_28 = NULL, *_29 = NULL, *_31 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *_0, *_1 = NULL, *_3, *_4 = NULL, *_6, *_7 = NULL, *tokens = NULL, *cursor = NULL, *token = NULL, *nextToken = NULL, *prevToken = NULL, *length = NULL, *expecting = NULL, *notExpecting = NULL, *current = NULL, *next = NULL, *tmp = NULL, *_8, **_11, *_13, *_15, *_16, *_17, *_18, *_20 = NULL, *_21 = NULL, *_22 = NULL, *_26, *_30, *_36, *_37 = NULL;

	ZEPHIR_MM_GROW();
	ZEPHIR_INIT_VAR(tokens);
	ZVAL_NULL(tokens);
	ZEPHIR_INIT_VAR(token);
	ZVAL_NULL(token);
	ZEPHIR_INIT_VAR(nextToken);
	ZVAL_NULL(nextToken);
	ZEPHIR_INIT_VAR(prevToken);
	ZVAL_NULL(prevToken);
	ZEPHIR_INIT_VAR(length);
	ZVAL_NULL(length);
	ZEPHIR_INIT_VAR(expecting);
	ZVAL_NULL(expecting);
	ZEPHIR_INIT_VAR(notExpecting);
	ZVAL_NULL(notExpecting);
	ZEPHIR_INIT_VAR(current);
	ZVAL_NULL(current);
	ZEPHIR_INIT_VAR(next);
	ZVAL_NULL(next);

	ZEPHIR_INIT_VAR(_0);
	object_init_ex(_0, bolt_app_view_parser_node_ce);
	ZEPHIR_INIT_VAR(_1);
	ZVAL_LONG(_1, -1);
	ZEPHIR_CALL_METHOD(NULL, _0, "__construct", &_2, _1);
	zephir_check_call_status();
	zephir_update_property_this(this_ptr, SL("_tree"), _0 TSRMLS_CC);
	_3 = zephir_fetch_nproperty_this(this_ptr, SL("_fileName"), PH_NOISY_CC);
	ZEPHIR_CALL_FUNCTION(&_4, "is_readable", &_5, _3);
	zephir_check_call_status();
	if (!(zephir_is_true(_4))) {
		ZEPHIR_INIT_NVAR(_1);
		object_init_ex(_1, bolt_app_view_exception_ce);
		_6 = zephir_fetch_nproperty_this(this_ptr, SL("_fileName"), PH_NOISY_CC);
		ZEPHIR_INIT_VAR(_7);
		ZEPHIR_CONCAT_SV(_7, "No such file ", _6);
		ZEPHIR_CALL_METHOD(NULL, _1, "__construct", NULL, _7);
		zephir_check_call_status();
		zephir_throw_exception_debug(_1, "bolt/app/view/Parser.zep", 36 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	_6 = zephir_fetch_nproperty_this(this_ptr, SL("_tokenizer"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(NULL, _6, "scan", NULL);
	zephir_check_call_status();
	_8 = zephir_fetch_nproperty_this(this_ptr, SL("_tokenizer"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(&tokens, _8, "gettokens", NULL);
	zephir_check_call_status();
	ZEPHIR_OBS_NVAR(current);
	zephir_read_property_this(&current, this_ptr, SL("_tree"), PH_NOISY_CC);
	ZEPHIR_INIT_NVAR(length);
	ZVAL_LONG(length, zephir_fast_count_int(tokens TSRMLS_CC));
	ZEPHIR_INIT_NVAR(expecting);
	array_init_size(expecting, 7);
	ZEPHIR_INIT_NVAR(_1);
	ZVAL_LONG(_1, 0);
	zephir_array_fast_append(expecting, _1);
	ZEPHIR_INIT_NVAR(_1);
	ZVAL_LONG(_1, 2);
	zephir_array_fast_append(expecting, _1);
	ZEPHIR_INIT_NVAR(_1);
	ZVAL_LONG(_1, 4);
	zephir_array_fast_append(expecting, _1);
	ZEPHIR_INIT_NVAR(_1);
	ZVAL_LONG(_1, 6);
	zephir_array_fast_append(expecting, _1);
	ZEPHIR_INIT_NVAR(_1);
	ZVAL_LONG(_1, 14);
	zephir_array_fast_append(expecting, _1);
	zephir_is_iterable(tokens, &_10, &_9, 0, 0, "bolt/app/view/Parser.zep", 220);
	for (
	  ; zephir_hash_get_current_data_ex(_10, (void**) &_11, &_9) == SUCCESS
	  ; zephir_hash_move_forward_ex(_10, &_9)
	) {
		ZEPHIR_GET_HMKEY(cursor, _10, _9);
		ZEPHIR_GET_HVALUE(token, _11);
		zephir_update_property_this(this_ptr, SL("_token"), token TSRMLS_CC);
		if (ZEPHIR_GT_LONG(length, (zephir_get_numberval(cursor) + 1))) {
			ZEPHIR_OBS_NVAR(nextToken);
			zephir_array_fetch_long(&nextToken, tokens, (zephir_get_numberval(cursor) + 1), PH_NOISY, "bolt/app/view/Parser.zep", 54 TSRMLS_CC);
		} else {
			ZEPHIR_INIT_NVAR(nextToken);
			ZVAL_NULL(nextToken);
		}
		if ((zephir_get_numberval(cursor) - 1) > 0) {
			ZEPHIR_OBS_NVAR(prevToken);
			zephir_array_fetch_long(&prevToken, tokens, (zephir_get_numberval(cursor) - 1), PH_NOISY, "bolt/app/view/Parser.zep", 60 TSRMLS_CC);
		}
		if (zephir_is_true(expecting)) {
			_12 = Z_TYPE_P(expecting) == IS_ARRAY;
			if (_12) {
				zephir_array_fetch_string(&_13, token, SL("type"), PH_NOISY | PH_READONLY, "bolt/app/view/Parser.zep", 64 TSRMLS_CC);
				_12 = !zephir_fast_in_array(_13, expecting TSRMLS_CC);
			}
			_14 = Z_TYPE_P(expecting) == IS_LONG;
			if (_14) {
				zephir_array_fetch_string(&_15, token, SL("type"), PH_NOISY | PH_READONLY, "bolt/app/view/Parser.zep", 66 TSRMLS_CC);
				_14 = !ZEPHIR_IS_EQUAL(expecting, _15);
			}
			if (_12) {
				ZEPHIR_INIT_NVAR(_1);
				object_init_ex(_1, bolt_app_view_exception_ce);
				_16 = zephir_fetch_nproperty_this(this_ptr, SL("_fileName"), PH_NOISY_CC);
				zephir_array_fetch_string(&_17, token, SL("line"), PH_NOISY | PH_READONLY, "bolt/app/view/Parser.zep", 65 TSRMLS_CC);
				zephir_array_fetch_string(&_18, token, SL("value"), PH_NOISY | PH_READONLY, "bolt/app/view/Parser.zep", 65 TSRMLS_CC);
				ZEPHIR_INIT_LNVAR(_7);
				ZEPHIR_CONCAT_SVSVSVS(_7, "Unexpected token in ", _16, " on line ", _17, "\n", _18, "\n");
				ZEPHIR_CALL_METHOD(NULL, _1, "__construct", &_19, _7);
				zephir_check_call_status();
				zephir_throw_exception_debug(_1, "bolt/app/view/Parser.zep", 65 TSRMLS_CC);
				ZEPHIR_MM_RESTORE();
				return;
			} else if (_14) {
				ZEPHIR_INIT_NVAR(_1);
				object_init_ex(_1, bolt_app_view_exception_ce);
				_16 = zephir_fetch_nproperty_this(this_ptr, SL("_fileName"), PH_NOISY_CC);
				zephir_array_fetch_string(&_17, token, SL("line"), PH_NOISY | PH_READONLY, "bolt/app/view/Parser.zep", 67 TSRMLS_CC);
				zephir_array_fetch_string(&_18, token, SL("value"), PH_NOISY | PH_READONLY, "bolt/app/view/Parser.zep", 67 TSRMLS_CC);
				ZEPHIR_INIT_LNVAR(_20);
				ZEPHIR_CONCAT_SVSVSVS(_20, "Unexpected token in ", _16, " on line ", _17, "\n", _18, "\n");
				ZEPHIR_CALL_METHOD(NULL, _1, "__construct", &_19, _20);
				zephir_check_call_status();
				zephir_throw_exception_debug(_1, "bolt/app/view/Parser.zep", 67 TSRMLS_CC);
				ZEPHIR_MM_RESTORE();
				return;
			}
		}
		if (zephir_is_true(notExpecting)) {
			_12 = Z_TYPE_P(notExpecting) == IS_ARRAY;
			if (_12) {
				zephir_array_fetch_string(&_13, token, SL("type"), PH_NOISY | PH_READONLY, "bolt/app/view/Parser.zep", 72 TSRMLS_CC);
				_12 = zephir_fast_in_array(_13, notExpecting TSRMLS_CC);
			}
			_14 = Z_TYPE_P(notExpecting) == IS_LONG;
			if (_14) {
				zephir_array_fetch_string(&_15, token, SL("type"), PH_NOISY | PH_READONLY, "bolt/app/view/Parser.zep", 74 TSRMLS_CC);
				_14 = ZEPHIR_IS_EQUAL(notExpecting, _15);
			}
			if (_12) {
				ZEPHIR_INIT_NVAR(_1);
				object_init_ex(_1, bolt_app_view_exception_ce);
				_16 = zephir_fetch_nproperty_this(this_ptr, SL("_fileName"), PH_NOISY_CC);
				zephir_array_fetch_string(&_17, token, SL("line"), PH_NOISY | PH_READONLY, "bolt/app/view/Parser.zep", 73 TSRMLS_CC);
				ZEPHIR_INIT_LNVAR(_20);
				ZEPHIR_CONCAT_SVSV(_20, "Unexpected token in ", _16, " on line ", _17);
				ZEPHIR_CALL_METHOD(NULL, _1, "__construct", &_19, _20);
				zephir_check_call_status();
				zephir_throw_exception_debug(_1, "bolt/app/view/Parser.zep", 73 TSRMLS_CC);
				ZEPHIR_MM_RESTORE();
				return;
			} else if (_14) {
				ZEPHIR_INIT_NVAR(_1);
				object_init_ex(_1, bolt_app_view_exception_ce);
				_16 = zephir_fetch_nproperty_this(this_ptr, SL("_fileName"), PH_NOISY_CC);
				zephir_array_fetch_string(&_17, token, SL("line"), PH_NOISY | PH_READONLY, "bolt/app/view/Parser.zep", 75 TSRMLS_CC);
				ZEPHIR_INIT_LNVAR(_20);
				ZEPHIR_CONCAT_SVSV(_20, "Unexpected token in ", _16, " on line ", _17);
				ZEPHIR_CALL_METHOD(NULL, _1, "__construct", &_19, _20);
				zephir_check_call_status();
				zephir_throw_exception_debug(_1, "bolt/app/view/Parser.zep", 75 TSRMLS_CC);
				ZEPHIR_MM_RESTORE();
				return;
			}
		}
		_12 = zephir_is_true(next);
		if (_12) {
			zephir_array_fetch_string(&_13, token, SL("type"), PH_NOISY | PH_READONLY, "bolt/app/view/Parser.zep", 79 TSRMLS_CC);
			_12 = !ZEPHIR_IS_EQUAL(next, _13);
		}
		if (_12) {
			continue;
		}
		ZEPHIR_INIT_NVAR(next);
		ZVAL_NULL(next);
		ZEPHIR_INIT_NVAR(expecting);
		ZVAL_NULL(expecting);
		ZEPHIR_INIT_NVAR(notExpecting);
		ZVAL_NULL(notExpecting);
		zephir_array_fetch_string(&_13, token, SL("type"), PH_NOISY | PH_READONLY, "bolt/app/view/Parser.zep", 87 TSRMLS_CC);
		do {
			if (ZEPHIR_IS_LONG(_13, 0)) {
				ZEPHIR_INIT_NVAR(expecting);
				array_init_size(expecting, 7);
				ZEPHIR_INIT_NVAR(_1);
				ZVAL_LONG(_1, 0);
				zephir_array_fast_append(expecting, _1);
				ZEPHIR_INIT_NVAR(_1);
				ZVAL_LONG(_1, 2);
				zephir_array_fast_append(expecting, _1);
				ZEPHIR_INIT_NVAR(_1);
				ZVAL_LONG(_1, 4);
				zephir_array_fast_append(expecting, _1);
				ZEPHIR_INIT_NVAR(_1);
				ZVAL_LONG(_1, 6);
				zephir_array_fast_append(expecting, _1);
				ZEPHIR_INIT_NVAR(_1);
				ZVAL_LONG(_1, 14);
				zephir_array_fast_append(expecting, _1);
				ZEPHIR_INIT_NVAR(_1);
				object_init_ex(_1, bolt_app_view_parser_node_ce);
				zephir_array_fetch_string(&_15, token, SL("value"), PH_NOISY | PH_READONLY, "bolt/app/view/Parser.zep", 90 TSRMLS_CC);
				ZEPHIR_INIT_NVAR(_21);
				ZVAL_LONG(_21, 0);
				ZEPHIR_CALL_METHOD(NULL, _1, "__construct", &_2, _21, _15);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(NULL, current, "addchild", NULL, _1);
				zephir_check_call_status();
				break;
			}
			if (ZEPHIR_IS_LONG(_13, 13)) {
				ZEPHIR_INIT_NVAR(_21);
				object_init_ex(_21, bolt_app_view_parser_node_ce);
				zephir_array_fetch_string(&_13, token, SL("value"), PH_NOISY | PH_READONLY, "bolt/app/view/Parser.zep", 94 TSRMLS_CC);
				ZEPHIR_INIT_NVAR(_22);
				ZVAL_LONG(_22, 0);
				ZEPHIR_CALL_METHOD(NULL, _21, "__construct", &_2, _22, _13);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(NULL, current, "addchild", NULL, _21);
				zephir_check_call_status();
				break;
			}
			if (ZEPHIR_IS_LONG(_13, 4)) {
				ZEPHIR_INIT_NVAR(expecting);
				array_init_size(expecting, 3);
				ZEPHIR_INIT_NVAR(_21);
				ZVAL_LONG(_21, 1);
				zephir_array_fast_append(expecting, _21);
				ZEPHIR_INIT_NVAR(_21);
				ZVAL_LONG(_21, 17);
				zephir_array_fast_append(expecting, _21);
				ZEPHIR_INIT_NVAR(tmp);
				object_init_ex(tmp, bolt_app_view_parser_node_ce);
				zephir_array_fetch_string(&_13, token, SL("value"), PH_NOISY | PH_READONLY, "bolt/app/view/Parser.zep", 99 TSRMLS_CC);
				ZEPHIR_INIT_NVAR(_21);
				ZVAL_LONG(_21, 2);
				ZEPHIR_CALL_METHOD(NULL, tmp, "__construct", &_2, _21, _13);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(NULL, current, "addchild", NULL, tmp);
				zephir_check_call_status();
				ZEPHIR_CPY_WRT(current, tmp);
				ZEPHIR_INIT_NVAR(tmp);
				ZVAL_NULL(tmp);
				inExpression = 1;
				break;
			}
			if (ZEPHIR_IS_LONG(_13, 2)) {
				ZEPHIR_INIT_NVAR(expecting);
				array_init_size(expecting, 3);
				ZEPHIR_INIT_NVAR(_21);
				ZVAL_LONG(_21, 1);
				zephir_array_fast_append(expecting, _21);
				ZEPHIR_INIT_NVAR(_21);
				ZVAL_LONG(_21, 17);
				zephir_array_fast_append(expecting, _21);
				ZEPHIR_INIT_NVAR(tmp);
				object_init_ex(tmp, bolt_app_view_parser_node_ce);
				zephir_array_fetch_string(&_13, token, SL("value"), PH_NOISY | PH_READONLY, "bolt/app/view/Parser.zep", 108 TSRMLS_CC);
				ZEPHIR_INIT_NVAR(_21);
				ZVAL_LONG(_21, 1);
				ZEPHIR_CALL_METHOD(NULL, tmp, "__construct", &_2, _21, _13);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(NULL, current, "addchild", &_23, tmp);
				zephir_check_call_status();
				ZEPHIR_CPY_WRT(current, tmp);
				ZEPHIR_INIT_NVAR(tmp);
				ZVAL_NULL(tmp);
				inElement = 1;
				break;
			}
			if (ZEPHIR_IS_LONG(_13, 1)) {
				ZEPHIR_INIT_NVAR(tmp);
				object_init_ex(tmp, bolt_app_view_parser_node_ce);
				zephir_array_fetch_string(&_13, token, SL("value"), PH_NOISY | PH_READONLY, "bolt/app/view/Parser.zep", 117 TSRMLS_CC);
				ZEPHIR_INIT_NVAR(_21);
				ZVAL_LONG(_21, 4);
				ZEPHIR_CALL_METHOD(NULL, tmp, "__construct", &_2, _21, _13);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(NULL, current, "addproperty", &_24, tmp);
				zephir_check_call_status();
				zephir_array_fetch_string(&_15, nextToken, SL("type"), PH_NOISY | PH_READONLY, "bolt/app/view/Parser.zep", 119 TSRMLS_CC);
				_12 = ZEPHIR_IS_LONG(_15, 8);
				if (!(_12)) {
					zephir_array_fetch_string(&_17, nextToken, SL("type"), PH_NOISY | PH_READONLY, "bolt/app/view/Parser.zep", 119 TSRMLS_CC);
					_12 = ZEPHIR_IS_LONG(_17, 9);
				}
				if (_12) {
					ZEPHIR_CPY_WRT(current, tmp);
				}
				ZEPHIR_INIT_NVAR(tmp);
				ZVAL_NULL(tmp);
				break;
			}
			if (ZEPHIR_IS_LONG(_13, 8)) {
				ZEPHIR_INIT_NVAR(tmp);
				object_init_ex(tmp, bolt_app_view_parser_node_ce);
				zephir_array_fetch_string(&_13, token, SL("value"), PH_NOISY | PH_READONLY, "bolt/app/view/Parser.zep", 127 TSRMLS_CC);
				ZEPHIR_INIT_NVAR(_21);
				ZVAL_LONG(_21, 3);
				ZEPHIR_CALL_METHOD(NULL, tmp, "__construct", &_2, _21, _13);
				zephir_check_call_status();
				inModifier = 1;
				ZEPHIR_CALL_METHOD(NULL, current, "addmodifier", &_25, tmp);
				zephir_check_call_status();
				zephir_array_fetch_string(&_15, nextToken, SL("type"), PH_NOISY | PH_READONLY, "bolt/app/view/Parser.zep", 132 TSRMLS_CC);
				_12 = ZEPHIR_IS_LONG(_15, 1);
				if (!(_12)) {
					zephir_array_fetch_string(&_17, nextToken, SL("type"), PH_NOISY | PH_READONLY, "bolt/app/view/Parser.zep", 132 TSRMLS_CC);
					_12 = ZEPHIR_IS_LONG(_17, 5);
				}
				_14 = _12;
				if (!(_14)) {
					zephir_array_fetch_string(&_18, nextToken, SL("type"), PH_NOISY | PH_READONLY, "bolt/app/view/Parser.zep", 132 TSRMLS_CC);
					_14 = ZEPHIR_IS_LONG(_18, 3);
				}
				zephir_array_fetch_string(&_26, nextToken, SL("type"), PH_NOISY | PH_READONLY, "bolt/app/view/Parser.zep", 137 TSRMLS_CC);
				if (_14) {
					ZEPHIR_CALL_METHOD(&tmp, current, "getparent", &_27);
					zephir_check_call_status();
					ZEPHIR_CPY_WRT(current, tmp);
					ZEPHIR_INIT_NVAR(tmp);
					ZVAL_NULL(tmp);
					inModifier = 0;
				} else if (ZEPHIR_IS_LONG(_26, 9)) {
					ZEPHIR_CPY_WRT(current, tmp);
				}
				ZEPHIR_INIT_NVAR(tmp);
				ZVAL_NULL(tmp);
				break;
			}
			if (ZEPHIR_IS_LONG(_13, 9)) {
				ZEPHIR_CALL_METHOD(NULL, current, "setasfunction", &_28);
				zephir_check_call_status();
				break;
			}
			if (ZEPHIR_IS_LONG(_13, 17)) {
				ZEPHIR_INIT_NVAR(tmp);
				object_init_ex(tmp, bolt_app_view_parser_node_ce);
				zephir_array_fetch_string(&_13, token, SL("value"), PH_NOISY | PH_READONLY, "bolt/app/view/Parser.zep", 148 TSRMLS_CC);
				ZEPHIR_INIT_NVAR(_21);
				ZVAL_LONG(_21, 4);
				ZEPHIR_CALL_METHOD(NULL, tmp, "__construct", &_2, _21, _13);
				zephir_check_call_status();
				_16 = zephir_fetch_nproperty_this(this_ptr, SL("_arrayDepth"), PH_NOISY_CC);
				if (ZEPHIR_GT_LONG(_16, 0)) {
					ZEPHIR_CALL_METHOD(NULL, current, "addchild", &_23, tmp);
					zephir_check_call_status();
				} else {
					ZEPHIR_CALL_METHOD(NULL, current, "addproperty", &_24, tmp);
					zephir_check_call_status();
				}
				ZEPHIR_CALL_METHOD(NULL, tmp, "setasscalar", &_29);
				zephir_check_call_status();
				ZEPHIR_CPY_WRT(current, tmp);
				ZEPHIR_INIT_NVAR(tmp);
				ZVAL_NULL(tmp);
				_16 = zephir_fetch_nproperty_this(this_ptr, SL("_arrayDepth"), PH_NOISY_CC);
				ZEPHIR_INIT_ZVAL_NREF(_30);
				ZVAL_LONG(_30, (zephir_get_numberval(_16) + 1));
				zephir_update_property_this(this_ptr, SL("_arrayDepth"), _30 TSRMLS_CC);
				break;
			}
			if (ZEPHIR_IS_LONG(_13, 12)) {
				_30 = zephir_fetch_nproperty_this(this_ptr, SL("_arrayDepth"), PH_NOISY_CC);
				if (ZEPHIR_GT_LONG(_30, 0)) {
					ZEPHIR_INIT_NVAR(tmp);
					object_init_ex(tmp, bolt_app_view_parser_node_ce);
					zephir_array_fetch_string(&_13, token, SL("value"), PH_NOISY | PH_READONLY, "bolt/app/view/Parser.zep", 162 TSRMLS_CC);
					ZEPHIR_INIT_NVAR(_21);
					ZVAL_LONG(_21, 4);
					ZEPHIR_CALL_METHOD(NULL, tmp, "__construct", &_2, _21, _13);
					zephir_check_call_status();
					ZEPHIR_CALL_METHOD(NULL, current, "addchild", &_23, tmp);
					zephir_check_call_status();
					zephir_array_fetch_string(&_15, prevToken, SL("type"), PH_NOISY | PH_READONLY, "bolt/app/view/Parser.zep", 165 TSRMLS_CC);
					if (ZEPHIR_IS_LONG(_15, 19)) {
						zephir_array_fetch_string(&_17, prevToken, SL("value"), PH_NOISY | PH_READONLY, "bolt/app/view/Parser.zep", 166 TSRMLS_CC);
						ZEPHIR_CALL_METHOD(NULL, tmp, "addargument", &_31, _17);
						zephir_check_call_status();
					}
					ZEPHIR_INIT_NVAR(tmp);
					ZVAL_NULL(tmp);
				} else {
					zephir_array_fetch_string(&_17, token, SL("value"), PH_NOISY | PH_READONLY, "bolt/app/view/Parser.zep", 171 TSRMLS_CC);
					ZEPHIR_CALL_METHOD(NULL, current, "addargument", &_31, _17);
					zephir_check_call_status();
				}
				break;
			}
			if (ZEPHIR_IS_LONG(_13, 18)) {
				ZEPHIR_CALL_METHOD(&tmp, current, "getparent", &_27);
				zephir_check_call_status();
				ZEPHIR_CPY_WRT(current, tmp);
				ZEPHIR_INIT_NVAR(tmp);
				ZVAL_NULL(tmp);
				_16 = zephir_fetch_nproperty_this(this_ptr, SL("_arrayDepth"), PH_NOISY_CC);
				ZEPHIR_INIT_ZVAL_NREF(_30);
				ZVAL_LONG(_30, (zephir_get_numberval(_16) - 1));
				zephir_update_property_this(this_ptr, SL("_arrayDepth"), _30 TSRMLS_CC);
				break;
			}
			if (ZEPHIR_IS_LONG(_13, 11)) {
				_12 = inModifier;
				if (_12) {
					zephir_array_fetch_string(&_13, nextToken, SL("type"), PH_NOISY | PH_READONLY, "bolt/app/view/Parser.zep", 184 TSRMLS_CC);
					_14 = ZEPHIR_IS_LONG(_13, 5);
					if (!(_14)) {
						zephir_array_fetch_string(&_15, nextToken, SL("type"), PH_NOISY | PH_READONLY, "bolt/app/view/Parser.zep", 184 TSRMLS_CC);
						_14 = ZEPHIR_IS_LONG(_15, 3);
					}
					_32 = _14;
					if (!(_32)) {
						zephir_array_fetch_string(&_17, nextToken, SL("type"), PH_NOISY | PH_READONLY, "bolt/app/view/Parser.zep", 184 TSRMLS_CC);
						_32 = ZEPHIR_IS_LONG(_17, 1);
					}
					_12 = _32;
				}
				_33 = inModifier;
				if (_33) {
					zephir_array_fetch_string(&_18, nextToken, SL("type"), PH_NOISY | PH_READONLY, "bolt/app/view/Parser.zep", 188 TSRMLS_CC);
					_33 = ZEPHIR_IS_LONG(_18, 8);
				}
				_34 = !inModifier;
				if (_34) {
					zephir_array_fetch_string(&_26, nextToken, SL("type"), PH_NOISY | PH_READONLY, "bolt/app/view/Parser.zep", 192 TSRMLS_CC);
					_35 = ZEPHIR_IS_LONG(_26, 5);
					if (!(_35)) {
						zephir_array_fetch_string(&_36, nextToken, SL("type"), PH_NOISY | PH_READONLY, "bolt/app/view/Parser.zep", 192 TSRMLS_CC);
						_35 = ZEPHIR_IS_LONG(_36, 3);
					}
					_34 = _35;
				}
				if (_12) {
					ZEPHIR_CALL_METHOD(&_37, current, "getparent", &_27);
					zephir_check_call_status();
					ZEPHIR_CALL_METHOD(&tmp, _37, "getparent", NULL);
					zephir_check_call_status();
					ZEPHIR_CPY_WRT(current, tmp);
					ZEPHIR_INIT_NVAR(tmp);
					ZVAL_NULL(tmp);
				} else if (_33) {
					ZEPHIR_CALL_METHOD(&tmp, current, "getparent", &_27);
					zephir_check_call_status();
					ZEPHIR_CPY_WRT(current, tmp);
					ZEPHIR_INIT_NVAR(tmp);
					ZVAL_NULL(tmp);
				} else if (_34) {
					ZEPHIR_CALL_METHOD(&tmp, current, "getparent", &_27);
					zephir_check_call_status();
					ZEPHIR_CPY_WRT(current, tmp);
					ZEPHIR_INIT_NVAR(tmp);
					ZVAL_NULL(tmp);
				}
				if (inModifier) {
					inModifier = 0;
				}
				break;
			}
			if (ZEPHIR_IS_LONG(_13, 5)) {
				ZEPHIR_CALL_METHOD(&tmp, current, "getparent", &_27);
				zephir_check_call_status();
				ZEPHIR_CPY_WRT(current, tmp);
				ZEPHIR_INIT_NVAR(tmp);
				ZVAL_NULL(tmp);
				inExpression = 0;
				break;
			}
			if (ZEPHIR_IS_LONG(_13, 3)) {
				ZEPHIR_CALL_METHOD(&tmp, current, "getparent", &_27);
				zephir_check_call_status();
				ZEPHIR_CPY_WRT(current, tmp);
				ZEPHIR_INIT_NVAR(tmp);
				ZVAL_NULL(tmp);
				inElement = 0;
				break;
			}
		} while(0);

	}
	RETURN_MM_MEMBER(this_ptr, "_tree");

}

PHP_METHOD(Bolt_App_View_Parser, _debugTree) {

	HashTable *_12, *_16, *_19;
	HashPosition _11, _15, _18;
	int ZEPHIR_LAST_CALL_STATUS;
	zephir_nts_static zephir_fcall_cache_entry *_2 = NULL, *_4 = NULL, *_14 = NULL;
	zval *node, *indent = NULL, *mod = NULL, *prop = NULL, *ch = NULL, _0 = zval_used_for_init, *_1 = NULL, *_3 = NULL, *_5, *_6 = NULL, *_7 = NULL, *_8 = NULL, *_9 = NULL, *_10, **_13, **_17, **_20;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &node, &indent);

	if (!indent) {
		ZEPHIR_INIT_VAR(indent);
		ZVAL_LONG(indent, 0);
	}


	ZEPHIR_SINIT_VAR(_0);
	ZVAL_STRING(&_0, " ", 0);
	ZEPHIR_CALL_FUNCTION(&_1, "str_repeat", &_2, &_0, indent);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_3, this_ptr, "_printfullname", &_4, node);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(_5);
	ZEPHIR_CONCAT_VSV(_5, _1, "Node:", _3);
	zend_print_zval(_5, 0);
	ZEPHIR_CALL_METHOD(&_6, node, "hasarguments", NULL);
	zephir_check_call_status();
	if (zephir_is_true(_6)) {
		ZEPHIR_SINIT_NVAR(_0);
		ZVAL_STRING(&_0, " ", 0);
		ZEPHIR_CALL_FUNCTION(&_7, "str_repeat", &_2, &_0, indent);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(_8);
		ZEPHIR_CALL_METHOD(&_9, node, "getarguments", NULL);
		zephir_check_call_status();
		zephir_fast_join_str(_8, SL(","), _9 TSRMLS_CC);
		ZEPHIR_INIT_VAR(_10);
		ZEPHIR_CONCAT_VSVS(_10, _7, "Arguments: (", _8, ")");
		zend_print_zval(_10, 0);
	}
	ZEPHIR_CALL_METHOD(&_7, node, "hasmodifiers", NULL);
	zephir_check_call_status();
	if (zephir_is_true(_7)) {
		php_printf("%s", "\n");
		ZEPHIR_CALL_METHOD(&_9, node, "getmodifiers", NULL);
		zephir_check_call_status();
		zephir_is_iterable(_9, &_12, &_11, 0, 0, "bolt/app/view/Parser.zep", 238);
		for (
		  ; zephir_hash_get_current_data_ex(_12, (void**) &_13, &_11) == SUCCESS
		  ; zephir_hash_move_forward_ex(_12, &_11)
		) {
			ZEPHIR_GET_HVALUE(mod, _13);
			ZEPHIR_INIT_NVAR(_8);
			ZVAL_LONG(_8, (zephir_get_numberval(indent) + 2));
			ZEPHIR_CALL_METHOD(NULL, this_ptr, "_debugtree", &_14, mod, _8);
			zephir_check_call_status();
		}
	}
	ZEPHIR_CALL_METHOD(&_7, node, "hasproperties", NULL);
	zephir_check_call_status();
	if (zephir_is_true(_7)) {
		php_printf("%s", "\n");
		ZEPHIR_CALL_METHOD(&_9, node, "getproperties", NULL);
		zephir_check_call_status();
		zephir_is_iterable(_9, &_16, &_15, 0, 0, "bolt/app/view/Parser.zep", 245);
		for (
		  ; zephir_hash_get_current_data_ex(_16, (void**) &_17, &_15) == SUCCESS
		  ; zephir_hash_move_forward_ex(_16, &_15)
		) {
			ZEPHIR_GET_HVALUE(prop, _17);
			ZEPHIR_INIT_NVAR(_8);
			ZVAL_LONG(_8, (zephir_get_numberval(indent) + 2));
			ZEPHIR_CALL_METHOD(NULL, this_ptr, "_debugtree", &_14, prop, _8);
			zephir_check_call_status();
		}
	}
	ZEPHIR_CALL_METHOD(&_7, node, "haschildren", NULL);
	zephir_check_call_status();
	if (zephir_is_true(_7)) {
		php_printf("%s", "\n");
		ZEPHIR_CALL_METHOD(&_9, node, "getchildren", NULL);
		zephir_check_call_status();
		zephir_is_iterable(_9, &_19, &_18, 0, 0, "bolt/app/view/Parser.zep", 254);
		for (
		  ; zephir_hash_get_current_data_ex(_19, (void**) &_20, &_18) == SUCCESS
		  ; zephir_hash_move_forward_ex(_19, &_18)
		) {
			ZEPHIR_GET_HVALUE(ch, _20);
			ZEPHIR_INIT_NVAR(_8);
			ZVAL_LONG(_8, (zephir_get_numberval(indent) + 4));
			ZEPHIR_CALL_METHOD(NULL, this_ptr, "_debugtree", &_14, ch, _8);
			zephir_check_call_status();
		}
	}
	php_printf("%s", "\n\n");
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Bolt_App_View_Parser, _printFullName) {

	zephir_nts_static zephir_fcall_cache_entry *_9 = NULL, *_14 = NULL;
	zval *_1 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *node, *str = NULL, *val = NULL, *_0 = NULL, *_2, _3, _4, *_5 = NULL, _6, _7, *_8 = NULL, *_10, *_11 = NULL, *_12 = NULL, *_13 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &node, &str);

	if (!str) {
		ZEPHIR_INIT_VAR(str);
		ZVAL_STRING(str, "", 1);
	} else {
		ZEPHIR_SEPARATE_PARAM(str);
	}


	ZEPHIR_CALL_METHOD(&_0, node, "getvalue", NULL);
	zephir_check_call_status();
	zephir_get_strval(_1, _0);
	ZEPHIR_CPY_WRT(val, _1);
	ZEPHIR_INIT_VAR(_2);
	ZEPHIR_SINIT_VAR(_3);
	ZVAL_STRING(&_3, "\n", 0);
	ZEPHIR_SINIT_VAR(_4);
	ZVAL_STRING(&_4, "", 0);
	zephir_fast_str_replace(_2, &_3, &_4, val TSRMLS_CC);
	ZEPHIR_CPY_WRT(val, _2);
	ZEPHIR_CALL_METHOD(&_5, node, "getstringifiedtype", NULL);
	zephir_check_call_status();
	ZEPHIR_SINIT_VAR(_6);
	ZVAL_LONG(&_6, 0);
	ZEPHIR_SINIT_VAR(_7);
	ZVAL_LONG(&_7, 10);
	ZEPHIR_CALL_FUNCTION(&_8, "substr", &_9, val, &_6, &_7);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(_10);
	ZEPHIR_CONCAT_VSVSSV(_10, _5, "( ", _8, " )", ">", str);
	ZEPHIR_CPY_WRT(str, _10);
	ZEPHIR_CALL_METHOD(&_11, node, "isroot", NULL);
	zephir_check_call_status();
	if (!(zephir_is_true(_11))) {
		ZEPHIR_CALL_METHOD(&_13, node, "getparent", NULL);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&_12, this_ptr, "_printfullname", &_14, _13, str);
		zephir_check_call_status();
		ZEPHIR_CPY_WRT(str, _12);
	}
	RETVAL_ZVAL(str, 1, 0);
	RETURN_MM();

}

