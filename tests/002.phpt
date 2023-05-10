--TEST--
test1() Basic test
--EXTENSIONS--
include_logger
--FILE--
<?php
$ret = test1();

var_dump($ret);
?>
--EXPECT--
The extension include_logger is loaded and working!
NULL
