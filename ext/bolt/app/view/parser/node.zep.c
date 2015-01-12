
#ifdef HAVE_CONFIG_H
#include "../../../../ext_config.h"
#endif

#include <php.h>
#include "../../../../php_ext.h"
#include "../../../../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/memory.h"
#include "kernel/object.h"
#include "kernel/operators.h"
#include "kernel/exception.h"
#include "kernel/fcall.h"
#include "kernel/array.h"

ZEPHIR_INIT_CLASS(Bolt_App_View_Parser_Node) {

	ZEPHIR_REGISTER_CLASS(Bolt\\App\\View\\Parser, Node, bolt, app_view_parser_node, bolt_app_view_parser_node_method_entry, 0);

	zend_declare_property_long(bolt_app_view_parser_node_ce, SL("_type"), -1, ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_string(bolt_app_view_parser_node_ce, SL("_value"), "", ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(bolt_app_view_parser_node_ce, SL("_arguments"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(bolt_app_view_parser_node_ce, SL("_handler"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(bolt_app_view_parser_node_ce, SL("_parent"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(bolt_app_view_parser_node_ce, SL("_children"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(bolt_app_view_parser_node_ce, SL("_modifiers"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(bolt_app_view_parser_node_ce, SL("_properties"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_bool(bolt_app_view_parser_node_ce, SL("_isFunction"), 0, ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_bool(bolt_app_view_parser_node_ce, SL("_isScalar"), 0, ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(bolt_app_view_parser_node_ce, SL("_key"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_class_constant_long(bolt_app_view_parser_node_ce, SL("TYPE_NODE"), -1 TSRMLS_CC);

	zend_declare_class_constant_long(bolt_app_view_parser_node_ce, SL("TYPE_TEXT"), 0 TSRMLS_CC);

	zend_declare_class_constant_long(bolt_app_view_parser_node_ce, SL("TYPE_ELEMENT"), 1 TSRMLS_CC);

	zend_declare_class_constant_long(bolt_app_view_parser_node_ce, SL("TYPE_EXPRESSION"), 2 TSRMLS_CC);

	zend_declare_class_constant_long(bolt_app_view_parser_node_ce, SL("TYPE_MODIFIER"), 3 TSRMLS_CC);

	zend_declare_class_constant_long(bolt_app_view_parser_node_ce, SL("TYPE_PROPERTY"), 4 TSRMLS_CC);

	return SUCCESS;

}

PHP_METHOD(Bolt_App_View_Parser_Node, __construct) {

	zval *type = NULL, *value = NULL, *_0, *_1, *_2, *_3;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 2, &type, &value);

	if (!type) {
		ZEPHIR_INIT_VAR(type);
		ZVAL_LONG(type, -1);
	}
	if (!value) {
		value = ZEPHIR_GLOBAL(global_null);
	}


	ZEPHIR_INIT_VAR(_0);
	array_init(_0);
	zephir_update_property_this(this_ptr, SL("_properties"), _0 TSRMLS_CC);
	ZEPHIR_INIT_VAR(_1);
	array_init(_1);
	zephir_update_property_this(this_ptr, SL("_modifiers"), _1 TSRMLS_CC);
	ZEPHIR_INIT_VAR(_2);
	array_init(_2);
	zephir_update_property_this(this_ptr, SL("_children"), _2 TSRMLS_CC);
	ZEPHIR_INIT_VAR(_3);
	array_init(_3);
	zephir_update_property_this(this_ptr, SL("_arguments"), _3 TSRMLS_CC);
	zephir_update_property_this(this_ptr, SL("_type"), type TSRMLS_CC);
	zephir_update_property_this(this_ptr, SL("_value"), value TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Bolt_App_View_Parser_Node, isRoot) {

	zval *_0;


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_parent"), PH_NOISY_CC);
	RETURN_BOOL(Z_TYPE_P(_0) == IS_NULL);

}

PHP_METHOD(Bolt_App_View_Parser_Node, getParent) {


	RETURN_MEMBER(this_ptr, "_parent");

}

PHP_METHOD(Bolt_App_View_Parser_Node, setParent) {

	zval *parent;

	zephir_fetch_params(0, 1, 0, &parent);



	if (!(zephir_instance_of_ev(parent, bolt_app_view_parser_node_ce TSRMLS_CC))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STRW(spl_ce_InvalidArgumentException, "Parameter 'parent' must be an instance of 'Bolt\\App\\View\\Parser\\Node'", "", 0);
		return;
	}
	zephir_update_property_this(this_ptr, SL("_parent"), parent TSRMLS_CC);

}

PHP_METHOD(Bolt_App_View_Parser_Node, addChild) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *child;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &child);



	if (!(zephir_instance_of_ev(child, bolt_app_view_parser_node_ce TSRMLS_CC))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_InvalidArgumentException, "Parameter 'child' must be an instance of 'Bolt\\App\\View\\Parser\\Node'", "", 0);
		return;
	}
	ZEPHIR_CALL_METHOD(NULL, child, "setparent", NULL, this_ptr);
	zephir_check_call_status();
	zephir_update_property_array_append(this_ptr, SL("_children"), child TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Bolt_App_View_Parser_Node, addArgument) {

	zval *arg;

	zephir_fetch_params(0, 1, 0, &arg);



	zephir_update_property_array_append(this_ptr, SL("_arguments"), arg TSRMLS_CC);

}

PHP_METHOD(Bolt_App_View_Parser_Node, addModifier) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *modifier;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &modifier);



	if (!(zephir_instance_of_ev(modifier, bolt_app_view_parser_node_ce TSRMLS_CC))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_InvalidArgumentException, "Parameter 'modifier' must be an instance of 'Bolt\\App\\View\\Parser\\Node'", "", 0);
		return;
	}
	ZEPHIR_CALL_METHOD(NULL, modifier, "setparent", NULL, this_ptr);
	zephir_check_call_status();
	zephir_update_property_array_append(this_ptr, SL("_modifiers"), modifier TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Bolt_App_View_Parser_Node, setHandler) {

	zval *handler;

	zephir_fetch_params(0, 1, 0, &handler);



	zephir_update_property_this(this_ptr, SL("_handler"), handler TSRMLS_CC);

}

PHP_METHOD(Bolt_App_View_Parser_Node, addProperty) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *property;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &property);



	if (!(zephir_instance_of_ev(property, bolt_app_view_parser_node_ce TSRMLS_CC))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_InvalidArgumentException, "Parameter 'property' must be an instance of 'Bolt\\App\\View\\Parser\\Node'", "", 0);
		return;
	}
	ZEPHIR_CALL_METHOD(NULL, property, "setparent", NULL, this_ptr);
	zephir_check_call_status();
	zephir_update_property_array_append(this_ptr, SL("_properties"), property TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Bolt_App_View_Parser_Node, hasProperties) {

	zval *_0, *_1;

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(_0);
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("_properties"), PH_NOISY_CC);
	if (zephir_fast_count_int(_1 TSRMLS_CC) > 0) {
		ZVAL_BOOL(_0, 1);
	} else {
		ZVAL_BOOL(_0, 0);
	}
	RETURN_CCTOR(_0);

}

PHP_METHOD(Bolt_App_View_Parser_Node, hasModifiers) {

	zval *_0, *_1;

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(_0);
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("_modifiers"), PH_NOISY_CC);
	if (zephir_fast_count_int(_1 TSRMLS_CC) > 0) {
		ZVAL_BOOL(_0, 1);
	} else {
		ZVAL_BOOL(_0, 0);
	}
	RETURN_CCTOR(_0);

}

PHP_METHOD(Bolt_App_View_Parser_Node, hasChildren) {

	zval *_0, *_1;

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(_0);
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("_children"), PH_NOISY_CC);
	if (zephir_fast_count_int(_1 TSRMLS_CC) > 0) {
		ZVAL_BOOL(_0, 1);
	} else {
		ZVAL_BOOL(_0, 0);
	}
	RETURN_CCTOR(_0);

}

PHP_METHOD(Bolt_App_View_Parser_Node, hasArguments) {

	zval *_0, *_1;

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(_0);
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("_arguments"), PH_NOISY_CC);
	if (zephir_fast_count_int(_1 TSRMLS_CC) > 0) {
		ZVAL_BOOL(_0, 1);
	} else {
		ZVAL_BOOL(_0, 0);
	}
	RETURN_CCTOR(_0);

}

PHP_METHOD(Bolt_App_View_Parser_Node, getProperties) {


	RETURN_MEMBER(this_ptr, "_properties");

}

PHP_METHOD(Bolt_App_View_Parser_Node, getModifiers) {


	RETURN_MEMBER(this_ptr, "_modifiers");

}

PHP_METHOD(Bolt_App_View_Parser_Node, getArguments) {


	RETURN_MEMBER(this_ptr, "_arguments");

}

PHP_METHOD(Bolt_App_View_Parser_Node, getChildren) {


	RETURN_MEMBER(this_ptr, "_children");

}

PHP_METHOD(Bolt_App_View_Parser_Node, setAsScalar) {


	zephir_update_property_this(this_ptr, SL("_isScalar"), (1) ? ZEPHIR_GLOBAL(global_true) : ZEPHIR_GLOBAL(global_false) TSRMLS_CC);

}

PHP_METHOD(Bolt_App_View_Parser_Node, isScalar) {


	RETURN_MEMBER(this_ptr, "_isScalar");

}

PHP_METHOD(Bolt_App_View_Parser_Node, child) {

	zval *at_param = NULL, *_0, *_1, *_2;
	int at;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &at_param);

	at = zephir_get_intval(at_param);


	ZEPHIR_INIT_VAR(_0);
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("_children"), PH_NOISY_CC);
	if (zephir_array_isset_long(_1, at)) {
		_2 = zephir_fetch_nproperty_this(this_ptr, SL("_children"), PH_NOISY_CC);
		zephir_array_fetch_long(&_0, _2, at, PH_NOISY, "bolt/app/view/parser/Node.zep", 128 TSRMLS_CC);
	} else {
		ZVAL_NULL(_0);
	}
	RETURN_CCTOR(_0);

}

PHP_METHOD(Bolt_App_View_Parser_Node, property) {

	zval *at_param = NULL, *_0, *_1, *_2;
	int at;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &at_param);

	at = zephir_get_intval(at_param);


	ZEPHIR_INIT_VAR(_0);
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("_properties"), PH_NOISY_CC);
	if (zephir_array_isset_long(_1, at)) {
		_2 = zephir_fetch_nproperty_this(this_ptr, SL("_properties"), PH_NOISY_CC);
		zephir_array_fetch_long(&_0, _2, at, PH_NOISY, "bolt/app/view/parser/Node.zep", 133 TSRMLS_CC);
	} else {
		ZVAL_NULL(_0);
	}
	RETURN_CCTOR(_0);

}

PHP_METHOD(Bolt_App_View_Parser_Node, argument) {

	zval *at_param = NULL, *_0, *_1, *_2;
	int at;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &at_param);

	at = zephir_get_intval(at_param);


	ZEPHIR_INIT_VAR(_0);
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("_arguments"), PH_NOISY_CC);
	if (zephir_array_isset_long(_1, at)) {
		_2 = zephir_fetch_nproperty_this(this_ptr, SL("_arguments"), PH_NOISY_CC);
		zephir_array_fetch_long(&_0, _2, at, PH_NOISY, "bolt/app/view/parser/Node.zep", 138 TSRMLS_CC);
	} else {
		ZVAL_NULL(_0);
	}
	RETURN_CCTOR(_0);

}

PHP_METHOD(Bolt_App_View_Parser_Node, getValue) {


	RETURN_MEMBER(this_ptr, "_value");

}

PHP_METHOD(Bolt_App_View_Parser_Node, getType) {


	RETURN_MEMBER(this_ptr, "_type");

}

PHP_METHOD(Bolt_App_View_Parser_Node, setAsFunction) {


	zephir_update_property_this(this_ptr, SL("_isFunction"), (1) ? ZEPHIR_GLOBAL(global_true) : ZEPHIR_GLOBAL(global_false) TSRMLS_CC);

}

PHP_METHOD(Bolt_App_View_Parser_Node, isFunction) {


	RETURN_MEMBER(this_ptr, "_isFunction");

}

PHP_METHOD(Bolt_App_View_Parser_Node, getStringifiedType) {

	zval *_0;


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_type"), PH_NOISY_CC);
	do {
		if (ZEPHIR_IS_LONG(_0, -1)) {
			RETURN_STRING("Node::TYPE_NODE", 1);
		}
		if (ZEPHIR_IS_LONG(_0, 0)) {
			RETURN_STRING("Node::TYPE_TEXT", 1);
		}
		if (ZEPHIR_IS_LONG(_0, 1)) {
			RETURN_STRING("Node::TYPE_ELEMENT", 1);
		}
		if (ZEPHIR_IS_LONG(_0, 2)) {
			RETURN_STRING("Node::TYPE_EXPRESSION", 1);
		}
		if (ZEPHIR_IS_LONG(_0, 3)) {
			RETURN_STRING("Node::TYPE_MODIFIER", 1);
		}
		if (ZEPHIR_IS_LONG(_0, 4)) {
			RETURN_STRING("Node::TYPE_PROPERTY", 1);
		}
	} while(0);


}

