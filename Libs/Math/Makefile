#MathLib static library build makefile

CXX=g++
ARCH=ar
CFLAGS=-std=gnu++11
OBJDIR=obj
FRAMEWORKPATH = ../../Framework
MATHPATH = ../../Framework/Base/Math

_OBJ = Half.o MathPrim.o Sqrt.o

all: MakeDir $(_OBJ) mathlib.a 

MakeDir:
	mkdir -p $(OBJDIR)
	
mathlib.a: $(patsubst %,$(OBJDIR)/%,$(_OBJ))
	$(ARCH) rcs $@ $^
	
Half.o: $(MATHPATH)/thalf.cpp
	$(CXX) $(CFLAGS) -I$(FRAMEWORKPATH) -c $(MATHPATH)/thalf.cpp
	mv thalf.o $(OBJDIR)/Half.o
	
MathPrim.o: $(MATHPATH)/MathPrim.cpp
	$(CXX) $(CFLAGS) -I$(FRAMEWORKPATH) -c $(MATHPATH)/MathPrim.cpp
	mv MathPrim.o $(OBJDIR)/MathPrim.o

Sqrt.o: $(MATHPATH)/Sqrt.cpp $(MATHPATH)/MathPrim.cpp
	$(CXX) $(CFLAGS) -I$(FRAMEWORKPATH) -c $(MATHPATH)/Sqrt.cpp
	mv Sqrt.o $(OBJDIR)/Sqrt.o

.PHONY: clean

clean:
	rm -rf $(OBJDIR) mathlib.a

#gcc -c calc_mean.c -o calc_mean.o
#ar  rcs libmean.a      calc_mean.o
