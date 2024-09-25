#include <SFML/Graphics.hpp>
#include "game-utils/Ball.h"
#include "game-utils/Brick.h"
#include "game-utils/Paddle.h"

int main()
{
    auto window = sf::RenderWindow{ sf::VideoMode(800,600), "Breakout" };
    window.setFramerateLimit(144);

    while (window.isOpen())
    {
        for (auto event = sf::Event{}; window.pollEvent(event);)
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
        }

        window.clear();
        window.display();
    }
}
