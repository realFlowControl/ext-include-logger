/* include_logger extension for PHP (c) 2023 Florian Engelhardt */

#ifdef HAVE_CONFIG_H
# include "config.h"
#endif

#include "php.h"
#include "Zend/zend_compile.h"
#include "ext/standard/info.h"
#include "php_include_logger.h"

/* For compatibility with older PHP versions */
#ifndef ZEND_PARSE_PARAMETERS_NONE
#define ZEND_PARSE_PARAMETERS_NONE() \
    ZEND_PARSE_PARAMETERS_START(0, 0) \
    ZEND_PARSE_PARAMETERS_END()
#endif

zend_op_array *(*prev_zend_compile_file)(zend_file_handle *file_handle, int type);

zend_op_array *my_extension_compile_file(zend_file_handle *file_handle, int type)
{
    printf("\r\nIncluding file: %s\r\n", file_handle->filename->val);
    return prev_zend_compile_file(file_handle, type);
}

PHP_MINIT_FUNCTION(include_logger)
{
    prev_zend_compile_file = zend_compile_file;
    zend_compile_file = my_extension_compile_file;
    return SUCCESS;
}

PHP_MSHUTDOWN_FUNCTION(include_logger)
{
    zend_compile_file = prev_zend_compile_file;
    return SUCCESS;
}

zend_module_entry include_logger_module_entry = {
    STANDARD_MODULE_HEADER,
    "include_logger",               /* Extension name */
    NULL,                           /* zend_function_entry */
    PHP_MINIT(include_logger),      /* PHP_MINIT - Request initialization */
    PHP_MSHUTDOWN(include_logger),  /* PHP_MINIT - Request initialization */
    NULL,                           /* PHP_RINIT - Request initialization */
    NULL,                           /* PHP_RSHUTDOWN - Request shutdown */
    NULL,                           /* PHP_MINFO - Module info */
    PHP_INCLUDE_LOGGER_VERSION,     /* Version */
    STANDARD_MODULE_PROPERTIES
};

#ifdef COMPILE_DL_INCLUDE_LOGGER
# ifdef ZTS
ZEND_TSRMLS_CACHE_DEFINE()
# endif
ZEND_GET_MODULE(include_logger)
#endif
