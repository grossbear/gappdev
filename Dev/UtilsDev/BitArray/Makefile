#BitArray dev programme

CXX=g++
CFLAGS=-std=gnu++11
OBJDIR=obj
FRAMEWORKPATH = ../../../Framework
UTILSPATH = ../../../Framework/Base/Utils
MATHLIBPATH = ../../../Libs/MathLib

_OBJ = bitarray.o progarray.o

PROGNAME := 
ifeq ($(OS),Windows_NT)
	PROGNAME += progarray.exe
else
	PROGNAME += progarray
endif


all: MakeDir $(_OBJ) $(PROGNAME)

MakeDir:
	mkdir -p $(OBJDIR)
	
$(PROGNAME): $(patsubst %,$(OBJDIR)/%,$(_OBJ))
	$(CXX) -o $@ $^

bitarray.o: $(UTILSPATH)/Arrays/BitArray.cpp
	$(CXX) $(CFLAGS) -I$(UTILSPATH) -c $(UTILSPATH)/Arrays/BitArray.cpp
	mv BitArray.o $(OBJDIR)/bitarray.o

progarray.o: progarray.cpp
	$(CXX) $(CFLAGS) -I$(FRAMEWORKPATH) -c progarray.cpp
	mv progarray.o $(OBJDIR)/progarray.o

.PHONY: clean

clean:
	rm -rf $(OBJDIR) $(PROGNAME)


