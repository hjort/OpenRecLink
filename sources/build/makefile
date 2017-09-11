# -------------------------------------------------------------------------
# These are configurable options:
# -------------------------------------------------------------------------

# OS Version targets
OS := $(shell uname -o)

ifeq ($(OS),GNU/Linux)
   VERSION = UBU
else ifeq ($(OS),Msys)
   VERSION = WIN
else
   $(error OS not known)
endif

# C compiler
CC := ccache gcc

# C++ compiler
CXX := ccache g++

# Standard flags for C++
#ifeq ($(VERSION), WIN)
#   CXXFLAGS := -O
#else
#   CXXFLAGS :=
#endif

CXXFLAGS := -O2 -D NDEBUG

# Standard preprocessor flags (common for CC and CXX)
CPPFLAGS := 

# include directory - adjust according to actual locations
ifeq ($(VERSION), WIN)
   INCLUDEDIR := C:/dev/include
endif

ifeq ($(VERSION), UBU)
   INCLUDEDIR := /usr/include
endif

# libs directory - adjust according to actual locations
ifeq ($(VERSION), WIN)
   LIBDIR := C:/dev/lib
endif

ifeq ($(VERSION), UBU)
   LIBDIR := /usr/lib
endif

# Location and arguments of wx-config script
WX_CONFIG := wx-config

# Standard linker flags
LDFLAGS := -L$(LIBDIR) -lxbase
#LDFLAGS := -L$(LIBDIR) -lxbase64
ifeq ($(VERSION), WIN)
   WINOPTS = -Wl,--subsystem,windows
else
   WINOPTS = 
endif 

# C++ flags to use with wxWidgets code
WX_CXXFLAGS := `$(WX_CONFIG) --cxxflags`

# -------------------------------------------------------------------------
# Do not modify the rest of this file!
# -------------------------------------------------------------------------

### Variables: ###

MFOPTS = `echo $@ | sed -e 's,\.o$$,.d,'`
#CPPDEPS = -MT$@ -MF`echo $@ | sed -e 's,\.o$$,.d,'` -MD
CPPDEPS = -MT$@ -MF$(MFOPTS) -MD
#CPPDEPS = `echo $@`s

OPENRECLINK_CXXFLAGS =  -I../gui -I../nongui -I../wxthings -I$(INCLUDEDIR) $(WX_CXXFLAGS) $(CPPFLAGS) $(CXXFLAGS)

OPENRECLINK_OBJECTS = \
	xbtable.o \
	ntable.o \
        ntable_grid.o \
	dblowlevel.o \
	execcmb.o \
	execdup.o \
	execjin.o \
	execlnk.o \
	execlnmatrix.o \
	execstd.o \
        exportdlg.o \
        importcsv.o \
        importdlg.o \
	inspect.o \
	langdlg.o \
	reclinkApp.o \
	reclinkmain.o \
	runcalc.o \
	setoptsdlg.o \
	viewdup.o \
	viewtable.o \
	wizdup.o \
	wizjin.o \
	wizlnk.o \
	wizstd.o \
	showstructdlg.o \
	calc.o \
	Levenshtein.o \
	compnumseq.o \
	dbcomb.o \
	dbconvert.o \
	dbdup.o \
	dbjin.o \
	dblink.o \
	dblnmatrix.o \
	fldconvert.o \
	matrix.o \
	parameters.o \
	soundex.o \
	dbutils.o \
	progressdialog.o \
	freqanalysis.o \
	freqdlg.o \
	indexdialog.o \
	SQLexportdlg.o \
	findex.o \
	viewlog.o \
	execpurge.o \
	execmark.o \
	bigfiledlg.o \
	ops_log.o \
	wizcopy.o \
	execcopy.o \
	docopy.o \
	aboutpanel.o

ifeq ($(VERSION), WIN)
   ARTPROVIDER = wxwinartprovider.o
   OPENRECLINK_OBJECTS += $(ARTPROVIDER)	 
endif

IMPDBF_OBJECTS = \
	xbtable.o \
	ntable.o \
	dbutils.o \
	dblowlevel.o \
	findex.o \
	main.o

### Conditionally set variables: ###

### Targets: ###

all: openreclink impdbf

install: all

uninstall:

