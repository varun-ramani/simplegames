#ifndef FOOD_H
#define FOOD_H

#include "snake.h"
#include <SFML/Graphics.hpp>
#include <cstdlib>

class Food {
    public:
        Food(sf::RenderWindow* window, Snake* snake);
        void generate();
        void draw();
        void checkEaten();

    private:
        sf::RenderWindow* window;
        sf::CircleShape* shape;
        Snake* snake;
        int x;
        int y;
};

#endif