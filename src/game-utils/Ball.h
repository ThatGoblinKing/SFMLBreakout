#pragma once
#include <SFML/Graphics.hpp>
#include "Brick.h"
#include "Paddle.h"

class Ball {
    sf::CircleShape shape;
    float radius, xPos, yPos, xVel, yVel;
    float SCREEN_WIDTH = 800, HAMPTER_SIZE = 100;
    sf::Sprite sprite;
public:
    Ball();
    Ball(float rad, float x, float y, const sf::Texture& texture);
    void draw(sf::RenderWindow &window) const;
    void move();
    bool brickCollision(Brick& brick);
    bool paddleCollision(const Paddle& paddle);
};