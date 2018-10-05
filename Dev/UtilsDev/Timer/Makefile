#UtilsLib build makefile and build timer dev program

CXX=g++
CFLAGS=-std=gnu++11
FRAMEWORKPATH = ../../../Framework
UTILSPATH = ../../../Framework/Base/Utils
UTILSLIBPATH = ../../../Libs/UtilsLib

OBJDIR=obj
objdir_tgt = $(OBJDIR)-$(wildcard $(OBJDIR))
objdir_present = $(OBJDIR)-$(OBJDIR)
objdir_absent = $(OBJDIR)-

_OBJ = $(OBJDIR)/progtimer.o $(OBJDIR)/utilslib.a

PROGNAME := 
ifeq ($(OS),Windows_NT)
	PROGNAME += timerprog.exe
else
	PROGNAME += timerprog
endif

all: | $(objdir_tgt) $(_OBJ) $(PROGNAME)

#MakeDir:
#	mkdir -p $(OBJDIR)
	
$(objdir_present):
	@echo "Directory '$(OBJDIR)' exists, no need to create it again."

$(objdir_absent):
	@echo "Directory '$(OBJDIR)' does not exists."
	@echo "Creating directory '$(OBJDIR)'."
	@mkdir -p $(OBJDIR)

$(PROGNAME): $(patsubst %, %,$(_OBJ))
	@echo "Building programme:$(PROGNAME)"
	@$(CXX) -o $@ $^

$(OBJDIR)/utilslib.a:
	@make -C $(UTILSLIBPATH)
	@cp $(UTILSLIBPATH)/utilslib.a $(OBJDIR)/utilslib.a
	
$(OBJDIR)/progtimer.o: progtimer.cpp
	@echo "Compiling file: $<"
	@$(CXX) $(CFLAGS) -I$(FRAMEWORKPATH) -c progtimer.cpp
	@mv progtimer.o $(OBJDIR)/progtimer.o

.PHONY: clean

clean:
	rm -rf $(OBJDIR)
	rm $(PROGNAME)
