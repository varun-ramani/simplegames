#include "globals.h"

#include <SFML/Graphics.hpp>
#include <iostream>
#include "ship.h"


Ship player1(sf::Color::Blue, 10, 10);

void controls() {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
        
    }
}

int main(int argc, char const *argv[])
{

    std::cout << "Let's play Yeetships!" << std::endl;

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }

        window.clear(sf::Color::Black);

        player1.draw();

        window.display();
    }

    std::cout << "Bye!" << std::endl;

    return 0;
}
