#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>

#include "snake.h"
#include "food.h"

int waittime = 300;

void checkControls(Snake* snake) {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
        snake->setDirection('R');
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
        snake->setDirection('L');
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
        snake->setDirection('D');
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
        snake->setDirection('U');
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
        waittime = 50;
    } else {
        waittime = 150;
    }

}

int main(int argc, char const *argv[])
{
    sf::RenderWindow window(sf::VideoMode(1000, 1000), "Snake");

    sf::RectangleShape border(sf::Vector2f(800.f,800.f));
    border.setPosition(40.f, 40.f);
    border.setOutlineThickness(2.f);
    border.setFillColor(sf::Color::Transparent);

    Snake snake(&window, &border);
    Food food(&window, &snake);

    sf::Clock clock;

    while (window.isOpen()) {
        sf::Event event;

        if (clock.getElapsedTime().asMilliseconds() > waittime) {
            clock.restart();
            snake.move();
        }

        while (window.pollEvent(event)) {
            switch (event.type) {
                case sf::Event::Closed:
                    window.close();
                    break;
            }
        }

        window.clear(sf::Color::Black);

        checkControls(&snake);

        snake.draw();
        window.draw(border);
        food.draw();
        food.checkEaten();

        window.display();
    }

    return 0;
}