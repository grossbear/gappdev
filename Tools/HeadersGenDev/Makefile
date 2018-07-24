#Headers files generation development programme

CXX=g++
CFLAGS=-std=gnu++11
FRAMEWORKPATH = ../../Framework
MAINTOOLSPATH = ../
TOOLSCOMMONSRCPATH = ../CommonSrc
HEADERDIR = headers
OBJDIR=obj

DATASRC_H = $(TOOLSCOMMONSRCPATH)/DataSrcSaver.h
DATASRC_CPP = $(TOOLSCOMMONSRCPATH)/DataSrcSaver.cpp

_OBJ = datasrcsaver.o testsave.o main.o

PROGNAME :=
ifeq ($(OS),Windows_NT)
	PROGNAME += headgen.exe
else
	PROGNAME += headgen
endif

all: MakeDir $(_OBJ) $(PROGNAME)


MakeDir:
	@echo "Making obj directory"	
	@mkdir -p $(OBJDIR)
	@echo "Making headers directory"
	@mkdir -p $(HEADERDIR)

datasrcsaver.o: $(DATASRC_CPP) $(DATASRC_H)
	$(CXX) $(CFLAGS) -c $<
	mv DataSrcSaver.o $(OBJDIR)/datasrcsaver.o

testsave.o: testsave.cpp testsave.h $(DATASRC_H) $(DATASRC_CPP)
	$(CXX) $(CFLAGS) -I$(MAINTOOLSPATH) -c $<
	mv testsave.o $(OBJDIR)/testsave.o

main.o: main.cpp testsave.cpp testsave.h $(DATASRC_H) $(DATASRC_CPP)
	$(CXX) $(CFLAGS) -I$(FRAMEWORKPATH) -c main.cpp
	mv main.o $(OBJDIR)/main.o

$(PROGNAME): $(patsubst %,$(OBJDIR)/%,$(_OBJ))
	@echo "Compiling programme:$(PROGNAME)"
	$(CXX) -o $@ $^


.PHONY: clean

clean:
	rm $(PROGNAME)
	rm -rf $(HEADERDIR)
	rm -rf $(OBJDIR)
