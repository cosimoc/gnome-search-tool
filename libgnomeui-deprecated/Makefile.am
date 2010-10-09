INCLUDES = \
	-DGTK_DISABLE_DEPRECATED	\
	-DGDK_DISABLE_DEPRECATED	\
	-DG_DISABLE_DEPRECATED

noinst_LTLIBRARIES = libgnomeui-deprecated.la

libgnomeui_deprecated_la_CFLAGS = \
	$(GLIB_CFLAGS)			\
	$(GTK2_CFLAGS)			\
	$(GCONF_CFLAGS)			\
	$(WARN_CFLAGS)

libgnomeui_deprecated_la_LIBADD = \
	$(GLIB_LIBS)			\
	$(GTK2_LIBS)			\
	$(GCONF_LIBS)

libgnomeui_deprecated_la_SOURCES = \
	gsearchtool-entry.h	\
	gsearchtool-entry.c
