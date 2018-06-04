#Perlin Tables Gen makefile also can build MathLib

CXX=g++
CFLAGS=-std=gnu++11
OBJDIR=obj
FRAMEWORKPATH = ../../Framework
MATHPATH = ../../Framework/Base/Math
MATHLIBPATH = ../../Libs/MathLib
MAINTOOLSPATH = ../

_OBJ = main.o perlintabsgen.o intnumgen.o datasrcsaver.o mathlib.a

all: MakeDir $(_OBJ) perlintabsgen.exe

MakeDir:
	mkdir -p $(OBJDIR)

perlintabsgen.exe: $(patsubst %,$(OBJDIR)/%,$(_OBJ))
	$(CXX) -o $@ $^
    
main.o: main.cpp
	$(CXX) $(CFLAGS) -I$(FRAMEWORKPATH) -I$(MAINTOOLSPATH) -c main.cpp
	mv main.o $(OBJDIR)/main.o 

mathlib.a:
	make clean -C $(MATHLIBPATH)
	make VECFLAGS=MATH_HIGH_PREC_FLOAT_VEC -C $(MATHLIBPATH) -j 4
	cp $(MATHLIBPATH)/mathlib.a $(OBJDIR)/mathlib.a

intnumgen.o: IntNumGen.cpp
	$(CXX) $(CFLAGS) -I$(FRAMEWORKPATH) -c IntNumGen.cpp
	mv IntNumGen.o $(OBJDIR)/intnumgen.o
	
datasrcsaver.o: $(MAINTOOLSPATH)/CommonSrc/DataSrcSaver.cpp
	$(CXX) $(CFLAGS) -I$(FRAMEWORKPATH) -c $(MAINTOOLSPATH)/CommonSrc/DataSrcSaver.cpp
	mv DataSrcSaver.o $(OBJDIR)/datasrcsaver.o		
	
perlintabsgen.o: PerlinTabsGen.cpp
	$(CXX) $(CFLAGS) -I$(FRAMEWORKPATH) -c PerlinTabsGen.cpp
	mv PerlinTabsGen.o $(OBJDIR)/perlintabsgen.o

tool: main.o perlintabsgen.o intnumgen.o

.PHONY: clean

clean:
	rm -rf $(OBJDIR) perlintabsgen.exe
