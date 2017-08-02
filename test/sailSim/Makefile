# This makefile builds all the object files from the source directory, you can
# add in specific recipes for your own executables

# Compiler
CC=g++

# Options Passed to compiler
CFLAGS=-c -Wall -std=c++11 -I./include -g

# Directories
sourceDir = source/
buildDir = build/

sources = $(wildcard $(sourceDir)*.cpp)
objects = $(patsubst $(sourceDir)%.cpp, $(buildDir)%.o, $(sources))

all: $(objects) sailSim

sailSim: $(objects)
	$(CC) -o sailSim $(objects) -std=c++11 -I./include

$(objects): $(buildDir)%.o : $(sourceDir)%.cpp
	-$(CC) $(CFLAGS) $< -o $@
