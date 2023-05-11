--TEST--
Check if include_logger is loaded
--EXTENSIONS--
include_logger
--FILE--
<?php
echo 'The extension "include_logger" is available';
?>
--EXPECTF--
The extension "include_logger" is available
Including file: %s/001.php
