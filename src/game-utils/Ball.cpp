#include "Ball.h"
#include "Brick.h"

Ball::Ball() {
    radius = 0;
    xPos = 0;
    yPos = 0;
    xVel = 0;
    yVel = 0;
}

Ball::Ball(const float rad, const float x, const float y) {
    radius = rad;
    xPos = x;
    yPos = y;

    shape.setRadius(radius);
    shape.setPosition(xPos, yPos);
    shape.setFillColor(sf::Color::White);
}

bool Ball::brickCollision(Brick& brick) {
    if (!brick.isDead() &&
        xPos + radius > brick.getXPos() &&
        xPos - radius < brick.getXPos() + brick.getWidth() &&
        yPos + radius > brick.getYPos() &&
        yPos - radius < brick.getYPos() + brick.getHeight()) {
        brick.killBrick();
        yVel *= -1;
        return true;
        } else {
            return false;
        }
}

bool Ball::paddleCollision(Paddle& paddle) {
    return false;
}

void Ball::move() {
    xPos += xVel;
    yPos += yVel;
    shape.setPosition(xPos, yPos);
}

void Ball::draw(sf::RenderWindow &window) const {
    window.draw(shape);
}


