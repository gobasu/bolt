
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
#include "kernel/object.h"
#include "kernel/exception.h"
#include "kernel/memory.h"
#include "kernel/array.h"
#include "kernel/fcall.h"
#include "kernel/operators.h"
#include "kernel/hash.h"
#include "kernel/string.h"
#include "kernel/concat.h"
#include "kernel/variables.h"

ZEPHIR_INIT_CLASS(Bolt_App_View_Compiler) {

	ZEPHIR_REGISTER_CLASS(Bolt\\App\\View, Compiler, bolt, app_view_compiler, bolt_app_view_compiler_method_entry, 0);

	zend_declare_property_null(bolt_app_view_compiler_ce, SL("_parser"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(bolt_app_view_compiler_ce, SL("_output"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_string(bolt_app_view_compiler_ce, SL("_file"), "string::", ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(bolt_app_view_compiler_ce, SL("_tree"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(bolt_app_view_compiler_ce, SL("_elements"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(bolt_app_view_compiler_ce, SL("_buffer"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_string(bolt_app_view_compiler_ce, SL("_extends"), "\\Bolt\\App\\View\\Template", ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_string(bolt_app_view_compiler_ce, SL("_main"), "", ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(bolt_app_view_compiler_ce, SL("_blocks"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(bolt_app_view_compiler_ce, SL("_loops"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(bolt_app_view_compiler_ce, SL("_loopVariables"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_string(bolt_app_view_compiler_ce, SL("_currentBlock"), "#", ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(bolt_app_view_compiler_ce, SL("_dependencies"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(bolt_app_view_compiler_ce, SL("_expressionsHandlers"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(bolt_app_view_compiler_ce, SL("_elementsHandlers"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_class_constant_string(bolt_app_view_compiler_ce, SL("VARNAME_REGEX"), "/[a-z]([a-z0-9_]+)?/is" TSRMLS_CC);

	return SUCCESS;

}

PHP_METHOD(Bolt_App_View_Compiler, __construct) {

	zval *_0, *_3;
	zval *parser, *file = NULL, *_1 = NULL, *_2, *_4, *_5, *_6;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &parser, &file);

	if (!file) {
		ZEPHIR_INIT_VAR(file);
		ZVAL_STRING(file, "string::", 1);
	}


	if (!(zephir_instance_of_ev(parser, bolt_app_view_parser_ce TSRMLS_CC))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_InvalidArgumentException, "Parameter 'parser' must be an instance of 'Bolt\\App\\View\\Parser'", "", 0);
		return;
	}
	ZEPHIR_INIT_VAR(_0);
	array_init_size(_0, 3);
	ZEPHIR_INIT_VAR(_1);
	array_init(_1);
	zephir_array_update_string(&_0, SL("open"), &_1, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(_1);
	array_init(_1);
	zephir_array_update_string(&_0, SL("close"), &_1, PH_COPY | PH_SEPARATE);
	zephir_update_property_this(this_ptr, SL("_elementsHandlers"), _0 TSRMLS_CC);
	ZEPHIR_INIT_NVAR(_1);
	array_init(_1);
	zephir_update_property_this(this_ptr, SL("_expressionsHandlers"), _1 TSRMLS_CC);
	ZEPHIR_INIT_VAR(_2);
	array_init(_2);
	zephir_update_property_this(this_ptr, SL("_dependencies"), _2 TSRMLS_CC);
	ZEPHIR_INIT_VAR(_3);
	array_init_size(_3, 8);
	zephir_array_update_string(&_3, SL("index"), &ZEPHIR_GLOBAL(global_true), PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&_3, SL("key"), &ZEPHIR_GLOBAL(global_true), PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&_3, SL("last"), &ZEPHIR_GLOBAL(global_true), PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&_3, SL("first"), &ZEPHIR_GLOBAL(global_true), PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&_3, SL("length"), &ZEPHIR_GLOBAL(global_true), PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&_3, SL("item"), &ZEPHIR_GLOBAL(global_true), PH_COPY | PH_SEPARATE);
	zephir_update_property_this(this_ptr, SL("_loopVariables"), _3 TSRMLS_CC);
	ZEPHIR_INIT_VAR(_4);
	array_init(_4);
	zephir_update_property_this(this_ptr, SL("_loops"), _4 TSRMLS_CC);
	ZEPHIR_INIT_VAR(_5);
	array_init(_5);
	zephir_update_property_this(this_ptr, SL("_blocks"), _5 TSRMLS_CC);
	ZEPHIR_INIT_VAR(_6);
	array_init(_6);
	zephir_update_property_this(this_ptr, SL("_elements"), _6 TSRMLS_CC);
	zephir_update_property_this(this_ptr, SL("_parser"), parser TSRMLS_CC);
	zephir_update_property_this(this_ptr, SL("_file"), file TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Bolt_App_View_Compiler, compile) {

	zval *_3, *_5, *_6, *_7, *_8, *_9, *_11, *_12, *_13, *_14, *_15, *_16, *_17, *_18;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *_0, *_1 = NULL, *_2, *_4 = NULL, *_10 = NULL;

	ZEPHIR_MM_GROW();

	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_parser"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(&_1, _0, "parse", NULL);
	zephir_check_call_status();
	zephir_update_property_this(this_ptr, SL("_tree"), _1 TSRMLS_CC);
	ZEPHIR_INIT_ZVAL_NREF(_2);
	ZVAL_STRING(_2, "", 1);
	zephir_update_property_this(this_ptr, SL("_output"), _2 TSRMLS_CC);
	ZEPHIR_INIT_ZVAL_NREF(_2);
	ZVAL_STRING(_2, "", 1);
	zephir_update_property_this(this_ptr, SL("_buffer"), _2 TSRMLS_CC);
	ZEPHIR_INIT_VAR(_3);
	array_init_size(_3, 3);
	zephir_array_fast_append(_3, this_ptr);
	ZEPHIR_INIT_VAR(_4);
	ZVAL_STRING(_4, "_compileParent", 1);
	zephir_array_fast_append(_3, _4);
	ZEPHIR_INIT_NVAR(_4);
	ZVAL_STRING(_4, "parent", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "addexpressionhandler", NULL, _4, _3);
	zephir_check_temp_parameter(_4);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(_5);
	array_init_size(_5, 3);
	zephir_array_fast_append(_5, this_ptr);
	ZEPHIR_INIT_NVAR(_4);
	ZVAL_STRING(_4, "_compileContinue", 1);
	zephir_array_fast_append(_5, _4);
	ZEPHIR_INIT_NVAR(_4);
	ZVAL_STRING(_4, "continue", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "addexpressionhandler", NULL, _4, _5);
	zephir_check_temp_parameter(_4);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(_6);
	array_init_size(_6, 3);
	zephir_array_fast_append(_6, this_ptr);
	ZEPHIR_INIT_NVAR(_4);
	ZVAL_STRING(_4, "_compileBreak", 1);
	zephir_array_fast_append(_6, _4);
	ZEPHIR_INIT_NVAR(_4);
	ZVAL_STRING(_4, "break", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "addexpressionhandler", NULL, _4, _6);
	zephir_check_temp_parameter(_4);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(_7);
	array_init_size(_7, 3);
	zephir_array_fast_append(_7, this_ptr);
	ZEPHIR_INIT_NVAR(_4);
	ZVAL_STRING(_4, "_compileI18n", 1);
	zephir_array_fast_append(_7, _4);
	ZEPHIR_INIT_NVAR(_4);
	ZVAL_STRING(_4, "_", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "addexpressionhandler", NULL, _4, _7);
	zephir_check_temp_parameter(_4);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(_8);
	array_init_size(_8, 3);
	zephir_array_fast_append(_8, this_ptr);
	ZEPHIR_INIT_NVAR(_4);
	ZVAL_STRING(_4, "_compileBlock", 1);
	zephir_array_fast_append(_8, _4);
	ZEPHIR_INIT_VAR(_9);
	array_init_size(_9, 3);
	zephir_array_fast_append(_9, this_ptr);
	ZEPHIR_INIT_NVAR(_4);
	ZVAL_STRING(_4, "_compileEndBlock", 1);
	zephir_array_fast_append(_9, _4);
	ZEPHIR_INIT_NVAR(_4);
	ZVAL_STRING(_4, "block", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_INIT_VAR(_10);
	ZVAL_STRING(_10, "endblock", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "addelementhandler", NULL, _4, _8, _10, _9);
	zephir_check_temp_parameter(_4);
	zephir_check_temp_parameter(_10);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(_11);
	array_init_size(_11, 3);
	zephir_array_fast_append(_11, this_ptr);
	ZEPHIR_INIT_NVAR(_4);
	ZVAL_STRING(_4, "_compileIf", 1);
	zephir_array_fast_append(_11, _4);
	ZEPHIR_INIT_VAR(_12);
	array_init_size(_12, 3);
	zephir_array_fast_append(_12, this_ptr);
	ZEPHIR_INIT_NVAR(_4);
	ZVAL_STRING(_4, "_compileEndIf", 1);
	zephir_array_fast_append(_12, _4);
	ZEPHIR_INIT_NVAR(_4);
	ZVAL_STRING(_4, "if", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_INIT_NVAR(_10);
	ZVAL_STRING(_10, "endif", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "addelementhandler", NULL, _4, _11, _10, _12);
	zephir_check_temp_parameter(_4);
	zephir_check_temp_parameter(_10);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(_13);
	array_init_size(_13, 3);
	zephir_array_fast_append(_13, this_ptr);
	ZEPHIR_INIT_NVAR(_4);
	ZVAL_STRING(_4, "_compileElse", 1);
	zephir_array_fast_append(_13, _4);
	ZEPHIR_INIT_NVAR(_4);
	ZVAL_STRING(_4, "else", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "addelementhandler", NULL, _4, _13);
	zephir_check_temp_parameter(_4);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(_14);
	array_init_size(_14, 3);
	zephir_array_fast_append(_14, this_ptr);
	ZEPHIR_INIT_NVAR(_4);
	ZVAL_STRING(_4, "_compileFor", 1);
	zephir_array_fast_append(_14, _4);
	ZEPHIR_INIT_VAR(_15);
	array_init_size(_15, 3);
	zephir_array_fast_append(_15, this_ptr);
	ZEPHIR_INIT_NVAR(_4);
	ZVAL_STRING(_4, "_compileEndFor", 1);
	zephir_array_fast_append(_15, _4);
	ZEPHIR_INIT_NVAR(_4);
	ZVAL_STRING(_4, "for", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_INIT_NVAR(_10);
	ZVAL_STRING(_10, "endfor", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "addelementhandler", NULL, _4, _14, _10, _15);
	zephir_check_temp_parameter(_4);
	zephir_check_temp_parameter(_10);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(_16);
	array_init_size(_16, 3);
	zephir_array_fast_append(_16, this_ptr);
	ZEPHIR_INIT_NVAR(_4);
	ZVAL_STRING(_4, "_compileInclude", 1);
	zephir_array_fast_append(_16, _4);
	ZEPHIR_INIT_NVAR(_4);
	ZVAL_STRING(_4, "include", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "addelementhandler", NULL, _4, _16);
	zephir_check_temp_parameter(_4);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(_17);
	array_init_size(_17, 3);
	zephir_array_fast_append(_17, this_ptr);
	ZEPHIR_INIT_NVAR(_4);
	ZVAL_STRING(_4, "_compileExtend", 1);
	zephir_array_fast_append(_17, _4);
	ZEPHIR_INIT_NVAR(_4);
	ZVAL_STRING(_4, "extends", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "addelementhandler", NULL, _4, _17);
	zephir_check_temp_parameter(_4);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(_18);
	array_init_size(_18, 3);
	zephir_array_fast_append(_18, this_ptr);
	ZEPHIR_INIT_NVAR(_4);
	ZVAL_STRING(_4, "_compileExtend", 1);
	zephir_array_fast_append(_18, _4);
	ZEPHIR_INIT_NVAR(_4);
	ZVAL_STRING(_4, "extend", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "addelementhandler", NULL, _4, _18);
	zephir_check_temp_parameter(_4);
	zephir_check_call_status();
	_2 = zephir_fetch_nproperty_this(this_ptr, SL("_tree"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "_compilenode", NULL, _2);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Bolt_App_View_Compiler, addExpressionHandler) {

	zval *name_param = NULL, *handler;
	zval *name = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &name_param, &handler);

	zephir_get_strval(name, name_param);


	zephir_update_property_array(this_ptr, SL("_expressionsHandlers"), name, handler TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Bolt_App_View_Compiler, addElementHandler) {

	zval *open_param = NULL, *openHandler, *close_param = NULL, *closeHandler = NULL;
	zval *open = NULL, *close = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 2, &open_param, &openHandler, &close_param, &closeHandler);

	zephir_get_strval(open, open_param);
	if (!close_param) {
		ZEPHIR_INIT_VAR(close);
		ZVAL_EMPTY_STRING(close);
	} else {
		zephir_get_strval(close, close_param);
	}
	if (!closeHandler) {
		closeHandler = ZEPHIR_GLOBAL(global_null);
	}


	zephir_update_property_array_multi(this_ptr, SL("_elementsHandlers"), &openHandler TSRMLS_CC, SL("sz"), 3, SL("open"), open);
	if (!ZEPHIR_IS_STRING(close, "")) {
		zephir_update_property_array_multi(this_ptr, SL("_elementsHandlers"), &closeHandler TSRMLS_CC, SL("sz"), 3, SL("close"), close);
	}
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Bolt_App_View_Compiler, _compileNode) {

	zephir_fcall_cache_entry *_6 = NULL;
	HashTable *_4;
	HashPosition _3;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *node, *child = NULL, *_0 = NULL, *_1 = NULL, *_2 = NULL, **_5;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &node);



	if (!(zephir_instance_of_ev(node, bolt_app_view_parser_node_ce TSRMLS_CC))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_InvalidArgumentException, "Parameter 'node' must be an instance of 'Bolt\\App\\View\\Parser\\Node'", "", 0);
		return;
	}
	ZEPHIR_CALL_METHOD(&_0, node, "gettype", NULL);
	zephir_check_call_status();
	do {
		if (ZEPHIR_IS_LONG(_0, -1)) {
			break;
		}
		if (ZEPHIR_IS_LONG(_0, 0)) {
			ZEPHIR_CALL_METHOD(NULL, this_ptr, "_compiletext", NULL, node);
			zephir_check_call_status();
			break;
		}
		if (ZEPHIR_IS_LONG(_0, 1)) {
			ZEPHIR_CALL_METHOD(NULL, this_ptr, "_compileelement", NULL, node);
			zephir_check_call_status();
			break;
		}
		if (ZEPHIR_IS_LONG(_0, 2)) {
			ZEPHIR_CALL_METHOD(NULL, this_ptr, "_compileexpression", NULL, node);
			zephir_check_call_status();
			break;
		}
	} while(0);

	ZEPHIR_CALL_METHOD(&_1, node, "haschildren", NULL);
	zephir_check_call_status();
	if (zephir_is_true(_1)) {
		ZEPHIR_CALL_METHOD(&_2, node, "getchildren", NULL);
		zephir_check_call_status();
		zephir_is_iterable(_2, &_4, &_3, 0, 0, "bolt/app/view/Compiler.zep", 92);
		for (
		  ; zephir_hash_get_current_data_ex(_4, (void**) &_5, &_3) == SUCCESS
		  ; zephir_hash_move_forward_ex(_4, &_3)
		) {
			ZEPHIR_GET_HVALUE(child, _5);
			ZEPHIR_CALL_METHOD(NULL, this_ptr, "_compilenode", &_6, child);
			zephir_check_call_status();
		}
	}
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Bolt_App_View_Compiler, _compileText) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *node, *str = NULL, *_0, _1, _2;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &node);



	if (!(zephir_instance_of_ev(node, bolt_app_view_parser_node_ce TSRMLS_CC))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_InvalidArgumentException, "Parameter 'node' must be an instance of 'Bolt\\App\\View\\Parser\\Node'", "", 0);
		return;
	}
	ZEPHIR_CALL_METHOD(&str, node, "getvalue", NULL);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(_0);
	ZEPHIR_SINIT_VAR(_1);
	ZVAL_STRING(&_1, "<?", 0);
	ZEPHIR_SINIT_VAR(_2);
	ZVAL_STRING(&_2, "&lt;?", 0);
	zephir_fast_str_replace(_0, &_1, &_2, str TSRMLS_CC);
	ZEPHIR_CPY_WRT(str, _0);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "addtoblock", NULL, str);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Bolt_App_View_Compiler, addToBlock) {

	zval *str_param = NULL, *_0, *_1, *_2 = NULL, *_3, *_4, *_5, *_6 = NULL, *_7;
	zval *str = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &str_param);

	zephir_get_strval(str, str_param);


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_currentBlock"), PH_NOISY_CC);
	if (ZEPHIR_IS_STRING(_0, "#")) {
		_1 = zephir_fetch_nproperty_this(this_ptr, SL("_main"), PH_NOISY_CC);
		ZEPHIR_INIT_VAR(_2);
		ZEPHIR_CONCAT_VV(_2, _1, str);
		zephir_update_property_this(this_ptr, SL("_main"), _2 TSRMLS_CC);
	} else {
		_1 = zephir_fetch_nproperty_this(this_ptr, SL("_blocks"), PH_NOISY_CC);
		_3 = zephir_fetch_nproperty_this(this_ptr, SL("_currentBlock"), PH_NOISY_CC);
		if (zephir_array_isset(_1, _3)) {
			_4 = zephir_fetch_nproperty_this(this_ptr, SL("_blocks"), PH_NOISY_CC);
			ZEPHIR_OBS_VAR(_6);
			zephir_read_property_this(&_6, this_ptr, SL("_currentBlock"), PH_NOISY_CC);
			zephir_array_fetch(&_5, _4, _6, PH_NOISY | PH_READONLY, "bolt/app/view/Compiler.zep", 109 TSRMLS_CC);
			ZEPHIR_INIT_LNVAR(_2);
			ZEPHIR_CONCAT_VV(_2, _5, str);
			ZEPHIR_OBS_VAR(_7);
			zephir_read_property_this(&_7, this_ptr, SL("_currentBlock"), PH_NOISY_CC);
			zephir_update_property_array(this_ptr, SL("_blocks"), _7, _2 TSRMLS_CC);
		} else {
			ZEPHIR_OBS_NVAR(_6);
			zephir_read_property_this(&_6, this_ptr, SL("_currentBlock"), PH_NOISY_CC);
			zephir_update_property_array(this_ptr, SL("_blocks"), _6, str TSRMLS_CC);
		}
	}
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Bolt_App_View_Compiler, addToMain) {

	zval *str_param = NULL, *_0, *_1;
	zval *str = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &str_param);

	zephir_get_strval(str, str_param);


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_main"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(_1);
	ZEPHIR_CONCAT_VV(_1, _0, str);
	zephir_update_property_this(this_ptr, SL("_main"), _1 TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Bolt_App_View_Compiler, getCurrentLoop) {

	int ZEPHIR_LAST_CALL_STATUS;
	zephir_nts_static zephir_fcall_cache_entry *_1 = NULL;
	zval *_0;

	ZEPHIR_MM_GROW();

	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_loops"), PH_NOISY_CC);
	Z_SET_ISREF_P(_0);
	ZEPHIR_RETURN_CALL_FUNCTION("end", &_1, _0);
	Z_UNSET_ISREF_P(_0);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Bolt_App_View_Compiler, _compileElement) {

	zephir_nts_static zephir_fcall_cache_entry *_6 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *node, *prototype = NULL, *name = NULL, *_0, *_1, *_2, *_3, *_4, *_5, *_7, *_8;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &node);



	if (!(zephir_instance_of_ev(node, bolt_app_view_parser_node_ce TSRMLS_CC))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_InvalidArgumentException, "Parameter 'node' must be an instance of 'Bolt\\App\\View\\Parser\\Node'", "", 0);
		return;
	}
	ZEPHIR_INIT_VAR(_0);
	ZVAL_LONG(_0, 0);
	ZEPHIR_CALL_METHOD(&prototype, node, "property", NULL, _0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&name, prototype, "getvalue", NULL);
	zephir_check_call_status();
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("_elementsHandlers"), PH_NOISY_CC);
	zephir_array_fetch_string(&_2, _1, SL("open"), PH_READONLY, "bolt/app/view/Compiler.zep", 132 TSRMLS_CC);
	if (zephir_array_isset(_2, name)) {
		_3 = zephir_fetch_nproperty_this(this_ptr, SL("_elementsHandlers"), PH_NOISY_CC);
		zephir_array_fetch_string(&_4, _3, SL("open"), PH_NOISY | PH_READONLY, "bolt/app/view/Compiler.zep", 133 TSRMLS_CC);
		zephir_array_fetch(&_5, _4, name, PH_NOISY | PH_READONLY, "bolt/app/view/Compiler.zep", 133 TSRMLS_CC);
		ZEPHIR_CALL_FUNCTION(NULL, "call_user_func", &_6, _5, this_ptr, node);
		zephir_check_call_status();
	}
	_3 = zephir_fetch_nproperty_this(this_ptr, SL("_elementsHandlers"), PH_NOISY_CC);
	zephir_array_fetch_string(&_4, _3, SL("close"), PH_READONLY, "bolt/app/view/Compiler.zep", 136 TSRMLS_CC);
	if (zephir_array_isset(_4, name)) {
		_7 = zephir_fetch_nproperty_this(this_ptr, SL("_elementsHandlers"), PH_NOISY_CC);
		zephir_array_fetch_string(&_5, _7, SL("close"), PH_NOISY | PH_READONLY, "bolt/app/view/Compiler.zep", 137 TSRMLS_CC);
		zephir_array_fetch(&_8, _5, name, PH_NOISY | PH_READONLY, "bolt/app/view/Compiler.zep", 137 TSRMLS_CC);
		ZEPHIR_CALL_FUNCTION(NULL, "call_user_func", &_6, _8, this_ptr, node);
		zephir_check_call_status();
	}
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Bolt_App_View_Compiler, _compileExpression) {

	zephir_nts_static zephir_fcall_cache_entry *_8 = NULL, *_11 = NULL;
	zend_bool _2;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *node, *prototype = NULL, *name = NULL, *each = NULL, *pos, *loopName = NULL, *_0 = NULL, *_1 = NULL, *_3, *_4 = NULL, *_5, *_6, *_7 = NULL, _9 = zval_used_for_init, _10 = zval_used_for_init, *_12 = NULL, *_13 = NULL, *_14;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &node);



	if (!(zephir_instance_of_ev(node, bolt_app_view_parser_node_ce TSRMLS_CC))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_InvalidArgumentException, "Parameter 'node' must be an instance of 'Bolt\\App\\View\\Parser\\Node'", "", 0);
		return;
	}
	ZEPHIR_INIT_VAR(_0);
	ZVAL_LONG(_0, 0);
	ZEPHIR_CALL_METHOD(&prototype, node, "property", NULL, _0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&name, prototype, "getvalue", NULL);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_1, prototype, "isfunction", NULL);
	zephir_check_call_status();
	_2 = zephir_is_true(_1);
	if (_2) {
		_3 = zephir_fetch_nproperty_this(this_ptr, SL("_expressionsHandlers"), PH_NOISY_CC);
		ZEPHIR_CALL_METHOD(&_4, prototype, "getvalue", NULL);
		zephir_check_call_status();
		_2 = zephir_array_isset(_3, _4);
	}
	if (_2) {
		_5 = zephir_fetch_nproperty_this(this_ptr, SL("_expressionsHandlers"), PH_NOISY_CC);
		ZEPHIR_CALL_METHOD(&_7, prototype, "getvalue", NULL);
		zephir_check_call_status();
		zephir_array_fetch(&_6, _5, _7, PH_NOISY | PH_READONLY, "bolt/app/view/Compiler.zep", 151 TSRMLS_CC);
		ZEPHIR_CALL_FUNCTION(NULL, "call_user_func", &_8, _6, this_ptr, node);
		zephir_check_call_status();
	} else {
		ZEPHIR_SINIT_VAR(_9);
		ZVAL_LONG(&_9, 0);
		ZEPHIR_SINIT_VAR(_10);
		ZVAL_LONG(&_10, 1);
		ZEPHIR_CALL_FUNCTION(&_7, "substr", &_11, name, &_9, &_10);
		zephir_check_call_status();
		if (ZEPHIR_IS_STRING(_7, "@")) {
			ZEPHIR_CALL_METHOD(&each, this_ptr, "getcurrentloop", NULL);
			zephir_check_call_status();
			if (!(zephir_is_true(each))) {
				ZEPHIR_THROW_EXCEPTION_DEBUG_STR(bolt_app_view_exception_ce, "Cannot use loop variable outside the loop", "bolt/app/view/Compiler.zep", 157);
				return;
			} else {
				ZEPHIR_OBS_VAR(loopName);
				zephir_array_fetch_string(&loopName, each, SL("name"), PH_NOISY, "bolt/app/view/Compiler.zep", 159 TSRMLS_CC);
				ZEPHIR_SINIT_NVAR(_9);
				ZVAL_LONG(&_9, 1);
				ZEPHIR_CALL_FUNCTION(&_12, "substr", &_11, name, &_9);
				zephir_check_call_status();
				ZEPHIR_CPY_WRT(name, _12);
				ZEPHIR_SINIT_NVAR(_9);
				ZVAL_STRING(&_9, ":", 0);
				ZEPHIR_INIT_VAR(pos);
				zephir_fast_strpos(pos, name, &_9, 0 );
				if (ZEPHIR_GT_LONG(pos, 0)) {
					ZEPHIR_SINIT_NVAR(_10);
					ZVAL_LONG(&_10, 0);
					ZEPHIR_CALL_FUNCTION(&loopName, "substr", &_11, name, &_10, pos);
					zephir_check_call_status();
					ZEPHIR_SINIT_NVAR(_10);
					ZVAL_LONG(&_10, (zephir_get_numberval(pos) + 1));
					ZEPHIR_CALL_FUNCTION(&_12, "substr", &_11, name, &_10);
					zephir_check_call_status();
					ZEPHIR_CPY_WRT(name, _12);
				}
				_5 = zephir_fetch_nproperty_this(this_ptr, SL("_loopVariables"), PH_NOISY_CC);
				if (!(zephir_array_isset(_5, name))) {
					ZEPHIR_INIT_NVAR(_0);
					object_init_ex(_0, bolt_app_view_exception_ce);
					ZEPHIR_INIT_VAR(_13);
					ZEPHIR_CONCAT_SVS(_13, "Undefined loop variable `", name, "`, expected: index, key, length, last or first");
					ZEPHIR_CALL_METHOD(NULL, _0, "__construct", NULL, _13);
					zephir_check_call_status();
					zephir_throw_exception_debug(_0, "bolt/app/view/Compiler.zep", 169 TSRMLS_CC);
					ZEPHIR_MM_RESTORE();
					return;
				}
				ZEPHIR_INIT_LNVAR(_13);
				ZEPHIR_CONCAT_SVSVS(_13, "<?=$_loop_", loopName, "_", name, "?>");
				ZEPHIR_CALL_METHOD(NULL, this_ptr, "addtoblock", NULL, _13);
				zephir_check_call_status();
			}
		} else {
			ZEPHIR_CALL_METHOD(&_12, this_ptr, "compileproperty", NULL, prototype);
			zephir_check_call_status();
			ZEPHIR_INIT_VAR(_14);
			ZEPHIR_CONCAT_SVS(_14, "<?=", _12, "?>");
			ZEPHIR_CALL_METHOD(NULL, this_ptr, "addtoblock", NULL, _14);
			zephir_check_call_status();
		}
	}
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Bolt_App_View_Compiler, compileProperty) {

	zephir_fcall_cache_entry *_9 = NULL;
	HashTable *_1, *_6, *_18;
	HashPosition _0, _5, _17;
	int length, i, ZEPHIR_LAST_CALL_STATUS;
	zval *result = NULL, *_21 = NULL;
	zval *node, *modifiers = NULL, *modifier = NULL, *arguments = NULL, *arg = NULL, **_2, *_3 = NULL, *_4 = NULL, **_7, *_8 = NULL, *_10 = NULL, *_11 = NULL, *_12 = NULL, *_13 = NULL, *_14 = NULL, *_15 = NULL, *_16 = NULL, **_19, *_20 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &node);

	ZEPHIR_INIT_VAR(result);
	ZVAL_STRING(result, "", 1);


	if (!(zephir_instance_of_ev(node, bolt_app_view_parser_node_ce TSRMLS_CC))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_InvalidArgumentException, "Parameter 'node' must be an instance of 'Bolt\\App\\View\\Parser\\Node'", "", 0);
		return;
	}
	ZEPHIR_CALL_METHOD(&modifiers, node, "getmodifiers", NULL);
	zephir_check_call_status();
	length = zephir_fast_count_int(modifiers TSRMLS_CC);
	if (length > 0) {
		i = 0;
		zephir_is_iterable(modifiers, &_1, &_0, 0, 0, "bolt/app/view/Compiler.zep", 202);
		for (
		  ; zephir_hash_get_current_data_ex(_1, (void**) &_2, &_0) == SUCCESS
		  ; zephir_hash_move_forward_ex(_1, &_0)
		) {
			ZEPHIR_GET_HVALUE(modifier, _2);
			ZEPHIR_INIT_NVAR(arguments);
			array_init(arguments);
			ZEPHIR_CALL_METHOD(&_3, modifier, "hasarguments", NULL);
			zephir_check_call_status();
			if (zephir_is_true(_3)) {
				ZEPHIR_CALL_METHOD(&_4, modifier, "getarguments", NULL);
				zephir_check_call_status();
				zephir_is_iterable(_4, &_6, &_5, 0, 0, "bolt/app/view/Compiler.zep", 196);
				for (
				  ; zephir_hash_get_current_data_ex(_6, (void**) &_7, &_5) == SUCCESS
				  ; zephir_hash_move_forward_ex(_6, &_5)
				) {
					ZEPHIR_GET_HVALUE(arg, _7);
					ZEPHIR_CALL_METHOD(&_8, this_ptr, "_compileargument", &_9, arg);
					zephir_check_call_status();
					zephir_array_append(&arguments, _8, PH_SEPARATE, "bolt/app/view/Compiler.zep", 194);
				}
			}
			ZEPHIR_CALL_METHOD(&_4, modifier, "getvalue", NULL);
			zephir_check_call_status();
			ZEPHIR_INIT_NVAR(_10);
			zephir_fast_join_str(_10, SL(","), arguments TSRMLS_CC);
			ZEPHIR_INIT_LNVAR(_11);
			ZEPHIR_CONCAT_VSVSVS(_11, result, "$this->_filter('", _4, "', array(", _10, "), ");
			zephir_get_strval(result, _11);
			i++;
		}
	}
	ZEPHIR_CALL_METHOD(&_3, node, "isscalar", NULL);
	zephir_check_call_status();
	if (zephir_is_true(_3)) {
		ZEPHIR_CALL_METHOD(&_8, this_ptr, "_compilescalar", NULL, node);
		zephir_check_call_status();
		zephir_concat_self(&result, _8 TSRMLS_CC);
	} else {
		ZEPHIR_CALL_METHOD(&_13, node, "getvalue", NULL);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&_12, this_ptr, "_compileargument", &_9, _13);
		zephir_check_call_status();
		zephir_concat_self(&result, _12 TSRMLS_CC);
		ZEPHIR_CALL_METHOD(&_14, node, "hasarguments", NULL);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&_15, node, "isfunction", NULL);
		zephir_check_call_status();
		if (zephir_is_true(_14)) {
			ZEPHIR_INIT_NVAR(arguments);
			array_init(arguments);
			zephir_concat_self_str(&result, "(", sizeof("(")-1 TSRMLS_CC);
			ZEPHIR_CALL_METHOD(&_16, node, "getarguments", NULL);
			zephir_check_call_status();
			zephir_is_iterable(_16, &_18, &_17, 0, 0, "bolt/app/view/Compiler.zep", 216);
			for (
			  ; zephir_hash_get_current_data_ex(_18, (void**) &_19, &_17) == SUCCESS
			  ; zephir_hash_move_forward_ex(_18, &_17)
			) {
				ZEPHIR_GET_HVALUE(arg, _19);
				ZEPHIR_CALL_METHOD(&_20, this_ptr, "_compileargument", &_9, arg);
				zephir_check_call_status();
				zephir_array_append(&arguments, _20, PH_SEPARATE, "bolt/app/view/Compiler.zep", 214);
			}
			ZEPHIR_INIT_NVAR(_10);
			zephir_fast_join_str(_10, SL(","), arguments TSRMLS_CC);
			zephir_concat_self(&result, _10 TSRMLS_CC);
			zephir_concat_self_str(&result, ")", sizeof(")")-1 TSRMLS_CC);
		} else if (zephir_is_true(_15)) {
			zephir_concat_self_str(&result, "()", sizeof("()")-1 TSRMLS_CC);
		}
	}
	if (length > 0) {
		while (1) {
			if (!(i > 0)) {
				break;
			}
			ZEPHIR_INIT_LNVAR(_21);
			ZEPHIR_CONCAT_VS(_21, result, ")");
			ZEPHIR_CPY_WRT(result, _21);
			i--;
		}
	}
	RETURN_CTOR(result);

}

PHP_METHOD(Bolt_App_View_Compiler, _compileScalar) {

	zephir_fcall_cache_entry *_9 = NULL, *_12 = NULL;
	HashTable *_2;
	HashPosition _1;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *result;
	zval *node, *child = NULL, *values, *_0 = NULL, **_3, *_4 = NULL, *_5 = NULL, *_6 = NULL, *_7 = NULL, *_8 = NULL, *_10 = NULL, *_11 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &node);

	ZEPHIR_INIT_VAR(values);
	array_init(values);


	if (!(zephir_instance_of_ev(node, bolt_app_view_parser_node_ce TSRMLS_CC))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_InvalidArgumentException, "Parameter 'node' must be an instance of 'Bolt\\App\\View\\Parser\\Node'", "", 0);
		return;
	}
	ZEPHIR_INIT_VAR(result);
	ZVAL_STRING(result, "array(", 1);
	ZEPHIR_CALL_METHOD(&_0, node, "getchildren", NULL);
	zephir_check_call_status();
	zephir_is_iterable(_0, &_2, &_1, 0, 0, "bolt/app/view/Compiler.zep", 255);
	for (
	  ; zephir_hash_get_current_data_ex(_2, (void**) &_3, &_1) == SUCCESS
	  ; zephir_hash_move_forward_ex(_2, &_1)
	) {
		ZEPHIR_GET_HVALUE(child, _3);
		ZEPHIR_CALL_METHOD(&_4, child, "isscalar", NULL);
		zephir_check_call_status();
		if (zephir_is_true(_4)) {
			ZEPHIR_CALL_METHOD(&_5, child, "hasarguments", NULL);
			zephir_check_call_status();
			if (zephir_is_true(_5)) {
				ZEPHIR_INIT_NVAR(_7);
				ZVAL_LONG(_7, 0);
				ZEPHIR_CALL_METHOD(&_6, child, "argument", NULL, _7);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&_8, this_ptr, "_compilescalar", &_9, child);
				zephir_check_call_status();
				ZEPHIR_INIT_LNVAR(_10);
				ZEPHIR_CONCAT_SVSV(_10, "'", _6, "'=>", _8);
				zephir_array_append(&values, _10, PH_SEPARATE, "bolt/app/view/Compiler.zep", 243);
			} else {
				ZEPHIR_CALL_METHOD(&_6, this_ptr, "_compilescalar", &_9, child);
				zephir_check_call_status();
				zephir_array_append(&values, _6, PH_SEPARATE, "bolt/app/view/Compiler.zep", 245);
			}
		} else {
			ZEPHIR_CALL_METHOD(&_5, child, "hasarguments", NULL);
			zephir_check_call_status();
			if (zephir_is_true(_5)) {
				ZEPHIR_INIT_NVAR(_7);
				ZVAL_LONG(_7, 0);
				ZEPHIR_CALL_METHOD(&_6, child, "argument", NULL, _7);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&_11, child, "getvalue", NULL);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&_8, this_ptr, "_compileargument", &_12, _11);
				zephir_check_call_status();
				ZEPHIR_INIT_LNVAR(_10);
				ZEPHIR_CONCAT_SVSV(_10, "'", _6, "'=>", _8);
				zephir_array_append(&values, _10, PH_SEPARATE, "bolt/app/view/Compiler.zep", 249);
			} else {
				ZEPHIR_CALL_METHOD(&_8, child, "getvalue", NULL);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&_6, this_ptr, "_compileargument", &_12, _8);
				zephir_check_call_status();
				zephir_array_append(&values, _6, PH_SEPARATE, "bolt/app/view/Compiler.zep", 251);
			}
		}
	}
	ZEPHIR_INIT_NVAR(_7);
	zephir_fast_join_str(_7, SL(","), values TSRMLS_CC);
	ZEPHIR_CONCAT_VVS(return_value, result, _7, ")");
	RETURN_MM();

}

PHP_METHOD(Bolt_App_View_Compiler, _compileModifiers) {

	zephir_fcall_cache_entry *_9 = NULL;
	HashTable *_1, *_6;
	HashPosition _0, _5;
	int length, i, ZEPHIR_LAST_CALL_STATUS;
	zval *param = NULL, *result = NULL, *_12 = NULL;
	zval *node, *param_param = NULL, *modifiers = NULL, *modifier = NULL, *arguments = NULL, *arg = NULL, **_2, *_3 = NULL, *_4 = NULL, **_7, *_8 = NULL, *_10 = NULL, *_11 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &node, &param_param);

	zephir_get_strval(param, param_param);
	ZEPHIR_INIT_VAR(result);
	ZVAL_STRING(result, "", 1);


	if (!(zephir_instance_of_ev(node, bolt_app_view_parser_node_ce TSRMLS_CC))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_InvalidArgumentException, "Parameter 'node' must be an instance of 'Bolt\\App\\View\\Parser\\Node'", "", 0);
		return;
	}
	ZEPHIR_CALL_METHOD(&modifiers, node, "getmodifiers", NULL);
	zephir_check_call_status();
	length = zephir_fast_count_int(modifiers TSRMLS_CC);
	if (length > 0) {
		i = 0;
		zephir_is_iterable(modifiers, &_1, &_0, 0, 0, "bolt/app/view/Compiler.zep", 278);
		for (
		  ; zephir_hash_get_current_data_ex(_1, (void**) &_2, &_0) == SUCCESS
		  ; zephir_hash_move_forward_ex(_1, &_0)
		) {
			ZEPHIR_GET_HVALUE(modifier, _2);
			ZEPHIR_INIT_NVAR(arguments);
			array_init(arguments);
			ZEPHIR_CALL_METHOD(&_3, modifier, "hasarguments", NULL);
			zephir_check_call_status();
			if (zephir_is_true(_3)) {
				ZEPHIR_CALL_METHOD(&_4, modifier, "getarguments", NULL);
				zephir_check_call_status();
				zephir_is_iterable(_4, &_6, &_5, 0, 0, "bolt/app/view/Compiler.zep", 273);
				for (
				  ; zephir_hash_get_current_data_ex(_6, (void**) &_7, &_5) == SUCCESS
				  ; zephir_hash_move_forward_ex(_6, &_5)
				) {
					ZEPHIR_GET_HVALUE(arg, _7);
					ZEPHIR_CALL_METHOD(&_8, this_ptr, "_compileargument", &_9, arg);
					zephir_check_call_status();
					zephir_array_append(&arguments, _8, PH_SEPARATE, "bolt/app/view/Compiler.zep", 271);
				}
			}
			ZEPHIR_CALL_METHOD(&_4, modifier, "getvalue", NULL);
			zephir_check_call_status();
			ZEPHIR_INIT_NVAR(_10);
			zephir_fast_join_str(_10, SL(","), arguments TSRMLS_CC);
			ZEPHIR_INIT_LNVAR(_11);
			ZEPHIR_CONCAT_VSVSVS(_11, result, "$this->_filter('", _4, "', array(", _10, "), ");
			zephir_get_strval(result, _11);
			i++;
		}
	}
	zephir_concat_self(&result, param TSRMLS_CC);
	if (length > 0) {
		while (1) {
			if (!(i > 0)) {
				break;
			}
			ZEPHIR_INIT_LNVAR(_12);
			ZEPHIR_CONCAT_VS(_12, result, ")");
			ZEPHIR_CPY_WRT(result, _12);
			i--;
		}
	}
	RETURN_CTOR(result);

}

PHP_METHOD(Bolt_App_View_Compiler, _compileArgument) {

	zend_bool _2, _4, _5, _6, _9, _10, _11, _12;
	unsigned char _1, _3;
	int ZEPHIR_LAST_CALL_STATUS;
	zephir_nts_static zephir_fcall_cache_entry *_0 = NULL, *_14 = NULL, *_18 = NULL;
	zval *item_param = NULL, *sub = NULL, *search, *replace = NULL, *dotPos, *arrPos, *pos = NULL, *map = NULL, _7, _8, _13, *_15 = NULL, *_17 = NULL;
	zval *item = NULL, *_16 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &item_param);

	zephir_get_strval(item, item_param);
	ZEPHIR_INIT_VAR(map);
	array_init(map);


	ZEPHIR_INIT_NVAR(map);
	array_init_size(map, 4);
	add_assoc_stringl_ex(map, SS("/\\./"), SL("->"), 1);
	add_assoc_stringl_ex(map, SS("/\\[/"), SL("['"), 1);
	add_assoc_stringl_ex(map, SS("/\\]/"), SL("']"), 1);
	ZEPHIR_INIT_VAR(search);
	zephir_array_keys(search, map TSRMLS_CC);
	ZEPHIR_CALL_FUNCTION(&replace, "array_values", &_0, map);
	zephir_check_call_status();
	_1 = ZEPHIR_STRING_OFFSET(item, 0);
	_2 = _1 == '\'';
	if (!(_2)) {
		_3 = ZEPHIR_STRING_OFFSET(item, 0);
		_2 = _3 == '"';
	}
	_4 = _2;
	if (!(_4)) {
		_4 = zephir_is_numeric(item);
	}
	if (_4) {
		RETURN_CTOR(item);
	}
	_5 = ZEPHIR_IS_STRING(item, "true");
	if (!(_5)) {
		_5 = ZEPHIR_IS_STRING(item, "false");
	}
	_6 = _5;
	if (!(_6)) {
		_6 = ZEPHIR_IS_STRING(item, "null");
	}
	if (_6) {
		RETURN_CTOR(item);
	}
	ZEPHIR_SINIT_VAR(_7);
	ZVAL_STRING(&_7, "[", 0);
	ZEPHIR_INIT_VAR(arrPos);
	zephir_fast_strpos(arrPos, item, &_7, 0 );
	ZEPHIR_SINIT_VAR(_8);
	ZVAL_STRING(&_8, ".", 0);
	ZEPHIR_INIT_VAR(dotPos);
	zephir_fast_strpos(dotPos, item, &_8, 0 );
	php_printf("%s", "arrpos:");
	zephir_var_dump(&arrPos TSRMLS_CC);
	php_printf("%s", "dotPos");
	zephir_var_dump(&dotPos TSRMLS_CC);
	_9 = ZEPHIR_IS_FALSE_IDENTICAL(arrPos);
	if (_9) {
		_9 = ZEPHIR_IS_FALSE_IDENTICAL(dotPos);
	}
	_10 = !ZEPHIR_IS_FALSE_IDENTICAL(arrPos);
	if (_10) {
		_10 = ZEPHIR_GE_LONG(arrPos, 0);
	}
	_11 = _10;
	if (_11) {
		_11 = !ZEPHIR_IS_FALSE_IDENTICAL(dotPos);
	}
	_12 = _11;
	if (_12) {
		_12 = ZEPHIR_GE_LONG(dotPos, 0);
	}
	if (_9) {
		ZEPHIR_CONCAT_SVS(return_value, "$this->_vars['", item, "']");
		RETURN_MM();
	} else if (_12) {
		if (ZEPHIR_GT(arrPos, dotPos)) {
			ZEPHIR_CPY_WRT(pos, dotPos);
		} else {
			ZEPHIR_CPY_WRT(pos, arrPos);
		}
	} else if (!ZEPHIR_IS_FALSE_IDENTICAL(dotPos)) {
		ZEPHIR_CPY_WRT(pos, dotPos);
	} else if (!ZEPHIR_IS_FALSE_IDENTICAL(arrPos)) {
		ZEPHIR_CPY_WRT(pos, arrPos);
	}
	ZEPHIR_SINIT_VAR(_13);
	ZVAL_LONG(&_13, 0);
	ZEPHIR_CALL_FUNCTION(&sub, "substr", &_14, item, &_13, pos);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(&_15, "substr", &_14, item, pos);
	zephir_check_call_status();
	zephir_get_strval(item, _15);
	zephir_get_strval(_16, item);
	ZEPHIR_CALL_FUNCTION(&_17, "preg_replace", &_18, search, replace, _16);
	zephir_check_call_status();
	ZEPHIR_CONCAT_SVSV(return_value, "$this->_vars['", sub, "']", _17);
	RETURN_MM();

}

PHP_METHOD(Bolt_App_View_Compiler, _compileInclude) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *compiler, *node, *_0 = NULL, *_1 = NULL, *_2 = NULL, *_3 = NULL, *_4;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &compiler, &node);



	ZEPHIR_INIT_VAR(_1);
	ZVAL_LONG(_1, 1);
	ZEPHIR_CALL_METHOD(&_0, node, "property", NULL, _1);
	zephir_check_call_status();
	if (!(zephir_is_true(_0))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(bolt_app_view_exception_ce, "{% include %} requires at least one property", "bolt/app/view/Compiler.zep", 340);
		return;
	}
	ZEPHIR_INIT_NVAR(_1);
	ZVAL_LONG(_1, 1);
	ZEPHIR_CALL_METHOD(&_3, node, "property", NULL, _1);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_2, this_ptr, "_compileargument", NULL, _3);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(_4);
	ZEPHIR_CONCAT_SVS(_4, "<?$this->_include(", _2, ")?>");
	ZEPHIR_CALL_METHOD(NULL, compiler, "addtoblock", NULL, _4);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Bolt_App_View_Compiler, _compileExtend) {

	zephir_nts_static zephir_fcall_cache_entry *_11 = NULL, *_13 = NULL;
	zend_bool _6;
	unsigned char _5, _7;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *templateName = NULL, *_4 = NULL;
	zval *compiler, *node, *_0 = NULL, *_1 = NULL, *_2 = NULL, *_3 = NULL, _8, _9, *_10 = NULL, *_12 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &compiler, &node);



	ZEPHIR_INIT_VAR(_1);
	ZVAL_LONG(_1, 1);
	ZEPHIR_CALL_METHOD(&_0, node, "property", NULL, _1);
	zephir_check_call_status();
	if (!(zephir_is_true(_0))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(bolt_app_view_exception_ce, "{% extends %} requires template name to be set", "bolt/app/view/Compiler.zep", 350);
		return;
	}
	ZEPHIR_INIT_NVAR(_1);
	ZVAL_LONG(_1, 1);
	ZEPHIR_CALL_METHOD(&_2, node, "property", NULL, _1);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_3, _2, "getvalue", NULL);
	zephir_check_call_status();
	zephir_get_strval(_4, _3);
	ZEPHIR_CPY_WRT(templateName, _4);
	_5 = ZEPHIR_STRING_OFFSET(templateName, 0);
	_6 = _5 != '\'';
	if (_6) {
		_7 = ZEPHIR_STRING_OFFSET(templateName, 0);
		_6 = _7 != '"';
	}
	if (_6) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(bolt_app_view_exception_ce, "{% extends %} requires template name to be constant string", "bolt/app/view/Compiler.zep", 355);
		return;
	}
	ZEPHIR_SINIT_VAR(_8);
	ZVAL_LONG(&_8, 1);
	ZEPHIR_SINIT_VAR(_9);
	ZVAL_LONG(&_9, -1);
	ZEPHIR_CALL_FUNCTION(&_10, "substr", &_11, templateName, &_8, &_9);
	zephir_check_call_status();
	zephir_get_strval(templateName, _10);
	ZEPHIR_CALL_FUNCTION(&_12, "md5", &_13, templateName);
	zephir_check_call_status();
	zephir_update_property_this(this_ptr, SL("_extends"), _12 TSRMLS_CC);
	zephir_update_property_array_append(this_ptr, SL("_dependencies"), templateName TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Bolt_App_View_Compiler, _compileI18n) {

	zephir_fcall_cache_entry *_9 = NULL;
	HashTable *_6;
	HashPosition _5;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *compiler, *node, *arguments, *arg = NULL, *_0 = NULL, *_1 = NULL, *_2 = NULL, *_3 = NULL, *_4 = NULL, **_7, *_8 = NULL, *_10;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &compiler, &node);

	ZEPHIR_INIT_VAR(arguments);
	array_init(arguments);


	ZEPHIR_INIT_VAR(_1);
	ZVAL_LONG(_1, 0);
	ZEPHIR_CALL_METHOD(&_0, node, "property", NULL, _1);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_2, _0, "hasarguments", NULL);
	zephir_check_call_status();
	if (ZEPHIR_IS_FALSE(_2)) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(bolt_app_view_exception_ce, "{{_}} requires at least one parameter", "bolt/app/view/Compiler.zep", 368);
		return;
	}
	ZEPHIR_INIT_NVAR(_1);
	ZVAL_LONG(_1, 0);
	ZEPHIR_CALL_METHOD(&_3, node, "property", NULL, _1);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_4, _3, "getarguments", NULL);
	zephir_check_call_status();
	zephir_is_iterable(_4, &_6, &_5, 0, 0, "bolt/app/view/Compiler.zep", 375);
	for (
	  ; zephir_hash_get_current_data_ex(_6, (void**) &_7, &_5) == SUCCESS
	  ; zephir_hash_move_forward_ex(_6, &_5)
	) {
		ZEPHIR_GET_HVALUE(arg, _7);
		ZEPHIR_CALL_METHOD(&_8, this_ptr, "_compileargument", &_9, arg);
		zephir_check_call_status();
		zephir_array_append(&arguments, _8, PH_SEPARATE, "bolt/app/view/Compiler.zep", 372);
	}
	ZEPHIR_INIT_NVAR(_1);
	zephir_fast_join_str(_1, SL(","), arguments TSRMLS_CC);
	ZEPHIR_INIT_VAR(_10);
	ZEPHIR_CONCAT_SVS(_10, "<?$this->_translate(", _1, ")?>");
	ZEPHIR_CALL_METHOD(NULL, compiler, "addtoblock", NULL, _10);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Bolt_App_View_Compiler, _compileParent) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *compiler, *node, *_0, *_1;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &compiler, &node);



	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_currentBlock"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(_1);
	ZEPHIR_CONCAT_SVS(_1, "<?parent::", _0, "()?>");
	ZEPHIR_CALL_METHOD(NULL, compiler, "addtoblock", NULL, _1);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Bolt_App_View_Compiler, _compileContinue) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *compiler, *node, *each = NULL, *_0;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &compiler, &node);



	ZEPHIR_CALL_METHOD(&each, this_ptr, "getcurrentloop", NULL);
	zephir_check_call_status();
	if (!(zephir_is_true(each))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(bolt_app_view_exception_ce, "Cannot use {{continue()}} outside the loop context", "bolt/app/view/Compiler.zep", 389);
		return;
	}
	ZEPHIR_INIT_VAR(_0);
	ZVAL_STRING(_0, "<?continue?>", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(NULL, compiler, "addtoblock", NULL, _0);
	zephir_check_temp_parameter(_0);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Bolt_App_View_Compiler, _compileBreak) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *compiler, *node, *each = NULL, *_0;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &compiler, &node);



	ZEPHIR_CALL_METHOD(&each, this_ptr, "getcurrentloop", NULL);
	zephir_check_call_status();
	if (!(zephir_is_true(each))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(bolt_app_view_exception_ce, "Cannot use {{break()}} outside the loop context", "bolt/app/view/Compiler.zep", 400);
		return;
	}
	ZEPHIR_INIT_VAR(_0);
	ZVAL_STRING(_0, "<?break?>", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(NULL, compiler, "addtoblock", NULL, _0);
	zephir_check_temp_parameter(_0);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Bolt_App_View_Compiler, _compileBlock) {

	zval *_8;
	zephir_nts_static zephir_fcall_cache_entry *_7 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *compiler, *node, *_0, *_1 = NULL, *_2, *_3 = NULL, *blockName = NULL, *_4 = NULL, *_5 = NULL, *_6 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &compiler, &node);



	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_currentBlock"), PH_NOISY_CC);
	if (!ZEPHIR_IS_STRING(_0, "#")) {
		ZEPHIR_INIT_VAR(_1);
		object_init_ex(_1, bolt_app_view_exception_ce);
		_2 = zephir_fetch_nproperty_this(this_ptr, SL("_file"), PH_NOISY_CC);
		ZEPHIR_INIT_VAR(_3);
		ZEPHIR_CONCAT_SV(_3, "Nested block are not allowed in ", _2);
		ZEPHIR_CALL_METHOD(NULL, _1, "__construct", NULL, _3);
		zephir_check_call_status();
		zephir_throw_exception_debug(_1, "bolt/app/view/Compiler.zep", 408 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_INIT_NVAR(_1);
	ZVAL_LONG(_1, 1);
	ZEPHIR_CALL_METHOD(&_4, node, "property", NULL, _1);
	zephir_check_call_status();
	if (!(zephir_is_true(_4))) {
		ZEPHIR_INIT_NVAR(_1);
		object_init_ex(_1, bolt_app_view_exception_ce);
		_2 = zephir_fetch_nproperty_this(this_ptr, SL("_file"), PH_NOISY_CC);
		ZEPHIR_INIT_LNVAR(_3);
		ZEPHIR_CONCAT_SV(_3, "Block's name is not defined in ", _2);
		ZEPHIR_CALL_METHOD(NULL, _1, "__construct", NULL, _3);
		zephir_check_call_status();
		zephir_throw_exception_debug(_1, "bolt/app/view/Compiler.zep", 412 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_INIT_NVAR(_1);
	ZVAL_LONG(_1, 1);
	ZEPHIR_CALL_METHOD(&_5, node, "property", NULL, _1);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&blockName, _5, "getvalue", NULL);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(_1);
	ZVAL_STRING(_1, "/[a-z]([a-z0-9_]+)?/is", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_FUNCTION(&_6, "preg_match", &_7, _1, blockName);
	zephir_check_temp_parameter(_1);
	zephir_check_call_status();
	if (!(zephir_is_true(_6))) {
		ZEPHIR_INIT_NVAR(_1);
		object_init_ex(_1, bolt_app_view_exception_ce);
		ZEPHIR_INIT_LNVAR(_3);
		ZEPHIR_CONCAT_SVS(_3, "Invalid block name `", blockName, "`. Valid name should match the pattern [a-z][a-z0-9_]+");
		ZEPHIR_CALL_METHOD(NULL, _1, "__construct", NULL, _3);
		zephir_check_call_status();
		zephir_throw_exception_debug(_1, "bolt/app/view/Compiler.zep", 417 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_update_property_this(this_ptr, SL("_currentBlock"), blockName TSRMLS_CC);
	ZEPHIR_INIT_VAR(_8);
	array_init_size(_8, 2);
	add_assoc_stringl_ex(_8, SS("type"), SL("block"), 1);
	zephir_update_property_array_append(this_ptr, SL("_elements"), _8 TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Bolt_App_View_Compiler, _compileEndBlock) {

	zephir_nts_static zephir_fcall_cache_entry *_3 = NULL, *_9 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *compiler, *node, *element = NULL, *_0, *_1, *_2, *_4, *_5, *_6, *_7, *_8;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &compiler, &node);



	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_currentBlock"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(_1);
	ZEPHIR_CONCAT_SVS(_1, "<?$this->block", _0, "()?>");
	ZEPHIR_CALL_METHOD(NULL, compiler, "addtomain", NULL, _1);
	zephir_check_call_status();
	ZEPHIR_INIT_ZVAL_NREF(_2);
	ZVAL_STRING(_2, "#", 1);
	zephir_update_property_this(this_ptr, SL("_currentBlock"), _2 TSRMLS_CC);
	_2 = zephir_fetch_nproperty_this(this_ptr, SL("_elements"), PH_NOISY_CC);
	Z_SET_ISREF_P(_2);
	ZEPHIR_CALL_FUNCTION(&element, "end", &_3, _2);
	Z_UNSET_ISREF_P(_2);
	zephir_check_call_status();
	zephir_array_fetch_string(&_4, element, SL("type"), PH_NOISY | PH_READONLY, "bolt/app/view/Compiler.zep", 433 TSRMLS_CC);
	if (!ZEPHIR_IS_STRING(_4, "block")) {
		ZEPHIR_INIT_VAR(_5);
		object_init_ex(_5, bolt_app_view_exception_ce);
		zephir_array_fetch_string(&_6, element, SL("type"), PH_NOISY | PH_READONLY, "bolt/app/view/Compiler.zep", 434 TSRMLS_CC);
		ZEPHIR_INIT_VAR(_7);
		ZEPHIR_CONCAT_SVS(_7, "Nesting conflict expected {% end", _6, " %} got {% endblock %}");
		ZEPHIR_CALL_METHOD(NULL, _5, "__construct", NULL, _7);
		zephir_check_call_status();
		zephir_throw_exception_debug(_5, "bolt/app/view/Compiler.zep", 434 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	_8 = zephir_fetch_nproperty_this(this_ptr, SL("_elements"), PH_NOISY_CC);
	Z_SET_ISREF_P(_8);
	ZEPHIR_CALL_FUNCTION(NULL, "array_pop", &_9, _8);
	Z_UNSET_ISREF_P(_8);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Bolt_App_View_Compiler, _compileFor) {

	zval *_22, *_23;
	zephir_nts_static zephir_fcall_cache_entry *_7 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *compiler, *node, *varName = NULL, *loopName = NULL, *index, *length, *key, *first, *last, *each, *item, *keys, *props = NULL, *propsLength, *tmp = NULL, *_0 = NULL, *_1 = NULL, *_2 = NULL, *_3 = NULL, *_4 = NULL, *_5, _6, *_8 = NULL, *_9 = NULL, *_10, *_11, *_12, *_13, *_14, *_15 = NULL, *_16 = NULL, *_17 = NULL, *_18 = NULL, *_19 = NULL, *_20 = NULL, *_21;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &compiler, &node);



	ZEPHIR_CALL_METHOD(&props, node, "getproperties", NULL);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(propsLength);
	ZVAL_LONG(propsLength, zephir_fast_count_int(props TSRMLS_CC));
	if (!ZEPHIR_IS_LONG(propsLength, 4)) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(bolt_app_view_exception_ce, "Invalid {% for %} expression", "bolt/app/view/Compiler.zep", 446);
		return;
	}
	ZEPHIR_INIT_VAR(_1);
	ZVAL_LONG(_1, 2);
	ZEPHIR_CALL_METHOD(&_0, node, "property", NULL, _1);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_2, _0, "getvalue", NULL);
	zephir_check_call_status();
	if (!ZEPHIR_IS_STRING(_2, "in")) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(bolt_app_view_exception_ce, "Invalid {% for %} expression", "bolt/app/view/Compiler.zep", 450);
		return;
	}
	ZEPHIR_INIT_NVAR(_1);
	ZVAL_LONG(_1, 1);
	ZEPHIR_CALL_METHOD(&_3, node, "property", NULL, _1);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&varName, _3, "getvalue", NULL);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(_1);
	ZVAL_LONG(_1, 3);
	ZEPHIR_CALL_METHOD(&_4, node, "property", NULL, _1);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&loopName, _4, "getvalue", NULL);
	zephir_check_call_status();
	if (ZEPHIR_IS_STRING(loopName, "[")) {
		_5 = zephir_fetch_nproperty_this(this_ptr, SL("_loops"), PH_NOISY_CC);
		ZEPHIR_SINIT_VAR(_6);
		ZVAL_LONG(&_6, zephir_fast_count_int(_5 TSRMLS_CC));
		ZEPHIR_CALL_FUNCTION(&tmp, "strval", &_7, &_6);
		zephir_check_call_status();
		ZEPHIR_INIT_NVAR(loopName);
		ZEPHIR_CONCAT_SV(loopName, "loop", tmp);
	}
	ZEPHIR_INIT_VAR(each);
	ZEPHIR_CONCAT_SV(each, "$_each_", loopName);
	ZEPHIR_INIT_VAR(index);
	ZEPHIR_CONCAT_VS(index, each, "_index");
	ZEPHIR_INIT_VAR(length);
	ZEPHIR_CONCAT_VS(length, each, "_length");
	ZEPHIR_INIT_VAR(key);
	ZEPHIR_CONCAT_VS(key, each, "_key");
	ZEPHIR_INIT_VAR(first);
	ZEPHIR_CONCAT_VS(first, each, "_first");
	ZEPHIR_INIT_VAR(last);
	ZEPHIR_CONCAT_VS(last, each, "_last");
	ZEPHIR_INIT_VAR(item);
	ZEPHIR_CONCAT_VS(item, each, "_item");
	ZEPHIR_INIT_VAR(keys);
	ZEPHIR_CONCAT_VS(keys, each, "_keys");
	ZEPHIR_INIT_NVAR(_1);
	ZVAL_LONG(_1, 3);
	ZEPHIR_CALL_METHOD(&_9, node, "property", NULL, _1);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_8, this_ptr, "compileproperty", NULL, _9);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(_10);
	ZEPHIR_CONCAT_SVSVS(_10, "<?", each, " = ", _8, "?>");
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "addtoblock", NULL, _10);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(_11);
	ZEPHIR_CONCAT_SVS(_11, "<?if(", each, "):?>");
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "addtoblock", NULL, _11);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(_12);
	ZEPHIR_CONCAT_SVSVS(_12, "<?", keys, " = array_keys(", each, ")?>");
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "addtoblock", NULL, _12);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(_13);
	ZEPHIR_CONCAT_SVSVS(_13, "<?", length, " = count(", keys, ")?>");
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "addtoblock", NULL, _13);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(_14);
	ZEPHIR_CONCAT_SVSVSVSVS(_14, "<?for(", index, " = 0; ", index, "<", length, "; ", index, "++):?>");
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "addtoblock", NULL, _14);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(_1);
	ZVAL_LONG(_1, 1);
	ZEPHIR_CALL_METHOD(&_15, node, "property", NULL, _1);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_16, _15, "hasmodifiers", NULL);
	zephir_check_call_status();
	if (zephir_is_true(_16)) {
		ZEPHIR_INIT_NVAR(_1);
		ZVAL_LONG(_1, 1);
		ZEPHIR_CALL_METHOD(&_18, node, "property", NULL, _1);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(_19);
		ZEPHIR_CONCAT_VSVSVS(_19, each, "[", keys, "[", index, "]]");
		ZEPHIR_CALL_METHOD(&_17, this_ptr, "_compilemodifiers", NULL, _18, _19);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(_20);
		ZEPHIR_CONCAT_SVSVS(_20, "<?$this->_vars->", varName, " = ", _17, "?>");
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "addtoblock", NULL, _20);
		zephir_check_call_status();
	} else {
		ZEPHIR_INIT_LNVAR(_19);
		ZEPHIR_CONCAT_SVSVSVSVS(_19, "<?$this->_vars->", varName, " = ", each, "[", keys, "[", index, "]]?>");
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "addtoblock", NULL, _19);
		zephir_check_call_status();
	}
	ZEPHIR_INIT_LNVAR(_19);
	ZEPHIR_CONCAT_SVSVSVS(_19, "<?", key, " = ", keys, "[", index, "]?>");
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "addtoblock", NULL, _19);
	zephir_check_call_status();
	ZEPHIR_INIT_LNVAR(_20);
	ZEPHIR_CONCAT_SVSVS(_20, "<?", first, "=", index, " == 0 ? true : false?>");
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "addtoblock", NULL, _20);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(_21);
	ZEPHIR_CONCAT_SVSVSVS(_21, "<?", last, "=", index, " == (", length, " - 1) ? true : false?>");
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "addtoblock", NULL, _21);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(_22);
	array_init_size(_22, 2);
	zephir_array_update_string(&_22, SL("name"), &loopName, PH_COPY | PH_SEPARATE);
	zephir_update_property_array_append(this_ptr, SL("_loops"), _22 TSRMLS_CC);
	ZEPHIR_INIT_VAR(_23);
	array_init_size(_23, 2);
	add_assoc_stringl_ex(_23, SS("type"), SL("for"), 1);
	zephir_update_property_array_append(this_ptr, SL("_elements"), _23 TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Bolt_App_View_Compiler, _compileEndFor) {

	int ZEPHIR_LAST_CALL_STATUS;
	zephir_nts_static zephir_fcall_cache_entry *_1 = NULL, *_7 = NULL;
	zval *compiler, *node, *element = NULL, *_0, *_2, *_3 = NULL, *_4, *_5, *_6, *_8;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &compiler, &node);



	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_elements"), PH_NOISY_CC);
	Z_SET_ISREF_P(_0);
	ZEPHIR_CALL_FUNCTION(&element, "end", &_1, _0);
	Z_UNSET_ISREF_P(_0);
	zephir_check_call_status();
	zephir_array_fetch_string(&_2, element, SL("type"), PH_NOISY | PH_READONLY, "bolt/app/view/Compiler.zep", 495 TSRMLS_CC);
	if (!ZEPHIR_IS_STRING(_2, "for")) {
		ZEPHIR_INIT_VAR(_3);
		object_init_ex(_3, bolt_app_view_exception_ce);
		zephir_array_fetch_string(&_4, element, SL("type"), PH_NOISY | PH_READONLY, "bolt/app/view/Compiler.zep", 496 TSRMLS_CC);
		ZEPHIR_INIT_VAR(_5);
		ZEPHIR_CONCAT_SVS(_5, "Nesting conflict expected {% end", _4, " %} got {% endfor %}");
		ZEPHIR_CALL_METHOD(NULL, _3, "__construct", NULL, _5);
		zephir_check_call_status();
		zephir_throw_exception_debug(_3, "bolt/app/view/Compiler.zep", 496 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (!(zephir_array_isset_string(element, SS("else")))) {
		ZEPHIR_INIT_NVAR(_3);
		ZVAL_STRING(_3, "<?endfor?>", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "addtoblock", NULL, _3);
		zephir_check_temp_parameter(_3);
		zephir_check_call_status();
	}
	ZEPHIR_INIT_NVAR(_3);
	ZVAL_STRING(_3, "<?endif?>", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "addtoblock", NULL, _3);
	zephir_check_temp_parameter(_3);
	zephir_check_call_status();
	_6 = zephir_fetch_nproperty_this(this_ptr, SL("_loops"), PH_NOISY_CC);
	Z_SET_ISREF_P(_6);
	ZEPHIR_CALL_FUNCTION(NULL, "array_pop", &_7, _6);
	Z_UNSET_ISREF_P(_6);
	zephir_check_call_status();
	_8 = zephir_fetch_nproperty_this(this_ptr, SL("_elements"), PH_NOISY_CC);
	Z_SET_ISREF_P(_8);
	ZEPHIR_CALL_FUNCTION(NULL, "array_pop", &_7, _8);
	Z_UNSET_ISREF_P(_8);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Bolt_App_View_Compiler, _compileElse) {

	int ZEPHIR_LAST_CALL_STATUS;
	zephir_nts_static zephir_fcall_cache_entry *_1 = NULL, *_6 = NULL;
	zval *compiler, *node, *element = NULL, *_0, *_2, *_3, *_4 = NULL, *_5;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &compiler, &node);



	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_elements"), PH_NOISY_CC);
	Z_SET_ISREF_P(_0);
	ZEPHIR_CALL_FUNCTION(&element, "end", &_1, _0);
	Z_UNSET_ISREF_P(_0);
	zephir_check_call_status();
	if (!(zephir_is_true(element))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(bolt_app_view_exception_ce, "Cannot use {% else %} element outside {% for %}, {% if %} blocks context", "bolt/app/view/Compiler.zep", 512);
		return;
	}
	zephir_array_fetch_string(&_2, element, SL("type"), PH_NOISY | PH_READONLY, "bolt/app/view/Compiler.zep", 515 TSRMLS_CC);
	zephir_array_fetch_string(&_3, element, SL("type"), PH_NOISY | PH_READONLY, "bolt/app/view/Compiler.zep", 517 TSRMLS_CC);
	if (ZEPHIR_IS_STRING(_2, "if")) {
		ZEPHIR_INIT_VAR(_4);
		ZVAL_STRING(_4, "<?else:?>", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(NULL, compiler, "addtoblock", NULL, _4);
		zephir_check_temp_parameter(_4);
		zephir_check_call_status();
	} else if (ZEPHIR_IS_STRING(_3, "for")) {
		ZEPHIR_INIT_NVAR(_4);
		ZVAL_STRING(_4, "<?endfor?>", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(NULL, compiler, "addtoblock", NULL, _4);
		zephir_check_temp_parameter(_4);
		zephir_check_call_status();
		ZEPHIR_INIT_NVAR(_4);
		ZVAL_STRING(_4, "<?else:?>", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(NULL, compiler, "addtoblock", NULL, _4);
		zephir_check_temp_parameter(_4);
		zephir_check_call_status();
		zephir_array_update_string(&element, SL("else"), &ZEPHIR_GLOBAL(global_true), PH_COPY | PH_SEPARATE);
		_5 = zephir_fetch_nproperty_this(this_ptr, SL("_elements"), PH_NOISY_CC);
		Z_SET_ISREF_P(_5);
		ZEPHIR_CALL_FUNCTION(NULL, "array_pop", &_6, _5);
		Z_UNSET_ISREF_P(_5);
		zephir_check_call_status();
		zephir_update_property_array_append(this_ptr, SL("_elements"), element TSRMLS_CC);
	} else {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(bolt_app_view_exception_ce, "Cannot use {% else %} element outside {% for %}, {% if %} blocks context", "bolt/app/view/Compiler.zep", 524);
		return;
	}
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Bolt_App_View_Compiler, _compileIf) {

	zend_bool _1, _8;
	zval *_0;
	zval *operator = NULL, *type = NULL, *not = NULL, *_7 = NULL, *_11 = NULL, *_26;
	int propsLength, ZEPHIR_LAST_CALL_STATUS;
	zval *compiler, *node, *props = NULL, *_2, *_3 = NULL, *_4 = NULL, *_5, *_6 = NULL, *_9, *_10 = NULL, *_12 = NULL, *_13, *_14 = NULL, *_15 = NULL, *_16 = NULL, *_17, *_18 = NULL, *_19, *_20 = NULL, *_21, *_22 = NULL, *_23, *_24 = NULL, *_25;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &compiler, &node);

	ZEPHIR_INIT_VAR(not);
	ZVAL_STRING(not, "", 1);


	ZEPHIR_INIT_VAR(_0);
	array_init_size(_0, 2);
	add_assoc_stringl_ex(_0, SS("type"), SL("if"), 1);
	zephir_update_property_array_append(this_ptr, SL("_elements"), _0 TSRMLS_CC);
	ZEPHIR_CALL_METHOD(&props, node, "getproperties", NULL);
	zephir_check_call_status();
	propsLength = zephir_fast_count_int(props TSRMLS_CC);
	_1 = propsLength == 3;
	if (_1) {
		zephir_array_fetch_long(&_2, props, 1, PH_NOISY | PH_READONLY, "bolt/app/view/Compiler.zep", 542 TSRMLS_CC);
		ZEPHIR_CALL_METHOD(&_3, _2, "getvalue", NULL);
		zephir_check_call_status();
		_1 = ZEPHIR_IS_STRING(_3, "not");
	}
	if (propsLength == 1) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(bolt_app_view_exception_ce, "{% if %} block requires a statement", "bolt/app/view/Compiler.zep", 539);
		return;
	} else if (propsLength == 2) {
		zephir_array_fetch_long(&_5, props, 1, PH_NOISY | PH_READONLY, "bolt/app/view/Compiler.zep", 541 TSRMLS_CC);
		ZEPHIR_CALL_METHOD(&_4, this_ptr, "compileproperty", NULL, _5);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(_6);
		ZEPHIR_CONCAT_SVS(_6, "<?if(", _4, "):?>");
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "addtoblock", NULL, _6);
		zephir_check_call_status();
	} else if (_1) {
		zephir_array_fetch_long(&_5, props, 2, PH_NOISY | PH_READONLY, "bolt/app/view/Compiler.zep", 543 TSRMLS_CC);
		ZEPHIR_CALL_METHOD(&_4, this_ptr, "compileproperty", NULL, _5);
		zephir_check_call_status();
		ZEPHIR_INIT_LNVAR(_6);
		ZEPHIR_CONCAT_SVS(_6, "<?if(!", _4, "):?>");
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "addtoblock", NULL, _6);
		zephir_check_call_status();
	} else if (propsLength == 4) {
		zephir_array_fetch_long(&_5, props, 2, PH_NOISY | PH_READONLY, "bolt/app/view/Compiler.zep", 546 TSRMLS_CC);
		ZEPHIR_CALL_METHOD(&_4, _5, "getvalue", NULL);
		zephir_check_call_status();
		zephir_get_strval(_7, _4);
		ZEPHIR_CPY_WRT(operator, _7);
		_8 = ZEPHIR_IS_STRING(operator, "is");
		if (!(_8)) {
			_8 = ZEPHIR_IS_STRING(operator, "not");
		}
		if (_8) {
			zephir_array_fetch_long(&_9, props, 3, PH_NOISY | PH_READONLY, "bolt/app/view/Compiler.zep", 549 TSRMLS_CC);
			ZEPHIR_CALL_METHOD(&_10, _9, "getvalue", NULL);
			zephir_check_call_status();
			zephir_get_strval(_11, _10);
			ZEPHIR_CPY_WRT(type, _11);
			if (ZEPHIR_IS_STRING(operator, "not")) {
				ZEPHIR_INIT_NVAR(not);
				ZVAL_STRING(not, "!", 1);
			} else {
				ZEPHIR_INIT_NVAR(not);
				ZVAL_EMPTY_STRING(not);
			}
			if (ZEPHIR_IS_STRING(type, "numeric")) {
				zephir_array_fetch_long(&_13, props, 1, PH_NOISY | PH_READONLY, "bolt/app/view/Compiler.zep", 557 TSRMLS_CC);
				ZEPHIR_CALL_METHOD(&_12, this_ptr, "compileproperty", NULL, _13);
				zephir_check_call_status();
				ZEPHIR_INIT_LNVAR(_6);
				ZEPHIR_CONCAT_SVSVS(_6, "<?if(", not, "is_numeric(", _12, ")):?>");
				ZEPHIR_CALL_METHOD(NULL, this_ptr, "addtoblock", NULL, _6);
				zephir_check_call_status();
			} else if (ZEPHIR_IS_STRING(type, "odd")) {
				zephir_array_fetch_long(&_13, props, 1, PH_NOISY | PH_READONLY, "bolt/app/view/Compiler.zep", 559 TSRMLS_CC);
				ZEPHIR_CALL_METHOD(&_12, this_ptr, "compileproperty", NULL, _13);
				zephir_check_call_status();
				ZEPHIR_INIT_VAR(_14);
				if (not && Z_STRLEN_P(not)) {
					ZEPHIR_INIT_NVAR(_14);
					ZVAL_STRING(_14, "=", 1);
				} else {
					ZEPHIR_INIT_NVAR(_14);
					ZVAL_STRING(_14, "!", 1);
				}
				ZEPHIR_INIT_VAR(_15);
				ZEPHIR_CONCAT_SVSVS(_15, "<?if(", _12, " % 2 ", _14, "= 0)):?>");
				ZEPHIR_CALL_METHOD(NULL, this_ptr, "addtoblock", NULL, _15);
				zephir_check_call_status();
			} else if (ZEPHIR_IS_STRING(type, "even")) {
				zephir_array_fetch_long(&_13, props, 1, PH_NOISY | PH_READONLY, "bolt/app/view/Compiler.zep", 561 TSRMLS_CC);
				ZEPHIR_CALL_METHOD(&_12, this_ptr, "compileproperty", NULL, _13);
				zephir_check_call_status();
				ZEPHIR_INIT_LNVAR(_14);
				if (not && Z_STRLEN_P(not)) {
					ZEPHIR_INIT_NVAR(_14);
					ZVAL_STRING(_14, "!", 1);
				} else {
					ZEPHIR_INIT_NVAR(_14);
					ZVAL_STRING(_14, "=", 1);
				}
				ZEPHIR_INIT_LNVAR(_15);
				ZEPHIR_CONCAT_SVSVS(_15, "<?if(", _12, " % 2 ", _14, "= 0)):?>");
				ZEPHIR_CALL_METHOD(NULL, this_ptr, "addtoblock", NULL, _15);
				zephir_check_call_status();
			} else if (ZEPHIR_IS_STRING(type, "empty")) {
				zephir_array_fetch_long(&_13, props, 1, PH_NOISY | PH_READONLY, "bolt/app/view/Compiler.zep", 563 TSRMLS_CC);
				ZEPHIR_CALL_METHOD(&_12, this_ptr, "compileproperty", NULL, _13);
				zephir_check_call_status();
				ZEPHIR_INIT_LNVAR(_14);
				ZEPHIR_CONCAT_SVSVS(_14, "<?if(", not, "empty(", _12, ")):?>");
				ZEPHIR_CALL_METHOD(NULL, this_ptr, "addtoblock", NULL, _14);
				zephir_check_call_status();
			} else if (ZEPHIR_IS_STRING(type, "defined")) {
				zephir_array_fetch_long(&_13, props, 1, PH_NOISY | PH_READONLY, "bolt/app/view/Compiler.zep", 565 TSRMLS_CC);
				ZEPHIR_CALL_METHOD(&_12, this_ptr, "compileproperty", NULL, _13);
				zephir_check_call_status();
				ZEPHIR_INIT_LNVAR(_14);
				ZEPHIR_CONCAT_SVSVS(_14, "<?if(", not, "isset(", _12, ")):?>");
				ZEPHIR_CALL_METHOD(NULL, this_ptr, "addtoblock", NULL, _14);
				zephir_check_call_status();
			} else if (ZEPHIR_IS_STRING(type, "email")) {
				zephir_array_fetch_long(&_13, props, 1, PH_NOISY | PH_READONLY, "bolt/app/view/Compiler.zep", 567 TSRMLS_CC);
				ZEPHIR_CALL_METHOD(&_12, this_ptr, "compileproperty", NULL, _13);
				zephir_check_call_status();
				ZEPHIR_INIT_LNVAR(_14);
				ZEPHIR_CONCAT_SVSVS(_14, "<?if(", not, "filter_var(", _12, ", FILTER_VALIDATE_EMAIL)):?>");
				ZEPHIR_CALL_METHOD(NULL, this_ptr, "addtoblock", NULL, _14);
				zephir_check_call_status();
			} else {
				zephir_array_fetch_long(&_13, props, 1, PH_NOISY | PH_READONLY, "bolt/app/view/Compiler.zep", 569 TSRMLS_CC);
				ZEPHIR_CALL_METHOD(&_12, this_ptr, "compileproperty", NULL, _13);
				zephir_check_call_status();
				ZEPHIR_INIT_LNVAR(_14);
				ZEPHIR_CONCAT_SVSVSVS(_14, "<?if(", not, "(", _12, " instanceof ", type, ")):?>");
				ZEPHIR_CALL_METHOD(NULL, this_ptr, "addtoblock", NULL, _14);
				zephir_check_call_status();
			}
			RETURN_MM_NULL();
		} else if (ZEPHIR_IS_STRING(operator, "in")) {
			zephir_array_fetch_long(&_9, props, 3, PH_NOISY | PH_READONLY, "bolt/app/view/Compiler.zep", 573 TSRMLS_CC);
			ZEPHIR_CALL_METHOD(&_10, this_ptr, "compileproperty", NULL, _9);
			zephir_check_call_status();
			zephir_array_fetch_long(&_13, props, 1, PH_NOISY | PH_READONLY, "bolt/app/view/Compiler.zep", 573 TSRMLS_CC);
			ZEPHIR_CALL_METHOD(&_12, this_ptr, "compileproperty", NULL, _13);
			zephir_check_call_status();
			zephir_array_fetch_long(&_17, props, 3, PH_NOISY | PH_READONLY, "bolt/app/view/Compiler.zep", 573 TSRMLS_CC);
			ZEPHIR_CALL_METHOD(&_16, this_ptr, "compileproperty", NULL, _17);
			zephir_check_call_status();
			zephir_array_fetch_long(&_19, props, 3, PH_NOISY | PH_READONLY, "bolt/app/view/Compiler.zep", 573 TSRMLS_CC);
			ZEPHIR_CALL_METHOD(&_18, this_ptr, "compileproperty", NULL, _19);
			zephir_check_call_status();
			zephir_array_fetch_long(&_21, props, 1, PH_NOISY | PH_READONLY, "bolt/app/view/Compiler.zep", 573 TSRMLS_CC);
			ZEPHIR_CALL_METHOD(&_20, this_ptr, "compileproperty", NULL, _21);
			zephir_check_call_status();
			zephir_array_fetch_long(&_23, props, 3, PH_NOISY | PH_READONLY, "bolt/app/view/Compiler.zep", 573 TSRMLS_CC);
			ZEPHIR_CALL_METHOD(&_22, this_ptr, "compileproperty", NULL, _23);
			zephir_check_call_status();
			ZEPHIR_INIT_LNVAR(_14);
			ZEPHIR_CONCAT_SVSVSVSVSVSVS(_14, "<?if((is_array(", _10, ") && in_array(", _12, ", ", _16, ")) || (is_string(", _18, ") && strpos(", _20, ", ", _22, ") !== false)):?>");
			ZEPHIR_CALL_METHOD(NULL, this_ptr, "addtoblock", NULL, _14);
			zephir_check_call_status();
			RETURN_MM_NULL();
		} else if (ZEPHIR_IS_STRING(operator, "eq")) {
			zephir_array_fetch_long(&_9, props, 1, PH_NOISY | PH_READONLY, "bolt/app/view/Compiler.zep", 576 TSRMLS_CC);
			ZEPHIR_CALL_METHOD(&_10, this_ptr, "compileproperty", NULL, _9);
			zephir_check_call_status();
			zephir_array_fetch_long(&_17, props, 3, PH_NOISY | PH_READONLY, "bolt/app/view/Compiler.zep", 576 TSRMLS_CC);
			ZEPHIR_CALL_METHOD(&_16, this_ptr, "compileproperty", NULL, _17);
			zephir_check_call_status();
			ZEPHIR_INIT_LNVAR(_15);
			ZEPHIR_CONCAT_SVSVS(_15, "<?if(", _10, " == ", _16, "):?>");
			ZEPHIR_CALL_METHOD(NULL, this_ptr, "addtoblock", NULL, _15);
			zephir_check_call_status();
			RETURN_MM_NULL();
		} else if (ZEPHIR_IS_STRING(operator, "neq")) {
			zephir_array_fetch_long(&_9, props, 1, PH_NOISY | PH_READONLY, "bolt/app/view/Compiler.zep", 579 TSRMLS_CC);
			ZEPHIR_CALL_METHOD(&_10, this_ptr, "compileproperty", NULL, _9);
			zephir_check_call_status();
			zephir_array_fetch_long(&_17, props, 3, PH_NOISY | PH_READONLY, "bolt/app/view/Compiler.zep", 579 TSRMLS_CC);
			ZEPHIR_CALL_METHOD(&_16, this_ptr, "compileproperty", NULL, _17);
			zephir_check_call_status();
			ZEPHIR_INIT_VAR(_24);
			ZEPHIR_CONCAT_SVSVS(_24, "<?if(", _10, " != ", _16, "):?>");
			ZEPHIR_CALL_METHOD(NULL, this_ptr, "addtoblock", NULL, _24);
			zephir_check_call_status();
			RETURN_MM_NULL();
		} else if (ZEPHIR_IS_STRING(operator, "lt")) {
			zephir_array_fetch_long(&_9, props, 1, PH_NOISY | PH_READONLY, "bolt/app/view/Compiler.zep", 582 TSRMLS_CC);
			ZEPHIR_CALL_METHOD(&_10, this_ptr, "compileproperty", NULL, _9);
			zephir_check_call_status();
			zephir_array_fetch_long(&_17, props, 3, PH_NOISY | PH_READONLY, "bolt/app/view/Compiler.zep", 582 TSRMLS_CC);
			ZEPHIR_CALL_METHOD(&_16, this_ptr, "compileproperty", NULL, _17);
			zephir_check_call_status();
			ZEPHIR_INIT_LNVAR(_24);
			ZEPHIR_CONCAT_SVSVS(_24, "<?if(", _10, " < ", _16, "):?>");
			ZEPHIR_CALL_METHOD(NULL, this_ptr, "addtoblock", NULL, _24);
			zephir_check_call_status();
			RETURN_MM_NULL();
		} else if (ZEPHIR_IS_STRING(operator, "lte")) {
			zephir_array_fetch_long(&_9, props, 1, PH_NOISY | PH_READONLY, "bolt/app/view/Compiler.zep", 585 TSRMLS_CC);
			ZEPHIR_CALL_METHOD(&_10, this_ptr, "compileproperty", NULL, _9);
			zephir_check_call_status();
			zephir_array_fetch_long(&_17, props, 3, PH_NOISY | PH_READONLY, "bolt/app/view/Compiler.zep", 585 TSRMLS_CC);
			ZEPHIR_CALL_METHOD(&_16, this_ptr, "compileproperty", NULL, _17);
			zephir_check_call_status();
			ZEPHIR_INIT_LNVAR(_24);
			ZEPHIR_CONCAT_SVSVS(_24, "<?if(", _10, " <= ", _16, "):?>");
			ZEPHIR_CALL_METHOD(NULL, this_ptr, "addtoblock", NULL, _24);
			zephir_check_call_status();
			RETURN_MM_NULL();
		} else if (ZEPHIR_IS_STRING(operator, "gt")) {
			zephir_array_fetch_long(&_9, props, 1, PH_NOISY | PH_READONLY, "bolt/app/view/Compiler.zep", 588 TSRMLS_CC);
			ZEPHIR_CALL_METHOD(&_10, this_ptr, "compileproperty", NULL, _9);
			zephir_check_call_status();
			zephir_array_fetch_long(&_17, props, 3, PH_NOISY | PH_READONLY, "bolt/app/view/Compiler.zep", 588 TSRMLS_CC);
			ZEPHIR_CALL_METHOD(&_16, this_ptr, "compileproperty", NULL, _17);
			zephir_check_call_status();
			ZEPHIR_INIT_LNVAR(_24);
			ZEPHIR_CONCAT_SVSVS(_24, "<?if(", _10, " > ", _16, "):?>");
			ZEPHIR_CALL_METHOD(NULL, this_ptr, "addtoblock", NULL, _24);
			zephir_check_call_status();
			RETURN_MM_NULL();
		} else if (ZEPHIR_IS_STRING(operator, "gte")) {
			zephir_array_fetch_long(&_9, props, 1, PH_NOISY | PH_READONLY, "bolt/app/view/Compiler.zep", 591 TSRMLS_CC);
			ZEPHIR_CALL_METHOD(&_10, this_ptr, "compileproperty", NULL, _9);
			zephir_check_call_status();
			zephir_array_fetch_long(&_17, props, 3, PH_NOISY | PH_READONLY, "bolt/app/view/Compiler.zep", 591 TSRMLS_CC);
			ZEPHIR_CALL_METHOD(&_16, this_ptr, "compileproperty", NULL, _17);
			zephir_check_call_status();
			ZEPHIR_INIT_LNVAR(_24);
			ZEPHIR_CONCAT_SVSVS(_24, "<?if(", _10, " >= ", _16, "):?>");
			ZEPHIR_CALL_METHOD(NULL, this_ptr, "addtoblock", NULL, _24);
			zephir_check_call_status();
			RETURN_MM_NULL();
		} else if (ZEPHIR_IS_STRING(operator, "contains")) {
			zephir_array_fetch_long(&_9, props, 1, PH_NOISY | PH_READONLY, "bolt/app/view/Compiler.zep", 594 TSRMLS_CC);
			ZEPHIR_CALL_METHOD(&_10, this_ptr, "compileproperty", NULL, _9);
			zephir_check_call_status();
			zephir_array_fetch_long(&_17, props, 3, PH_NOISY | PH_READONLY, "bolt/app/view/Compiler.zep", 594 TSRMLS_CC);
			ZEPHIR_CALL_METHOD(&_16, this_ptr, "compileproperty", NULL, _17);
			zephir_check_call_status();
			ZEPHIR_INIT_LNVAR(_24);
			ZEPHIR_CONCAT_SVSVS(_24, "<?if(strpos(", _10, ", ", _16, ") !== false):?>");
			ZEPHIR_CALL_METHOD(NULL, this_ptr, "addtoblock", NULL, _24);
			zephir_check_call_status();
			RETURN_MM_NULL();
		} else if (ZEPHIR_IS_STRING(operator, "matches")) {
			zephir_array_fetch_long(&_9, props, 3, PH_NOISY | PH_READONLY, "bolt/app/view/Compiler.zep", 597 TSRMLS_CC);
			ZEPHIR_CALL_METHOD(&_10, _9, "getvalue", NULL);
			zephir_check_call_status();
			zephir_array_fetch_long(&_17, props, 1, PH_NOISY | PH_READONLY, "bolt/app/view/Compiler.zep", 597 TSRMLS_CC);
			ZEPHIR_CALL_METHOD(&_16, this_ptr, "compileproperty", NULL, _17);
			zephir_check_call_status();
			ZEPHIR_INIT_LNVAR(_24);
			ZEPHIR_CONCAT_SVSVS(_24, "<?if(preg_match('", _10, "', ", _16, ")):?>");
			ZEPHIR_CALL_METHOD(NULL, this_ptr, "addtoblock", NULL, _24);
			zephir_check_call_status();
			RETURN_MM_NULL();
		}
		ZEPHIR_INIT_VAR(_25);
		object_init_ex(_25, bolt_app_view_exception_ce);
		ZEPHIR_INIT_VAR(_26);
		ZEPHIR_CONCAT_SVS(_26, "Unsupported operator `", operator, "` in {% if %} block");
		ZEPHIR_CALL_METHOD(NULL, _25, "__construct", NULL, _26);
		zephir_check_call_status();
		zephir_throw_exception_debug(_25, "bolt/app/view/Compiler.zep", 600 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	} else {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(bolt_app_view_exception_ce, "Unsupported expression in {% if %} block", "bolt/app/view/Compiler.zep", 603);
		return;
	}

}

