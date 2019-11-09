#include "ship.h"

sf::CircleShape shipShape(30.f, 3);

Ship::Ship(sf::Color color, float initialX, float initialY) {
    shipShape.setPosition(initialX, initialY);
    shipShape.setFillColor(color);   
}

void Ship::draw() {
    window.draw(shipShape);   
}