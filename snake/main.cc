#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <bits/stdc++.h>

#include "snake.h"
#include "food.h"
#include "text.h"

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
        waittime = 15;
    } else {
        waittime = (300 / snake->getSegs()) + 10;
    }

}

int main(int argc, char const *argv[])
{
    sf::Texture background;
    background.loadFromFile("milkyway.jpg");

    sf::RenderWindow window(sf::VideoMode(1000, 1000), "Snake");

    sf::RectangleShape border(sf::Vector2f(800.f,800.f));
    border.setTexture(&background);
    border.setPosition(40.f, 40.f);
    border.setOutlineThickness(2.f);

    sf::Music music;
    music.openFromFile("music.wav");
    music.setLoop(true);
    music.setPitch(1.5);
    music.setVolume(40);
    music.play();

    Snake snake(&window, &border);
    Food food(&window, &snake);
    Text text(&waittime, &snake, &window);

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

        

        window.draw(border);

        snake.draw();
        food.draw();
        food.checkEaten();

        window.display();
    }

    return 0;
}
