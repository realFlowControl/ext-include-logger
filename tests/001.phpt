--TEST--
Check if include_logger is loaded
--EXTENSIONS--
include_logger
--INI--
error_log=/dev/stdout
--FILE--
<?php
echo 'The extension "include_logger" is available';
?>
--EXPECTF--
[%s] compiled file '%s/001.php' in %d nanoseconds
The extension "include_logger" is available
