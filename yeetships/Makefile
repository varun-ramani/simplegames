all: main

main: main.cc main.h ship.o globals.o
	c++ -lsfml-window -lsfml-audio -lsfml-graphics -lsfml-system main.cc ship.o globals.o -o main

ship.o: ship.cc ship.h
	c++ -c ship.cc -o ship.o

globals.o: globals.cc globals.h
	c++ -c globals.cc -o globals.o

build: main
	rm -rf build
	mkdir build
	cp main build/snake
	cp *.wav build
	cp ./operatormono.otf build

