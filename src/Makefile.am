
INCLUDES = 	\
	-I$(top_srcdir)/libgnomeui-deprecated			\
	-I$(top_srcdir)/libeggsmclient				\
	-DG_DISABLE_DEPRECATED					\
	-DGNOMELOCALEDIR=\""$(prefix)/$(DATADIRNAME)/locale"\"	\
	-DLOCALEDIR=\"$(datadir)/locale\"			\
	-DDATADIR=\""$(datadir)"\"				\
	-DGREP_COMMAND=\""$(GREP_COMMAND)"\"

libgnomeui_deprecated_LIB = $(top_builddir)/libgnomeui-deprecated/libgnomeui-deprecated.la
libeggsmclient_LIB = $(top_builddir)/libeggsmclient/libeggsmclient.la

bin_PROGRAMS = gnome-search-tool

gnome_search_tool_SOURCES =     \
	gsearchtool-support.c   \
	gsearchtool-support.h   \
	gsearchtool-callbacks.c \
	gsearchtool-callbacks.h \
	gsearchtool.c	        \
	gsearchtool.h

gnome_search_tool_CFLAGS = \
	$(GSEARCHTOOL_CFLAGS)

gnome_search_tool_LDADD = \
	$(GSEARCHTOOL_LIBS)		\
	$(libgnomeui_deprecated_LIB)	\
	$(libeggsmclient_LIB)
