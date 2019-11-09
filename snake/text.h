#include <SFML/Graphics.hpp>
#include "snake.h"
#include <bits/stdc++.h>

class Text {
    public:
        Text(int* waittime, Snake* snake, sf::RenderWindow* window);
        void draw();

    private:
        int* waittime;
        Snake* snake;
        sf::RenderWindow* window;
        sf::Text* waitText;
        sf::Text* scoreText;
        sf::Text* titleText;
};