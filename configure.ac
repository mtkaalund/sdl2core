AC_INIT([sdl2core], [0.1], [kaalund@gmail.com])
AM_INIT_AUTOMAKE
AC_CONFIG_SRCDIR([src])

# Checks for programs.
AC_PROG_CXX

# Checks for libraries
LT_INIT
AC_ENABLE_SHARED
AC_DISABLE_STATIC
AC_PROG_LIBTOOL(libsdl2core)
AC_PROG_LIBTOOL(libsdl2net)

# Checks for typedefs, structures and compiler characteristics
AC_HEADER_STDBOOL
AC_C_INLINE
AC_TYPE_SIZE_T

# Output makefile files.
AC_CONFIG_FILES([Makefile src/Makefile])
AC_OUTPUT

