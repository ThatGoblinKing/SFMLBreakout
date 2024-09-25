#pragma once
#include <SFML/Graphics.hpp>
#include "Brick.h"
#include "Paddle.h"



class Ball {
 void draw(sf::RenderWindow &window);
 void move(sf::RenderWindow &window);
 bool brickCollision(Brick&);
 bool paddleCollision(Paddle&);
};

