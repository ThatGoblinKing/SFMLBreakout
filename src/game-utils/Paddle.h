#pragma once
#include <SFML\Graphics.hpp>

class Paddle {
    private:
        float width, height, xPos, yPos;
        sf::RectangleShape shape;
    public:
    const float PADDLE_SPEED = 5;
    Paddle();
    Paddle(float w, float h, float x, float y);
    void moveLeft();
    void moveRight();
    void draw(sf::RenderWindow &window) const;
    float getLeftPos() const;
    float getRightPos() const;
    float getTopPos() const;
    float getBottomPos() const;
};