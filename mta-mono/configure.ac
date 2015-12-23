# -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.

AC_PREREQ([2.69])
AC_INIT(mta-mono, 0.26a, kernell.it@gmail.com)
AM_INIT_AUTOMAKE([-Wall -Werror foreign])

# prevent setting xFLAGS to default of -g -O2
if test x"$CFLAGS" = x""; then
  AC_SUBST(CFLAGS, [ ])
fi
if test x"$CXXFLAGS" = x""; then
  AC_SUBST(CXXFLAGS, [ ])
fi

AC_ARG_ENABLE(debug,
	AC_HELP_STRING([--enable-debug], [compile with debug symbols @<:@default=no@:>@]),
	[case "${enableval}" in
		 yes) debug=true ;;
		 no)  debug=false ;;
		 *)   AC_MSG_ERROR([bad value ${enableval} for --enable-debug]);;
	esac],
	[debug=false]
)

if test x"$debug" == x"true"; then
	CFLAGS="$CFLAGS -std=c++0x -Wall -O0 -pipe -fPIC -ggdb -D_DEBUG -DGC_LINUX_THREADS -D_REENTRANT"
	CXXFLAGS="$CXXFLAGS -std=c++0x -Wall -O0 -pipe -fPIC -D_DEBUG -ggdb -DGC_LINUX_THREADS -D_REENTRANT"
	AC_DEFINE([DEBUG], 1, [Define for debugging])
else
	CFLAGS="$CFLAGS -std=c++0x -Wall -O2 -pipe -fPIC -MD -DNDEBUG -DGC_LINUX_THREADS -D_REENTRANT"
	CXXFLAGS="$CXXFLAGS -std=c++0x -Wall -O2 -pipe -fPIC -MD -DNDEBUG -DGC_LINUX_THREADS -D_REENTRANT"
fi

AC_CONFIG_FILES([Makefile src/Makefile src/extra/Makefile src/lua/Makefile])

AC_CHECK_TOOL(CC, gcc, gcc)
AC_PROG_CC
AC_CHECK_TOOL(CXX, g++, g++)
AC_PROG_CXX
AM_PROG_AR
AM_PROG_AS
AC_PROG_LIBTOOL
AC_PROG_INSTALL
AC_PROG_AWK
AM_PROG_CC_C_O

AC_C_CONST
AC_TYPE_SIZE_T
AC_TYPE_SSIZE_T

AC_OUTPUT

LT_INIT