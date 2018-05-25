#MathLib Numerical Limits Development Programme Makefile

CXX=g++
CFLAGS=-std=gnu++11
OBJDIR=obj
FRAMEWORKPATH = ../../Framework
MATHPATH = ../../Framework/Base/Math
MATHLIBPATH = ../../Libs/MathLib

OSFLAG := 

_OBJ = numlimits.o

PROGNAME := 
ifeq ($(OS),Windows_NT)
	PROGNAME += numlimits.exe
else
	PROGNAME += numlimits
endif

all: MakeDir $(_OBJ) $(PROGNAME)

MakeDir:
	mkdir -p $(OBJDIR)
	
$(PROGNAME): $(patsubst %,$(OBJDIR)/%,$(_OBJ))
	$(CXX) -o $@ $^

numlimits.o: numlimits.cpp
	$(CXX) $(CFLAGS) -I$(FRAMEWORKPATH) -c numlimits.cpp
	mv numlimits.o $(OBJDIR)/numlimits.o


.PHONY: clean

clean:
	rm -rf $(OBJDIR) $(PROGNAME)