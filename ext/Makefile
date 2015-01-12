srcdir = /Users/lunereaper/Projects/bolt/ext
builddir = /Users/lunereaper/Projects/bolt/ext
top_srcdir = /Users/lunereaper/Projects/bolt/ext
top_builddir = /Users/lunereaper/Projects/bolt/ext
EGREP = /usr/bin/grep -E
SED = /usr/bin/sed
CONFIGURE_COMMAND = './configure' '--enable-bolt'
CONFIGURE_OPTIONS = '--enable-bolt'
SHLIB_SUFFIX_NAME = dylib
SHLIB_DL_SUFFIX_NAME = so
ZEND_EXT_TYPE = zend_extension
RE2C = re2c
AWK = awk
shared_objects_bolt = bolt.lo kernel/main.lo kernel/memory.lo kernel/exception.lo kernel/hash.lo kernel/debug.lo kernel/backtrace.lo kernel/object.lo kernel/array.lo kernel/extended/array.lo kernel/string.lo kernel/fcall.lo kernel/require.lo kernel/file.lo kernel/operators.lo kernel/concat.lo kernel/variables.lo kernel/filter.lo kernel/iterator.lo kernel/exit.lo bolt/exception.lo bolt/app/exception.lo bolt/app/router.lo bolt/app/view.lo bolt/app/router/exception.lo bolt/app/router/route.lo bolt/app/view/compiler.lo bolt/app/view/context.lo bolt/app/view/exception.lo bolt/app/view/parser.lo bolt/app/view/template.lo bolt/app/view/tokenizer.lo bolt/app/view/parser/node.lo bolt/http/request.lo
PHP_PECL_EXTENSION = bolt
BOLT_SHARED_LIBADD =
PHP_MODULES = $(phplibdir)/bolt.la
PHP_ZEND_EX =
all_targets = $(PHP_MODULES) $(PHP_ZEND_EX)
install_targets = install-modules install-headers
prefix = /usr
exec_prefix = $(prefix)
libdir = ${exec_prefix}/lib
prefix = /usr
phplibdir = /Users/lunereaper/Projects/bolt/ext/modules
phpincludedir = /usr/include/php
CC = gcc
CFLAGS = -O2 -fvisibility=hidden -Wparentheses -flto -DZEPHIR_RELEASE=1
CFLAGS_CLEAN = $(CFLAGS)
CPP = gcc -E
CPPFLAGS = -DHAVE_CONFIG_H
CXX =
CXXFLAGS =
CXXFLAGS_CLEAN = $(CXXFLAGS)
EXTENSION_DIR = /usr/lib/php/extensions/no-debug-non-zts-20100525
PHP_EXECUTABLE = /usr/bin/php
EXTRA_LDFLAGS =
EXTRA_LIBS =
INCLUDES = -I/usr/include/php -I/usr/include/php/main -I/usr/include/php/TSRM -I/usr/include/php/Zend -I/usr/include/php/ext -I/usr/include/php/ext/date/lib
LFLAGS =
LDFLAGS =
SHARED_LIBTOOL =
LIBTOOL = $(SHELL) $(top_builddir)/libtool
SHELL = /bin/sh
INSTALL_HEADERS = ext/bolt/php_BOLT.h
mkinstalldirs = $(top_srcdir)/build/shtool mkdir -p
INSTALL = $(top_srcdir)/build/shtool install -c
INSTALL_DATA = $(INSTALL) -m 644

DEFS = -DPHP_ATOM_INC -I$(top_builddir)/include -I$(top_builddir)/main -I$(top_srcdir)
COMMON_FLAGS = $(DEFS) $(INCLUDES) $(EXTRA_INCLUDES) $(CPPFLAGS) $(PHP_FRAMEWORKPATH)

all: $(all_targets) 
	@echo
	@echo "Build complete."
	@echo "Don't forget to run 'make test'."
	@echo

build-modules: $(PHP_MODULES) $(PHP_ZEND_EX)

build-binaries: $(PHP_BINARIES)

