#MathLib static library build makefile

CXX=g++
ARCH=ar
CFLAGS=-std=gnu++11 -Wshift-count-overflow
OBJDIR=obj
FRAMEWORKPATH = ../../Framework
MATHPATH = ../../Framework/Base/Math

_OBJ = Half.o MathPrim.o Sqrt.o Trigonometry.o Vector.o Plane.o Matrix.o Quaternion.o 3DMath.o

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
	
Vector.o: $(MATHPATH)/VectorSpec.cpp
	$(CXX) $(CFLAGS) -I$(FRAMEWORKPATH) -c $(MATHPATH)/VectorSpec.cpp
	mv VectorSpec.o $(OBJDIR)/Vector.o
	
Plane.o: $(MATHPATH)/PlaneSpec.cpp
	$(CXX) $(CFLAGS) -I$(FRAMEWORKPATH) -c $(MATHPATH)/PlaneSpec.cpp
	mv PlaneSpec.o $(OBJDIR)/Plane.o
	
Matrix.o: $(MATHPATH)/MtxSpec.cpp
	$(CXX) $(CFLAGS) -I$(FRAMEWORKPATH) -c $(MATHPATH)/MtxSpec.cpp
	mv MtxSpec.o $(OBJDIR)/Matrix.o
	
Quaternion.o: $(MATHPATH)/QuatSpec.cpp
	$(CXX) $(CFLAGS) -I$(FRAMEWORKPATH) -c $(MATHPATH)/QuatSpec.cpp
	mv QuatSpec.o $(OBJDIR)/Quaternion.o
	
3DMath.o: $(MATHPATH)/3DMathSpec.cpp
	$(CXX) $(CFLAGS) -I$(FRAMEWORKPATH) -c $(MATHPATH)/3DMathSpec.cpp
	mv 3DMathSpec.o $(OBJDIR)/3DMath.o

.PHONY: clean

clean:
	rm -rf $(OBJDIR) mathlib.a

#gcc -c calc_mean.c -o calc_mean.o
#ar  rcs libmean.a      calc_mean.o
