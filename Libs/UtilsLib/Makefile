#UtilsLib static library build Makefile

CXX=g++
ARCH=ar
CFLAGS=-std=gnu++11 -Wall
OBJDIR=obj
FRAMEWORKPATH = ../../Framework
UTILSPATH = ../../Framework/Base/Utils

_OBJ = $(OBJDIR)/BitArray.o $(OBJDIR)/FileStream.o $(OBJDIR)/Logger.o $(OBJDIR)/MemAlloc.o

all: MakeDir $(_OBJ) utilslib.a

MakeDir:
	@echo "Creating $(OBJDIR) directory."
	@mkdir -p $(OBJDIR)
	
# link
utilslib.a: $(patsubst %, %, $(_OBJ))
	@echo "Building static library: $@"
	@$(ARCH) rcs $@ $^

# compile and generate dependency info	
$(OBJDIR)/BitArray.o: $(UTILSPATH)/Arrays/BitArray.cpp $(UTILSPATH)/Arrays/BitArray.h
	@echo "Compiling file: $<" 
	@$(CXX) $(CFLAGS) -I$(FRAMEWORKPATH) -I$(UTILSPATH) -c $< -o $@
#	@mv BitArray.o $(OBJDIR)/BitArray.o
	
$(OBJDIR)/FileStream.o: $(UTILSPATH)/IOStream/FileStream.cpp $(UTILSPATH)/IOStream/FileStream.h
	@echo "Compiling file: $<"
	@$(CXX) $(CFLAGS) -I$(FRAMEWORKPATH) -I$(UTILSPATH) -c $< -o $@
#	@mv FileStream.o $(OBJDIR)/FileStream.o

$(OBJDIR)/Logger.o: $(UTILSPATH)/Logger/Logger.cpp $(UTILSPATH)/Logger/Logger.cpp
	@echo "Compiling file: $<"
	@$(CXX) $(CFLAGS) -I$(FRAMEWORKPATH) -I$(UTILSPATH) -c $< -o $@
#	@mv Logger.o $(OBJDIR)/Logger.o

$(OBJDIR)/MemAlloc.o: $(UTILSPATH)/MemAlloc/memory_allocator_new.cpp $(UTILSPATH)/MemAlloc/memory_allocator_new.h\
$(UTILSPATH)/MemAlloc/memory_allocator.h
	@echo "Compiling file: $<"
	@$(CXX) $(CFLAGS) -I$(FRAMEWORKPATH) -I$(UTILSPATH) -c $< -o $@
#	@mv memory_allocator_new.o $(OBJDIR)/MemAlloc.o

.PHONY: clean

# remove compilation products
clean:
	@echo "Removing $(OBJDIR) directory and utilslib.a library."
	@rm -rf $(OBJDIR) utilslib.a