libphp$(PHP_MAJOR_VERSION).la: $(PHP_GLOBAL_OBJS) $(PHP_SAPI_OBJS)
	$(LIBTOOL) --mode=link $(CC) $(CFLAGS) $(EXTRA_CFLAGS) -rpath $(phptempdir) $(EXTRA_LDFLAGS) $(LDFLAGS) $(PHP_RPATHS) $(PHP_GLOBAL_OBJS) $(PHP_SAPI_OBJS) $(EXTRA_LIBS) $(ZEND_EXTRA_LIBS) -o $@
	-@$(LIBTOOL) --silent --mode=install cp $@ $(phptempdir)/$@ >/dev/null 2>&1

libs/libphp$(PHP_MAJOR_VERSION).bundle: $(PHP_GLOBAL_OBJS) $(PHP_SAPI_OBJS)
	$(CC) $(MH_BUNDLE_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS) $(LDFLAGS) $(EXTRA_LDFLAGS) $(PHP_GLOBAL_OBJS:.lo=.o) $(PHP_SAPI_OBJS:.lo=.o) $(PHP_FRAMEWORKS) $(EXTRA_LIBS) $(ZEND_EXTRA_LIBS) -o $@ && cp $@ libs/libphp$(PHP_MAJOR_VERSION).so

install: $(all_targets) $(install_targets)

install-sapi: $(OVERALL_TARGET)
	@echo "Installing PHP SAPI module:       $(PHP_SAPI)"
	-@$(mkinstalldirs) $(INSTALL_ROOT)$(bindir)
	-@if test ! -r $(phptempdir)/libphp$(PHP_MAJOR_VERSION).$(SHLIB_DL_SUFFIX_NAME); then \
		for i in 0.0.0 0.0 0; do \
			if test -r $(phptempdir)/libphp$(PHP_MAJOR_VERSION).$(SHLIB_DL_SUFFIX_NAME).$$i; then \
				$(LN_S) $(phptempdir)/libphp$(PHP_MAJOR_VERSION).$(SHLIB_DL_SUFFIX_NAME).$$i $(phptempdir)/libphp$(PHP_MAJOR_VERSION).$(SHLIB_DL_SUFFIX_NAME); \
				break; \
			fi; \
		done; \
	fi
	@$(INSTALL_IT)

install-binaries: build-binaries $(install_binary_targets)

