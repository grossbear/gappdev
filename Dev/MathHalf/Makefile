#MathLib build makefile and build dev program

CXX=g++
CFLAGS=-std=gnu++11
OBJDIR=obj
FRAMEWORKPATH = ../../Framework
MATHPATH = ../../Framework/Base/Math
MATHLIBPATH = ../../Libs/MathLib

_OBJ = mathhalfdev.o mathlib.a

all: MakeDir $(_OBJ) mathhalfdev.exe

MakeDir:
	mkdir -p $(OBJDIR)

mathhalfdev.exe: $(patsubst %,$(OBJDIR)/%,$(_OBJ))
	$(CXX) -o $@ $^

mathlib.a:
	make -C $(MATHLIBPATH)
	cp $(MATHLIBPATH)/mathlib.a $(OBJDIR)/mathlib.a
	
mathhalfdev.o: mathhalfdev.cpp
	$(CXX) $(CFLAGS) -I$(FRAMEWORKPATH) -c mathhalfdev.cpp
	mv mathhalfdev.o $(OBJDIR)/mathhalfdev.o

.PHONY: clean

clean:
	rm -rf $(OBJDIR) mathhalfdev.exe
