#include "ship.h"
#include "math.h"

sf::CircleShape shipShape(30.f, 3);

Ship::Ship(sf::Color color, float initialX, float initialY) {
    shipShape.setPosition(initialX, initialY);
    shipShape.setFillColor(color);
}

void Ship::updatePos() {
    if (this->speed > 0) {
        speed -= 0.1;
    }

    float radAngle = (angle / 180.0) * M_PI;
    float changeX = cos(radAngle) * speed;
    float changeY = sin(radAngle) * speed;
    xcoord += changeX;
    ycoord += changeY;
}

void Ship::thrust() {
    
}

void Ship::draw() {
    shipShape.setPosition(xcoord, ycoord);
    shipShape.setRotation(angle);
    window.draw(shipShape);   
}