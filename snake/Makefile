all: main

main: main.cc main.h snake.o food.o text.o
	c++ -lsfml-window -lsfml-audio -lsfml-graphics -lsfml-system main.cc snake.o food.o text.o -o main 

snake.o: snake.cc snake.h
	c++ -c snake.cc -o snake.o

food.o: food.cc food.h
	c++ -c food.cc -o food.o

text.o: text.cc text.h
	c++ -c text.cc -o text.o

build: main
	rm -rf build
	mkdir build
	cp main build/snake
	cp *.wav build
	cp ./operatormono.otf build
