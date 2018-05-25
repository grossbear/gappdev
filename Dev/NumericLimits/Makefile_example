#MathLib build makefile and build dev program

CXX=g++
CFLAGS=-std=gnu++11
OBJDIR=obj
FRAMEWORKPATH = ../../Framework
MATHPATH = ../../Framework/Base/Math
MATHLIBPATH = ../../Libs/MathLib

_OBJ = mathlibdev.o mathlib.a

all: MakeDir $(_OBJ) mathlibdev.exe

MakeDir:
	mkdir -p $(OBJDIR)

mathlibdev.exe: $(patsubst %,$(OBJDIR)/%,$(_OBJ))
	$(CXX) -o $@ $^

mathlib.a:
	make -C $(MATHLIBPATH)
	cp $(MATHLIBPATH)/mathlib.a $(OBJDIR)/mathlib.a
	
mathlibdev.o: mathlibdev.cpp
	$(CXX) $(CFLAGS) -I$(FRAMEWORKPATH) -c mathlibdev.cpp
	mv mathlibdev.o $(OBJDIR)/mathlibdev.o

.PHONY: clean

clean:
	rm -rf $(OBJDIR) mathlibdev.exe
