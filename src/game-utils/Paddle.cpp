#include "Paddle.h"
Paddle::Paddle() {
    width = 0;
    height = 0;
    xPos = 0;
    yPos = 0;
}

Paddle::Paddle(const float w, const float h, const float x, const float y) {
    width = w;
    height = h;
    xPos = x;
    yPos = y;

    shape.setSize(sf::Vector2f(width, height));
    shape.setPosition(xPos, yPos);
    shape.setFillColor(sf::Color::White);
}

void Paddle::moveLeft() {
    if (xPos >= 0) {
        xPos -= PADDLE_SPEED;
        shape.move(-PADDLE_SPEED, 0);
    }
}

void Paddle::moveRight() {
    if (getRightPos() <= SCREEN_WIDTH) {
        xPos += PADDLE_SPEED;
        shape.move(PADDLE_SPEED, 0);
    }
}

void Paddle::draw(sf::RenderWindow &window) const {
    window.draw(shape);
}


float Paddle::getLeftPos() const {
    return xPos;
}
float Paddle::getRightPos() const {
    return xPos + width;
}
float Paddle::getTopPos() const {
    return yPos;
}

float Paddle::getBottomPos() const {
    return yPos + height;
}


