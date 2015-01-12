
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
#include "kernel/fcall.h"
#include "kernel/object.h"
#include "kernel/operators.h"
#include "kernel/hash.h"
#include "kernel/array.h"


ZEPHIR_INIT_CLASS(Bolt_App_View_Template) {

	ZEPHIR_REGISTER_CLASS(Bolt\\App\\View, Template, bolt, app_view_template, bolt_app_view_template_method_entry, ZEND_ACC_EXPLICIT_ABSTRACT_CLASS);

	zend_declare_property_null(bolt_app_view_template_ce, SL("_vars"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(bolt_app_view_template_ce, SL("_filePath"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(bolt_app_view_template_ce, SL("_filters"), ZEND_ACC_PROTECTED|ZEND_ACC_STATIC TSRMLS_CC);

	return SUCCESS;

}

PHP_METHOD(Bolt_App_View_Template, __construct) {

	int ZEPHIR_LAST_CALL_STATUS;
	zephir_nts_static zend_class_entry *_1 = NULL;
	zval *_0;

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(_0);
	if (!_1) {
		_1 = zend_fetch_class(SL("Bolt\\App\\View\\stdClass"), ZEND_FETCH_CLASS_AUTO TSRMLS_CC);
	}
	object_init_ex(_0, _1);
	if (zephir_has_constructor(_0 TSRMLS_CC)) {
		ZEPHIR_CALL_METHOD(NULL, _0, "__construct", NULL);
		zephir_check_call_status();
	}
	zephir_update_property_this(this_ptr, SL("_vars"), _0 TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Bolt_App_View_Template, render) {

	HashTable *_1;
	HashPosition _0;
	zval *vars = NULL, *key = NULL, *item = NULL, **_2;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &vars);

	if (!vars) {
		vars = ZEPHIR_GLOBAL(global_null);
	}


	if (zephir_is_true(vars)) {
		zephir_is_iterable(vars, &_1, &_0, 0, 0, "bolt/app/view/Template.zep", 22);
		for (
		  ; zephir_hash_get_current_data_ex(_1, (void**) &_2, &_0) == SUCCESS
		  ; zephir_hash_move_forward_ex(_1, &_0)
		) {
			ZEPHIR_GET_HMKEY(key, _1, _0);
			ZEPHIR_GET_HVALUE(item, _2);
			zephir_update_property_array(this_ptr, SL("_vars"), key, item TSRMLS_CC);
		}
	}
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Bolt_App_View_Template, _filter) {

	zval *_2;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *name, *args, *val, *_0, *_1;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 0, &name, &args, &val);



	_0 = zephir_fetch_static_property_ce(bolt_app_view_template_ce, SL("_filters") TSRMLS_CC);
	if (!(zephir_array_isset(_0, name))) {
		RETVAL_ZVAL(val, 1, 0);
		RETURN_MM();
	}
	_1 = zephir_fetch_static_property_ce(bolt_app_view_template_ce, SL("_filters") TSRMLS_CC);
	ZEPHIR_INIT_VAR(_2);
	array_init_size(_2, 3);
	zephir_array_fast_append(_2, val);
	zephir_array_fast_append(_2, args);
	ZEPHIR_CALL_USER_FUNC_ARRAY(return_value, _1, _2);
	zephir_check_call_status();
	RETURN_MM();

}