PHP_METHOD(Bolt_App_View_Compiler, _compileEndIf) {

	zend_bool _2;
	int ZEPHIR_LAST_CALL_STATUS;
	zephir_nts_static zephir_fcall_cache_entry *_1 = NULL, *_6 = NULL;
	zval *compiler, *node, *element = NULL, *_0, *_3, *_4, *_5;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &compiler, &node);



	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_elements"), PH_NOISY_CC);
	Z_SET_ISREF_P(_0);
	ZEPHIR_CALL_FUNCTION(&element, "end", &_1, _0);
	Z_UNSET_ISREF_P(_0);
	zephir_check_call_status();
	_2 = !zephir_is_true(element);
	if (!(_2)) {
		zephir_array_fetch_string(&_3, element, SL("type"), PH_NOISY | PH_READONLY, "bolt/app/view/Compiler.zep", 612 TSRMLS_CC);
		_2 = !ZEPHIR_IS_STRING(_3, "if");
	}
	if (_2) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(bolt_app_view_exception_ce, "Cannot use {% endif %} element outside {% if %} context", "bolt/app/view/Compiler.zep", 613);
		return;
	}
	ZEPHIR_INIT_VAR(_4);
	ZVAL_STRING(_4, "<?endif?>", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "addtoblock", NULL, _4);
	zephir_check_temp_parameter(_4);
	zephir_check_call_status();
	_5 = zephir_fetch_nproperty_this(this_ptr, SL("_elements"), PH_NOISY_CC);
	Z_SET_ISREF_P(_5);
	ZEPHIR_CALL_FUNCTION(NULL, "array_pop", &_6, _5);
	Z_UNSET_ISREF_P(_5);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Bolt_App_View_Compiler, _getHeader) {

	int ZEPHIR_LAST_CALL_STATUS;
	zephir_nts_static zephir_fcall_cache_entry *_2 = NULL;
	zval *_0, *_1 = NULL, *_3;

	ZEPHIR_MM_GROW();

	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_file"), PH_NOISY_CC);
	ZEPHIR_CALL_FUNCTION(&_1, "md5", &_2, _0);
	zephir_check_call_status();
	_3 = zephir_fetch_nproperty_this(this_ptr, SL("_extends"), PH_NOISY_CC);
	ZEPHIR_CONCAT_SVSVS(return_value, "class _BoltTemplate_", _1, " extends ", _3, " \n{\n");
	RETURN_MM();

}

PHP_METHOD(Bolt_App_View_Compiler, _getFooter) {


	RETURN_STRING("\n}", 1);

}

PHP_METHOD(Bolt_App_View_Compiler, getBlocks) {


	RETURN_MEMBER(this_ptr, "_blocks");

}

PHP_METHOD(Bolt_App_View_Compiler, getMain) {


	RETURN_MEMBER(this_ptr, "_main");

}

PHP_METHOD(Bolt_App_View_Compiler, output) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *_0 = NULL, *_1 = NULL, *_2 = NULL;

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(&_0, this_ptr, "_getheader", NULL);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_1, this_ptr, "getmain", NULL);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_2, this_ptr, "_getfooter", NULL);
	zephir_check_call_status();
	ZEPHIR_CONCAT_VSVSV(return_value, _0, "\npublic function render($context = null) {\n ?>", _1, "<?\n}", _2);
	RETURN_MM();

}

