#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "globals.h"

class Ship {
    public:
        Ship(sf::Color color, float initialX, float initialY);
        void draw();
        void thrust();
        void brake();
        void left();
        void right();
        void updatePos();

    private:
        float xcoord;
        float ycoord;
        float angle;
        float speed;
};
