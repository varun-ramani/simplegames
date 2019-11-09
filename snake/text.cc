#include "text.h"

Text::Text(int* waittime, Snake* snake, sf::RenderWindow* window) {
    this->waittime = waittime;
    this->snake = snake;
    this->window = window;

    sf::Font font;
    font.loadFromFile("operatormono.otf");

    this->titleText = new sf::Text();
    titleText->setFont(font);
    titleText->setString("Crazy Snake!");
    titleText->setFillColor(sf::Color::Red);
    titleText->setCharacterSize(24);
    titleText->setStyle(sf::Text::Style::Regular);
    titleText->setPosition(40, 0);

    this->waitText = new sf::Text();
    waitText->setFont(font);
    waitText->setString("");
    waitText->setFillColor(sf::Color::Green);
    waitText->setCharacterSize(15);
    waitText->setStyle(sf::Text::Style::Regular);
    waitText->setPosition(40, 860);

    this->scoreText = new sf::Text();
    scoreText->setFont(font);
    scoreText->setString("");
    scoreText->setFillColor(sf::Color::Green);
    scoreText->setCharacterSize(15);
    scoreText->setStyle(sf::Text::Style::Regular);
    scoreText->setPosition(40, 900);

}

void Text::draw() {
    waitText->setString(std::string("Time Between Tics: ") + std::to_string(*waittime));
    scoreText->setString(std::string("Score: ") + std::to_string(snake->getSegs()));

    window->draw(*waitText);
    window->draw(*scoreText);
    window->draw(*titleText);
}