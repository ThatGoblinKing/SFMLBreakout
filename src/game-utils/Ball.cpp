#include "Ball.h"
#include "Brick.h"
#include <iostream>

Ball::Ball() {
    radius = 0;
    xPos = 0;
    yPos = 0;
    xVel = 0;
    yVel = 0;
}

Ball::Ball(const float rad, const float x, const float y, const sf::Texture& texture){
    radius = rad;
    xPos = x;
    yPos = y;
    xVel = -1;
    yVel = -3;

    shape.setRadius(radius);
    shape.setOrigin(radius,radius);
    shape.setPosition(xPos, yPos);
    shape.setFillColor(sf::Color::White);
    sprite.setTexture(texture);
    sprite.setScale(((radius * 2)/HAMPTER_SIZE),  ((radius * 2)/HAMPTER_SIZE));

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

bool Ball::paddleCollision(const Paddle& paddle) {
    if (xPos + radius > paddle.getLeftPos() &&
        xPos - radius < paddle.getRightPos() &&
        yPos + radius > paddle.getTopPos() &&
        yPos - radius < paddle.getBottomPos()) {
        yPos = paddle.getTopPos() - radius;
        yVel *= -1;
        return true;
    }
    return false;
}

void Ball::move() {
    if (xPos + radius + xVel > SCREEN_WIDTH) {
        xVel *= -1;
        xPos = SCREEN_WIDTH - radius;
    }
    else if (xPos - radius + xVel < 0) {
        xVel *= -1;
    }
    if (yPos - radius + yVel < 0) {
        yVel *= -1;
        yPos = radius;
    }
    xPos += xVel;
    yPos += yVel;
    shape.setPosition(xPos, yPos);
    sprite.setPosition(shape.getPosition().x - radius, shape.getPosition().y - radius);
}

void Ball::draw(sf::RenderWindow &window) const {
    window.draw(shape);
    window.draw(sprite);
}


