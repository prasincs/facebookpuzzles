# Autoconf input file
# $Id$

# AC - autoconf
# FB - facebook

#########################################################################
# DO NOT TOUCH EXCEPT TO CHANGE REV# IN AC_INIT

AC_PREREQ(2.52)
AC_INIT([libfb303],[20080209])
#AC_CONFIG_AUX_DIR([/usr/share/automake-1.9])
# To install locally
FB_INITIALIZE([localinstall])
AC_PREFIX_DEFAULT([/usr/local])

############################################################################
# User Configurable. Change With CAUTION!
# User can include custom makefile rules. Uncomment and update only <name> in PRODUCT_MK.
# Include where appropriate in any Makefile.am as @PRODUCT_MK@

#PRODUCT_MK="include ${EXTERNAL_PATH}/shared/build/<name>.mk"

# Default path to external Facebook components and shared build toools I.e fb303 etc.
# To point to other locations set  environment variable EXTERNAL_PATH.
# To change the current default you must change bootstrap.sh.
FB_WITH_EXTERNAL_PATH([`pwd`])

AC_ARG_VAR([PY_PREFIX], [Prefix for installing Python modules.
                         (Normal --prefix is ignored for Python because
                         Python has different conventions.)
                         Default = "/usr"])
AS_IF([test "x$PY_PREFIX" = x], [PY_PREFIX="/usr"])

##########################################################################
# User Configurable

# Pre-defined macro to set opt build mode. Run with --disable-shared option to turn off optimization.
FB_ENABLE_DEFAULT_OPT_BUILD

# Predefined macro to set static library mode. Run with --disable-static option to turn off static lib mode.
FB_ENABLE_DEFAULT_STATIC

# Personalized feature generator. Creates defines/conditionals and --enable --disable command line options.
# FB_ENABLE_FEATURE([FEATURE], [feature]) OR FB_ENABLE_FEATURE([FEATURE], [feature], [\"<value>\"])

# Example: Macro supplies -DFACEBOOK at compile time and "if FACEBOOK endif" capabilities.

# Personalized path generator Sets default paths. Provides --with-xx=DIR options.
# FB_WITH_PATH([<var>_home], [<var>path], [<default location>]

# Example: sets $(thrift_home) variable with default path set to /usr/local.
FB_WITH_PATH([thrift_home], [thriftpath], [/usr/local])

# Require boost 1.33.1 or later
AX_BOOST_BASE([1.33.1])

# Generates Makefile from Makefile.am. Modify when new subdirs are added.
# Change Makefile.am also to add subdirectly.
AC_CONFIG_FILES(Makefile cpp/Makefile py/Makefile)

############################################################################
# DO NOT TOUCH.

AC_SUBST(PRODUCT_MK)
AC_OUTPUT

#############################################################################
######### FINISH ############################################################

echo "EXTERNAL_PATH $EXTERNAL_PATH"


#
# NOTES FOR USER
# Short cut to create conditional flags.
#enable_facebook="yes"
#AM_CONDITIONAL([FACEBOOK], [test "$enable_facebook" = yes])
#enable_hdfs="yes"
#AM_CONDITIONAL([HDFS], [test "$enable_hdfs" = yes])

# Enable options with --enable and --disable configurable.
#AC_MSG_CHECKING([whether to enable FACEBOOK])
#FACEBOOK=""
#AC_ARG_ENABLE([facebook],
#  [  --enable-facebook     Enable facebook.],
#  [
#     ENABLE_FACEBOOK=$enableval
#  ],
#  [
#     ENABLE_FACEBOOK="no"
#  ]
#)
#AM_CONDITIONAL([FACEBOOK], [test "$ENABLE_FACEBOOK" = yes])
#AC_MSG_RESULT($ENABLE_FACEBOOK)

