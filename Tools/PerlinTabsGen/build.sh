#!/bin/bash
# g++ -std=gnu++11 -o genprog.exe main.cpp PerlinTabsGen.cpp 

make tool
g++ -std=gnu++11 -o perlintabsgen.exe obj/main.o obj/perlintabsgen.o obj/mathlib.a
