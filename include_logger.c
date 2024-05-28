/* include_logger extension for PHP (c) 2023 Florian Engelhardt */

#include <stdio.h>
#ifdef HAVE_CONFIG_H
# include "config.h"
#endif

#include "php.h"
#include "Zend/zend_compile.h"
#include "ext/standard/info.h"
#include "ext/standard/basic_functions.h"
#include "php_include_logger.h"

// pointer to store previous handler
zend_op_array *(*prev_zend_compile_file)(zend_file_handle *file_handle, int type);

zend_op_array *my_extension_compile_file(zend_file_handle *file_handle, int type)
{
    struct timespec start, end;
    double time;
    zend_op_array* op_array = NULL;
    char log[2048];
    clock_gettime(CLOCK_MONOTONIC, &start);
    op_array = prev_zend_compile_file(file_handle, type);
    clock_gettime(CLOCK_MONOTONIC, &end);
    time = end.tv_nsec - start.tv_nsec + (end.tv_sec - start.tv_sec) * 1000000000;
    snprintf(log, 2048, "compiled file '%s' in %.0f nanoseconds", op_array->filename->val, time);
    _php_error_log(0, log, NULL, NULL);
    return op_array;
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
