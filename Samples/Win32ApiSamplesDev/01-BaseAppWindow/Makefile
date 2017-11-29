CXX=g++
CFLAGS=-I.
OBJDIR=obj
FRAMEWORKPATH = ../../../Framework
APPWNDPATH = ../../../Framework/Base/AppWindow
COMMONPATH = ../../../Framework/Base/Common
_OBJ = WinMain.o Application.o BaseWinApp.o AppWindow.o


all: MakeDir $(_OBJ) baseapp.exe

baseapp.exe: $(patsubst %,$(OBJDIR)/%,$(_OBJ))
	$(CXX) -o $@ $^
    
MakeDir:
	mkdir -p $(OBJDIR)
	
WinMain.o: $(APPWNDPATH)/WinMain.cpp
	$(CXX) -I$(FRAMEWORKPATH) -c $(APPWNDPATH)/WinMain.cpp
	mv WinMain.o $(OBJDIR)/WinMain.o
	
BaseWinApp.o: BaseWinApp.h BaseWinApp.cpp
	$(CXX) -I$(FRAMEWORKPATH) -c BaseWinApp.cpp
	mv BaseWinApp.o $(OBJDIR)/BaseWinApp.o
	
Application.o: $(COMMONPATH)/Application.h $(COMMONPATH)/Application.cpp
	$(CXX) -I$(FRAMEWORKPATH) -c $(COMMONPATH)/Application.cpp
	mv Application.o $(OBJDIR)/Application.o
	
AppWindow.o: $(APPWNDPATH)/AppWindow.h $(APPWNDPATH)/AppWindow.cpp
	$(CXX) -I$(FRAMEWORKPATH) -c $(APPWNDPATH)/AppWindow.cpp
	mv AppWindow.o $(OBJDIR)/AppWindow.o
	
Test.o: 
	mkdir -p $(OBJDIR)
	@echo $(APPWNDPATH)
	
	
#gcc *.c -o Output
#building all c files in folder

.PHONY: clean 
 
clean:
	rm -rf $(OBJDIR) baseapp.exe
