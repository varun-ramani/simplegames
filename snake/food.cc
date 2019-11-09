#include "food.h"

Food::Food(sf::RenderWindow* window, Snake* snake) {
    this->window = window;
    this->snake = snake;
    shape = new sf::CircleShape(10.f);
    generate();

    buffer = new sf::SoundBuffer();
    buffer->loadFromFile("point.wav");

    apple = new sf::Texture();
    apple->loadFromFile("apple.png");

    shape->setTexture(apple);
    sound = new sf::Sound();
    sound->setBuffer(*buffer);
}

void Food::generate() {
    x = (rand() % 38 + 1) * 20 + 40;
    y = (rand() % 38 + 1) * 20 + 40;
    shape->setPosition(x, y);
}

void Food::draw() {
    window->draw(*shape);
}

void Food::checkEaten() {
    if (snake->getHead().getPosition().x == x && snake->getHead().getPosition().y == y) {
        generate();
        snake->eat();
        sound->play();
    }
}
