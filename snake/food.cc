#include "food.h"

Food::Food(sf::RenderWindow* window, Snake* snake) {
    this->window = window;
    this->snake = snake;
    shape = new sf::CircleShape(10.f);
    shape->setFillColor(sf::Color::Blue);
    generate();
}

void Food::generate() {
    x = (rand() % 40) * 20 + 40;
    y = (rand() % 40) * 20 + 40;
    shape->setPosition(x, y);
}

void Food::draw() {
    window->draw(*shape);
}

void Food::checkEaten() {
    if (snake->getHead().getPosition().x == x && snake->getHead().getPosition().y == y) {
        generate();
        snake->eat();
    }
}