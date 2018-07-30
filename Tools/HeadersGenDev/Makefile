#Headers files generation development programme

CXX=g++
CFLAGS=-std=gnu++11
FRAMEWORKPATH = ../../Framework
MAINTOOLSPATH = ../
TOOLSCOMMONSRCPATH = ../CommonSrc

DATASRC_H = $(TOOLSCOMMONSRCPATH)/DataSrcSaver.h
DATASRC_CPP = $(TOOLSCOMMONSRCPATH)/DataSrcSaver.cpp

HEADERDIR = headers
headdir_tgt = $(HEADERDIR)-$(wildcard $(HEADERDIR))
headdir_present = $(HEADERDIR)-$(HEADERDIR)
headdir_absent = $(HEADERDIR)-

OBJDIR = obj
objdir_tgt = $(OBJDIR)-$(wildcard $(OBJDIR))
objdir_present = $(OBJDIR)-$(OBJDIR)
objdir_absent = $(OBJDIR)-

_OBJ = obj/datasrcsaver.o obj/testsave.o obj/main.o

PROGNAME :=
ifeq ($(OS),Windows_NT)
	PROGNAME += headgen.exe
else
	PROGNAME += headgen
endif


.PHONY: all

all:  | $(headdir_tgt) $(objdir_tgt) $(_OBJ) $(PROGNAME)

$(headdir_present):
	@echo "Directory '$(HEADERDIR)' exists, no need to create it again."

$(headdir_absent):
	@echo "Directory '$(HEADERDIR)' does not exists."
	@echo "Creating directory '$(HEADERDIR)'."
	@mkdir -p $(HEADERDIR)

$(objdir_present):
	@echo "Directory '$(OBJDIR)' exists, no need to create it again."

$(objdir_absent):
	@echo "Directory '$(OBJDIR)' does not exists."
	@echo "Creating directory '$(OBJDIR)'."
	@mkdir -p $(OBJDIR)

obj/datasrcsaver.o: $(DATASRC_CPP) $(DATASRC_H)
	@echo "Compiling file: $<"
	@$(CXX) $(CFLAGS) -I$(MAINTOOLSPATH) -c $(DATASRC_CPP) -o $@

obj/testsave.o: testsave.cpp testsave.h
	@echo "Compiling file: $<"
	@$(CXX) $(CFLAGS) -I$(MAINTOOLSPATH) -c testsave.cpp -o $@

obj/main.o: main.cpp testsave.h
	@echo "Compiling file: $<"
	@$(CXX) $(CFLAGS) -I$(MAINTOOLSPATH) -c main.cpp -o $@

$(PROGNAME): $(_OBJ)
	@echo "Building programme:$(PROGNAME)"
	@$(CXX) $(CFLAGS) -o $@ $^


.PHONY: clean

clean:
	rm $(PROGNAME)
	rm -rf $(HEADERDIR)
	rm -rf $(OBJDIR)
