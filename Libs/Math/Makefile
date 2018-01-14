#MathLib static library build makefile

CXX=g++
ARCH=ar
CFLAGS=-std=gnu++11
OBJDIR=obj
FRAMEWORKPATH = ../../Framework
MATHPATH = ../../Framework/Base/Math

_OBJ = Half.o MathPrim.o Sqrt.o Trigonometry.o PseudoRandom.o Perlin.o\
Vector.o Plane.o Matrix.o Quaternion.o 3DMath.o

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

Trigonometry.o: $(MATHPATH)/Trigonometry.cpp
	$(CXX) $(CFLAGS) -I$(FRAMEWORKPATH) -c $(MATHPATH)/Trigonometry.cpp
	mv Trigonometry.o $(OBJDIR)/Trigonometry.o
	
PseudoRandom.o: $(MATHPATH)/PseudoRandom.cpp
	$(CXX) $(CFLAGS) -I$(FRAMEWORKPATH) -c $(MATHPATH)/PseudoRandom.cpp
	mv PseudoRandom.o $(OBJDIR)/PseudoRandom.o
	
Perlin.o: $(MATHPATH)/Perlin.cpp
	$(CXX) $(CFLAGS) -I$(FRAMEWORKPATH) -c $(MATHPATH)/Perlin.cpp
	mv Perlin.o $(OBJDIR)/Perlin.o
	
Vector.o: $(MATHPATH)/VectorInst.cpp
	$(CXX) $(CFLAGS) -I$(FRAMEWORKPATH) -c $(MATHPATH)/VectorInst.cpp
	mv VectorInst.o $(OBJDIR)/Vector.o
	
Plane.o: $(MATHPATH)/PlaneInst.cpp
	$(CXX) $(CFLAGS) -I$(FRAMEWORKPATH) -c $(MATHPATH)/PlaneInst.cpp
	mv PlaneInst.o $(OBJDIR)/Plane.o
	
Matrix.o: $(MATHPATH)/MtxInst.cpp
	$(CXX) $(CFLAGS) -I$(FRAMEWORKPATH) -c $(MATHPATH)/MtxInst.cpp
	mv MtxInst.o $(OBJDIR)/Matrix.o
	
Quaternion.o: $(MATHPATH)/QuatInst.cpp
	$(CXX) $(CFLAGS) -I$(FRAMEWORKPATH) -c $(MATHPATH)/QuatInst.cpp
	mv QuatInst.o $(OBJDIR)/Quaternion.o
	
3DMath.o: $(MATHPATH)/3DMathInst.cpp
	$(CXX) $(CFLAGS) -I$(FRAMEWORKPATH) -c $(MATHPATH)/3DMathInst.cpp
	mv 3DMathInst.o $(OBJDIR)/3DMath.o

.PHONY: clean

clean:
	rm -rf $(OBJDIR) mathlib.a

#gcc -c calc_mean.c -o calc_mean.o
#ar  rcs libmean.a      calc_mean.o
