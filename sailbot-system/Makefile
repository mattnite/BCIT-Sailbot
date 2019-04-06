CC=g++
CFLAGS=-Iinc -g $(pkg-config --libs libgps)
SRCDIR=lib
OBJDIR=build
SOURCE=$(wildcard $(SRCDIR)/*)
OBJECTS=$(patsubst $(SRCDIR)/%.cpp, $(OBJDIR)/%.o, $(SOURCE))

all: main datalogger gps

main: $(OBJECTS) build/main.o
	${CC} $(CFLAGS) $(OBJECTS) build/main.o -o main

datalogger: $(OBJECTS) build/data-logger.o
	${CC} $(CFLAGS) $(OBJECTS) build/data-logger.o -o datalogger

gps: $(OBJECTS) build/gps.o
	${CC} $(CFLAGS) $(OBJECTS) build/gps.o -o gps -lgps

build/%.o: lib/%.cpp
	$(CC) $^ -c ${CFLAGS} -o $@

build/%.o: src/%.cpp
	$(CC) $^ -c ${CFLAGS} -o $@

clean:
	echo $(SOURCE)
	-rm main $(OBJECTS)
