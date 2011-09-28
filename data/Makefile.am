icondir = $(datadir)/pixmaps/gsearchtool
icon_DATA = thumbnail_frame.png 

man_MANS = gnome-search-tool.1

schemadir = $(GCONF_SCHEMA_FILE_DIR)
schema_in_file = gnome-search-tool.schemas.in
schema_DATA = $(schema_in_file:.schemas.in=.schemas)
@INTLTOOL_SCHEMAS_RULE@

Utilitiesdir = $(datadir)/applications
Utilities_in_files = gnome-search-tool.desktop.in 
Utilities_DATA = $(Utilities_in_files:.desktop.in=.desktop)
@INTLTOOL_DESKTOP_RULE@

EXTRA_DIST = \
	$(icon_DATA) \
	$(man_MANS) \
	$(schema_in_file) \
	$(Utilities_in_files) \
	$(Utilities_DATA)

if GCONF_SCHEMAS_INSTALL
install-data-local:
	if test -z "$(DESTDIR)" ; then \
		GCONF_CONFIG_SOURCE=$(GCONF_SCHEMA_CONFIG_SOURCE) $(GCONFTOOL) --makefile-install-rule $(top_builddir)/data/$(schema_DATA) ; \
	fi
else
install-data-local:
endif

CLEANFILES = 				\
	gnome-search-tool.desktop	\
	$(schema_DATA)

disthook:
	cd $(distdir) ; rm -f $(CLEANFILES)
