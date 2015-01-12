<?php
header("Conent-Type: text/plain");

$time = microtime();


$parser = new \Bolt\App\View\Parser( __DIR__ . '/test.htm');
//$parser->getTokenizer()->scan();
$compiler = new \Bolt\App\View\Compiler($parser);
$compiler->compile();
//$tree = $parser->parse();
//print_r($parser->getTokenizer()->getTokens());
//print_r($parser->_debugTree($tree));
//print_r($tree);
//print_r($compiler->_compileProperty($tree->child(2)->getProperties()[0]));

print_r($compiler->output());


echo microtime() - $time;
