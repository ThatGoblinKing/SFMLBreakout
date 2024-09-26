#pragma once
#include <SFML/Graphics.hpp>

class Brick {
    float width, height, xPos, yPos;
    bool dead = false;
    sf::RectangleShape shape;
public:
    Brick();
    Brick(float w, float h, float x, float y);
    void draw(sf::RenderWindow &window) const;
    void killBrick();
    float getXPos() const;
    float getYPos() const;
    float getWidth() const;
    float getHeight() const;
    bool isDead() const;
};