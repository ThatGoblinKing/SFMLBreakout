#pragma once
#include <SFML/Graphics.hpp>

class Brick {
private:
    float width, height, xPos, yPos;
    bool dead = false;
public:
    Brick(float w, float h, float x, float y);
    void draw(sf::RenderWindow &window);
    void killBrick();
};