
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
#include "ext/spl/spl_exceptions.h"
#include "kernel/exception.h"
#include "kernel/operators.h"
#include "kernel/string.h"
#include "kernel/fcall.h"
#include "kernel/array.h"
#include "kernel/concat.h"

ZEPHIR_INIT_CLASS(Bolt_App_View_Tokenizer) {

	ZEPHIR_REGISTER_CLASS(Bolt\\App\\View, Tokenizer, bolt, app_view_tokenizer, bolt_app_view_tokenizer_method_entry, ZEND_ACC_FINAL_CLASS);

	zend_declare_property_string(bolt_app_view_tokenizer_ce, SL("_text"), "", ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(bolt_app_view_tokenizer_ce, SL("_tokens"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_string(bolt_app_view_tokenizer_ce, SL("_token"), "", ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_long(bolt_app_view_tokenizer_ce, SL("_length"), 0, ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_long(bolt_app_view_tokenizer_ce, SL("_index"), 0, ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_long(bolt_app_view_tokenizer_ce, SL("_column"), 0, ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_string(bolt_app_view_tokenizer_ce, SL("_strDelimiter"), "", ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_string(bolt_app_view_tokenizer_ce, SL("_buffer"), "", ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(bolt_app_view_tokenizer_ce, SL("_state"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_long(bolt_app_view_tokenizer_ce, SL("_line"), 0, ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_string(bolt_app_view_tokenizer_ce, SL("_file"), "string::", ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_bool(bolt_app_view_tokenizer_ce, SL("_inBlock"), 0, ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_bool(bolt_app_view_tokenizer_ce, SL("_inVar"), 0, ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_bool(bolt_app_view_tokenizer_ce, SL("_inArguments"), 0, ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_bool(bolt_app_view_tokenizer_ce, SL("_inModifier"), 0, ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_bool(bolt_app_view_tokenizer_ce, SL("_inArray"), 0, ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_bool(bolt_app_view_tokenizer_ce, SL("_hasArgumentNameAlready"), 0, ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_long(bolt_app_view_tokenizer_ce, SL("_arrayLevel"), 0, ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_bool(bolt_app_view_tokenizer_ce, SL("_escapeArrayArg"), 0, ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_class_constant_string(bolt_app_view_tokenizer_ce, SL("T_START_ELEMENT"), "{%" TSRMLS_CC);

	zend_declare_class_constant_string(bolt_app_view_tokenizer_ce, SL("T_END_ELEMENT"), "%}" TSRMLS_CC);

	zend_declare_class_constant_string(bolt_app_view_tokenizer_ce, SL("T_START_EXPRESSION"), "{{" TSRMLS_CC);

	zend_declare_class_constant_string(bolt_app_view_tokenizer_ce, SL("T_END_EXPRESSION"), "}}" TSRMLS_CC);

	zend_declare_class_constant_string(bolt_app_view_tokenizer_ce, SL("T_START_COMMENT"), "{#" TSRMLS_CC);

	zend_declare_class_constant_string(bolt_app_view_tokenizer_ce, SL("T_END_COMMENT"), "#}" TSRMLS_CC);

	zend_declare_class_constant_string(bolt_app_view_tokenizer_ce, SL("T_START_IGNORE"), "{!" TSRMLS_CC);

	zend_declare_class_constant_string(bolt_app_view_tokenizer_ce, SL("T_END_IGNORE"), "!}" TSRMLS_CC);

	zend_declare_class_constant_null(bolt_app_view_tokenizer_ce, SL("T_MODIFIER") TSRMLS_CC);

	zend_declare_class_constant_null(bolt_app_view_tokenizer_ce, SL("T_START_ARGS") TSRMLS_CC);

	zend_declare_class_constant_null(bolt_app_view_tokenizer_ce, SL("T_END_ARGS") TSRMLS_CC);

	zend_declare_class_constant_null(bolt_app_view_tokenizer_ce, SL("T_ARGS_SEPARATOR") TSRMLS_CC);

	zend_declare_class_constant_null(bolt_app_view_tokenizer_ce, SL("T_START_ARRAY") TSRMLS_CC);

	zend_declare_class_constant_null(bolt_app_view_tokenizer_ce, SL("T_END_ARRAY") TSRMLS_CC);

	zend_declare_class_constant_long(bolt_app_view_tokenizer_ce, SL("TYPE_TEXT"), 0 TSRMLS_CC);

	zend_declare_class_constant_long(bolt_app_view_tokenizer_ce, SL("TYPE_PROPERTY"), 1 TSRMLS_CC);

	zend_declare_class_constant_long(bolt_app_view_tokenizer_ce, SL("TYPE_OPEN_ELEMENT"), 2 TSRMLS_CC);

	zend_declare_class_constant_long(bolt_app_view_tokenizer_ce, SL("TYPE_CLOSE_ELEMENT"), 3 TSRMLS_CC);

	zend_declare_class_constant_long(bolt_app_view_tokenizer_ce, SL("TYPE_OPEN_EXPRESSION"), 4 TSRMLS_CC);

	zend_declare_class_constant_long(bolt_app_view_tokenizer_ce, SL("TYPE_CLOSE_EXPRESSION"), 5 TSRMLS_CC);

	zend_declare_class_constant_long(bolt_app_view_tokenizer_ce, SL("TYPE_OPEN_IGNORE"), 6 TSRMLS_CC);

	zend_declare_class_constant_long(bolt_app_view_tokenizer_ce, SL("TYPE_CLOSE_IGNORE"), 7 TSRMLS_CC);

	zend_declare_class_constant_long(bolt_app_view_tokenizer_ce, SL("TYPE_MODIFIER"), 8 TSRMLS_CC);

	zend_declare_class_constant_long(bolt_app_view_tokenizer_ce, SL("TYPE_OPEN_ARGUMENTS"), 9 TSRMLS_CC);

	zend_declare_class_constant_long(bolt_app_view_tokenizer_ce, SL("TYPE_CLOSE_ARGUMENTS"), 11 TSRMLS_CC);

	zend_declare_class_constant_long(bolt_app_view_tokenizer_ce, SL("TYPE_ARGUMENT"), 12 TSRMLS_CC);

	zend_declare_class_constant_long(bolt_app_view_tokenizer_ce, SL("TYPE_IGNORED"), 13 TSRMLS_CC);

	zend_declare_class_constant_long(bolt_app_view_tokenizer_ce, SL("TYPE_OPEN_COMMENT"), 14 TSRMLS_CC);

	zend_declare_class_constant_long(bolt_app_view_tokenizer_ce, SL("TYPE_CLOSE_COMMENT"), 15 TSRMLS_CC);

	zend_declare_class_constant_long(bolt_app_view_tokenizer_ce, SL("TYPE_COMMENTED"), 16 TSRMLS_CC);

	zend_declare_class_constant_long(bolt_app_view_tokenizer_ce, SL("TYPE_OPEN_ARRAY"), 17 TSRMLS_CC);

	zend_declare_class_constant_long(bolt_app_view_tokenizer_ce, SL("TYPE_CLOSE_ARRAY"), 18 TSRMLS_CC);

	zend_declare_class_constant_long(bolt_app_view_tokenizer_ce, SL("TYPE_ARGUMENTS_NAME"), 19 TSRMLS_CC);

	zend_declare_class_constant_long(bolt_app_view_tokenizer_ce, SL("S_TEXT"), 0 TSRMLS_CC);

	zend_declare_class_constant_long(bolt_app_view_tokenizer_ce, SL("S_TAG"), 1 TSRMLS_CC);

	zend_declare_class_constant_long(bolt_app_view_tokenizer_ce, SL("S_PROPERTY"), 2 TSRMLS_CC);

	zend_declare_class_constant_long(bolt_app_view_tokenizer_ce, SL("S_STRING"), 3 TSRMLS_CC);

	zend_declare_class_constant_long(bolt_app_view_tokenizer_ce, SL("S_IGNORE"), 4 TSRMLS_CC);

	zend_declare_class_constant_long(bolt_app_view_tokenizer_ce, SL("S_MODIFIER"), 5 TSRMLS_CC);

	zend_declare_class_constant_long(bolt_app_view_tokenizer_ce, SL("S_ARGUMENTS"), 6 TSRMLS_CC);

	zend_declare_class_constant_long(bolt_app_view_tokenizer_ce, SL("S_COMMENT"), 7 TSRMLS_CC);

	zend_declare_class_constant_long(bolt_app_view_tokenizer_ce, SL("S_ARRAY"), 8 TSRMLS_CC);

	return SUCCESS;

}

PHP_METHOD(Bolt_App_View_Tokenizer, __construct) {

	zval *text_param = NULL, *filePath_param = NULL, *_0;
	zval *text = NULL, *filePath = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &text_param, &filePath_param);

	if (unlikely(Z_TYPE_P(text_param) != IS_STRING && Z_TYPE_P(text_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'text' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (likely(Z_TYPE_P(text_param) == IS_STRING)) {
		zephir_get_strval(text, text_param);
	} else {
		ZEPHIR_INIT_VAR(text);
		ZVAL_EMPTY_STRING(text);
	}
	if (!filePath_param) {
		ZEPHIR_INIT_VAR(filePath);
		ZVAL_STRING(filePath, "string::", 1);
	} else {
	if (unlikely(Z_TYPE_P(filePath_param) != IS_STRING && Z_TYPE_P(filePath_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'filePath' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (likely(Z_TYPE_P(filePath_param) == IS_STRING)) {
		zephir_get_strval(filePath, filePath_param);
	} else {
		ZEPHIR_INIT_VAR(filePath);
		ZVAL_EMPTY_STRING(filePath);
	}
	}


	ZEPHIR_INIT_VAR(_0);
	array_init(_0);
	zephir_update_property_this(this_ptr, SL("_tokens"), _0 TSRMLS_CC);
	zephir_update_property_this(this_ptr, SL("_text"), text TSRMLS_CC);
	zephir_update_property_this(this_ptr, SL("_file"), filePath TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Bolt_App_View_Tokenizer, scan) {

	zephir_nts_static zephir_fcall_cache_entry *_4 = NULL, *_8 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *_0, *_1, *_2, *_3, *_5, *_6, *_7;

	ZEPHIR_MM_GROW();

	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_text"), PH_NOISY_CC);
	ZEPHIR_INIT_ZVAL_NREF(_1);
	ZVAL_LONG(_1, zephir_fast_strlen_ev(_0));
	zephir_update_property_this(this_ptr, SL("_length"), _1 TSRMLS_CC);
	ZEPHIR_INIT_ZVAL_NREF(_1);
	ZVAL_LONG(_1, 0);
	zephir_update_property_this(this_ptr, SL("_index"), _1 TSRMLS_CC);
	ZEPHIR_INIT_ZVAL_NREF(_1);
	ZVAL_LONG(_1, 1);
	zephir_update_property_this(this_ptr, SL("_column"), _1 TSRMLS_CC);
	ZEPHIR_INIT_ZVAL_NREF(_1);
	ZVAL_LONG(_1, 1);
	zephir_update_property_this(this_ptr, SL("_line"), _1 TSRMLS_CC);
	ZEPHIR_INIT_ZVAL_NREF(_1);
	ZVAL_STRING(_1, "", 1);
	zephir_update_property_this(this_ptr, SL("_token"), _1 TSRMLS_CC);
	ZEPHIR_INIT_VAR(_2);
	array_init(_2);
	zephir_update_property_this(this_ptr, SL("_tokens"), _2 TSRMLS_CC);
	ZEPHIR_INIT_ZVAL_NREF(_1);
	ZVAL_LONG(_1, 0);
	zephir_update_property_this(this_ptr, SL("_state"), _1 TSRMLS_CC);
	while (1) {
		_1 = zephir_fetch_nproperty_this(this_ptr, SL("_index"), PH_NOISY_CC);
		_3 = zephir_fetch_nproperty_this(this_ptr, SL("_length"), PH_NOISY_CC);
		if (!(ZEPHIR_LT(_1, _3))) {
			break;
		}
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "_handlemainstate", &_4);
		zephir_check_call_status();
	}
	_5 = zephir_fetch_nproperty_this(this_ptr, SL("_buffer"), PH_NOISY_CC);
	if (zephir_is_true(_5)) {
		_6 = zephir_fetch_nproperty_this(this_ptr, SL("_buffer"), PH_NOISY_CC);
		ZEPHIR_INIT_VAR(_7);
		ZVAL_LONG(_7, 0);
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "_addtoken", &_8, _7, _6);
		zephir_check_call_status();
	}
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Bolt_App_View_Tokenizer, getTokens) {


	RETURN_MEMBER(this_ptr, "_tokens");

}

PHP_METHOD(Bolt_App_View_Tokenizer, getText) {


	RETURN_MEMBER(this_ptr, "_text");

}

PHP_METHOD(Bolt_App_View_Tokenizer, getFile) {


	RETURN_MEMBER(this_ptr, "_file");

}

PHP_METHOD(Bolt_App_View_Tokenizer, _addToken) {

	zval *_1 = NULL;
	zval *_0;
	zval *type, *value, *_2, *_3, *_4;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &type, &value);



	ZEPHIR_INIT_VAR(_0);
	array_init_size(_0, 8);
	zephir_array_update_string(&_0, SL("type"), &type, PH_COPY | PH_SEPARATE);
	zephir_get_strval(_1, value);
	zephir_array_update_string(&_0, SL("value"), &_1, PH_COPY | PH_SEPARATE);
	ZEPHIR_OBS_VAR(_2);
	zephir_read_property_this(&_2, this_ptr, SL("_column"), PH_NOISY_CC);
	add_assoc_long_ex(_0, SS("column"), zephir_get_intval(_2));
	ZEPHIR_OBS_VAR(_3);
	zephir_read_property_this(&_3, this_ptr, SL("_line"), PH_NOISY_CC);
	add_assoc_long_ex(_0, SS("line"), zephir_get_intval(_3));
	ZEPHIR_OBS_VAR(_4);
	zephir_read_property_this(&_4, this_ptr, SL("_index"), PH_NOISY_CC);
	add_assoc_long_ex(_0, SS("index"), zephir_get_intval(_4));
	add_assoc_long_ex(_0, SS("length"), zephir_fast_strlen_ev(value));
	zephir_update_property_array_append(this_ptr, SL("_tokens"), _0 TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Bolt_App_View_Tokenizer, _isOpeningToken) {

	zend_bool _0, _1, _2;
	zval *token_param = NULL;
	zval *token = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &token_param);

	if (unlikely(Z_TYPE_P(token_param) != IS_STRING && Z_TYPE_P(token_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'token' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (likely(Z_TYPE_P(token_param) == IS_STRING)) {
		zephir_get_strval(token, token_param);
	} else {
		ZEPHIR_INIT_VAR(token);
		ZVAL_EMPTY_STRING(token);
	}


	_0 = ZEPHIR_IS_STRING(token, "{%");
	if (!(_0)) {
		_0 = ZEPHIR_IS_STRING(token, "{#");
	}
	_1 = _0;
	if (!(_1)) {
		_1 = ZEPHIR_IS_STRING(token, "{{");
	}
	_2 = _1;
	if (!(_2)) {
		_2 = ZEPHIR_IS_STRING(token, "{!");
	}
	if (_2) {
		RETURN_MM_BOOL(1);
	}
	RETURN_MM_BOOL(0);

}

PHP_METHOD(Bolt_App_View_Tokenizer, _handleMainState) {

	zend_bool _20, _21, _23, _25, _28, _32, _33, _34, _35, _36;
	zephir_fcall_cache_entry *_19 = NULL;
	zephir_nts_static zephir_fcall_cache_entry *_9 = NULL, *_13 = NULL, *_16 = NULL, *_26 = NULL, *_37 = NULL, *_43 = NULL;
	unsigned char _5, _10;
	int index, tmpIndex, ZEPHIR_LAST_CALL_STATUS, _45;
	zval *text = NULL, *_1 = NULL;
	zval *prevCh, *currentCh, *nextCh, tmp = zval_used_for_init, *_0, *_2, *_3, *_4, _6 = zval_used_for_init, _7 = zval_used_for_init, *_8 = NULL, *_11, *_12, *_14, *_15 = NULL, *_17, *_18, *_22, *_24 = NULL, *_27 = NULL, *_29 = NULL, *_30, *_31, *_38, *_39, *_40 = NULL, *_41 = NULL, *_42, *_44 = NULL;

	ZEPHIR_MM_GROW();

	ZEPHIR_OBS_VAR(_0);
	zephir_read_property_this(&_0, this_ptr, SL("_text"), PH_NOISY_CC);
	zephir_get_strval(_1, _0);
	ZEPHIR_CPY_WRT(text, _1);
	ZEPHIR_OBS_VAR(_2);
	zephir_read_property_this(&_2, this_ptr, SL("_index"), PH_NOISY_CC);
	index = zephir_get_intval(_2);
	_3 = zephir_fetch_nproperty_this(this_ptr, SL("_column"), PH_NOISY_CC);
	ZEPHIR_INIT_ZVAL_NREF(_4);
	ZVAL_LONG(_4, (zephir_get_numberval(_3) + 1));
	zephir_update_property_this(this_ptr, SL("_column"), _4 TSRMLS_CC);
	if (index > 0) {
		_5 = ZEPHIR_STRING_OFFSET(text, (index - 1));
		ZEPHIR_INIT_VAR(prevCh);
		ZVAL_LONG(prevCh, _5);
	}
	_5 = ZEPHIR_STRING_OFFSET(text, index);
	ZEPHIR_INIT_VAR(currentCh);
	ZVAL_LONG(currentCh, _5);
	_4 = zephir_fetch_nproperty_this(this_ptr, SL("_length"), PH_NOISY_CC);
	if (ZEPHIR_GT_LONG(_4, (index + 1))) {
		ZEPHIR_SINIT_VAR(_6);
		ZVAL_LONG(&_6, index);
		ZEPHIR_SINIT_VAR(_7);
		ZVAL_LONG(&_7, 2);
		ZEPHIR_CALL_FUNCTION(&_8, "substr", &_9, text, &_6, &_7);
		zephir_check_call_status();
		zephir_update_property_this(this_ptr, SL("_token"), _8 TSRMLS_CC);
		_10 = ZEPHIR_STRING_OFFSET(text, (index + 1));
		ZEPHIR_INIT_VAR(nextCh);
		ZVAL_LONG(nextCh, _10);
	}
	if (ZEPHIR_IS_LONG(currentCh, '\n')) {
		_11 = zephir_fetch_nproperty_this(this_ptr, SL("_line"), PH_NOISY_CC);
		ZEPHIR_INIT_ZVAL_NREF(_12);
		ZVAL_LONG(_12, (zephir_get_numberval(_11) + 1));
		zephir_update_property_this(this_ptr, SL("_line"), _12 TSRMLS_CC);
		ZEPHIR_INIT_ZVAL_NREF(_12);
		ZVAL_LONG(_12, 1);
		zephir_update_property_this(this_ptr, SL("_column"), _12 TSRMLS_CC);
	}
	_11 = zephir_fetch_nproperty_this(this_ptr, SL("_state"), PH_NOISY_CC);
	do {
		if (ZEPHIR_IS_LONG(_11, 0)) {
			_12 = zephir_fetch_nproperty_this(this_ptr, SL("_token"), PH_NOISY_CC);
			ZEPHIR_CALL_METHOD(&_8, this_ptr, "_isopeningtoken", &_13, _12);
			zephir_check_call_status();
			if (zephir_is_true(_8)) {
				_14 = zephir_fetch_nproperty_this(this_ptr, SL("_buffer"), PH_NOISY_CC);
				ZEPHIR_INIT_VAR(_15);
				ZVAL_LONG(_15, 0);
				ZEPHIR_CALL_METHOD(NULL, this_ptr, "_addtoken", &_16, _15, _14);
				zephir_check_call_status();
				ZEPHIR_INIT_ZVAL_NREF(_17);
				ZVAL_STRING(_17, "", 1);
				zephir_update_property_this(this_ptr, SL("_buffer"), _17 TSRMLS_CC);
			}
			_14 = zephir_fetch_nproperty_this(this_ptr, SL("_token"), PH_NOISY_CC);
			do {
				if (ZEPHIR_IS_STRING(_14, "{%")) {
					ZEPHIR_INIT_ZVAL_NREF(_17);
					ZVAL_LONG(_17, 1);
					zephir_update_property_this(this_ptr, SL("_state"), _17 TSRMLS_CC);
					_17 = zephir_fetch_nproperty_this(this_ptr, SL("_token"), PH_NOISY_CC);
					ZEPHIR_INIT_NVAR(_15);
					ZVAL_LONG(_15, 2);
					ZEPHIR_CALL_METHOD(NULL, this_ptr, "_addtoken", &_16, _15, _17);
					zephir_check_call_status();
					zephir_update_property_this(this_ptr, SL("_inBlock"), (1) ? ZEPHIR_GLOBAL(global_true) : ZEPHIR_GLOBAL(global_false) TSRMLS_CC);
					ZEPHIR_INIT_ZVAL_NREF(_18);
					ZVAL_LONG(_18, (index + 2));
					zephir_update_property_this(this_ptr, SL("_index"), _18 TSRMLS_CC);
					RETURN_MM_NULL();
				}
				if (ZEPHIR_IS_STRING(_14, "{{")) {
					ZEPHIR_INIT_ZVAL_NREF(_14);
					ZVAL_LONG(_14, 1);
					zephir_update_property_this(this_ptr, SL("_state"), _14 TSRMLS_CC);
					_14 = zephir_fetch_nproperty_this(this_ptr, SL("_token"), PH_NOISY_CC);
					ZEPHIR_INIT_NVAR(_15);
					ZVAL_LONG(_15, 4);
					ZEPHIR_CALL_METHOD(NULL, this_ptr, "_addtoken", &_16, _15, _14);
					zephir_check_call_status();
					zephir_update_property_this(this_ptr, SL("_inVar"), (1) ? ZEPHIR_GLOBAL(global_true) : ZEPHIR_GLOBAL(global_false) TSRMLS_CC);
					ZEPHIR_INIT_ZVAL_NREF(_17);
					ZVAL_LONG(_17, (index + 2));
					zephir_update_property_this(this_ptr, SL("_index"), _17 TSRMLS_CC);
					RETURN_MM_NULL();
				}
				if (ZEPHIR_IS_STRING(_14, "{#")) {
					ZEPHIR_INIT_ZVAL_NREF(_14);
					ZVAL_LONG(_14, 7);
					zephir_update_property_this(this_ptr, SL("_state"), _14 TSRMLS_CC);
					_14 = zephir_fetch_nproperty_this(this_ptr, SL("_token"), PH_NOISY_CC);
					ZEPHIR_INIT_NVAR(_15);
					ZVAL_LONG(_15, 14);
					ZEPHIR_CALL_METHOD(NULL, this_ptr, "_addtoken", &_16, _15, _14);
					zephir_check_call_status();
					ZEPHIR_INIT_ZVAL_NREF(_17);
					ZVAL_LONG(_17, (index + 2));
					zephir_update_property_this(this_ptr, SL("_index"), _17 TSRMLS_CC);
					RETURN_MM_NULL();
				}
				if (ZEPHIR_IS_STRING(_14, "{!")) {
					ZEPHIR_INIT_ZVAL_NREF(_14);
					ZVAL_LONG(_14, 4);
					zephir_update_property_this(this_ptr, SL("_state"), _14 TSRMLS_CC);
					_14 = zephir_fetch_nproperty_this(this_ptr, SL("_token"), PH_NOISY_CC);
					ZEPHIR_INIT_NVAR(_15);
					ZVAL_LONG(_15, 6);
					ZEPHIR_CALL_METHOD(NULL, this_ptr, "_addtoken", &_16, _15, _14);
					zephir_check_call_status();
					ZEPHIR_INIT_ZVAL_NREF(_17);
					ZVAL_LONG(_17, (index + 2));
					zephir_update_property_this(this_ptr, SL("_index"), _17 TSRMLS_CC);
					RETURN_MM_NULL();
				}
			} while(0);

			break;
		}
		if (ZEPHIR_IS_LONG(_11, 1)) {
			ZEPHIR_CALL_FUNCTION(&_8, "ctype_space", &_19, currentCh);
			zephir_check_call_status();
			if (zephir_is_true(_8)) {
				ZEPHIR_INIT_ZVAL_NREF(_11);
				ZVAL_LONG(_11, (index + 1));
				zephir_update_property_this(this_ptr, SL("_index"), _11 TSRMLS_CC);
				RETURN_MM_NULL();
			}
			_11 = zephir_fetch_nproperty_this(this_ptr, SL("_inVar"), PH_NOISY_CC);
			_20 = zephir_is_true(_11);
			if (_20) {
				_12 = zephir_fetch_nproperty_this(this_ptr, SL("_token"), PH_NOISY_CC);
				_20 = ZEPHIR_IS_STRING(_12, "}}");
			}
			if (_20) {
				_14 = zephir_fetch_nproperty_this(this_ptr, SL("_token"), PH_NOISY_CC);
				ZEPHIR_INIT_NVAR(_15);
				ZVAL_LONG(_15, 5);
				ZEPHIR_CALL_METHOD(NULL, this_ptr, "_addtoken", &_16, _15, _14);
				zephir_check_call_status();
				zephir_update_property_this(this_ptr, SL("_inVar"), (0) ? ZEPHIR_GLOBAL(global_true) : ZEPHIR_GLOBAL(global_false) TSRMLS_CC);
				zephir_update_property_this(this_ptr, SL("_inBlock"), (0) ? ZEPHIR_GLOBAL(global_true) : ZEPHIR_GLOBAL(global_false) TSRMLS_CC);
				ZEPHIR_INIT_ZVAL_NREF(_17);
				ZVAL_STRING(_17, "", 1);
				zephir_update_property_this(this_ptr, SL("_buffer"), _17 TSRMLS_CC);
				ZEPHIR_INIT_ZVAL_NREF(_17);
				ZVAL_LONG(_17, 0);
				zephir_update_property_this(this_ptr, SL("_state"), _17 TSRMLS_CC);
				ZEPHIR_INIT_ZVAL_NREF(_17);
				ZVAL_LONG(_17, (index + 2));
				zephir_update_property_this(this_ptr, SL("_index"), _17 TSRMLS_CC);
				RETURN_MM_NULL();
			}
			_14 = zephir_fetch_nproperty_this(this_ptr, SL("_inBlock"), PH_NOISY_CC);
			_21 = zephir_is_true(_14);
			if (_21) {
				_17 = zephir_fetch_nproperty_this(this_ptr, SL("_token"), PH_NOISY_CC);
				_21 = ZEPHIR_IS_STRING(_17, "%}");
			}
			if (_21) {
				_18 = zephir_fetch_nproperty_this(this_ptr, SL("_token"), PH_NOISY_CC);
				ZEPHIR_INIT_NVAR(_15);
				ZVAL_LONG(_15, 3);
				ZEPHIR_CALL_METHOD(NULL, this_ptr, "_addtoken", &_16, _15, _18);
				zephir_check_call_status();
				zephir_update_property_this(this_ptr, SL("_inVar"), (0) ? ZEPHIR_GLOBAL(global_true) : ZEPHIR_GLOBAL(global_false) TSRMLS_CC);
				zephir_update_property_this(this_ptr, SL("_inBlock"), (0) ? ZEPHIR_GLOBAL(global_true) : ZEPHIR_GLOBAL(global_false) TSRMLS_CC);
				ZEPHIR_INIT_ZVAL_NREF(_22);
				ZVAL_STRING(_22, "", 1);
				zephir_update_property_this(this_ptr, SL("_buffer"), _22 TSRMLS_CC);
				ZEPHIR_INIT_ZVAL_NREF(_22);
				ZVAL_LONG(_22, 0);
				zephir_update_property_this(this_ptr, SL("_state"), _22 TSRMLS_CC);
				ZEPHIR_INIT_ZVAL_NREF(_22);
				ZVAL_LONG(_22, (index + 2));
				zephir_update_property_this(this_ptr, SL("_index"), _22 TSRMLS_CC);
				RETURN_MM_NULL();
			}
			ZEPHIR_INIT_ZVAL_NREF(_14);
			ZVAL_LONG(_14, 2);
			zephir_update_property_this(this_ptr, SL("_state"), _14 TSRMLS_CC);
			RETURN_MM_NULL();
		}
		if (ZEPHIR_IS_LONG(_11, 2)) {
			_20 = ZEPHIR_IS_LONG(currentCh, '"');
			if (!(_20)) {
				_20 = ZEPHIR_IS_LONG(currentCh, '\'');
			}
			_21 = _20;
			if (_21) {
				_11 = zephir_fetch_nproperty_this(this_ptr, SL("_buffer"), PH_NOISY_CC);
				_21 = ZEPHIR_IS_STRING(_11, "");
			}
			if (_21) {
				ZEPHIR_INIT_ZVAL_NREF(_12);
				ZVAL_LONG(_12, 3);
				zephir_update_property_this(this_ptr, SL("_state"), _12 TSRMLS_CC);
				zephir_update_property_this(this_ptr, SL("_strDelimiter"), currentCh TSRMLS_CC);
				ZEPHIR_INIT_ZVAL_NREF(_12);
				ZVAL_STRING(_12, "", 1);
				zephir_update_property_this(this_ptr, SL("_buffer"), _12 TSRMLS_CC);
				ZEPHIR_INIT_ZVAL_NREF(_12);
				ZVAL_LONG(_12, (index + 1));
				zephir_update_property_this(this_ptr, SL("_index"), _12 TSRMLS_CC);
				RETURN_MM_NULL();
			}
			_23 = ZEPHIR_IS_LONG(currentCh, '[');
			if (_23) {
				_12 = zephir_fetch_nproperty_this(this_ptr, SL("_buffer"), PH_NOISY_CC);
				_23 = ZEPHIR_IS_STRING(_12, "");
			}
			if (_23) {
				ZEPHIR_INIT_ZVAL_NREF(_14);
				ZVAL_LONG(_14, 8);
				zephir_update_property_this(this_ptr, SL("_state"), _14 TSRMLS_CC);
				ZEPHIR_INIT_NVAR(_15);
				ZVAL_LONG(_15, 17);
				ZEPHIR_INIT_VAR(_24);
				ZVAL_STRING(_24, "[", ZEPHIR_TEMP_PARAM_COPY);
				ZEPHIR_CALL_METHOD(NULL, this_ptr, "_addtoken", &_16, _15, _24);
				zephir_check_temp_parameter(_24);
				zephir_check_call_status();
				ZEPHIR_INIT_ZVAL_NREF(_14);
				ZVAL_STRING(_14, "", 1);
				zephir_update_property_this(this_ptr, SL("_buffer"), _14 TSRMLS_CC);
				ZEPHIR_INIT_ZVAL_NREF(_14);
				ZVAL_LONG(_14, (index + 1));
				zephir_update_property_this(this_ptr, SL("_index"), _14 TSRMLS_CC);
				zephir_update_property_this(this_ptr, SL("_inArray"), (1) ? ZEPHIR_GLOBAL(global_true) : ZEPHIR_GLOBAL(global_false) TSRMLS_CC);
				ZEPHIR_INIT_ZVAL_NREF(_14);
				ZVAL_LONG(_14, 1);
				zephir_update_property_this(this_ptr, SL("_arrayLevel"), _14 TSRMLS_CC);
				RETURN_MM_NULL();
			}
			_25 = ZEPHIR_IS_LONG(currentCh, '"');
			if (!(_25)) {
				_25 = ZEPHIR_IS_LONG(currentCh, '\'');
			}
			if (_25) {
				ZEPHIR_INIT_NVAR(_15);
				object_init_ex(_15, bolt_app_view_exception_ce);
				_14 = zephir_fetch_nproperty_this(this_ptr, SL("_file"), PH_NOISY_CC);
				_17 = zephir_fetch_nproperty_this(this_ptr, SL("_line"), PH_NOISY_CC);
				_18 = zephir_fetch_nproperty_this(this_ptr, SL("_line"), PH_NOISY_CC);
				_22 = zephir_fetch_nproperty_this(this_ptr, SL("_column"), PH_NOISY_CC);
				ZEPHIR_CALL_CE_STATIC(&_8, bolt_app_view_exception_ce, "geterrorhintfromstring", &_26, text, _18, _22);
				zephir_check_call_status();
				ZEPHIR_INIT_VAR(_27);
				ZEPHIR_CONCAT_SVSVSV(_27, "Unexpected token Tokenizer::T_STRING in ", _14, " on line ", _17, "\n", _8);
				ZEPHIR_CALL_METHOD(NULL, _15, "__construct", NULL, _27);
				zephir_check_call_status();
				zephir_throw_exception_debug(_15, "bolt/app/view/Tokenizer.zep", 259 TSRMLS_CC);
				ZEPHIR_MM_RESTORE();
				return;
			}
			if (ZEPHIR_IS_LONG(currentCh, '|')) {
				_14 = zephir_fetch_nproperty_this(this_ptr, SL("_buffer"), PH_NOISY_CC);
				_28 = !ZEPHIR_IS_LONG(prevCh, ')');
				if (_28) {
					_28 = !ZEPHIR_IS_LONG(prevCh, ']');
				}
				if (!ZEPHIR_IS_STRING(_14, "")) {
					_17 = zephir_fetch_nproperty_this(this_ptr, SL("_buffer"), PH_NOISY_CC);
					ZEPHIR_INIT_NVAR(_15);
					ZVAL_LONG(_15, 1);
					ZEPHIR_CALL_METHOD(NULL, this_ptr, "_addtoken", &_16, _15, _17);
					zephir_check_call_status();
					ZEPHIR_INIT_ZVAL_NREF(_18);
					ZVAL_STRING(_18, "", 1);
					zephir_update_property_this(this_ptr, SL("_buffer"), _18 TSRMLS_CC);
				} else if (_28) {
					ZEPHIR_INIT_NVAR(_15);
					object_init_ex(_15, bolt_app_view_exception_ce);
					_18 = zephir_fetch_nproperty_this(this_ptr, SL("_file"), PH_NOISY_CC);
					_22 = zephir_fetch_nproperty_this(this_ptr, SL("_line"), PH_NOISY_CC);
					_30 = zephir_fetch_nproperty_this(this_ptr, SL("_line"), PH_NOISY_CC);
					_31 = zephir_fetch_nproperty_this(this_ptr, SL("_column"), PH_NOISY_CC);
					ZEPHIR_CALL_CE_STATIC(&_29, bolt_app_view_exception_ce, "geterrorhintfromstring", &_26, text, _30, _31);
					zephir_check_call_status();
					ZEPHIR_INIT_LNVAR(_27);
					ZEPHIR_CONCAT_SVSVSV(_27, "Unexpected token Tokenizer::T_MODIFIER in ", _18, " on line ", _22, "\n", _29);
					ZEPHIR_CALL_METHOD(NULL, _15, "__construct", NULL, _27);
					zephir_check_call_status();
					zephir_throw_exception_debug(_15, "bolt/app/view/Tokenizer.zep", 268 TSRMLS_CC);
					ZEPHIR_MM_RESTORE();
					return;
				}
				ZEPHIR_INIT_ZVAL_NREF(_30);
				ZVAL_LONG(_30, 5);
				zephir_update_property_this(this_ptr, SL("_state"), _30 TSRMLS_CC);
				ZEPHIR_INIT_ZVAL_NREF(_30);
				ZVAL_LONG(_30, (index + 1));
				zephir_update_property_this(this_ptr, SL("_index"), _30 TSRMLS_CC);
				RETURN_MM_NULL();
			}
			if (ZEPHIR_IS_LONG(currentCh, '(')) {
				_14 = zephir_fetch_nproperty_this(this_ptr, SL("_buffer"), PH_NOISY_CC);
				ZEPHIR_INIT_NVAR(_15);
				ZVAL_LONG(_15, 1);
				ZEPHIR_CALL_METHOD(NULL, this_ptr, "_addtoken", &_16, _15, _14);
				zephir_check_call_status();
				ZEPHIR_INIT_NVAR(_15);
				ZVAL_LONG(_15, 9);
				ZEPHIR_INIT_NVAR(_24);
				ZVAL_STRING(_24, "(", ZEPHIR_TEMP_PARAM_COPY);
				ZEPHIR_CALL_METHOD(NULL, this_ptr, "_addtoken", &_16, _15, _24);
				zephir_check_temp_parameter(_24);
				zephir_check_call_status();
				zephir_update_property_this(this_ptr, SL("_inArguments"), (1) ? ZEPHIR_GLOBAL(global_true) : ZEPHIR_GLOBAL(global_false) TSRMLS_CC);
				ZEPHIR_INIT_ZVAL_NREF(_17);
				ZVAL_LONG(_17, 6);
				zephir_update_property_this(this_ptr, SL("_state"), _17 TSRMLS_CC);
				ZEPHIR_INIT_ZVAL_NREF(_17);
				ZVAL_LONG(_17, (index + 1));
				zephir_update_property_this(this_ptr, SL("_index"), _17 TSRMLS_CC);
				ZEPHIR_INIT_ZVAL_NREF(_17);
				ZVAL_STRING(_17, "", 1);
				zephir_update_property_this(this_ptr, SL("_buffer"), _17 TSRMLS_CC);
				RETURN_MM_NULL();
			}
			ZEPHIR_CALL_FUNCTION(&_29, "ctype_space", &_19, currentCh);
			zephir_check_call_status();
			if (zephir_is_true(_29)) {
				_14 = zephir_fetch_nproperty_this(this_ptr, SL("_buffer"), PH_NOISY_CC);
				if (!ZEPHIR_IS_STRING(_14, "")) {
					_17 = zephir_fetch_nproperty_this(this_ptr, SL("_buffer"), PH_NOISY_CC);
					ZEPHIR_INIT_NVAR(_15);
					ZVAL_LONG(_15, 1);
					ZEPHIR_CALL_METHOD(NULL, this_ptr, "_addtoken", &_16, _15, _17);
					zephir_check_call_status();
					ZEPHIR_INIT_ZVAL_NREF(_18);
					ZVAL_STRING(_18, "", 1);
					zephir_update_property_this(this_ptr, SL("_buffer"), _18 TSRMLS_CC);
				}
				ZEPHIR_INIT_ZVAL_NREF(_18);
				ZVAL_LONG(_18, 1);
				zephir_update_property_this(this_ptr, SL("_state"), _18 TSRMLS_CC);
				ZEPHIR_INIT_ZVAL_NREF(_18);
				ZVAL_LONG(_18, (index + 1));
				zephir_update_property_this(this_ptr, SL("_index"), _18 TSRMLS_CC);
				RETURN_MM_NULL();
			}
			_14 = zephir_fetch_nproperty_this(this_ptr, SL("_inVar"), PH_NOISY_CC);
			_28 = zephir_is_true(_14);
			if (_28) {
				_17 = zephir_fetch_nproperty_this(this_ptr, SL("_token"), PH_NOISY_CC);
				_28 = ZEPHIR_IS_STRING(_17, "}}");
			}
			if (_28) {
				ZEPHIR_INIT_NVAR(_15);
				_18 = zephir_fetch_nproperty_this(this_ptr, SL("_buffer"), PH_NOISY_CC);
				zephir_fast_trim(_15, _18, NULL , ZEPHIR_TRIM_BOTH TSRMLS_CC);
				if (!ZEPHIR_IS_STRING(_15, "")) {
					_22 = zephir_fetch_nproperty_this(this_ptr, SL("_buffer"), PH_NOISY_CC);
					ZEPHIR_INIT_NVAR(_24);
					ZVAL_LONG(_24, 1);
					ZEPHIR_CALL_METHOD(NULL, this_ptr, "_addtoken", &_16, _24, _22);
					zephir_check_call_status();
					ZEPHIR_INIT_ZVAL_NREF(_30);
					ZVAL_STRING(_30, "", 1);
					zephir_update_property_this(this_ptr, SL("_buffer"), _30 TSRMLS_CC);
				}
				_30 = zephir_fetch_nproperty_this(this_ptr, SL("_token"), PH_NOISY_CC);
				ZEPHIR_INIT_NVAR(_24);
				ZVAL_LONG(_24, 5);
				ZEPHIR_CALL_METHOD(NULL, this_ptr, "_addtoken", &_16, _24, _30);
				zephir_check_call_status();
				zephir_update_property_this(this_ptr, SL("_inVar"), (0) ? ZEPHIR_GLOBAL(global_true) : ZEPHIR_GLOBAL(global_false) TSRMLS_CC);
				zephir_update_property_this(this_ptr, SL("_inBlock"), (0) ? ZEPHIR_GLOBAL(global_true) : ZEPHIR_GLOBAL(global_false) TSRMLS_CC);
				ZEPHIR_INIT_ZVAL_NREF(_31);
				ZVAL_STRING(_31, "", 1);
				zephir_update_property_this(this_ptr, SL("_buffer"), _31 TSRMLS_CC);
				ZEPHIR_INIT_ZVAL_NREF(_31);
				ZVAL_LONG(_31, 0);
				zephir_update_property_this(this_ptr, SL("_state"), _31 TSRMLS_CC);
				ZEPHIR_INIT_ZVAL_NREF(_31);
				ZVAL_LONG(_31, (index + 2));
				zephir_update_property_this(this_ptr, SL("_index"), _31 TSRMLS_CC);
				RETURN_MM_NULL();
			}
			_14 = zephir_fetch_nproperty_this(this_ptr, SL("_inBlock"), PH_NOISY_CC);
			_28 = zephir_is_true(_14);
			if (_28) {
				_17 = zephir_fetch_nproperty_this(this_ptr, SL("_token"), PH_NOISY_CC);
				_28 = ZEPHIR_IS_STRING(_17, "%}");
			}
			if (_28) {
				ZEPHIR_INIT_NVAR(_15);
				_18 = zephir_fetch_nproperty_this(this_ptr, SL("_buffer"), PH_NOISY_CC);
				zephir_fast_trim(_15, _18, NULL , ZEPHIR_TRIM_BOTH TSRMLS_CC);
				if (!ZEPHIR_IS_STRING(_15, "")) {
					_22 = zephir_fetch_nproperty_this(this_ptr, SL("_buffer"), PH_NOISY_CC);
					ZEPHIR_INIT_NVAR(_24);
					ZVAL_LONG(_24, 1);
					ZEPHIR_CALL_METHOD(NULL, this_ptr, "_addtoken", &_16, _24, _22);
					zephir_check_call_status();
					ZEPHIR_INIT_ZVAL_NREF(_31);
					ZVAL_STRING(_31, "", 1);
					zephir_update_property_this(this_ptr, SL("_buffer"), _31 TSRMLS_CC);
				}
				_30 = zephir_fetch_nproperty_this(this_ptr, SL("_token"), PH_NOISY_CC);
				ZEPHIR_INIT_NVAR(_24);
				ZVAL_LONG(_24, 3);
				ZEPHIR_CALL_METHOD(NULL, this_ptr, "_addtoken", &_16, _24, _30);
				zephir_check_call_status();
				zephir_update_property_this(this_ptr, SL("_inVar"), (0) ? ZEPHIR_GLOBAL(global_true) : ZEPHIR_GLOBAL(global_false) TSRMLS_CC);
				zephir_update_property_this(this_ptr, SL("_inBlock"), (0) ? ZEPHIR_GLOBAL(global_true) : ZEPHIR_GLOBAL(global_false) TSRMLS_CC);
				ZEPHIR_INIT_ZVAL_NREF(_31);
				ZVAL_STRING(_31, "", 1);
				zephir_update_property_this(this_ptr, SL("_buffer"), _31 TSRMLS_CC);
				ZEPHIR_INIT_ZVAL_NREF(_31);
				ZVAL_LONG(_31, 0);
				zephir_update_property_this(this_ptr, SL("_state"), _31 TSRMLS_CC);
				ZEPHIR_INIT_ZVAL_NREF(_31);
				ZVAL_LONG(_31, (index + 2));
				zephir_update_property_this(this_ptr, SL("_index"), _31 TSRMLS_CC);
				RETURN_MM_NULL();
			}
			break;
		}
		if (ZEPHIR_IS_LONG(_11, 6)) {
			if (ZEPHIR_IS_LONG(currentCh, ')')) {
				_11 = zephir_fetch_nproperty_this(this_ptr, SL("_buffer"), PH_NOISY_CC);
				if (zephir_is_true(_11)) {
					_12 = zephir_fetch_nproperty_this(this_ptr, SL("_buffer"), PH_NOISY_CC);
					ZEPHIR_INIT_NVAR(_15);
					ZVAL_LONG(_15, 12);
					ZEPHIR_CALL_METHOD(NULL, this_ptr, "_addtoken", &_16, _15, _12);
					zephir_check_call_status();
					ZEPHIR_INIT_ZVAL_NREF(_14);
					ZVAL_STRING(_14, "", 1);
					zephir_update_property_this(this_ptr, SL("_buffer"), _14 TSRMLS_CC);
				}
				ZEPHIR_INIT_NVAR(_15);
				ZVAL_LONG(_15, 11);
				ZEPHIR_INIT_NVAR(_24);
				ZVAL_STRING(_24, ")", ZEPHIR_TEMP_PARAM_COPY);
				ZEPHIR_CALL_METHOD(NULL, this_ptr, "_addtoken", &_16, _15, _24);
				zephir_check_temp_parameter(_24);
				zephir_check_call_status();
				ZEPHIR_INIT_ZVAL_NREF(_14);
				ZVAL_LONG(_14, (index + 1));
				zephir_update_property_this(this_ptr, SL("_index"), _14 TSRMLS_CC);
				zephir_update_property_this(this_ptr, SL("_inArguments"), (0) ? ZEPHIR_GLOBAL(global_true) : ZEPHIR_GLOBAL(global_false) TSRMLS_CC);
				ZEPHIR_INIT_ZVAL_NREF(_14);
				ZVAL_LONG(_14, 2);
				zephir_update_property_this(this_ptr, SL("_state"), _14 TSRMLS_CC);
				RETURN_MM_NULL();
			}
			if (ZEPHIR_IS_LONG(currentCh, ',')) {
				_14 = zephir_fetch_nproperty_this(this_ptr, SL("_buffer"), PH_NOISY_CC);
				if (zephir_is_true(_14)) {
					_17 = zephir_fetch_nproperty_this(this_ptr, SL("_buffer"), PH_NOISY_CC);
					ZEPHIR_INIT_NVAR(_15);
					ZVAL_LONG(_15, 12);
					ZEPHIR_CALL_METHOD(NULL, this_ptr, "_addtoken", &_16, _15, _17);
					zephir_check_call_status();
				} else {
					ZEPHIR_INIT_NVAR(_15);
					ZVAL_LONG(_15, 12);
					ZEPHIR_INIT_NVAR(_24);
					ZVAL_STRING(_24, "", ZEPHIR_TEMP_PARAM_COPY);
					ZEPHIR_CALL_METHOD(NULL, this_ptr, "_addtoken", &_16, _15, _24);
					zephir_check_temp_parameter(_24);
					zephir_check_call_status();
				}
				ZEPHIR_INIT_ZVAL_NREF(_18);
				ZVAL_LONG(_18, (index + 1));
				zephir_update_property_this(this_ptr, SL("_index"), _18 TSRMLS_CC);
				ZEPHIR_INIT_ZVAL_NREF(_18);
				ZVAL_STRING(_18, "", 1);
				zephir_update_property_this(this_ptr, SL("_buffer"), _18 TSRMLS_CC);
				RETURN_MM_NULL();
			}
			_20 = ZEPHIR_IS_LONG(currentCh, '"');
			if (!(_20)) {
				_20 = ZEPHIR_IS_LONG(currentCh, '\'');
			}
			if (_20) {
				ZEPHIR_INIT_ZVAL_NREF(_14);
				ZVAL_STRING(_14, "", 1);
				zephir_update_property_this(this_ptr, SL("_buffer"), _14 TSRMLS_CC);
				ZEPHIR_INIT_ZVAL_NREF(_14);
				ZVAL_LONG(_14, (index + 1));
				zephir_update_property_this(this_ptr, SL("_index"), _14 TSRMLS_CC);
				ZEPHIR_INIT_ZVAL_NREF(_14);
				ZVAL_LONG(_14, 3);
				zephir_update_property_this(this_ptr, SL("_state"), _14 TSRMLS_CC);
				zephir_update_property_this(this_ptr, SL("_strDelimiter"), currentCh TSRMLS_CC);
				RETURN_MM_NULL();
			}
			_21 = ZEPHIR_GE_LONG(currentCh, 'a');
			if (_21) {
				_21 = ZEPHIR_LE_LONG(currentCh, 'z');
			}
			_23 = _21;
			if (!(_23)) {
				_25 = ZEPHIR_GE_LONG(currentCh, 'A');
				if (_25) {
					_25 = ZEPHIR_LE_LONG(currentCh, 'Z');
				}
				_23 = _25;
			}
			_28 = _23;
			if (!(_28)) {
				_32 = ZEPHIR_GE_LONG(currentCh, '0');
				if (_32) {
					_32 = ZEPHIR_LE_LONG(currentCh, '9');
				}
				_28 = _32;
			}
			_33 = _28;
			if (!(_33)) {
				_33 = ZEPHIR_IS_LONG(currentCh, '_');
			}
			_34 = _33;
			if (!(_34)) {
				_34 = ZEPHIR_IS_LONG(currentCh, '.');
			}
			_35 = _34;
			if (!(_35)) {
				_35 = ZEPHIR_IS_LONG(currentCh, '[');
			}
			_36 = _35;
			if (!(_36)) {
				_36 = ZEPHIR_IS_LONG(currentCh, ']');
			}
			if (_36) {
				break;
			}
			ZEPHIR_CALL_FUNCTION(&_8, "ctype_space", &_19, currentCh);
			zephir_check_call_status();
			if (zephir_is_true(_8)) {
				ZEPHIR_INIT_ZVAL_NREF(_14);
				ZVAL_LONG(_14, (index + 1));
				zephir_update_property_this(this_ptr, SL("_index"), _14 TSRMLS_CC);
				RETURN_MM_NULL();
			}
			ZEPHIR_INIT_NVAR(_15);
			object_init_ex(_15, bolt_app_view_exception_ce);
			_14 = zephir_fetch_nproperty_this(this_ptr, SL("_file"), PH_NOISY_CC);
			_17 = zephir_fetch_nproperty_this(this_ptr, SL("_line"), PH_NOISY_CC);
			_18 = zephir_fetch_nproperty_this(this_ptr, SL("_line"), PH_NOISY_CC);
			_22 = zephir_fetch_nproperty_this(this_ptr, SL("_column"), PH_NOISY_CC);
			ZEPHIR_CALL_CE_STATIC(&_29, bolt_app_view_exception_ce, "geterrorhintfromstring", &_26, text, _18, _22);
			zephir_check_call_status();
			ZEPHIR_INIT_LNVAR(_27);
			ZEPHIR_CONCAT_SVSVSVSV(_27, "Unexpected character `", currentCh, "` in ", _14, " on line ", _17, "\n", _29);
			ZEPHIR_CALL_METHOD(NULL, _15, "__construct", NULL, _27);
			zephir_check_call_status();
			zephir_throw_exception_debug(_15, "bolt/app/view/Tokenizer.zep", 368 TSRMLS_CC);
			ZEPHIR_MM_RESTORE();
			return;
		}
		if (ZEPHIR_IS_LONG(_11, 3)) {
			_11 = zephir_fetch_nproperty_this(this_ptr, SL("_strDelimiter"), PH_NOISY_CC);
			_20 = ZEPHIR_IS_EQUAL(currentCh, _11);
			if (_20) {
				_20 = !ZEPHIR_IS_LONG(prevCh, '\\');
			}
			if (_20) {
				_12 = zephir_fetch_nproperty_this(this_ptr, SL("_inArray"), PH_NOISY_CC);
				_30 = zephir_fetch_nproperty_this(this_ptr, SL("_inArguments"), PH_NOISY_CC);
				if (zephir_is_true(_12)) {
					_31 = zephir_fetch_nproperty_this(this_ptr, SL("_strDelimiter"), PH_NOISY_CC);
					ZEPHIR_CALL_FUNCTION(&_8, "chr", &_37, _31);
					zephir_check_call_status();
					_38 = zephir_fetch_nproperty_this(this_ptr, SL("_buffer"), PH_NOISY_CC);
					_39 = zephir_fetch_nproperty_this(this_ptr, SL("_strDelimiter"), PH_NOISY_CC);
					ZEPHIR_CALL_FUNCTION(&_40, "chr", &_37, _39);
					zephir_check_call_status();
					ZEPHIR_INIT_VAR(_41);
					ZEPHIR_CONCAT_VVV(_41, _8, _38, _40);
					ZEPHIR_INIT_NVAR(_15);
					ZVAL_LONG(_15, 12);
					ZEPHIR_CALL_METHOD(NULL, this_ptr, "_addtoken", &_16, _15, _41);
					zephir_check_call_status();
					ZEPHIR_INIT_ZVAL_NREF(_42);
					ZVAL_LONG(_42, 8);
					zephir_update_property_this(this_ptr, SL("_state"), _42 TSRMLS_CC);
					if (ZEPHIR_IS_LONG(nextCh, ',')) {
						index++;
					}
				} else if (zephir_is_true(_30)) {
					_30 = zephir_fetch_nproperty_this(this_ptr, SL("_strDelimiter"), PH_NOISY_CC);
					ZEPHIR_CALL_FUNCTION(&_29, "chr", &_37, _30);
					zephir_check_call_status();
					_31 = zephir_fetch_nproperty_this(this_ptr, SL("_buffer"), PH_NOISY_CC);
					_38 = zephir_fetch_nproperty_this(this_ptr, SL("_strDelimiter"), PH_NOISY_CC);
					ZEPHIR_CALL_FUNCTION(&_40, "chr", &_37, _38);
					zephir_check_call_status();
					ZEPHIR_INIT_LNVAR(_41);
					ZEPHIR_CONCAT_VVV(_41, _29, _31, _40);
					ZEPHIR_INIT_NVAR(_15);
					ZVAL_LONG(_15, 12);
					ZEPHIR_CALL_METHOD(NULL, this_ptr, "_addtoken", &_16, _15, _41);
					zephir_check_call_status();
					ZEPHIR_INIT_ZVAL_NREF(_39);
					ZVAL_LONG(_39, 6);
					zephir_update_property_this(this_ptr, SL("_state"), _39 TSRMLS_CC);
					if (ZEPHIR_IS_LONG(nextCh, ',')) {
						index++;
					}
				} else {
					_30 = zephir_fetch_nproperty_this(this_ptr, SL("_strDelimiter"), PH_NOISY_CC);
					ZEPHIR_CALL_FUNCTION(&_29, "chr", &_37, _30);
					zephir_check_call_status();
					_31 = zephir_fetch_nproperty_this(this_ptr, SL("_buffer"), PH_NOISY_CC);
					_38 = zephir_fetch_nproperty_this(this_ptr, SL("_strDelimiter"), PH_NOISY_CC);
					ZEPHIR_CALL_FUNCTION(&_40, "chr", &_37, _38);
					zephir_check_call_status();
					ZEPHIR_INIT_LNVAR(_41);
					ZEPHIR_CONCAT_VVV(_41, _29, _31, _40);
					ZEPHIR_INIT_NVAR(_15);
					ZVAL_LONG(_15, 1);
					ZEPHIR_CALL_METHOD(NULL, this_ptr, "_addtoken", &_16, _15, _41);
					zephir_check_call_status();
					index = (index + 1);
					if (ZEPHIR_IS_LONG(nextCh, '|')) {
						ZEPHIR_INIT_ZVAL_NREF(_39);
						ZVAL_LONG(_39, 5);
						zephir_update_property_this(this_ptr, SL("_state"), _39 TSRMLS_CC);
					} else {
						ZEPHIR_INIT_ZVAL_NREF(_39);
						ZVAL_LONG(_39, 1);
						zephir_update_property_this(this_ptr, SL("_state"), _39 TSRMLS_CC);
					}
				}
				ZEPHIR_INIT_ZVAL_NREF(_30);
				ZVAL_STRING(_30, "", 1);
				zephir_update_property_this(this_ptr, SL("_buffer"), _30 TSRMLS_CC);
				ZEPHIR_INIT_ZVAL_NREF(_30);
				ZVAL_LONG(_30, (index + 1));
				zephir_update_property_this(this_ptr, SL("_index"), _30 TSRMLS_CC);
				RETURN_MM_NULL();
			}
			break;
		}
		if (ZEPHIR_IS_LONG(_11, 5)) {
			ZEPHIR_CALL_FUNCTION(&_8, "ctype_space", &_19, currentCh);
			zephir_check_call_status();
			if (zephir_is_true(_8)) {
				_11 = zephir_fetch_nproperty_this(this_ptr, SL("_buffer"), PH_NOISY_CC);
				ZEPHIR_INIT_NVAR(_15);
				ZVAL_LONG(_15, 8);
				ZEPHIR_CALL_METHOD(NULL, this_ptr, "_addtoken", &_16, _15, _11);
				zephir_check_call_status();
				ZEPHIR_INIT_ZVAL_NREF(_12);
				ZVAL_STRING(_12, "", 1);
				zephir_update_property_this(this_ptr, SL("_buffer"), _12 TSRMLS_CC);
				ZEPHIR_INIT_ZVAL_NREF(_12);
				ZVAL_LONG(_12, 1);
				zephir_update_property_this(this_ptr, SL("_state"), _12 TSRMLS_CC);
				ZEPHIR_INIT_ZVAL_NREF(_12);
				ZVAL_LONG(_12, (index + 1));
				zephir_update_property_this(this_ptr, SL("_index"), _12 TSRMLS_CC);
				RETURN_MM_NULL();
			}
			if (ZEPHIR_IS_LONG(currentCh, '|')) {
				_12 = zephir_fetch_nproperty_this(this_ptr, SL("_buffer"), PH_NOISY_CC);
				ZEPHIR_INIT_NVAR(_15);
				ZVAL_LONG(_15, 8);
				ZEPHIR_CALL_METHOD(NULL, this_ptr, "_addtoken", &_16, _15, _12);
				zephir_check_call_status();
				ZEPHIR_INIT_ZVAL_NREF(_14);
				ZVAL_STRING(_14, "", 1);
				zephir_update_property_this(this_ptr, SL("_buffer"), _14 TSRMLS_CC);
				ZEPHIR_INIT_ZVAL_NREF(_14);
				ZVAL_LONG(_14, (index + 1));
				zephir_update_property_this(this_ptr, SL("_index"), _14 TSRMLS_CC);
				RETURN_MM_NULL();
			}
			if (ZEPHIR_IS_LONG(currentCh, '(')) {
				_14 = zephir_fetch_nproperty_this(this_ptr, SL("_buffer"), PH_NOISY_CC);
				ZEPHIR_INIT_NVAR(_15);
				ZVAL_LONG(_15, 8);
				ZEPHIR_CALL_METHOD(NULL, this_ptr, "_addtoken", &_16, _15, _14);
				zephir_check_call_status();
				ZEPHIR_INIT_NVAR(_15);
				ZVAL_LONG(_15, 9);
				ZEPHIR_INIT_NVAR(_24);
				ZVAL_STRING(_24, "(", ZEPHIR_TEMP_PARAM_COPY);
				ZEPHIR_CALL_METHOD(NULL, this_ptr, "_addtoken", &_16, _15, _24);
				zephir_check_temp_parameter(_24);
				zephir_check_call_status();
				zephir_update_property_this(this_ptr, SL("_inArguments"), (1) ? ZEPHIR_GLOBAL(global_true) : ZEPHIR_GLOBAL(global_false) TSRMLS_CC);
				ZEPHIR_INIT_ZVAL_NREF(_17);
				ZVAL_LONG(_17, 6);
				zephir_update_property_this(this_ptr, SL("_state"), _17 TSRMLS_CC);
				ZEPHIR_INIT_ZVAL_NREF(_17);
				ZVAL_LONG(_17, (index + 1));
				zephir_update_property_this(this_ptr, SL("_index"), _17 TSRMLS_CC);
				ZEPHIR_INIT_ZVAL_NREF(_17);
				ZVAL_STRING(_17, "", 1);
				zephir_update_property_this(this_ptr, SL("_buffer"), _17 TSRMLS_CC);
				RETURN_MM_NULL();
			}
			_20 = ZEPHIR_GE_LONG(currentCh, 'a');
			if (_20) {
				_20 = ZEPHIR_LE_LONG(currentCh, 'z');
			}
			_21 = _20;
			if (!(_21)) {
				_23 = ZEPHIR_GE_LONG(currentCh, 'A');
				if (_23) {
					_23 = ZEPHIR_LE_LONG(currentCh, 'Z');
				}
				_21 = _23;
			}
			_25 = _21;
			if (!(_25)) {
				_28 = ZEPHIR_GE_LONG(currentCh, '0');
				if (_28) {
					_28 = ZEPHIR_LE_LONG(currentCh, '9');
				}
				_25 = _28;
			}
			_32 = _25;
			if (!(_32)) {
				_32 = ZEPHIR_IS_LONG(currentCh, '_');
			}
			if (_32) {
				break;
			}
			_14 = zephir_fetch_nproperty_this(this_ptr, SL("_token"), PH_NOISY_CC);
			if (ZEPHIR_IS_STRING(_14, "}}")) {
				_17 = zephir_fetch_nproperty_this(this_ptr, SL("_buffer"), PH_NOISY_CC);
				ZEPHIR_INIT_NVAR(_15);
				ZVAL_LONG(_15, 8);
				ZEPHIR_CALL_METHOD(NULL, this_ptr, "_addtoken", &_16, _15, _17);
				zephir_check_call_status();
				ZEPHIR_INIT_ZVAL_NREF(_18);
				ZVAL_STRING(_18, "", 1);
				zephir_update_property_this(this_ptr, SL("_buffer"), _18 TSRMLS_CC);
				ZEPHIR_INIT_ZVAL_NREF(_18);
				ZVAL_LONG(_18, 1);
				zephir_update_property_this(this_ptr, SL("_state"), _18 TSRMLS_CC);
				RETURN_MM_NULL();
			}
			ZEPHIR_INIT_NVAR(_15);
			object_init_ex(_15, bolt_app_view_exception_ce);
			ZEPHIR_CALL_FUNCTION(&_29, "chr", &_37, currentCh);
			zephir_check_call_status();
			_14 = zephir_fetch_nproperty_this(this_ptr, SL("_file"), PH_NOISY_CC);
			_17 = zephir_fetch_nproperty_this(this_ptr, SL("_line"), PH_NOISY_CC);
			_18 = zephir_fetch_nproperty_this(this_ptr, SL("_line"), PH_NOISY_CC);
			_22 = zephir_fetch_nproperty_this(this_ptr, SL("_column"), PH_NOISY_CC);
			ZEPHIR_CALL_CE_STATIC(&_40, bolt_app_view_exception_ce, "geterrorhintfromstring", &_26, text, _18, _22);
			zephir_check_call_status();
			ZEPHIR_INIT_LNVAR(_27);
			ZEPHIR_CONCAT_SVSVSVSV(_27, "Unexpected character `", _29, "` in ", _14, " on line ", _17, "\n", _40);
			ZEPHIR_CALL_METHOD(NULL, _15, "__construct", NULL, _27);
			zephir_check_call_status();
			zephir_throw_exception_debug(_15, "bolt/app/view/Tokenizer.zep", 443 TSRMLS_CC);
			ZEPHIR_MM_RESTORE();
			return;
		}
		if (ZEPHIR_IS_LONG(_11, 7)) {
			_11 = zephir_fetch_nproperty_this(this_ptr, SL("_token"), PH_NOISY_CC);
			if (ZEPHIR_IS_STRING(_11, "#}")) {
				_12 = zephir_fetch_nproperty_this(this_ptr, SL("_buffer"), PH_NOISY_CC);
				ZEPHIR_INIT_NVAR(_15);
				ZVAL_LONG(_15, 16);
				ZEPHIR_CALL_METHOD(NULL, this_ptr, "_addtoken", &_16, _15, _12);
				zephir_check_call_status();
				ZEPHIR_INIT_ZVAL_NREF(_30);
				ZVAL_STRING(_30, "", 1);
				zephir_update_property_this(this_ptr, SL("_buffer"), _30 TSRMLS_CC);
				_30 = zephir_fetch_nproperty_this(this_ptr, SL("_token"), PH_NOISY_CC);
				ZEPHIR_INIT_NVAR(_15);
				ZVAL_LONG(_15, 15);
				ZEPHIR_CALL_METHOD(NULL, this_ptr, "_addtoken", &_16, _15, _30);
				zephir_check_call_status();
				ZEPHIR_INIT_ZVAL_NREF(_31);
				ZVAL_LONG(_31, 0);
				zephir_update_property_this(this_ptr, SL("_state"), _31 TSRMLS_CC);
				ZEPHIR_INIT_ZVAL_NREF(_31);
				ZVAL_LONG(_31, (index + 2));
				zephir_update_property_this(this_ptr, SL("_index"), _31 TSRMLS_CC);
				RETURN_MM_NULL();
			}
			break;
		}
		if (ZEPHIR_IS_LONG(_11, 4)) {
			_11 = zephir_fetch_nproperty_this(this_ptr, SL("_token"), PH_NOISY_CC);
			if (ZEPHIR_IS_STRING(_11, "!}")) {
				_12 = zephir_fetch_nproperty_this(this_ptr, SL("_buffer"), PH_NOISY_CC);
				ZEPHIR_INIT_NVAR(_15);
				ZVAL_LONG(_15, 13);
				ZEPHIR_CALL_METHOD(NULL, this_ptr, "_addtoken", &_16, _15, _12);
				zephir_check_call_status();
				ZEPHIR_INIT_ZVAL_NREF(_14);
				ZVAL_STRING(_14, "", 1);
				zephir_update_property_this(this_ptr, SL("_buffer"), _14 TSRMLS_CC);
				_14 = zephir_fetch_nproperty_this(this_ptr, SL("_token"), PH_NOISY_CC);
				ZEPHIR_INIT_NVAR(_15);
				ZVAL_LONG(_15, 7);
				ZEPHIR_CALL_METHOD(NULL, this_ptr, "_addtoken", &_16, _15, _14);
				zephir_check_call_status();
				ZEPHIR_INIT_ZVAL_NREF(_17);
				ZVAL_LONG(_17, 0);
				zephir_update_property_this(this_ptr, SL("_state"), _17 TSRMLS_CC);
				ZEPHIR_INIT_ZVAL_NREF(_17);
				ZVAL_LONG(_17, (index + 2));
				zephir_update_property_this(this_ptr, SL("_index"), _17 TSRMLS_CC);
				RETURN_MM_NULL();
			}
			break;
		}
		if (ZEPHIR_IS_LONG(_11, 8)) {
			if (ZEPHIR_IS_LONG(currentCh, ']')) {
				_11 = zephir_fetch_nproperty_this(this_ptr, SL("_buffer"), PH_NOISY_CC);
				if (!ZEPHIR_IS_STRING(_11, "")) {
					_12 = zephir_fetch_nproperty_this(this_ptr, SL("_buffer"), PH_NOISY_CC);
					ZEPHIR_SINIT_NVAR(_6);
					ZVAL_STRING(&_6, "]", 0);
					ZEPHIR_CALL_FUNCTION(&_8, "substr_count", &_43, _12, &_6);
					zephir_check_call_status();
					_14 = zephir_fetch_nproperty_this(this_ptr, SL("_buffer"), PH_NOISY_CC);
					ZEPHIR_SINIT_NVAR(_6);
					ZVAL_STRING(&_6, "[", 0);
					ZEPHIR_CALL_FUNCTION(&_44, "substr_count", &_43, _14, &_6);
					zephir_check_call_status();
					if (!ZEPHIR_IS_EQUAL(_8, _44)) {
						RETURN_MM_NULL();
					}
				}
				_17 = zephir_fetch_nproperty_this(this_ptr, SL("_buffer"), PH_NOISY_CC);
				if (zephir_is_true(_17)) {
					_18 = zephir_fetch_nproperty_this(this_ptr, SL("_buffer"), PH_NOISY_CC);
					ZEPHIR_INIT_NVAR(_15);
					ZVAL_LONG(_15, 12);
					ZEPHIR_CALL_METHOD(NULL, this_ptr, "_addtoken", &_16, _15, _18);
					zephir_check_call_status();
					ZEPHIR_INIT_ZVAL_NREF(_22);
					ZVAL_STRING(_22, "", 1);
					zephir_update_property_this(this_ptr, SL("_buffer"), _22 TSRMLS_CC);
				}
				ZEPHIR_INIT_NVAR(_15);
				ZVAL_LONG(_15, 18);
				ZEPHIR_INIT_NVAR(_24);
				ZVAL_STRING(_24, "]", ZEPHIR_TEMP_PARAM_COPY);
				ZEPHIR_CALL_METHOD(NULL, this_ptr, "_addtoken", &_16, _15, _24);
				zephir_check_temp_parameter(_24);
				zephir_check_call_status();
				ZEPHIR_INIT_ZVAL_NREF(_22);
				ZVAL_LONG(_22, (index + 1));
				zephir_update_property_this(this_ptr, SL("_index"), _22 TSRMLS_CC);
				_22 = zephir_fetch_nproperty_this(this_ptr, SL("_arrayLevel"), PH_NOISY_CC);
				if (ZEPHIR_IS_LONG(_22, 1)) {
					zephir_update_property_this(this_ptr, SL("_inArray"), (0) ? ZEPHIR_GLOBAL(global_true) : ZEPHIR_GLOBAL(global_false) TSRMLS_CC);
					ZEPHIR_INIT_ZVAL_NREF(_30);
					ZVAL_LONG(_30, 0);
					zephir_update_property_this(this_ptr, SL("_arrayLevel"), _30 TSRMLS_CC);
					ZEPHIR_INIT_ZVAL_NREF(_30);
					ZVAL_LONG(_30, 2);
					zephir_update_property_this(this_ptr, SL("_state"), _30 TSRMLS_CC);
				} else {
					_30 = zephir_fetch_nproperty_this(this_ptr, SL("_arrayLevel"), PH_NOISY_CC);
					ZEPHIR_INIT_ZVAL_NREF(_31);
					ZVAL_LONG(_31, (zephir_get_numberval(_30) - 1));
					zephir_update_property_this(this_ptr, SL("_arrayLevel"), _31 TSRMLS_CC);
				}
				RETURN_MM_NULL();
			}
			_20 = ZEPHIR_IS_LONG(currentCh, '[');
			if (_20) {
				_14 = zephir_fetch_nproperty_this(this_ptr, SL("_buffer"), PH_NOISY_CC);
				_20 = ZEPHIR_IS_STRING(_14, "");
			}
			if (_20) {
				ZEPHIR_INIT_NVAR(_15);
				ZVAL_LONG(_15, 17);
				ZEPHIR_INIT_NVAR(_24);
				ZVAL_STRING(_24, "[", ZEPHIR_TEMP_PARAM_COPY);
				ZEPHIR_CALL_METHOD(NULL, this_ptr, "_addtoken", &_16, _15, _24);
				zephir_check_temp_parameter(_24);
				zephir_check_call_status();
				_17 = zephir_fetch_nproperty_this(this_ptr, SL("_arrayLevel"), PH_NOISY_CC);
				ZEPHIR_INIT_ZVAL_NREF(_18);
				ZVAL_LONG(_18, (zephir_get_numberval(_17) + 1));
				zephir_update_property_this(this_ptr, SL("_arrayLevel"), _18 TSRMLS_CC);
				ZEPHIR_INIT_ZVAL_NREF(_18);
				ZVAL_LONG(_18, (index + 1));
				zephir_update_property_this(this_ptr, SL("_index"), _18 TSRMLS_CC);
				RETURN_MM_NULL();
			}
			if (ZEPHIR_IS_LONG(currentCh, ',')) {
				zephir_update_property_this(this_ptr, SL("_hasArgumentNameAlready"), (0) ? ZEPHIR_GLOBAL(global_true) : ZEPHIR_GLOBAL(global_false) TSRMLS_CC);
				_14 = zephir_fetch_nproperty_this(this_ptr, SL("_buffer"), PH_NOISY_CC);
				if (zephir_is_true(_14)) {
					_17 = zephir_fetch_nproperty_this(this_ptr, SL("_buffer"), PH_NOISY_CC);
					ZEPHIR_INIT_NVAR(_15);
					ZVAL_LONG(_15, 12);
					ZEPHIR_CALL_METHOD(NULL, this_ptr, "_addtoken", &_16, _15, _17);
					zephir_check_call_status();
				} else {
					tmpIndex = index;
					ZEPHIR_SINIT_VAR(tmp);
					ZVAL_LONG(&tmp, 0);
					while (1) {
						if (!(tmpIndex > 0)) {
							break;
						}
						_5 = ZEPHIR_STRING_OFFSET(text, tmpIndex);
						if (_5 == ',') {
							_45 = (zephir_get_numberval(&tmp) + 1);
							ZEPHIR_SINIT_NVAR(tmp);
							ZVAL_LONG(&tmp, _45);
						}
						_10 = ZEPHIR_STRING_OFFSET(text, tmpIndex);
						if (_10 == ']') {
							ZEPHIR_INIT_ZVAL_NREF(_18);
							ZVAL_LONG(_18, (index + 1));
							zephir_update_property_this(this_ptr, SL("_index"), _18 TSRMLS_CC);
							break;
						} else if (ZEPHIR_IS_LONG(&tmp, 2)) {
							ZEPHIR_INIT_NVAR(_15);
							ZVAL_LONG(_15, 12);
							ZEPHIR_INIT_NVAR(_24);
							ZVAL_STRING(_24, "null", ZEPHIR_TEMP_PARAM_COPY);
							ZEPHIR_CALL_METHOD(NULL, this_ptr, "_addtoken", &_16, _15, _24);
							zephir_check_temp_parameter(_24);
							zephir_check_call_status();
							break;
						}
						tmpIndex--;
					}
					tmpIndex = 0;
					ZEPHIR_SINIT_NVAR(tmp);
					ZVAL_NULL(&tmp);
				}
				ZEPHIR_INIT_ZVAL_NREF(_18);
				ZVAL_LONG(_18, (index + 1));
				zephir_update_property_this(this_ptr, SL("_index"), _18 TSRMLS_CC);
				ZEPHIR_INIT_ZVAL_NREF(_18);
				ZVAL_STRING(_18, "", 1);
				zephir_update_property_this(this_ptr, SL("_buffer"), _18 TSRMLS_CC);
				RETURN_MM_NULL();
			}
			if (ZEPHIR_IS_LONG(currentCh, ':')) {
				_14 = zephir_fetch_nproperty_this(this_ptr, SL("_hasArgumentNameAlready"), PH_NOISY_CC);
				if (zephir_is_true(_14)) {
					ZEPHIR_INIT_NVAR(_15);
					object_init_ex(_15, bolt_app_view_exception_ce);
					_17 = zephir_fetch_nproperty_this(this_ptr, SL("_file"), PH_NOISY_CC);
					_18 = zephir_fetch_nproperty_this(this_ptr, SL("_line"), PH_NOISY_CC);
					_22 = zephir_fetch_nproperty_this(this_ptr, SL("_line"), PH_NOISY_CC);
					_30 = zephir_fetch_nproperty_this(this_ptr, SL("_column"), PH_NOISY_CC);
					ZEPHIR_CALL_CE_STATIC(&_29, bolt_app_view_exception_ce, "geterrorhintfromstring", &_26, text, _22, _30);
					zephir_check_call_status();
					ZEPHIR_INIT_LNVAR(_27);
					ZEPHIR_CONCAT_SVSVSV(_27, "Argument has name already. Unexpected token `:` in ", _17, " on line ", _18, "\n", _29);
					ZEPHIR_CALL_METHOD(NULL, _15, "__construct", NULL, _27);
					zephir_check_call_status();
					zephir_throw_exception_debug(_15, "bolt/app/view/Tokenizer.zep", 534 TSRMLS_CC);
					ZEPHIR_MM_RESTORE();
					return;
				}
				_30 = zephir_fetch_nproperty_this(this_ptr, SL("_buffer"), PH_NOISY_CC);
				if (zephir_is_true(_30)) {
					_31 = zephir_fetch_nproperty_this(this_ptr, SL("_buffer"), PH_NOISY_CC);
					ZEPHIR_INIT_NVAR(_15);
					ZVAL_LONG(_15, 19);
					ZEPHIR_CALL_METHOD(NULL, this_ptr, "_addtoken", &_16, _15, _31);
					zephir_check_call_status();
					zephir_update_property_this(this_ptr, SL("_hasArgumentNameAlready"), (1) ? ZEPHIR_GLOBAL(global_true) : ZEPHIR_GLOBAL(global_false) TSRMLS_CC);
					ZEPHIR_INIT_ZVAL_NREF(_38);
					ZVAL_STRING(_38, "", 1);
					zephir_update_property_this(this_ptr, SL("_buffer"), _38 TSRMLS_CC);
					ZEPHIR_INIT_ZVAL_NREF(_38);
					ZVAL_LONG(_38, (index + 1));
					zephir_update_property_this(this_ptr, SL("_index"), _38 TSRMLS_CC);
					RETURN_MM_NULL();
				}
			}
			_21 = ZEPHIR_IS_LONG(currentCh, '"');
			if (!(_21)) {
				_21 = ZEPHIR_IS_LONG(currentCh, '\'');
			}
			if (_21) {
				ZEPHIR_INIT_ZVAL_NREF(_14);
				ZVAL_STRING(_14, "", 1);
				zephir_update_property_this(this_ptr, SL("_buffer"), _14 TSRMLS_CC);
				ZEPHIR_INIT_ZVAL_NREF(_14);
				ZVAL_LONG(_14, (index + 1));
				zephir_update_property_this(this_ptr, SL("_index"), _14 TSRMLS_CC);
				ZEPHIR_INIT_ZVAL_NREF(_14);
				ZVAL_LONG(_14, 3);
				zephir_update_property_this(this_ptr, SL("_state"), _14 TSRMLS_CC);
				zephir_update_property_this(this_ptr, SL("_strDelimiter"), currentCh TSRMLS_CC);
				RETURN_MM_NULL();
			}
			ZEPHIR_CALL_FUNCTION(&_29, "ctype_space", &_19, currentCh);
			zephir_check_call_status();
			if (zephir_is_true(_29)) {
				ZEPHIR_INIT_ZVAL_NREF(_14);
				ZVAL_LONG(_14, (index + 1));
				zephir_update_property_this(this_ptr, SL("_index"), _14 TSRMLS_CC);
				RETURN_MM_NULL();
			}
			_14 = zephir_fetch_nproperty_this(this_ptr, SL("_token"), PH_NOISY_CC);
			_23 = ZEPHIR_IS_STRING(_14, "}}");
			if (!(_23)) {
				_17 = zephir_fetch_nproperty_this(this_ptr, SL("_token"), PH_NOISY_CC);
				_23 = ZEPHIR_IS_STRING(_17, "%}");
			}
			if (_23) {
				ZEPHIR_INIT_NVAR(_15);
				object_init_ex(_15, bolt_app_view_exception_ce);
				_18 = zephir_fetch_nproperty_this(this_ptr, SL("_file"), PH_NOISY_CC);
				_22 = zephir_fetch_nproperty_this(this_ptr, SL("_line"), PH_NOISY_CC);
				_30 = zephir_fetch_nproperty_this(this_ptr, SL("_line"), PH_NOISY_CC);
				_31 = zephir_fetch_nproperty_this(this_ptr, SL("_column"), PH_NOISY_CC);
				ZEPHIR_CALL_CE_STATIC(&_40, bolt_app_view_exception_ce, "geterrorhintfromstring", &_26, text, _30, _31);
				zephir_check_call_status();
				ZEPHIR_INIT_LNVAR(_27);
				ZEPHIR_CONCAT_SVSVSV(_27, "Unexpected end of input. Expected `]` in ", _18, " on line ", _22, "\n", _40);
				ZEPHIR_CALL_METHOD(NULL, _15, "__construct", NULL, _27);
				zephir_check_call_status();
				zephir_throw_exception_debug(_15, "bolt/app/view/Tokenizer.zep", 559 TSRMLS_CC);
				ZEPHIR_MM_RESTORE();
				return;
			}
			break;
		}
	} while(0);

	_11 = zephir_fetch_nproperty_this(this_ptr, SL("_buffer"), PH_NOISY_CC);
	ZEPHIR_SINIT_NVAR(_6);
	ZVAL_LONG(&_6, index);
	ZEPHIR_SINIT_NVAR(_7);
	ZVAL_LONG(&_7, 1);
	ZEPHIR_CALL_FUNCTION(&_8, "substr", &_9, text, &_6, &_7);
	zephir_check_call_status();
	ZEPHIR_INIT_LNVAR(_27);
	ZEPHIR_CONCAT_VV(_27, _11, _8);
	zephir_update_property_this(this_ptr, SL("_buffer"), _27 TSRMLS_CC);
	ZEPHIR_INIT_ZVAL_NREF(_12);
	ZVAL_LONG(_12, (index + 1));
	zephir_update_property_this(this_ptr, SL("_index"), _12 TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

