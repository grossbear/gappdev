#File Writer Development Programme Makefile

CXX=g++
CFLAGS=-std=gnu++11
OBJDIR=obj
FRAMEWORKPATH = ../../../Framework
UTILSPATH = ../../../Framework/Base/Utils
MATHLIBPATH = ../../../Libs/MathLib

_OBJ = filewriter.o

PROGNAME := 
ifeq ($(OS),Windows_NT)
	PROGNAME += filewriter.exe
else
	PROGNAME += filewriter
endif

OUTFILE := outfile.txt

all: MakeDir $(_OBJ) $(PROGNAME)

MakeDir:
	mkdir -p $(OBJDIR)
	
$(PROGNAME): $(patsubst %,$(OBJDIR)/%,$(_OBJ))
	$(CXX) -o $@ $^

filewriter.o: main.cpp
	$(CXX) $(CFLAGS) -I$(FRAMEWORKPATH) -c main.cpp
	mv main.o $(OBJDIR)/filewriter.o


.PHONY: clean

clean:
	rm -rf $(OBJDIR) $(PROGNAME) $(OUTFILE)
