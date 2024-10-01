#pragma once
#include <SFML/Graphics.hpp>
#include "Brick.h"
#include "Paddle.h"

class Ball {
    sf::CircleShape shape;
    float radius, xPos, yPos, xVel, yVel;
    float SCREEN_WIDTH = 800;
public:
    Ball();
    Ball(float rad, float x, float y);
    void draw(sf::RenderWindow &window) const;
    void move();
    bool brickCollision(Brick& brick);
    bool paddleCollision(const Paddle& paddle);
};