#include "Brick.h"
#include <SFML/Graphics.hpp>

Brick::Brick() {
    width = 0;
    height = 0;
    xPos = 0;
    yPos = 0;
    dead = true;
}

Brick::Brick(const float w, const float h, const float x, const float y) {
    width = w;
    height = h;
    xPos = x;
    yPos = y;
    dead = false;

    shape.setSize(sf::Vector2f(width, height));
    shape.setPosition(xPos, yPos);
    shape.setFillColor(sf::Color::Red);
}

void Brick::draw(sf::RenderWindow &window) const {
    if (!dead) {
        window.draw(shape);
    }
}

void Brick::killBrick() {
    dead = true;
    shape.setFillColor(sf::Color::Transparent);
}

float Brick::getXPos() const {
    return xPos;
}

float Brick::getYPos() const {
    return yPos;
}

float Brick::getWidth() const {
    return width;
}

float Brick::getHeight() const {
    return height;
}

bool Brick::isDead() const {
    return dead;
}

