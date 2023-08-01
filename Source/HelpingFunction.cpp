#include"HelpingFunction.h"
#include <SFML/Graphics.hpp>

void static getRowColbyLeftClick(int& rpos, int& cpos, sf::RenderWindow& window)
{
    while (true)
    {
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
        {
            sf::Vector2i p = sf::Mouse::getPosition(window);

            cpos = p.x;
            rpos = p.y;
            break;
        }
    }
}
