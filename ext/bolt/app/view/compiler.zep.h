
extern zend_class_entry *bolt_app_view_compiler_ce;

ZEPHIR_INIT_CLASS(Bolt_App_View_Compiler);

PHP_METHOD(Bolt_App_View_Compiler, __construct);
PHP_METHOD(Bolt_App_View_Compiler, compile);
PHP_METHOD(Bolt_App_View_Compiler, addExpressionHandler);
PHP_METHOD(Bolt_App_View_Compiler, addElementHandler);
PHP_METHOD(Bolt_App_View_Compiler, _compileNode);
PHP_METHOD(Bolt_App_View_Compiler, _compileText);
PHP_METHOD(Bolt_App_View_Compiler, addToBlock);
PHP_METHOD(Bolt_App_View_Compiler, addToMain);
PHP_METHOD(Bolt_App_View_Compiler, getCurrentLoop);
PHP_METHOD(Bolt_App_View_Compiler, _compileElement);
PHP_METHOD(Bolt_App_View_Compiler, _compileExpression);
PHP_METHOD(Bolt_App_View_Compiler, compileProperty);
PHP_METHOD(Bolt_App_View_Compiler, _compileScalar);
PHP_METHOD(Bolt_App_View_Compiler, _compileModifiers);
PHP_METHOD(Bolt_App_View_Compiler, _compileArgument);
PHP_METHOD(Bolt_App_View_Compiler, _compileInclude);
PHP_METHOD(Bolt_App_View_Compiler, _compileExtend);
PHP_METHOD(Bolt_App_View_Compiler, _compileI18n);
PHP_METHOD(Bolt_App_View_Compiler, _compileParent);
PHP_METHOD(Bolt_App_View_Compiler, _compileContinue);
PHP_METHOD(Bolt_App_View_Compiler, _compileBreak);
PHP_METHOD(Bolt_App_View_Compiler, _compileBlock);
PHP_METHOD(Bolt_App_View_Compiler, _compileEndBlock);
PHP_METHOD(Bolt_App_View_Compiler, _compileFor);
PHP_METHOD(Bolt_App_View_Compiler, _compileEndFor);
PHP_METHOD(Bolt_App_View_Compiler, _compileElse);
PHP_METHOD(Bolt_App_View_Compiler, _compileIf);
PHP_METHOD(Bolt_App_View_Compiler, _compileEndIf);
PHP_METHOD(Bolt_App_View_Compiler, _getHeader);
PHP_METHOD(Bolt_App_View_Compiler, _getFooter);
PHP_METHOD(Bolt_App_View_Compiler, getBlocks);
PHP_METHOD(Bolt_App_View_Compiler, getMain);
PHP_METHOD(Bolt_App_View_Compiler, output);

