all: main 

main: main.cc main.h snake.o food.o
	c++ -lsfml-window -lsfml-graphics -lsfml-system main.cc snake.o food.o -o main 

snake.o: snake.cc snake.h
	c++ -c snake.cc -o snake.o

food.o: food.cc food.h
	c++ -c food.cc -o food.o
