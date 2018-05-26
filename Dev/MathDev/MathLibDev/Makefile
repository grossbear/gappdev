#MathLib build makefile and build dev program

CXX=g++
CFLAGS=-std=gnu++11
OBJDIR=obj
FRAMEWORKPATH = ../../../Framework
MATHPATH = ../../../Framework/Base/Math
MATHLIBPATH = ../../../Libs/MathLib

_OBJ = mathlibdev.o mathlib.a

PROGNAME := 
ifeq ($(OS),Windows_NT)
	PROGNAME += mathlibdev.exe
else
	PROGNAME += mathlibdev
endif

all: MakeDir $(_OBJ) $(PROGNAME)

MakeDir:
	mkdir -p $(OBJDIR)

$(PROGNAME): $(patsubst %,$(OBJDIR)/%,$(_OBJ))
	$(CXX) -o $@ $^

mathlib.a:
	make -C $(MATHLIBPATH)
	cp $(MATHLIBPATH)/mathlib.a $(OBJDIR)/mathlib.a
	
mathlibdev.o: mathlibdev.cpp
	$(CXX) $(CFLAGS) -I$(FRAMEWORKPATH) -c mathlibdev.cpp
	mv mathlibdev.o $(OBJDIR)/mathlibdev.o

.PHONY: clean

clean:
	rm -rf $(OBJDIR) $(PROGNAME)
