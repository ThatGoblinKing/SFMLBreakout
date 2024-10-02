#include "SFML/Graphics.hpp"
#include "game-utils/Ball.h"
#include "game-utils/Brick.h"
#include "game-utils/Paddle.h"

int main()
{
    sf::Texture ballTexture;
    ballTexture.loadFromFile("INSERT HAMPTER ABSOLUTE PATH HERE.");

    //Sound not working bc of importing issues :(
    const int SCREEN_WIDTH = 800;
    auto window = sf::RenderWindow{ sf::VideoMode(SCREEN_WIDTH,600), "Breakout" };
    window.setFramerateLimit(144);
    Ball ball(60, 100, 300 ,ballTexture);
    const int ROWS = 3, COLUMNS = 12, GAP = 10, HEIGHT = 20;
    Brick bricks[ROWS * COLUMNS];
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLUMNS; j++) {
            bricks[j + (COLUMNS * i)] = Brick(SCREEN_WIDTH / COLUMNS - GAP, HEIGHT, GAP + (SCREEN_WIDTH / COLUMNS) * j, (HEIGHT + GAP) * i);
        }
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
