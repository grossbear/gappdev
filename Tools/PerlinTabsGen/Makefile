#Perlin Tables Gen makefile also can build MathLib

CXX=g++
CFLAGS=-std=gnu++11
OBJDIR=obj
FRAMEWORKPATH = ../../Framework
MATHPATH = ../../Framework/Base/Math
MATHLIBPATH = ../../Libs/MathLib

_OBJ = main.o perlintabsgen.o intnumgen.o mathlib.a

all: MakeDir $(_OBJ) perlintabsgen.exe

MakeDir:
	mkdir -p $(OBJDIR)

perlintabsgen.exe: $(patsubst %,$(OBJDIR)/%,$(_OBJ))
	$(CXX) -o $@ $^
    
main.o: main.cpp
	$(CXX) $(CFLAGS) -I$(FRAMEWORKPATH) -c main.cpp
	mv main.o $(OBJDIR)/main.o 

mathlib.a:
	make -C $(MATHLIBPATH)
	cp $(MATHLIBPATH)/mathlib.a $(OBJDIR)/mathlib.a

intnumgen.o: IntNumGen.cpp
	$(CXX) $(CFLAGS) -I$(FRAMEWORKPATH) -c IntNumGen.cpp
	mv IntNumGen.o $(OBJDIR)/intnumgen.o

perlintabsgen.o: PerlinTabsGen.cpp
	$(CXX) $(CFLAGS) -I$(FRAMEWORKPATH) -c PerlinTabsGen.cpp
	mv PerlinTabsGen.o $(OBJDIR)/perlintabsgen.o

tool: main.o perlintabsgen.o intnumgen.o

.PHONY: clean

clean:
	rm -rf $(OBJDIR) perlintabsgen.exe
