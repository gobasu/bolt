
/* This file was generated automatically by Zephir do not modify it! */

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include <php.h>

#if PHP_VERSION_ID < 50500
#include <locale.h>
#endif

#include "php_ext.h"
#include "bolt.h"

#include <ext/standard/info.h>

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/fcall.h"
#include "kernel/memory.h"



zend_class_entry *bolt_exception_ce;
zend_class_entry *bolt_app_exception_ce;
zend_class_entry *bolt_app_router_ce;
zend_class_entry *bolt_app_router_exception_ce;
zend_class_entry *bolt_app_router_route_ce;
zend_class_entry *bolt_app_view_ce;
zend_class_entry *bolt_app_view_compiler_ce;
zend_class_entry *bolt_app_view_context_ce;
zend_class_entry *bolt_app_view_exception_ce;
zend_class_entry *bolt_app_view_parser_ce;
zend_class_entry *bolt_app_view_parser_node_ce;
zend_class_entry *bolt_app_view_template_ce;
zend_class_entry *bolt_app_view_tokenizer_ce;
zend_class_entry *bolt_http_request_ce;

ZEND_DECLARE_MODULE_GLOBALS(bolt)

static PHP_MINIT_FUNCTION(bolt)
{
#if PHP_VERSION_ID < 50500
	char* old_lc_all = setlocale(LC_ALL, NULL);
	if (old_lc_all) {
		size_t len = strlen(old_lc_all);
		char *tmp  = calloc(len+1, 1);
		if (UNEXPECTED(!tmp)) {
			return FAILURE;
		}

		memcpy(tmp, old_lc_all, len);
		old_lc_all = tmp;
	}

	setlocale(LC_ALL, "C");
#endif

	ZEPHIR_INIT(Bolt_Exception);
	ZEPHIR_INIT(Bolt_App_Exception);
	ZEPHIR_INIT(Bolt_App_Router);
	ZEPHIR_INIT(Bolt_App_Router_Exception);
	ZEPHIR_INIT(Bolt_App_Router_Route);
	ZEPHIR_INIT(Bolt_App_View);
	ZEPHIR_INIT(Bolt_App_View_Compiler);
	ZEPHIR_INIT(Bolt_App_View_Context);
	ZEPHIR_INIT(Bolt_App_View_Exception);
	ZEPHIR_INIT(Bolt_App_View_Parser);
	ZEPHIR_INIT(Bolt_App_View_Parser_Node);
	ZEPHIR_INIT(Bolt_App_View_Template);
	ZEPHIR_INIT(Bolt_App_View_Tokenizer);
	ZEPHIR_INIT(Bolt_Http_Request);

#if PHP_VERSION_ID < 50500
	setlocale(LC_ALL, old_lc_all);
	free(old_lc_all);
#endif
	return SUCCESS;
}

#ifndef ZEPHIR_RELEASE
static PHP_MSHUTDOWN_FUNCTION(bolt)
{

	zephir_deinitialize_memory(TSRMLS_C);

	return SUCCESS;
}
#endif

/**
 * Initialize globals on each request or each thread started
 */
static void php_zephir_init_globals(zend_bolt_globals *zephir_globals TSRMLS_DC)
{
	zephir_globals->initialized = 0;

	/* Memory options */
	zephir_globals->active_memory = NULL;

	/* Virtual Symbol Tables */
	zephir_globals->active_symbol_table = NULL;

	/* Cache Enabled */
	zephir_globals->cache_enabled = 1;

	/* Recursive Lock */
	zephir_globals->recursive_lock = 0;


}

static PHP_RINIT_FUNCTION(bolt)
{

	zend_bolt_globals *zephir_globals_ptr = ZEPHIR_VGLOBAL;

	php_zephir_init_globals(zephir_globals_ptr TSRMLS_CC);
	//zephir_init_interned_strings(TSRMLS_C);

	zephir_initialize_memory(zephir_globals_ptr TSRMLS_CC);

	return SUCCESS;
}

static PHP_RSHUTDOWN_FUNCTION(bolt)
{

	

	zephir_deinitialize_memory(TSRMLS_C);
	return SUCCESS;
}

static PHP_MINFO_FUNCTION(bolt)
{
	php_info_print_box_start(0);
	php_printf("%s", PHP_BOLT_DESCRIPTION);
	php_info_print_box_end();

	php_info_print_table_start();
	php_info_print_table_header(2, PHP_BOLT_NAME, "enabled");
	php_info_print_table_row(2, "Author", PHP_BOLT_AUTHOR);
	php_info_print_table_row(2, "Version", PHP_BOLT_VERSION);
	php_info_print_table_row(2, "Powered by Zephir", "Version " PHP_BOLT_ZEPVERSION);
	php_info_print_table_end();


}

static PHP_GINIT_FUNCTION(bolt)
{
	php_zephir_init_globals(bolt_globals TSRMLS_CC);
}

static PHP_GSHUTDOWN_FUNCTION(bolt)
{

}

zend_module_entry bolt_module_entry = {
	STANDARD_MODULE_HEADER_EX,
	NULL,
	NULL,
	PHP_BOLT_EXTNAME,
	NULL,
	PHP_MINIT(bolt),
#ifndef ZEPHIR_RELEASE
	PHP_MSHUTDOWN(bolt),
#else
	NULL,
#endif
	PHP_RINIT(bolt),
	PHP_RSHUTDOWN(bolt),
	PHP_MINFO(bolt),
	PHP_BOLT_VERSION,
	ZEND_MODULE_GLOBALS(bolt),
	PHP_GINIT(bolt),
	PHP_GSHUTDOWN(bolt),
	NULL,
	STANDARD_MODULE_PROPERTIES_EX
};

#ifdef COMPILE_DL_BOLT
ZEND_GET_MODULE(bolt)
#endif
