# This makefile builds all the object files from the source directory, you can
# add in specific recipes for your own executables

# Compiler
CC=g++

# Options Passed to compiler
CFLAGS= -Wall -std=c++11 -I./include -g -lsfml-graphics -lsfml-window -lsfml-system

# Directories
sourceDir = source/
buildDir = build/

sources = $(wildcard $(sourceDir)*.cpp)
objects = $(patsubst $(sourceDir)%.cpp, $(buildDir)%.o, $(sources))

all: $(objects) sailSim

sailSim: $(objects)
	$(CC) -o source/sailSim $(objects) $(CFLAGS) 

$(objects): $(buildDir)%.o : $(sourceDir)%.cpp
	-$(CC) -c $(CFLAGS) $< -o $@
