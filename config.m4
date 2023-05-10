dnl config.m4 for extension include_logger

dnl Comments in this file start with the string 'dnl'.
dnl Remove where necessary.

dnl If your extension references something external, use 'with':

dnl PHP_ARG_WITH([include_logger],
dnl   [for include_logger support],
dnl   [AS_HELP_STRING([--with-include_logger],
dnl     [Include include_logger support])])

dnl Otherwise use 'enable':

PHP_ARG_ENABLE([include_logger],
  [whether to enable include_logger support],
  [AS_HELP_STRING([--enable-include_logger],
    [Enable include_logger support])],
  [no])

if test "$PHP_INCLUDE_LOGGER" != "no"; then
  dnl Write more examples of tests here...

  dnl Remove this code block if the library does not support pkg-config.
  dnl PKG_CHECK_MODULES([LIBFOO], [foo])
  dnl PHP_EVAL_INCLINE($LIBFOO_CFLAGS)
  dnl PHP_EVAL_LIBLINE($LIBFOO_LIBS, INCLUDE_LOGGER_SHARED_LIBADD)

  dnl If you need to check for a particular library version using PKG_CHECK_MODULES,
  dnl you can use comparison operators. For example:
  dnl PKG_CHECK_MODULES([LIBFOO], [foo >= 1.2.3])
  dnl PKG_CHECK_MODULES([LIBFOO], [foo < 3.4])
  dnl PKG_CHECK_MODULES([LIBFOO], [foo = 1.2.3])

  dnl Remove this code block if the library supports pkg-config.
  dnl --with-include_logger -> check with-path
  dnl SEARCH_PATH="/usr/local /usr"     # you might want to change this
  dnl SEARCH_FOR="/include/include_logger.h"  # you most likely want to change this
  dnl if test -r $PHP_INCLUDE_LOGGER/$SEARCH_FOR; then # path given as parameter
  dnl   INCLUDE_LOGGER_DIR=$PHP_INCLUDE_LOGGER
  dnl else # search default path list
  dnl   AC_MSG_CHECKING([for include_logger files in default path])
  dnl   for i in $SEARCH_PATH ; do
  dnl     if test -r $i/$SEARCH_FOR; then
  dnl       INCLUDE_LOGGER_DIR=$i
  dnl       AC_MSG_RESULT(found in $i)
  dnl     fi
  dnl   done
  dnl fi
  dnl
  dnl if test -z "$INCLUDE_LOGGER_DIR"; then
  dnl   AC_MSG_RESULT([not found])
  dnl   AC_MSG_ERROR([Please reinstall the include_logger distribution])
  dnl fi

  dnl Remove this code block if the library supports pkg-config.
  dnl --with-include_logger -> add include path
  dnl PHP_ADD_INCLUDE($INCLUDE_LOGGER_DIR/include)

  dnl Remove this code block if the library supports pkg-config.
  dnl --with-include_logger -> check for lib and symbol presence
  dnl LIBNAME=INCLUDE_LOGGER # you may want to change this
  dnl LIBSYMBOL=INCLUDE_LOGGER # you most likely want to change this

  dnl If you need to check for a particular library function (e.g. a conditional
  dnl or version-dependent feature) and you are using pkg-config:
  dnl PHP_CHECK_LIBRARY($LIBNAME, $LIBSYMBOL,
  dnl [
  dnl   AC_DEFINE(HAVE_INCLUDE_LOGGER_FEATURE, 1, [ ])
  dnl ],[
  dnl   AC_MSG_ERROR([FEATURE not supported by your include_logger library.])
  dnl ], [
  dnl   $LIBFOO_LIBS
  dnl ])

  dnl If you need to check for a particular library function (e.g. a conditional
  dnl or version-dependent feature) and you are not using pkg-config:
  dnl PHP_CHECK_LIBRARY($LIBNAME, $LIBSYMBOL,
  dnl [
  dnl   PHP_ADD_LIBRARY_WITH_PATH($LIBNAME, $INCLUDE_LOGGER_DIR/$PHP_LIBDIR, INCLUDE_LOGGER_SHARED_LIBADD)
  dnl   AC_DEFINE(HAVE_INCLUDE_LOGGER_FEATURE, 1, [ ])
  dnl ],[
  dnl   AC_MSG_ERROR([FEATURE not supported by your include_logger library.])
  dnl ],[
  dnl   -L$INCLUDE_LOGGER_DIR/$PHP_LIBDIR -lm
  dnl ])
  dnl
  dnl PHP_SUBST(INCLUDE_LOGGER_SHARED_LIBADD)

  dnl In case of no dependencies
  AC_DEFINE(HAVE_INCLUDE_LOGGER, 1, [ Have include_logger support ])

  PHP_NEW_EXTENSION(include_logger, include_logger.c, $ext_shared)
fi
