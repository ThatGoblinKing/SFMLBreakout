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
        bricks[i] = Brick(100 + (60*i), 100, 50, 20);
    }

    while (window.isOpen())
    {
        for (auto event = sf::Event{}; window.pollEvent(event);)
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
        }
        ball.move();
        window.clear();
        for (Brick &brick : bricks) {
            brick.draw(window);
            ball.brickCollision(brick);
        }
        ball.draw(window);
        window.display();
    }
}
