
/* This file was generated automatically by Zephir do not modify it! */

#ifndef PHP_BOLT_H
#define PHP_BOLT_H 1

#ifdef PHP_WIN32
#define ZEPHIR_RELEASE 1
#endif

#include "kernel/globals.h"

#define PHP_BOLT_NAME        "bolt"
#define PHP_BOLT_VERSION     "0.0.1"
#define PHP_BOLT_EXTNAME     "bolt"
#define PHP_BOLT_AUTHOR      ""
#define PHP_BOLT_ZEPVERSION  "0.5.9a"
#define PHP_BOLT_DESCRIPTION ""



ZEND_BEGIN_MODULE_GLOBALS(bolt)

	int initialized;

	/* Memory */
	zephir_memory_entry *start_memory; /**< The first preallocated frame */
	zephir_memory_entry *end_memory; /**< The last preallocate frame */
	zephir_memory_entry *active_memory; /**< The current memory frame */

	/* Virtual Symbol Tables */
	zephir_symbol_table *active_symbol_table;

	/** Function cache */
	HashTable *fcache;

	/* Cache enabled */
	unsigned int cache_enabled;

	/* Max recursion control */
	unsigned int recursive_lock;

	/* Global constants */
	zval *global_true;
	zval *global_false;
	zval *global_null;
	
ZEND_END_MODULE_GLOBALS(bolt)

#ifdef ZTS
#include "TSRM.h"
#endif

ZEND_EXTERN_MODULE_GLOBALS(bolt)

#ifdef ZTS
	#define ZEPHIR_GLOBAL(v) TSRMG(bolt_globals_id, zend_bolt_globals *, v)
#else
	#define ZEPHIR_GLOBAL(v) (bolt_globals.v)
#endif

#ifdef ZTS
	#define ZEPHIR_VGLOBAL ((zend_bolt_globals *) (*((void ***) tsrm_ls))[TSRM_UNSHUFFLE_RSRC_ID(bolt_globals_id)])
#else
	#define ZEPHIR_VGLOBAL &(bolt_globals)
#endif

#define ZEPHIR_API ZEND_API

#define zephir_globals_def bolt_globals
#define zend_zephir_globals_def zend_bolt_globals

extern zend_module_entry bolt_module_entry;
#define phpext_bolt_ptr &bolt_module_entry

#endif
