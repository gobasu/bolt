PHP_ARG_ENABLE(bolt, whether to enable bolt, [ --enable-bolt   Enable Bolt])

if test "$PHP_BOLT" = "yes"; then

	

	if ! test "x" = "x"; then
		PHP_EVAL_LIBLINE(, BOLT_SHARED_LIBADD)
	fi

	AC_DEFINE(HAVE_BOLT, 1, [Whether you have Bolt])
	bolt_sources="bolt.c kernel/main.c kernel/memory.c kernel/exception.c kernel/hash.c kernel/debug.c kernel/backtrace.c kernel/object.c kernel/array.c kernel/extended/array.c kernel/string.c kernel/fcall.c kernel/require.c kernel/file.c kernel/operators.c kernel/concat.c kernel/variables.c kernel/filter.c kernel/iterator.c kernel/exit.c bolt/exception.zep.c
	bolt/app/exception.zep.c
	bolt/app/router.zep.c
	bolt/app/view.zep.c
	bolt/app/router/exception.zep.c
	bolt/app/router/route.zep.c
	bolt/app/view/compiler.zep.c
	bolt/app/view/context.zep.c
	bolt/app/view/exception.zep.c
	bolt/app/view/parser.zep.c
	bolt/app/view/template.zep.c
	bolt/app/view/tokenizer.zep.c
	bolt/app/view/parser/node.zep.c
	bolt/http/request.zep.c "
	PHP_NEW_EXTENSION(bolt, $bolt_sources, $ext_shared,, )
	PHP_SUBST(BOLT_SHARED_LIBADD)

	old_CPPFLAGS=$CPPFLAGS
	CPPFLAGS="$CPPFLAGS $INCLUDES"

	AC_CHECK_DECL(
		[HAVE_BUNDLED_PCRE],
		[
			AC_CHECK_HEADERS(
				[ext/pcre/php_pcre.h],
				[
					PHP_ADD_EXTENSION_DEP([bolt], [pcre])
					AC_DEFINE([ZEPHIR_USE_PHP_PCRE], [1], [Whether PHP pcre extension is present at compile time])
				],
				,
				[[#include "main/php.h"]]
			)
		],
		,
		[[#include "php_config.h"]]
	)

	AC_CHECK_DECL(
		[HAVE_JSON],
		[
			AC_CHECK_HEADERS(
				[ext/json/php_json.h],
				[
					PHP_ADD_EXTENSION_DEP([bolt], [json])
					AC_DEFINE([ZEPHIR_USE_PHP_JSON], [1], [Whether PHP json extension is present at compile time])
				],
				,
				[[#include "main/php.h"]]
			)
		],
		,
		[[#include "php_config.h"]]
	)

	CPPFLAGS=$old_CPPFLAGS

	PHP_INSTALL_HEADERS([ext/bolt], [php_BOLT.h])

fi
