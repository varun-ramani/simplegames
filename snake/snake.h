#include <SFML/Graphics.hpp>
#ifndef SNAKE_H
#define SNAKE_H

#include <SFML/Window.hpp>
#include <vector>

class Snake {
    public:
        Snake(sf::RenderWindow* window, sf::RectangleShape* border);
        void draw();
        int getSegs();
        void move();
        void setDirection(char direction);
        void eat();
        sf::CircleShape getHead();

    private:
        std::vector<sf::CircleShape> segments;
        sf::RenderWindow* window;
        sf::RectangleShape* border;
        char direction;
};

#endif