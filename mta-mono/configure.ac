# -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.

AC_PREREQ([2.69])
AC_INIT(mta-mono, 0.25a, kernell.it@gmail.com)
AM_INIT_AUTOMAKE([-Wall -Werror foreign])

AC_ARG_ENABLE(debug,
AS_HELP_STRING([--enable-debug],
               [enable debugging, default: no]),
[case "${enableval}" in
             yes) debug=true ;;
             no)  debug=false ;;
             *)   AC_MSG_ERROR([bad value ${enableval} for --enable-debug]) ;;
esac],
[debug=false])

AM_CONDITIONAL(DEBUG, test x"$debug" = x"true")

# prevent setting xFLAGS to default of -g -O2
if test x"$CFLAGS" = x""; then
  AC_SUBST(CFLAGS, [ ])
fi
if test x"$CXXFLAGS" = x""; then
  AC_SUBST(CXXFLAGS, [ ])
fi

AC_ARG_ENABLE([debug], 
              AC_HELP_STRING([--enable-debug],
              [compile with debug symbols @<:@default=no@:>@]),
              [want_debug="$enableval"], [want_debug=no])

if test "x$want_debug" = "xyes" -a $ac_cv_c_compiler_gnu != no; then
	CFLAGS="$CFLAGS -std=c++0x -pipe -Wall -O0 -ggdb -Wl,--export-dynamic"
	CXXFLAGS="$CXXFLAGS -std=c++0x -pipe -Wall -O0 -ggdb -Wl,--export-dynamic"
	AC_DEFINE([DEBUG], 1, [Define for debugging])
else
	CFLAGS="$CFLAGS -std=c++0x -pipe -Wall -O2 -DNDEBUG -D_FORTIFY_SOURCE=2 -fPIC -MD -Wl,--export-dynamic"
	CXXFLAGS="$CXXFLAGS -std=c++0x -pipe -Wall -O2 -DNDEBUG -D_FORTIFY_SOURCE=2 -fPIC -MD -Wl,--export-dynamic"
fi

AC_CONFIG_FILES([Makefile src/Makefile src/extra/Makefile src/lua/Makefile])

AM_PROG_AR

AC_PROG_CC
AC_PROG_CXX
AC_PROG_LIBTOOL

AC_C_CONST
AC_TYPE_SIZE_T
AC_TYPE_SSIZE_T

AC_OUTPUT

LT_INIT