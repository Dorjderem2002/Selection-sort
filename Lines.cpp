#include "Lines.hpp"


line::Lines::Lines(float h) {
    height = h;
    //height = rand() % 650 + 100;
    line.setSize(sf::Vector2f(2,height));
    line.setFillColor(sf::Color::White);
    line.setPosition(sf::Vector2f(0,800-height));
}
void line::Lines::draw(sf::RenderWindow &window) {
    window.draw(line);
}
void line::Lines::move(float speed) {
    line.move(speed, 0);
}
sf::Vector2f line::Lines::getPos() {
    return line.getPosition();
}
void line::Lines::setColor(sf::Color color) {
    line.setFillColor(color);
}
void line::Lines::setH(float h) {
    line.setSize(sf::Vector2f(1.5,h));
}
void line::Lines::setPos(float x) {
    line.setPosition(x, 800-height);
}
float line::Lines::getHeight() {
    return height;
}
