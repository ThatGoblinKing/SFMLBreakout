#include <SFML/Graphics.hpp>
#include "game-utils/Ball.h"
#include "game-utils/Brick.h"
#include "game-utils/Paddle.h"

int main()
{
    auto window = sf::RenderWindow{ sf::VideoMode(800,600), "Breakout" };
    window.setFramerateLimit(144);
    Brick bricks[3];
    Ball ball(10, 100, 300);
    for(int i = 0; i < 3; i++) {
        bricks[i] = Brick(50, 20, 100 + (60*i), 100);
    }

    Paddle paddle(100, 20, 60, 400);

    while (window.isOpen())
    {
        for (auto event = sf::Event{}; window.pollEvent(event);)
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
            paddle.moveLeft();
        } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
            paddle.moveRight();
        }
        ball.move();
        window.clear();
        for (Brick &brick : bricks) {
            brick.draw(window);
            if (ball.brickCollision(brick)) {
                break; //Make sure only 1 brick hit per frame
            }
        }
        ball.paddleCollision(paddle);
        ball.draw(window);
        paddle.draw(window);
        window.display();
    }
}
