#include "snake.h"

Snake::Snake(sf::RenderWindow* window, sf::RectangleShape* border) {
    this->window = window;
    this->border = border;

    direction = 'R';

    for (int i = 0; i < 5; i++) {

        sf::CircleShape newShape(10.f);
        newShape.setFillColor(sf::Color::White);
        newShape.setPosition(i * 20 + 60.f, 60.f);

        segments.push_back(newShape);
    }
}

int Snake::getSegs() {
    return segments.size();
}

void Snake::setDirection(char direction) {
    if (direction == 'R') this->direction = (this->direction == 'L') ? 'L' : 'R';
    if (direction == 'L') this->direction = (this->direction == 'R') ? 'R' : 'L';
    if (direction == 'U') this->direction = (this->direction == 'D') ? 'D' : 'U';
    if (direction == 'D') this->direction = (this->direction == 'U') ? 'U' : 'D';
}

void Snake::move() {

    int numSegs = getSegs();

    for (int i = 0; i < numSegs - 1; i++) {
        segments[i].setPosition(segments[i + 1].getPosition().x, segments[i + 1].getPosition().y);
    }

    switch (direction) {
        case 'R':
            segments[numSegs - 1].move(20, 0);
            break;
        case 'L':
            segments[numSegs - 1].move(-20, 0);
            break;
        case 'U':
            segments[numSegs - 1].move(0, -20);
            break;
        case 'D':
            segments[numSegs - 1].move(0, 20);
            break;
    }

    if (segments[numSegs - 1].getPosition().x >= border->getGlobalBounds().width+20) {
        printf("Collided with wall\n");
        window->close();
    }
    if (segments[numSegs - 1].getPosition().x < 40) {
        printf("Collided with wall\n");
        window->close();
    }
    if (segments[numSegs - 1].getPosition().y < 40) {
        printf("Collided with wall\n");
        window->close();
    }
    if (segments[numSegs - 1].getPosition().y >= border->getGlobalBounds().height+20) {
        printf("Collided with wall\n");
        window->close();
    }
}

void Snake::draw() {
    int numSegs = getSegs();

    for (int i = 0; i < numSegs; i++) {
        window->draw(segments[i]);
    }
}

void Snake::eat() {
    sf::CircleShape currentEnding = segments.back();
    move();
    sf::CircleShape newShape(10.f);
    newShape.setFillColor(sf::Color::White);
    newShape.setPosition(currentEnding.getPosition().x, currentEnding.getPosition().y);
    segments.push_back(newShape);
}

sf::CircleShape Snake::getHead() {
    return segments[getSegs() - 1];
}