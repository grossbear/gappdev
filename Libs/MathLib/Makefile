#MathLib static library build makefile

CXX=g++
ARCH=ar
CFLAGS=-std=gnu++11 -Wall
LDFLAGS=-lSDL -lSDL_gfx
OBJDIR=obj
FRAMEWORKPATH = ../../Framework
MATHPATH = ../../Framework/Base/Math
 
ifndef VECFLAGS
	VECFLAGS = MATH_HIGH_PREC_FLOAT_VEC
endif

_OBJ = thalf.o ElemFunc.o Sqrt.o Trigonometry.o Prng.o Perlin.o\
Vector.o Plane.o Matrix.o Quaternion.o 3DMath.o

all: $(_OBJ) mathlib.a

MakeDir:
	mkdir -p $(OBJDIR)
	
# link
mathlib.a: $(patsubst %,%,$(_OBJ))
	$(ARCH) rcs $@ $^
	
# pull in dependency info for *existing* .o files
-include $(_OBJ:.o=.d)


# compile and generate dependency info	
thalf.o: $(MATHPATH)/Types/thalf.cpp
	$(CXX) $(CFLAGS) -I$(FRAMEWORKPATH) -I$(MATHPATH) -c $(MATHPATH)/Types/thalf.cpp
	$(CXX) -MM $(CFLAGS) -I$(FRAMEWORKPATH) -I$(MATHPATH) -c $(MATHPATH)/Types/thalf.cpp > thalf.d
	
ElemFunc.o: $(MATHPATH)/Elementary/ElemFunc.cpp
	$(CXX) $(CFLAGS) -I$(FRAMEWORKPATH) -I$(MATHPATH) -c $(MATHPATH)/Elementary/ElemFunc.cpp
	$(CXX) -MM $(CFLAGS) -I$(FRAMEWORKPATH) -I$(MATHPATH) -c $(MATHPATH)/Elementary/ElemFunc.cpp > ElemFunc.d
	
Sqrt.o: $(MATHPATH)/Elementary/Sqrt.cpp
	$(CXX) $(CFLAGS) -I$(FRAMEWORKPATH) -I$(MATHPATH) -c $(MATHPATH)/Elementary/Sqrt.cpp
	$(CXX) -MM $(CFLAGS) -I$(FRAMEWORKPATH) -I$(MATHPATH) -c $(MATHPATH)/Elementary/Sqrt.cpp > Sqrt.d
	
Trigonometry.o: $(MATHPATH)/Elementary/Trigonometry.cpp
	$(CXX) $(CFLAGS) -I$(FRAMEWORKPATH) -I$(MATHPATH) -c $(MATHPATH)/Elementary/Trigonometry.cpp
	$(CXX) -MM $(CFLAGS) -I$(FRAMEWORKPATH) -I$(MATHPATH) -c $(MATHPATH)/Elementary/Trigonometry.cpp > Trigonometry.d
	
Prng.o: $(MATHPATH)/Random/Prng.cpp
	$(CXX) $(CFLAGS) -I$(FRAMEWORKPATH) -I$(MATHPATH) -c $(MATHPATH)/Random/Prng.cpp
	$(CXX) -MM $(CFLAGS) -I$(FRAMEWORKPATH) -I$(MATHPATH) -c $(MATHPATH)/Random/Prng.cpp > Prng.d
	
Perlin.o: $(MATHPATH)/Random/Perlin.cpp
	$(CXX) $(CFLAGS) -I$(FRAMEWORKPATH) -I$(MATHPATH) -c $(MATHPATH)/Random/Perlin.cpp
	$(CXX) -MM $(CFLAGS) -I$(FRAMEWORKPATH) -I$(MATHPATH) -c $(MATHPATH)/Random/Perlin.cpp > Perlin.d
	
Vector.o: $(MATHPATH)/Algebra/VectorInst.cpp
	$(CXX) $(CFLAGS) -D$(VECFLAGS) -I$(FRAMEWORKPATH) -I$(MATHPATH) -c $(MATHPATH)/Algebra/VectorInst.cpp
	$(CXX) -MM $(CFLAGS) -I$(FRAMEWORKPATH) -I$(MATHPATH) -c $(MATHPATH)/Algebra/VectorInst.cpp > Vector.d
	mv VectorInst.o Vector.o
	
Plane.o: $(MATHPATH)/Algebra/PlaneInst.cpp
	$(CXX) $(CFLAGS) -I$(FRAMEWORKPATH) -I$(MATHPATH) -c $(MATHPATH)/Algebra/PlaneInst.cpp
	$(CXX) -MM $(CFLAGS) -I$(FRAMEWORKPATH) -I$(MATHPATH) -c $(MATHPATH)/Algebra/PlaneInst.cpp > Plane.d
	mv PlaneInst.o Plane.o
	
Matrix.o: $(MATHPATH)/Algebra/MtxInst.cpp
	$(CXX) $(CFLAGS) -I$(FRAMEWORKPATH) -I$(MATHPATH) -c $(MATHPATH)/Algebra/MtxInst.cpp
	$(CXX) -MM $(CFLAGS) -I$(FRAMEWORKPATH) -I$(MATHPATH) -c $(MATHPATH)/Algebra/MtxInst.cpp > Matrix.d
	mv MtxInst.o Matrix.o
	
Quaternion.o: $(MATHPATH)/Algebra/QuatInst.cpp
	$(CXX) $(CFLAGS) -I$(FRAMEWORKPATH) -I$(MATHPATH) -c $(MATHPATH)/Algebra/QuatInst.cpp
	$(CXX) -MM $(CFLAGS) -I$(FRAMEWORKPATH) -I$(MATHPATH) -c $(MATHPATH)/Algebra/QuatInst.cpp > Quaternion.d
	mv QuatInst.o Quaternion.o
	
3DMath.o: $(MATHPATH)/Space/3DMathInst.cpp
	$(CXX) $(CFLAGS) -I$(FRAMEWORKPATH) -I$(MATHPATH) -c $(MATHPATH)/Space/3DMathInst.cpp
	$(CXX) -MM $(CFLAGS) -I$(FRAMEWORKPATH) -I$(MATHPATH) -c $(MATHPATH)/Space/3DMathInst.cpp > 3DMath.d
	mv 3DMathInst.o 3DMath.o
	
.PHONY: clean

# remove compilation products
clean:
	rm -rf *.d *.o mathlib.a