clean:
	rm -f ./*.o
	rm -f ./*.d
ifeq ($(VERSION), WIN)
	rm -f ./openreclink.exe
	rm -f ./impdbf.exe
else
	rm -f ./openreclink
	rm -f ./impdbf
endif

openreclink: $(OPENRECLINK_OBJECTS)
	$(CXX) -o $@ $(OPENRECLINK_OBJECTS) `$(WX_CONFIG) --libs` $(LDFLAGS) $(WINOPTS)

impdbf: $(IMPDBF_OBJECTS)
	$(CXX) -o $@ $(IMPDBF_OBJECTS) `$(WX_CONFIG) --libs` $(LDFLAGS)

xbtable.o: ../nongui/xbtable.cpp
	$(CXX) -c -o $@ $(OPENRECLINK_CXXFLAGS) $(CPPDEPS) $<

dblowlevel.o: ../nongui/dblowlevel.cpp
	$(CXX) -c -o $@ $(OPENRECLINK_CXXFLAGS) $(CPPDEPS) $<

ntable.o: ../nongui/ntable.cpp
	$(CXX) -c -o $@ $(OPENRECLINK_CXXFLAGS) $(CPPDEPS) $<

ntable_grid.o: ../nongui/ntable_grid.cpp
	$(CXX) -c -o $@ $(OPENRECLINK_CXXFLAGS) $(CPPDEPS) $<

ops_log.o: ../nongui/ops_log.cpp
	$(CXX) -c -o $@ $(OPENRECLINK_CXXFLAGS) $(CPPDEPS) $<

docopy.o: ../nongui/docopy.cpp
	$(CXX) -c -o $@ $(OPENRECLINK_CXXFLAGS) $(CPPDEPS) $<

main.o: ../nongui/main.cpp
	$(CXX) -c -o $@ $(OPENRECLINK_CXXFLAGS) $(CPPDEPS) $<

viewlog.o: ../gui/viewlog.cpp
	$(CXX) -c -o $@ $(OPENRECLINK_CXXFLAGS) $(CPPDEPS) $<

wizcopy.o: ../gui/wizcopy.cpp
	$(CXX) -c -o $@ $(OPENRECLINK_CXXFLAGS) $(CPPDEPS) $<

execcopy.o: ../gui/execcopy.cpp
	$(CXX) -c -o $@ $(OPENRECLINK_CXXFLAGS) $(CPPDEPS) $<

execpurge.o: ../gui/execpurge.cpp
	$(CXX) -c -o $@ $(OPENRECLINK_CXXFLAGS) $(CPPDEPS) $<

execmark.o: ../gui/execmark.cpp
	$(CXX) -c -o $@ $(OPENRECLINK_CXXFLAGS) $(CPPDEPS) $<

bigfiledlg.o: ../gui/bigfiledlg.cpp
	$(CXX) -c -o $@ $(OPENRECLINK_CXXFLAGS) $(CPPDEPS) $<

freqanalysis.o: ../gui/freqanalysis.cpp
	$(CXX) -c -o $@ $(OPENRECLINK_CXXFLAGS) $(CPPDEPS) $<

freqdlg.o: ../gui/freqdlg.cpp
	$(CXX) -c -o $@ $(OPENRECLINK_CXXFLAGS) $(CPPDEPS) $<

indexdialog.o: ../gui/indexdialog.cpp
	$(CXX) -c -o $@ $(OPENRECLINK_CXXFLAGS) $(CPPDEPS) $<

SQLexportdlg.o: ../gui/SQLexportdlg.cpp
	$(CXX) -c -o $@ $(OPENRECLINK_CXXFLAGS) $(CPPDEPS) $<

execcmb.o: ../gui/execcmb.cpp
	$(CXX) -c -o $@ $(OPENRECLINK_CXXFLAGS) $(CPPDEPS) $<

execdup.o: ../gui/execdup.cpp
	$(CXX) -c -o $@ $(OPENRECLINK_CXXFLAGS) $(CPPDEPS) $<

execjin.o: ../gui/execjin.cpp
	$(CXX) -c -o $@ $(OPENRECLINK_CXXFLAGS) $(CPPDEPS) $<

execlnk.o: ../gui/execlnk.cpp
	$(CXX) -c -o $@ $(OPENRECLINK_CXXFLAGS) $(CPPDEPS) $<

execlnmatrix.o: ../gui/execlnmatrix.cpp
	$(CXX) -c -o $@ $(OPENRECLINK_CXXFLAGS) $(CPPDEPS) $<

execstd.o: ../gui/execstd.cpp
	$(CXX) -c -o $@ $(OPENRECLINK_CXXFLAGS) $(CPPDEPS) $<

exportdlg.o: ../gui/exportdlg.cpp
	$(CXX) -c -o $@ $(OPENRECLINK_CXXFLAGS) $(CPPDEPS) $<

importcsv.o: ../gui/importcsv.cpp
	$(CXX) -c -o $@ $(OPENRECLINK_CXXFLAGS) $(CPPDEPS) $<

importdlg.o: ../gui/importdlg.cpp
	$(CXX) -c -o $@ $(OPENRECLINK_CXXFLAGS) $(CPPDEPS) $<

inspect.o: ../gui/inspect.cpp
	$(CXX) -c -o $@ $(OPENRECLINK_CXXFLAGS) $(CPPDEPS) $<

langdlg.o: ../gui/langdlg.cpp
	$(CXX) -c -o $@ $(OPENRECLINK_CXXFLAGS) $(CPPDEPS) $<

aboutpanel.o: ../gui/aboutpanel.cpp
	$(CXX) -c -o $@ $(OPENRECLINK_CXXFLAGS) $(CPPDEPS) $<

reclinkApp.o: ../gui/reclinkApp.cpp
	$(CXX) -c -o $@ $(OPENRECLINK_CXXFLAGS) $(CPPDEPS) $<

reclinkmain.o: ../gui/reclinkmain.cpp
	$(CXX) -c -o $@ $(OPENRECLINK_CXXFLAGS) $(CPPDEPS) $<

runcalc.o: ../gui/runcalc.cpp
	$(CXX) -c -o $@ $(OPENRECLINK_CXXFLAGS) $(CPPDEPS) $<

setoptsdlg.o: ../gui/setoptsdlg.cpp
	$(CXX) -c -o $@ $(OPENRECLINK_CXXFLAGS) $(CPPDEPS) $<

viewdup.o: ../gui/viewdup.cpp
	$(CXX) -c -o $@ $(OPENRECLINK_CXXFLAGS) $(CPPDEPS) $<

viewtable.o: ../gui/viewtable.cpp
	$(CXX) -c -o $@ $(OPENRECLINK_CXXFLAGS) $(CPPDEPS) $<

wizdup.o: ../gui/wizdup.cpp
	$(CXX) -c -o $@ $(OPENRECLINK_CXXFLAGS) $(CPPDEPS) $<

wizjin.o: ../gui/wizjin.cpp
	$(CXX) -c -o $@ $(OPENRECLINK_CXXFLAGS) $(CPPDEPS) $<

wizlnk.o: ../gui/wizlnk.cpp
	$(CXX) -c -o $@ $(OPENRECLINK_CXXFLAGS) $(CPPDEPS) $<

wizstd.o: ../gui/wizstd.cpp
	$(CXX) -c -o $@ $(OPENRECLINK_CXXFLAGS) $(CPPDEPS) $<

showstructdlg.o: ../gui/showstructdlg.cpp
	$(CXX) -c -o $@ $(OPENRECLINK_CXXFLAGS) $(CPPDEPS) $<
	
progressdialog.o: ../gui/progressdialog.cpp
	$(CXX) -c -o $@ $(OPENRECLINK_CXXFLAGS) $(CPPDEPS) $<
	
wxwinartprovider.o: ../gui/wxwinartprovider.cpp
	$(CXX) -c -o $@ $(OPENRECLINK_CXXFLAGS) $(CPPDEPS) $<

compnumseq.o: ../nongui/compnumseq.cpp
	$(CXX) -c -o $@ $(OPENRECLINK_CXXFLAGS) $(CPPDEPS) $<

dbcomb.o: ../nongui/dbcomb.cpp
	$(CXX) -c -o $@ $(OPENRECLINK_CXXFLAGS) $(CPPDEPS) $<

dbconvert.o: ../nongui/dbconvert.cpp
	$(CXX) -c -o $@ $(OPENRECLINK_CXXFLAGS) $(CPPDEPS) $<

dbdup.o: ../nongui/dbdup.cpp
	$(CXX) -c -o $@ $(OPENRECLINK_CXXFLAGS) $(CPPDEPS) $<

dbjin.o: ../nongui/dbjin.cpp
	$(CXX) -c -o $@ $(OPENRECLINK_CXXFLAGS) $(CPPDEPS) $<

dblink.o: ../nongui/dblink.cpp
	$(CXX) -c -o $@ $(OPENRECLINK_CXXFLAGS) $(CPPDEPS) $<

dblnmatrix.o: ../nongui/dblnmatrix.cpp
	$(CXX) -c -o $@ $(OPENRECLINK_CXXFLAGS) $(CPPDEPS) $<

fldconvert.o: ../nongui/fldconvert.cpp
	$(CXX) -c -o $@ $(OPENRECLINK_CXXFLAGS) $(CPPDEPS) $<

matrix.o: ../nongui/matrix.cpp
	$(CXX) -c -o $@ $(OPENRECLINK_CXXFLAGS) $(CPPDEPS) $<

parameters.o: ../nongui/parameters.cpp
	$(CXX) -c -o $@ $(OPENRECLINK_CXXFLAGS) $(CPPDEPS) $<

soundex.o: ../nongui/soundex.cpp
	$(CXX) -c -o $@ $(OPENRECLINK_CXXFLAGS) $(CPPDEPS) $<

dbutils.o: ../nongui/dbutils.cpp
	$(CXX) -c -o $@ $(OPENRECLINK_CXXFLAGS) $(CPPDEPS) $<

findex.o: ../nongui/findex.cpp
	$(CXX) -c -o $@ $(OPENRECLINK_CXXFLAGS) $(CPPDEPS) $<

calc.o: ../nongui/calc.c
	$(CC) -c -o $@ $(OPENRECLINK_CXXFLAGS) $(CPPDEPS) $<

Levenshtein.o: ../nongui/Levenshtein.c
	$(CC) -c -o $@ $(OPENRECLINK_CXXFLAGS) $(CPPDEPS) $<

.PHONY: all install uninstall clean

# Dependencies tracking:
-include ./*.d
