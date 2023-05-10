/* include_logger extension for PHP (c) 2023 Florian Engelhardt */

#ifndef PHP_INCLUDE_LOGGER_H
# define PHP_INCLUDE_LOGGER_H

extern zend_module_entry include_logger_module_entry;
# define phpext_include_logger_ptr &include_logger_module_entry

# define PHP_INCLUDE_LOGGER_VERSION "0.1.0"

# if defined(ZTS) && defined(COMPILE_DL_INCLUDE_LOGGER)
ZEND_TSRMLS_CACHE_EXTERN()
# endif

#endif	/* PHP_INCLUDE_LOGGER_H */
