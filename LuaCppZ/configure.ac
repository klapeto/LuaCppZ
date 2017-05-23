dnl Process this file with autoconf to produce a configure script.

AC_PREREQ(2.59)
AC_INIT(LuaCppZ, 1.0.0)
AC_PROG_CXX

AC_CANONICAL_SYSTEM

AC_CONFIG_MACRO_DIR([m4])

AM_PROG_CC_C_O

dnl Initialize automake
AM_INIT_AUTOMAKE([subdir-objects])

dnl Initialize Libtool
LT_INIT

dnl this allows us specify individual liking flags for each target
AC_LANG([C++])

AC_CHECK_HEADER_STDBOOL
AC_C_INLINE
AC_TYPE_INT16_T
AC_TYPE_SIZE_T

AC_CHECK_HEADER([stddef.h])
AC_HEADER_STDC
AC_CHECK_HEADER([string])
AC_CHECK_HEADER([iostream])

AX_CXX_COMPILE_STDCXX_11([],[mandatory])
PKG_CHECK_MODULES(lua51, [lua-5.1],[], [PKG_CHECK_MODULES(lua51, [lua5.1])])
AC_SUBST(CPPFLAGS_back,[$CPPFLAGS])
AC_SUBST(CPPFLAGS,["$CPPFLAGS $lua51_CFLAGS"])
AC_SUBST(CPPFLAGS,[$CPPFLAGS_back])

AC_CONFIG_FILES(Makefile
                exampleProgram/Makefile
                libluacppz/Makefile
                include/Makefile)
AC_OUTPUT