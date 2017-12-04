#MathLib static library build makefile

CXX=g++
ARCH=ar
CFLAGS=-std=gnu++11
OBJDIR=obj
FRAMEWORKPATH = ../../Framework
MATHPATH = ../../Framework/Base/Math

_OBJ = MathPrim.o

all: MakeDir $(_OBJ) mathlib.a 

MakeDir:
	mkdir -p $(OBJDIR)
	
mathlib.a: $(patsubst %,$(OBJDIR)/%,$(_OBJ))
	$(ARCH) rcs $@ $^
	
MathPrim.o: $(MATHPATH)/MathPrim.cpp
	$(CXX) $(CFLAGS) -I$(FRAMEWORKPATH) -c $(MATHPATH)/MathPrim.cpp
	mv MathPrim.o $(OBJDIR)/MathPrim.o

.PHONY: clean

clean:
	rm -rf $(OBJDIR) mathlib.a

#gcc -c calc_mean.c -o calc_mean.o
#ar  rcs libmean.a      calc_mean.o
