# =========================================================================
#     This makefile was generated by
#     Bakefile 0.2.3 (http://www.bakefile.org)
#     Do not modify, all changes will be overwritten!
# =========================================================================




prefix = /usr/local
exec_prefix = ${prefix}
datarootdir = ${prefix}/share
INSTALL = /usr/bin/install -c
EXEEXT = 
WINDRES = 
SETFILE = 
STRIP = strip
NM = nm
INSTALL_PROGRAM = ${INSTALL}
INSTALL_DATA = ${INSTALL} -m 644
INSTALL_DIR = $(INSTALL) -d
BK_DEPS = /home/leonti/proba/etmmanager/trunk/bk-deps
srcdir = .
bindir = ${exec_prefix}/bin
datadir = ${datarootdir}
LIBS = 
LDFLAGS_GUI = 
CXX = g++
CXXFLAGS =  -I/opt/wx/2.8/lib/wx/include/gtk2-unicode-release-2.8 -I/opt/wx/2.8/include/wx-2.8 -D_FILE_OFFSET_BITS=64 -D_LARGE_FILES -D__WXGTK__ -pthread
CPPFLAGS = 
LDFLAGS =  -L/opt/wx/2.8/lib -pthread   -L/usr/lib64   -lwx_gtk2u-2.8 

### Variables: ###

DESTDIR = 
ETMMANAGER_CXXFLAGS = -I/usr/include/mysql -I/usr/local/include/mysql++ -Wall \
	$(CPPFLAGS) $(CXXFLAGS)
ETMMANAGER_OBJECTS =  \
	$(__etmmanager___win32rc) \
	etmmanager_about.o \
	etmmanager_backup.o \
	etmmanager_db_set_panel.o \
	etmmanager_edit_time.o \
	etmmanager_etmmanagerApp.o \
	etmmanager_etmmanagerMain.o \
	etmmanager_prog_set_panel.o \
	etmmanager_prog_set_panel_adv.o \
	etmmanager_round.o \
	etmmanager_settings.o \
	etmmanager_workers.o \
	etmmanager_wx_std.o \
	etmmanager_contracts.o

### Conditionally set variables: ###

#CXXC = $(CXX)
CXXC = $(BK_DEPS) $(CXX)
__etmmanager___mac_setfilecmd = @true
#__etmmanager___mac_setfilecmd = \
#	$(SETFILE) -t APPL etmmanager$(EXEEXT)
COND_PLATFORM_OS2_1___etmmanager___os2_emxbindcmd = $(NM) etmmanager$(EXEEXT) \
	| if grep -q pmwin.763 ; then emxbind -ep etmmanager$(EXEEXT) ; fi
#__etmmanager___os2_emxbindcmd = $(COND_PLATFORM_OS2_1___etmmanager___os2_emxbindcmd)
#__etmmanager___win32rc = etmmanager_resource_rc.o

### Targets: ###

all: etmmanager$(EXEEXT)

install: all install_etmmanager
	$(INSTALL_DIR) $(DESTDIR)$(datadir)/etmmanager
	(cd $(srcdir)/src ; $(INSTALL_DATA)  ../share/etmmanager/table_schema.sql $(DESTDIR)$(datadir)/etmmanager)
	$(INSTALL_DIR) $(DESTDIR)$(datadir)
	for f in locale/pl/LC_MESSAGES/etmmanager.mo locale/es/LC_MESSAGES/etmmanager.mo locale/ru/LC_MESSAGES/etmmanager.mo locale/pt/LC_MESSAGES/etmmanager.mo; do \
	if test ! -d $(DESTDIR)$(datadir)/`dirname $$f` ; then \
	$(INSTALL_DIR) $(DESTDIR)$(datadir)/`dirname $$f`; \
	fi; \
	$(INSTALL_DATA) share/$$f $(DESTDIR)$(datadir)/$$f; \
	done

uninstall: uninstall_etmmanager
	(cd $(DESTDIR)$(datadir)/etmmanager ; rm -f table_schema.sql)
	for f in locale/pl/LC_MESSAGES/etmmanager.mo locale/es/LC_MESSAGES/etmmanager.mo locale/ru/LC_MESSAGES/etmmanager.mo locale/pt/LC_MESSAGES/etmmanager.mo; do \
	rm -f $(DESTDIR)$(datadir)/$$f; \
	done

