
extern zend_class_entry *bolt_app_view_parser_node_ce;

ZEPHIR_INIT_CLASS(Bolt_App_View_Parser_Node);

PHP_METHOD(Bolt_App_View_Parser_Node, __construct);
PHP_METHOD(Bolt_App_View_Parser_Node, isRoot);
PHP_METHOD(Bolt_App_View_Parser_Node, getParent);
PHP_METHOD(Bolt_App_View_Parser_Node, setParent);
PHP_METHOD(Bolt_App_View_Parser_Node, addChild);
PHP_METHOD(Bolt_App_View_Parser_Node, addArgument);
PHP_METHOD(Bolt_App_View_Parser_Node, addModifier);
PHP_METHOD(Bolt_App_View_Parser_Node, setHandler);
PHP_METHOD(Bolt_App_View_Parser_Node, addProperty);
PHP_METHOD(Bolt_App_View_Parser_Node, hasProperties);
PHP_METHOD(Bolt_App_View_Parser_Node, hasModifiers);
PHP_METHOD(Bolt_App_View_Parser_Node, hasChildren);
PHP_METHOD(Bolt_App_View_Parser_Node, hasArguments);
PHP_METHOD(Bolt_App_View_Parser_Node, getProperties);
PHP_METHOD(Bolt_App_View_Parser_Node, getModifiers);
PHP_METHOD(Bolt_App_View_Parser_Node, getArguments);
PHP_METHOD(Bolt_App_View_Parser_Node, getChildren);
PHP_METHOD(Bolt_App_View_Parser_Node, setAsScalar);
PHP_METHOD(Bolt_App_View_Parser_Node, isScalar);
PHP_METHOD(Bolt_App_View_Parser_Node, child);
PHP_METHOD(Bolt_App_View_Parser_Node, property);
PHP_METHOD(Bolt_App_View_Parser_Node, argument);
PHP_METHOD(Bolt_App_View_Parser_Node, getValue);
PHP_METHOD(Bolt_App_View_Parser_Node, getType);
PHP_METHOD(Bolt_App_View_Parser_Node, setAsFunction);
PHP_METHOD(Bolt_App_View_Parser_Node, isFunction);
PHP_METHOD(Bolt_App_View_Parser_Node, getStringifiedType);

ZEND_BEGIN_ARG_INFO_EX(arginfo_bolt_app_view_parser_node___construct, 0, 0, 0)
	ZEND_ARG_INFO(0, type)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_bolt_app_view_parser_node_setparent, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, parent, Bolt\\App\\View\\Parser\\Node, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_bolt_app_view_parser_node_addchild, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, child, Bolt\\App\\View\\Parser\\Node, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_bolt_app_view_parser_node_addargument, 0, 0, 1)
	ZEND_ARG_INFO(0, arg)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_bolt_app_view_parser_node_addmodifier, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, modifier, Bolt\\App\\View\\Parser\\Node, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_bolt_app_view_parser_node_sethandler, 0, 0, 1)
	ZEND_ARG_INFO(0, handler)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_bolt_app_view_parser_node_addproperty, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, property, Bolt\\App\\View\\Parser\\Node, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_bolt_app_view_parser_node_child, 0, 0, 1)
	ZEND_ARG_INFO(0, at)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_bolt_app_view_parser_node_property, 0, 0, 1)
	ZEND_ARG_INFO(0, at)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_bolt_app_view_parser_node_argument, 0, 0, 1)
	ZEND_ARG_INFO(0, at)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(bolt_app_view_parser_node_method_entry) {
	PHP_ME(Bolt_App_View_Parser_Node, __construct, arginfo_bolt_app_view_parser_node___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Bolt_App_View_Parser_Node, isRoot, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Bolt_App_View_Parser_Node, getParent, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Bolt_App_View_Parser_Node, setParent, arginfo_bolt_app_view_parser_node_setparent, ZEND_ACC_PUBLIC)
	PHP_ME(Bolt_App_View_Parser_Node, addChild, arginfo_bolt_app_view_parser_node_addchild, ZEND_ACC_PUBLIC)
	PHP_ME(Bolt_App_View_Parser_Node, addArgument, arginfo_bolt_app_view_parser_node_addargument, ZEND_ACC_PUBLIC)
	PHP_ME(Bolt_App_View_Parser_Node, addModifier, arginfo_bolt_app_view_parser_node_addmodifier, ZEND_ACC_PUBLIC)
	PHP_ME(Bolt_App_View_Parser_Node, setHandler, arginfo_bolt_app_view_parser_node_sethandler, ZEND_ACC_PUBLIC)
	PHP_ME(Bolt_App_View_Parser_Node, addProperty, arginfo_bolt_app_view_parser_node_addproperty, ZEND_ACC_PUBLIC)
	PHP_ME(Bolt_App_View_Parser_Node, hasProperties, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Bolt_App_View_Parser_Node, hasModifiers, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Bolt_App_View_Parser_Node, hasChildren, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Bolt_App_View_Parser_Node, hasArguments, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Bolt_App_View_Parser_Node, getProperties, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Bolt_App_View_Parser_Node, getModifiers, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Bolt_App_View_Parser_Node, getArguments, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Bolt_App_View_Parser_Node, getChildren, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Bolt_App_View_Parser_Node, setAsScalar, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Bolt_App_View_Parser_Node, isScalar, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Bolt_App_View_Parser_Node, child, arginfo_bolt_app_view_parser_node_child, ZEND_ACC_PUBLIC)
	PHP_ME(Bolt_App_View_Parser_Node, property, arginfo_bolt_app_view_parser_node_property, ZEND_ACC_PUBLIC)
	PHP_ME(Bolt_App_View_Parser_Node, argument, arginfo_bolt_app_view_parser_node_argument, ZEND_ACC_PUBLIC)
	PHP_ME(Bolt_App_View_Parser_Node, getValue, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Bolt_App_View_Parser_Node, getType, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Bolt_App_View_Parser_Node, setAsFunction, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Bolt_App_View_Parser_Node, isFunction, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Bolt_App_View_Parser_Node, getStringifiedType, NULL, ZEND_ACC_PUBLIC)
  PHP_FE_END
};
