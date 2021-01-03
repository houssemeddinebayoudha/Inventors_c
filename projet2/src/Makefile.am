## Process this file with automake to produce Makefile.in

INCLUDES = \
	-DPACKAGE_DATA_DIR=\""$(datadir)"\" \
	-DPACKAGE_LOCALE_DIR=\""$(prefix)/$(DATADIRNAME)/locale"\" \
	@PACKAGE_CFLAGS@

bin_PROGRAMS = projet2

projet2_SOURCES = \
	support.c support.h \
	interface.c interface.h \
	callbacks.c callbacks.h \
	plantation.c plantation.h

projet2_LDADD = @PACKAGE_LIBS@ $(INTLLIBS)

