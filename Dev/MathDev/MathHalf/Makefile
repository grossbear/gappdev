#MathLib build makefile and build dev program

CXX=g++
CFLAGS=-std=gnu++11
OBJDIR=obj
FRAMEWORKPATH = ../../../Framework
MATHPATH = ../../../Framework/Base/Math
MATHLIBPATH = ../../../Libs/MathLib

_OBJ = mathhalfdev.o mathlib.a

PROGNAME := 
ifeq ($(OS),Windows_NT)
	PROGNAME += mathhalfdev.exe
else
	PROGNAME += mathhalfdev
endif

all: MakeDir $(_OBJ) $(PROGNAME)

MakeDir:
	mkdir -p $(OBJDIR)

$(PROGNAME): $(patsubst %,$(OBJDIR)/%,$(_OBJ))
	$(CXX) -o $@ $^

mathlib.a:
	make -C $(MATHLIBPATH)
	cp $(MATHLIBPATH)/mathlib.a $(OBJDIR)/mathlib.a
	
mathhalfdev.o: mathhalfdev.cpp
	$(CXX) $(CFLAGS) -I$(FRAMEWORKPATH) -c mathhalfdev.cpp
	mv mathhalfdev.o $(OBJDIR)/mathhalfdev.o

.PHONY: clean

clean:
	rm -rf $(OBJDIR) $(PROGNAME)