ZEND_BEGIN_ARG_INFO_EX(arginfo_bolt_app_view_compiler___construct, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, parser, Bolt\\App\\View\\Parser, 0)
	ZEND_ARG_INFO(0, file)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_bolt_app_view_compiler_addexpressionhandler, 0, 0, 2)
	ZEND_ARG_INFO(0, name)
	ZEND_ARG_INFO(0, handler)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_bolt_app_view_compiler_addelementhandler, 0, 0, 2)
	ZEND_ARG_INFO(0, open)
	ZEND_ARG_INFO(0, openHandler)
	ZEND_ARG_INFO(0, close)
	ZEND_ARG_INFO(0, closeHandler)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_bolt_app_view_compiler__compilenode, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, node, Bolt\\App\\View\\Parser\\Node, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_bolt_app_view_compiler__compiletext, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, node, Bolt\\App\\View\\Parser\\Node, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_bolt_app_view_compiler_addtoblock, 0, 0, 1)
	ZEND_ARG_INFO(0, str)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_bolt_app_view_compiler_addtomain, 0, 0, 1)
	ZEND_ARG_INFO(0, str)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_bolt_app_view_compiler__compileelement, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, node, Bolt\\App\\View\\Parser\\Node, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_bolt_app_view_compiler__compileexpression, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, node, Bolt\\App\\View\\Parser\\Node, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_bolt_app_view_compiler_compileproperty, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, node, Bolt\\App\\View\\Parser\\Node, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_bolt_app_view_compiler__compilescalar, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, node, Bolt\\App\\View\\Parser\\Node, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_bolt_app_view_compiler__compilemodifiers, 0, 0, 2)
	ZEND_ARG_OBJ_INFO(0, node, Bolt\\App\\View\\Parser\\Node, 0)
	ZEND_ARG_INFO(0, param)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_bolt_app_view_compiler__compileargument, 0, 0, 1)
	ZEND_ARG_INFO(0, item)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_bolt_app_view_compiler__compileinclude, 0, 0, 2)
	ZEND_ARG_INFO(0, compiler)
	ZEND_ARG_INFO(0, node)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_bolt_app_view_compiler__compileextend, 0, 0, 2)
	ZEND_ARG_INFO(0, compiler)
	ZEND_ARG_INFO(0, node)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_bolt_app_view_compiler__compilei18n, 0, 0, 2)
	ZEND_ARG_INFO(0, compiler)
	ZEND_ARG_INFO(0, node)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_bolt_app_view_compiler__compileparent, 0, 0, 2)
	ZEND_ARG_INFO(0, compiler)
	ZEND_ARG_INFO(0, node)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_bolt_app_view_compiler__compilecontinue, 0, 0, 2)
	ZEND_ARG_INFO(0, compiler)
	ZEND_ARG_INFO(0, node)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_bolt_app_view_compiler__compilebreak, 0, 0, 2)
	ZEND_ARG_INFO(0, compiler)
	ZEND_ARG_INFO(0, node)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_bolt_app_view_compiler__compileblock, 0, 0, 2)
	ZEND_ARG_INFO(0, compiler)
	ZEND_ARG_INFO(0, node)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_bolt_app_view_compiler__compileendblock, 0, 0, 2)
	ZEND_ARG_INFO(0, compiler)
	ZEND_ARG_INFO(0, node)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_bolt_app_view_compiler__compilefor, 0, 0, 2)
	ZEND_ARG_INFO(0, compiler)
	ZEND_ARG_INFO(0, node)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_bolt_app_view_compiler__compileendfor, 0, 0, 2)
	ZEND_ARG_INFO(0, compiler)
	ZEND_ARG_INFO(0, node)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_bolt_app_view_compiler__compileelse, 0, 0, 2)
	ZEND_ARG_INFO(0, compiler)
	ZEND_ARG_INFO(0, node)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_bolt_app_view_compiler__compileif, 0, 0, 2)
	ZEND_ARG_INFO(0, compiler)
	ZEND_ARG_INFO(0, node)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_bolt_app_view_compiler__compileendif, 0, 0, 2)
	ZEND_ARG_INFO(0, compiler)
	ZEND_ARG_INFO(0, node)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(bolt_app_view_compiler_method_entry) {
	PHP_ME(Bolt_App_View_Compiler, __construct, arginfo_bolt_app_view_compiler___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Bolt_App_View_Compiler, compile, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Bolt_App_View_Compiler, addExpressionHandler, arginfo_bolt_app_view_compiler_addexpressionhandler, ZEND_ACC_PUBLIC)
	PHP_ME(Bolt_App_View_Compiler, addElementHandler, arginfo_bolt_app_view_compiler_addelementhandler, ZEND_ACC_PUBLIC)
	PHP_ME(Bolt_App_View_Compiler, _compileNode, arginfo_bolt_app_view_compiler__compilenode, ZEND_ACC_PUBLIC)
	PHP_ME(Bolt_App_View_Compiler, _compileText, arginfo_bolt_app_view_compiler__compiletext, ZEND_ACC_PROTECTED)
	PHP_ME(Bolt_App_View_Compiler, addToBlock, arginfo_bolt_app_view_compiler_addtoblock, ZEND_ACC_PUBLIC)
	PHP_ME(Bolt_App_View_Compiler, addToMain, arginfo_bolt_app_view_compiler_addtomain, ZEND_ACC_PUBLIC)
	PHP_ME(Bolt_App_View_Compiler, getCurrentLoop, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Bolt_App_View_Compiler, _compileElement, arginfo_bolt_app_view_compiler__compileelement, ZEND_ACC_PROTECTED)
	PHP_ME(Bolt_App_View_Compiler, _compileExpression, arginfo_bolt_app_view_compiler__compileexpression, ZEND_ACC_PUBLIC)
	PHP_ME(Bolt_App_View_Compiler, compileProperty, arginfo_bolt_app_view_compiler_compileproperty, ZEND_ACC_PUBLIC)
	PHP_ME(Bolt_App_View_Compiler, _compileScalar, arginfo_bolt_app_view_compiler__compilescalar, ZEND_ACC_PUBLIC)
	PHP_ME(Bolt_App_View_Compiler, _compileModifiers, arginfo_bolt_app_view_compiler__compilemodifiers, ZEND_ACC_PUBLIC)
	PHP_ME(Bolt_App_View_Compiler, _compileArgument, arginfo_bolt_app_view_compiler__compileargument, ZEND_ACC_PUBLIC)
	PHP_ME(Bolt_App_View_Compiler, _compileInclude, arginfo_bolt_app_view_compiler__compileinclude, ZEND_ACC_PUBLIC)
	PHP_ME(Bolt_App_View_Compiler, _compileExtend, arginfo_bolt_app_view_compiler__compileextend, ZEND_ACC_PUBLIC)
	PHP_ME(Bolt_App_View_Compiler, _compileI18n, arginfo_bolt_app_view_compiler__compilei18n, ZEND_ACC_PUBLIC)
	PHP_ME(Bolt_App_View_Compiler, _compileParent, arginfo_bolt_app_view_compiler__compileparent, ZEND_ACC_PUBLIC)
	PHP_ME(Bolt_App_View_Compiler, _compileContinue, arginfo_bolt_app_view_compiler__compilecontinue, ZEND_ACC_PUBLIC)
	PHP_ME(Bolt_App_View_Compiler, _compileBreak, arginfo_bolt_app_view_compiler__compilebreak, ZEND_ACC_PUBLIC)
	PHP_ME(Bolt_App_View_Compiler, _compileBlock, arginfo_bolt_app_view_compiler__compileblock, ZEND_ACC_PUBLIC)
	PHP_ME(Bolt_App_View_Compiler, _compileEndBlock, arginfo_bolt_app_view_compiler__compileendblock, ZEND_ACC_PUBLIC)
	PHP_ME(Bolt_App_View_Compiler, _compileFor, arginfo_bolt_app_view_compiler__compilefor, ZEND_ACC_PUBLIC)
	PHP_ME(Bolt_App_View_Compiler, _compileEndFor, arginfo_bolt_app_view_compiler__compileendfor, ZEND_ACC_PUBLIC)
	PHP_ME(Bolt_App_View_Compiler, _compileElse, arginfo_bolt_app_view_compiler__compileelse, ZEND_ACC_PUBLIC)
	PHP_ME(Bolt_App_View_Compiler, _compileIf, arginfo_bolt_app_view_compiler__compileif, ZEND_ACC_PUBLIC)
	PHP_ME(Bolt_App_View_Compiler, _compileEndIf, arginfo_bolt_app_view_compiler__compileendif, ZEND_ACC_PUBLIC)
	PHP_ME(Bolt_App_View_Compiler, _getHeader, NULL, ZEND_ACC_PROTECTED)
	PHP_ME(Bolt_App_View_Compiler, _getFooter, NULL, ZEND_ACC_PROTECTED)
	PHP_ME(Bolt_App_View_Compiler, getBlocks, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Bolt_App_View_Compiler, getMain, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Bolt_App_View_Compiler, output, NULL, ZEND_ACC_PUBLIC)
  PHP_FE_END
};