install-strip: install
	$(STRIP) $(DESTDIR)$(bindir)/etmmanager$(EXEEXT)

clean: 
	rm -rf ./.deps ./.pch
	rm -f ./*.o
	rm -f etmmanager$(EXEEXT)

distclean: clean
	rm -f config.cache config.log config.status bk-deps bk-make-pch shared-ld-sh Makefile

etmmanager$(EXEEXT): $(ETMMANAGER_OBJECTS) $(__etmmanager___win32rc)
	$(CXX) -o $@ $(ETMMANAGER_OBJECTS) $(LDFLAGS)  $(LDFLAGS_GUI)  $(LIBS) -lmysqlpp -lmysqlclient
	
	$(__etmmanager___mac_setfilecmd)
	$(__etmmanager___os2_emxbindcmd)

install_etmmanager: 
	$(INSTALL_DIR) $(DESTDIR)$(bindir)
	$(INSTALL_PROGRAM) etmmanager$(EXEEXT) $(DESTDIR)$(bindir)

uninstall_etmmanager: 
	rm -f $(DESTDIR)$(bindir)/etmmanager$(EXEEXT)

etmmanager_resource_rc.o: $(srcdir)/src/res/resource.rc
	$(WINDRES) -i$< -o$@  --include-dir /usr/include/mysql --include-dir /usr/local/include/mysql++

etmmanager_about.o: $(srcdir)/src/about.cpp
	$(CXXC) -c -o $@ $(ETMMANAGER_CXXFLAGS) $(srcdir)/src/about.cpp

etmmanager_backup.o: $(srcdir)/src/backup.cpp
	$(CXXC) -c -o $@ $(ETMMANAGER_CXXFLAGS) $(srcdir)/src/backup.cpp

etmmanager_db_set_panel.o: $(srcdir)/src/db_set_panel.cpp
	$(CXXC) -c -o $@ $(ETMMANAGER_CXXFLAGS) $(srcdir)/src/db_set_panel.cpp

etmmanager_edit_time.o: $(srcdir)/src/edit_time.cpp
	$(CXXC) -c -o $@ $(ETMMANAGER_CXXFLAGS) $(srcdir)/src/edit_time.cpp

etmmanager_etmmanagerApp.o: $(srcdir)/src/etmmanagerApp.cpp
	$(CXXC) -c -o $@ $(ETMMANAGER_CXXFLAGS) $(srcdir)/src/etmmanagerApp.cpp

etmmanager_etmmanagerMain.o: $(srcdir)/src/etmmanagerMain.cpp
	$(CXXC) -c -o $@ $(ETMMANAGER_CXXFLAGS) $(srcdir)/src/etmmanagerMain.cpp

etmmanager_prog_set_panel.o: $(srcdir)/src/prog_set_panel.cpp
	$(CXXC) -c -o $@ $(ETMMANAGER_CXXFLAGS) $(srcdir)/src/prog_set_panel.cpp

etmmanager_prog_set_panel_adv.o: $(srcdir)/src/prog_set_panel_adv.cpp
	$(CXXC) -c -o $@ $(ETMMANAGER_CXXFLAGS) $(srcdir)/src/prog_set_panel_adv.cpp

etmmanager_round.o: $(srcdir)/src/round.cpp
	$(CXXC) -c -o $@ $(ETMMANAGER_CXXFLAGS) $(srcdir)/src/round.cpp

etmmanager_settings.o: $(srcdir)/src/settings.cpp
	$(CXXC) -c -o $@ $(ETMMANAGER_CXXFLAGS) $(srcdir)/src/settings.cpp

etmmanager_workers.o: $(srcdir)/src/workers.cpp
	$(CXXC) -c -o $@ $(ETMMANAGER_CXXFLAGS) $(srcdir)/src/workers.cpp

etmmanager_wx_std.o: $(srcdir)/src/wx_std.cpp
	$(CXXC) -c -o $@ $(ETMMANAGER_CXXFLAGS) $(srcdir)/src/wx_std.cpp

etmmanager_contracts.o: $(srcdir)/src/contracts.cpp
	$(CXXC) -c -o $@ $(ETMMANAGER_CXXFLAGS) $(srcdir)/src/contracts.cpp


# Include dependency info, if present:
-include .deps/*.d

.PHONY: all install uninstall clean distclean install_etmmanager uninstall_etmmanager
