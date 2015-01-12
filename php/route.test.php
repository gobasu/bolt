<?php
header("Content-Type: text\plain");
echo "a";
$router = new \Bolt\App\Router();
$router->mount('/{path}', function() {echo 'route';});
//print_r($router);
//$router->unmount('/{path}');

print_r($router);
print_r($router->match('/dupa'));