AC_PREREQ([2.67])
AC_INIT([], [0], [foo@example.com])
AC_MSG_NOTICE([notice: ${abs_top_builddir}])
AC_MSG_NOTICE([notice+ac: ${abs_top_builddir}])
AC_CONFIG_COMMANDS_PRE([echo "pre+ac: ${ac_abs_top_builddir}"])
AC_CONFIG_COMMANDS_PRE([echo "pre: ${abs_top_builddir}"])
AC_CONFIG_COMMANDS_POST([echo "post+ac: ${ac_abs_top_builddir}"])
AC_CONFIG_COMMANDS_POST([echo "post: ${abs_top_builddir}"])
AC_CONFIG_COMMANDS([echo],
[echo "config.status+ac: ${ac_abs_top_builddir}"
echo "config.status: ${abs_top_builddir}"])
AC_CONFIG_FILES([test], [echo chmod +x ${ac_abs_top_builddir}/test])
AC_OUTPUT