install-modules: build-modules
	@test -d modules && \
	$(mkinstalldirs) $(INSTALL_ROOT)$(EXTENSION_DIR)
	@echo "Installing shared extensions:     $(INSTALL_ROOT)$(EXTENSION_DIR)/"
	@rm -f modules/*.la >/dev/null 2>&1
	@$(INSTALL) modules/* $(INSTALL_ROOT)$(EXTENSION_DIR)

install-headers:
	-@if test "$(INSTALL_HEADERS)"; then \
		for i in `echo $(INSTALL_HEADERS)`; do \
			i=`$(top_srcdir)/build/shtool path -d $$i`; \
			paths="$$paths $(INSTALL_ROOT)$(phpincludedir)/$$i"; \
		done; \
		$(mkinstalldirs) $$paths && \
		echo "Installing header files:          $(INSTALL_ROOT)$(phpincludedir)/" && \
		for i in `echo $(INSTALL_HEADERS)`; do \
			if test "$(PHP_PECL_EXTENSION)"; then \
				src=`echo $$i | $(SED) -e "s#ext/$(PHP_PECL_EXTENSION)/##g"`; \
			else \
				src=$$i; \
			fi; \
			if test -f "$(top_srcdir)/$$src"; then \
				$(INSTALL_DATA) $(top_srcdir)/$$src $(INSTALL_ROOT)$(phpincludedir)/$$i; \
			elif test -f "$(top_builddir)/$$src"; then \
				$(INSTALL_DATA) $(top_builddir)/$$src $(INSTALL_ROOT)$(phpincludedir)/$$i; \
			else \
				(cd $(top_srcdir)/$$src && $(INSTALL_DATA) *.h $(INSTALL_ROOT)$(phpincludedir)/$$i; \
				cd $(top_builddir)/$$src && $(INSTALL_DATA) *.h $(INSTALL_ROOT)$(phpincludedir)/$$i) 2>/dev/null || true; \
			fi \
		done; \
	fi

PHP_TEST_SETTINGS = -d 'open_basedir=' -d 'output_buffering=0' -d 'memory_limit=-1'
PHP_TEST_SHARED_EXTENSIONS =  ` \
	if test "x$(PHP_MODULES)" != "x"; then \
		for i in $(PHP_MODULES)""; do \
			. $$i; $(top_srcdir)/build/shtool echo -n -- " -d extension=$$dlname"; \
		done; \
	fi; \
	if test "x$(PHP_ZEND_EX)" != "x"; then \
		for i in $(PHP_ZEND_EX)""; do \
			. $$i; $(top_srcdir)/build/shtool echo -n -- " -d $(ZEND_EXT_TYPE)=$(top_builddir)/modules/$$dlname"; \
		done; \
	fi`
PHP_DEPRECATED_DIRECTIVES_REGEX = '^(magic_quotes_(gpc|runtime|sybase)?|(zend_)?extension(_debug)?(_ts)?)[\t\ ]*='

test: all
	-@if test ! -z "$(PHP_EXECUTABLE)" && test -x "$(PHP_EXECUTABLE)"; then \
		INI_FILE=`$(PHP_EXECUTABLE) -d 'display_errors=stderr' -r 'echo php_ini_loaded_file();' 2> /dev/null`; \
		if test "$$INI_FILE"; then \
			$(EGREP) -h -v $(PHP_DEPRECATED_DIRECTIVES_REGEX) "$$INI_FILE" > $(top_builddir)/tmp-php.ini; \
		else \
			echo > $(top_builddir)/tmp-php.ini; \
		fi; \
		INI_SCANNED_PATH=`$(PHP_EXECUTABLE) -d 'display_errors=stderr' -r '$$a = explode(",\n", trim(php_ini_scanned_files())); echo $$a[0];' 2> /dev/null`; \
		if test "$$INI_SCANNED_PATH"; then \
			INI_SCANNED_PATH=`$(top_srcdir)/build/shtool path -d $$INI_SCANNED_PATH`; \
			$(EGREP) -h -v $(PHP_DEPRECATED_DIRECTIVES_REGEX) "$$INI_SCANNED_PATH"/*.ini >> $(top_builddir)/tmp-php.ini; \
		fi; \
		TEST_PHP_EXECUTABLE=$(PHP_EXECUTABLE) \
		TEST_PHP_SRCDIR=$(top_srcdir) \
		CC="$(CC)" \
			$(PHP_EXECUTABLE) -n -c $(top_builddir)/tmp-php.ini $(PHP_TEST_SETTINGS) $(top_srcdir)/run-tests.php -n -c $(top_builddir)/tmp-php.ini -d extension_dir=$(top_builddir)/modules/ $(PHP_TEST_SHARED_EXTENSIONS) $(TESTS); \
		rm $(top_builddir)/tmp-php.ini; \
	else \
		echo "ERROR: Cannot run tests without CLI sapi."; \
	fi

clean:
	find . -name \*.gcno -o -name \*.gcda | xargs rm -f
	find . -name \*.lo -o -name \*.o | xargs rm -f
	find . -name \*.la -o -name \*.a | xargs rm -f 
	find . -name \*.so | xargs rm -f
	find . -name .libs -a -type d|xargs rm -rf
	find . -name \*.1 | xargs rm -f
	rm -f libphp$(PHP_MAJOR_VERSION).la $(SAPI_CLI_PATH) $(OVERALL_TARGET) modules/* libs/*

distclean: clean
	rm -f Makefile config.cache config.log config.status Makefile.objects Makefile.fragments libtool main/php_config.h stamp-h sapi/apache/libphp$(PHP_MAJOR_VERSION).module buildmk.stamp Zend/zend_dtrace_gen.h Zend/zend_dtrace_gen.h.bak
	$(EGREP) define'.*include/php' $(top_srcdir)/configure | $(SED) 's/.*>//'|xargs rm -f

.PHONY: all clean install distclean test
.NOEXPORT:
bolt.lo: /Users/lunereaper/Projects/bolt/ext/bolt.c
	$(LIBTOOL) --mode=compile $(CC)  -I. -I/Users/lunereaper/Projects/bolt/ext $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS)  -c /Users/lunereaper/Projects/bolt/ext/bolt.c -o bolt.lo 
kernel/main.lo: /Users/lunereaper/Projects/bolt/ext/kernel/main.c
	$(LIBTOOL) --mode=compile $(CC)  -I. -I/Users/lunereaper/Projects/bolt/ext $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS)  -c /Users/lunereaper/Projects/bolt/ext/kernel/main.c -o kernel/main.lo 
kernel/memory.lo: /Users/lunereaper/Projects/bolt/ext/kernel/memory.c
	$(LIBTOOL) --mode=compile $(CC)  -I. -I/Users/lunereaper/Projects/bolt/ext $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS)  -c /Users/lunereaper/Projects/bolt/ext/kernel/memory.c -o kernel/memory.lo 
kernel/exception.lo: /Users/lunereaper/Projects/bolt/ext/kernel/exception.c
	$(LIBTOOL) --mode=compile $(CC)  -I. -I/Users/lunereaper/Projects/bolt/ext $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS)  -c /Users/lunereaper/Projects/bolt/ext/kernel/exception.c -o kernel/exception.lo 
kernel/hash.lo: /Users/lunereaper/Projects/bolt/ext/kernel/hash.c
	$(LIBTOOL) --mode=compile $(CC)  -I. -I/Users/lunereaper/Projects/bolt/ext $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS)  -c /Users/lunereaper/Projects/bolt/ext/kernel/hash.c -o kernel/hash.lo 
kernel/debug.lo: /Users/lunereaper/Projects/bolt/ext/kernel/debug.c
	$(LIBTOOL) --mode=compile $(CC)  -I. -I/Users/lunereaper/Projects/bolt/ext $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS)  -c /Users/lunereaper/Projects/bolt/ext/kernel/debug.c -o kernel/debug.lo 
kernel/backtrace.lo: /Users/lunereaper/Projects/bolt/ext/kernel/backtrace.c
	$(LIBTOOL) --mode=compile $(CC)  -I. -I/Users/lunereaper/Projects/bolt/ext $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS)  -c /Users/lunereaper/Projects/bolt/ext/kernel/backtrace.c -o kernel/backtrace.lo 
kernel/object.lo: /Users/lunereaper/Projects/bolt/ext/kernel/object.c
	$(LIBTOOL) --mode=compile $(CC)  -I. -I/Users/lunereaper/Projects/bolt/ext $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS)  -c /Users/lunereaper/Projects/bolt/ext/kernel/object.c -o kernel/object.lo 
kernel/array.lo: /Users/lunereaper/Projects/bolt/ext/kernel/array.c
	$(LIBTOOL) --mode=compile $(CC)  -I. -I/Users/lunereaper/Projects/bolt/ext $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS)  -c /Users/lunereaper/Projects/bolt/ext/kernel/array.c -o kernel/array.lo 
kernel/extended/array.lo: /Users/lunereaper/Projects/bolt/ext/kernel/extended/array.c
	$(LIBTOOL) --mode=compile $(CC)  -I. -I/Users/lunereaper/Projects/bolt/ext $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS)  -c /Users/lunereaper/Projects/bolt/ext/kernel/extended/array.c -o kernel/extended/array.lo 
kernel/string.lo: /Users/lunereaper/Projects/bolt/ext/kernel/string.c
	$(LIBTOOL) --mode=compile $(CC)  -I. -I/Users/lunereaper/Projects/bolt/ext $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS)  -c /Users/lunereaper/Projects/bolt/ext/kernel/string.c -o kernel/string.lo 
kernel/fcall.lo: /Users/lunereaper/Projects/bolt/ext/kernel/fcall.c
	$(LIBTOOL) --mode=compile $(CC)  -I. -I/Users/lunereaper/Projects/bolt/ext $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS)  -c /Users/lunereaper/Projects/bolt/ext/kernel/fcall.c -o kernel/fcall.lo 
kernel/require.lo: /Users/lunereaper/Projects/bolt/ext/kernel/require.c
	$(LIBTOOL) --mode=compile $(CC)  -I. -I/Users/lunereaper/Projects/bolt/ext $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS)  -c /Users/lunereaper/Projects/bolt/ext/kernel/require.c -o kernel/require.lo 
kernel/file.lo: /Users/lunereaper/Projects/bolt/ext/kernel/file.c
	$(LIBTOOL) --mode=compile $(CC)  -I. -I/Users/lunereaper/Projects/bolt/ext $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS)  -c /Users/lunereaper/Projects/bolt/ext/kernel/file.c -o kernel/file.lo 
kernel/operators.lo: /Users/lunereaper/Projects/bolt/ext/kernel/operators.c
	$(LIBTOOL) --mode=compile $(CC)  -I. -I/Users/lunereaper/Projects/bolt/ext $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS)  -c /Users/lunereaper/Projects/bolt/ext/kernel/operators.c -o kernel/operators.lo 
kernel/concat.lo: /Users/lunereaper/Projects/bolt/ext/kernel/concat.c
	$(LIBTOOL) --mode=compile $(CC)  -I. -I/Users/lunereaper/Projects/bolt/ext $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS)  -c /Users/lunereaper/Projects/bolt/ext/kernel/concat.c -o kernel/concat.lo 
kernel/variables.lo: /Users/lunereaper/Projects/bolt/ext/kernel/variables.c
	$(LIBTOOL) --mode=compile $(CC)  -I. -I/Users/lunereaper/Projects/bolt/ext $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS)  -c /Users/lunereaper/Projects/bolt/ext/kernel/variables.c -o kernel/variables.lo 
kernel/filter.lo: /Users/lunereaper/Projects/bolt/ext/kernel/filter.c
	$(LIBTOOL) --mode=compile $(CC)  -I. -I/Users/lunereaper/Projects/bolt/ext $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS)  -c /Users/lunereaper/Projects/bolt/ext/kernel/filter.c -o kernel/filter.lo 
kernel/iterator.lo: /Users/lunereaper/Projects/bolt/ext/kernel/iterator.c
	$(LIBTOOL) --mode=compile $(CC)  -I. -I/Users/lunereaper/Projects/bolt/ext $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS)  -c /Users/lunereaper/Projects/bolt/ext/kernel/iterator.c -o kernel/iterator.lo 
kernel/exit.lo: /Users/lunereaper/Projects/bolt/ext/kernel/exit.c
	$(LIBTOOL) --mode=compile $(CC)  -I. -I/Users/lunereaper/Projects/bolt/ext $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS)  -c /Users/lunereaper/Projects/bolt/ext/kernel/exit.c -o kernel/exit.lo 
bolt/exception.lo: /Users/lunereaper/Projects/bolt/ext/bolt/exception.zep.c
	$(LIBTOOL) --mode=compile $(CC)  -I. -I/Users/lunereaper/Projects/bolt/ext $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS)  -c /Users/lunereaper/Projects/bolt/ext/bolt/exception.zep.c -o bolt/exception.lo 
bolt/app/exception.lo: /Users/lunereaper/Projects/bolt/ext/bolt/app/exception.zep.c
	$(LIBTOOL) --mode=compile $(CC)  -I. -I/Users/lunereaper/Projects/bolt/ext $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS)  -c /Users/lunereaper/Projects/bolt/ext/bolt/app/exception.zep.c -o bolt/app/exception.lo 
bolt/app/router.lo: /Users/lunereaper/Projects/bolt/ext/bolt/app/router.zep.c
	$(LIBTOOL) --mode=compile $(CC)  -I. -I/Users/lunereaper/Projects/bolt/ext $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS)  -c /Users/lunereaper/Projects/bolt/ext/bolt/app/router.zep.c -o bolt/app/router.lo 
bolt/app/view.lo: /Users/lunereaper/Projects/bolt/ext/bolt/app/view.zep.c
	$(LIBTOOL) --mode=compile $(CC)  -I. -I/Users/lunereaper/Projects/bolt/ext $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS)  -c /Users/lunereaper/Projects/bolt/ext/bolt/app/view.zep.c -o bolt/app/view.lo 
bolt/app/router/exception.lo: /Users/lunereaper/Projects/bolt/ext/bolt/app/router/exception.zep.c
	$(LIBTOOL) --mode=compile $(CC)  -I. -I/Users/lunereaper/Projects/bolt/ext $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS)  -c /Users/lunereaper/Projects/bolt/ext/bolt/app/router/exception.zep.c -o bolt/app/router/exception.lo 
bolt/app/router/route.lo: /Users/lunereaper/Projects/bolt/ext/bolt/app/router/route.zep.c
	$(LIBTOOL) --mode=compile $(CC)  -I. -I/Users/lunereaper/Projects/bolt/ext $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS)  -c /Users/lunereaper/Projects/bolt/ext/bolt/app/router/route.zep.c -o bolt/app/router/route.lo 
bolt/app/view/compiler.lo: /Users/lunereaper/Projects/bolt/ext/bolt/app/view/compiler.zep.c
	$(LIBTOOL) --mode=compile $(CC)  -I. -I/Users/lunereaper/Projects/bolt/ext $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS)  -c /Users/lunereaper/Projects/bolt/ext/bolt/app/view/compiler.zep.c -o bolt/app/view/compiler.lo 
bolt/app/view/context.lo: /Users/lunereaper/Projects/bolt/ext/bolt/app/view/context.zep.c
	$(LIBTOOL) --mode=compile $(CC)  -I. -I/Users/lunereaper/Projects/bolt/ext $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS)  -c /Users/lunereaper/Projects/bolt/ext/bolt/app/view/context.zep.c -o bolt/app/view/context.lo 
bolt/app/view/exception.lo: /Users/lunereaper/Projects/bolt/ext/bolt/app/view/exception.zep.c
	$(LIBTOOL) --mode=compile $(CC)  -I. -I/Users/lunereaper/Projects/bolt/ext $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS)  -c /Users/lunereaper/Projects/bolt/ext/bolt/app/view/exception.zep.c -o bolt/app/view/exception.lo 
bolt/app/view/parser.lo: /Users/lunereaper/Projects/bolt/ext/bolt/app/view/parser.zep.c
	$(LIBTOOL) --mode=compile $(CC)  -I. -I/Users/lunereaper/Projects/bolt/ext $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS)  -c /Users/lunereaper/Projects/bolt/ext/bolt/app/view/parser.zep.c -o bolt/app/view/parser.lo 
bolt/app/view/template.lo: /Users/lunereaper/Projects/bolt/ext/bolt/app/view/template.zep.c
	$(LIBTOOL) --mode=compile $(CC)  -I. -I/Users/lunereaper/Projects/bolt/ext $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS)  -c /Users/lunereaper/Projects/bolt/ext/bolt/app/view/template.zep.c -o bolt/app/view/template.lo 
bolt/app/view/tokenizer.lo: /Users/lunereaper/Projects/bolt/ext/bolt/app/view/tokenizer.zep.c
	$(LIBTOOL) --mode=compile $(CC)  -I. -I/Users/lunereaper/Projects/bolt/ext $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS)  -c /Users/lunereaper/Projects/bolt/ext/bolt/app/view/tokenizer.zep.c -o bolt/app/view/tokenizer.lo 
bolt/app/view/parser/node.lo: /Users/lunereaper/Projects/bolt/ext/bolt/app/view/parser/node.zep.c
	$(LIBTOOL) --mode=compile $(CC)  -I. -I/Users/lunereaper/Projects/bolt/ext $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS)  -c /Users/lunereaper/Projects/bolt/ext/bolt/app/view/parser/node.zep.c -o bolt/app/view/parser/node.lo 
bolt/http/request.lo: /Users/lunereaper/Projects/bolt/ext/bolt/http/request.zep.c
	$(LIBTOOL) --mode=compile $(CC)  -I. -I/Users/lunereaper/Projects/bolt/ext $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS)  -c /Users/lunereaper/Projects/bolt/ext/bolt/http/request.zep.c -o bolt/http/request.lo 
$(phplibdir)/bolt.la: ./bolt.la
	$(LIBTOOL) --mode=install cp ./bolt.la $(phplibdir)

./bolt.la: $(shared_objects_bolt) $(BOLT_SHARED_DEPENDENCIES)
	$(LIBTOOL) --mode=link $(CC) $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS) $(LDFLAGS) -o $@ -export-dynamic -avoid-version -prefer-pic -module -rpath $(phplibdir) $(EXTRA_LDFLAGS) $(shared_objects_bolt) $(BOLT_SHARED_LIBADD)

