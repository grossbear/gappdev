#UtilsLib static library build Makefile

CXX=g++
ARCH=ar
CFLAGS=-std=gnu++11 -Wall
OBJDIR=obj
FRAMEWORKPATH = ../../Framework
UTILSPATH = ../../Framework/Base/Utils

_OBJ = BitArray.o FileStream.o Logger.o MemAlloc.o

all: $(_OBJ) utilslib.a

MakeDir:
	mkdir -p $(OBJDIR)
	
# link
utilslib.a: $(patsubst %,%,$(_OBJ))
	$(ARCH) rcs $@ $^

# compile and generate dependency info	
BitArray.o: $(UTILSPATH)/Arrays/BitArray.cpp
	$(CXX) $(CFLAGS) -I$(FRAMEWORKPATH) -I$(UTILSPATH) -c $(UTILSPATH)/Arrays/BitArray.cpp
	$(CXX) -MM $(CFLAGS) -I$(FRAMEWORKPATH) -I$(UTILSPATH) -c $(UTILSPATH)/Arrays/BitArray.cpp > BitArray.d
	
FileStream.o: $(UTILSPATH)/IOStream/FileStream.cpp
	$(CXX) $(CFLAGS) -I$(FRAMEWORKPATH) -I$(UTILSPATH) -c $(UTILSPATH)/IOStream/FileStream.cpp
	$(CXX) -MM $(CFLAGS) -I$(FRAMEWORKPATH) -I$(UTILSPATH) -c $(UTILSPATH)/IOStream/FileStream.cpp > FileStream.d

Logger.o: $(UTILSPATH)/Logger/Logger.cpp
	$(CXX) $(CFLAGS) -I$(FRAMEWORKPATH) -I$(UTILSPATH) -c $(UTILSPATH)/Logger/Logger.cpp
	$(CXX) -MM $(CFLAGS) -I$(FRAMEWORKPATH) -I$(UTILSPATH) -c $(UTILSPATH)/Logger/Logger.cpp > Logger.d

MemAlloc.o: $(UTILSPATH)/MemAlloc/memory_allocator_new.cpp
	$(CXX) $(CFLAGS) -I$(FRAMEWORKPATH) -I$(UTILSPATH) -c $(UTILSPATH)/MemAlloc/memory_allocator_new.cpp
	$(CXX) -MM $(CFLAGS) -I$(FRAMEWORKPATH) -I$(UTILSPATH) -c $(UTILSPATH)/MemAlloc/memory_allocator_new.cpp > memory_allocator_new.d
	mv memory_allocator_new.o MemAlloc.o

.PHONY: clean

# remove compilation products
clean:
	rm -r *.d *.o utilslib.a
