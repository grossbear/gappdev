#MathLib build makefile and build test program

CXX=g++
CFLAGS=-I
OBJDIR=obj
FRAMEWORKPATH = ../../Framework
MATHPATH = ../../Framework/Base/Math
MATHLIBPATH = ../../Libs/Math

_OBJ = mathlibtest.o mathlib.a

all: MakeDir $(_OBJ) mathlibtest.exe

MakeDir:
	mkdir -p $(OBJDIR)
	
testbuild: $(patsubst %,$(OBJDIR)/%,$(_OBJ))
	$(CXX) -o prog.exe mathlibtest.o libmath.a 

mathlibtest.exe: $(patsubst %,$(OBJDIR)/%,$(_OBJ))
	$(CXX) -o $@ $^

mathlib.a:
	make -C $(MATHLIBPATH)
	cp $(MATHLIBPATH)/mathlib.a $(OBJDIR)/mathlib.a

mathlibtest.o: mathlibtest.cpp
	$(CXX) -I$(FRAMEWORKPATH) -c mathlibtest.cpp
	mv mathlibtest.o $(OBJDIR)/mathlibtest.o

.PHONY: clean

clean:
	rm -rf $(OBJDIR) mathlibtest.exe
