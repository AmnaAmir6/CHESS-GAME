#include"HelpingFunction.h"
#include <SFML/Graphics.hpp>
#include"Chess.h"
#include<fstream>

int main()
{
    char ch;
    sf::RenderWindow window(sf::VideoMode(1000, 600), "Game Menu");
    sf::Font font;
    if (!font.loadFromFile("arial.ttf")) {
        std::cout << "Error loading font." << std::endl;
        return 1;
    }

    sf::Text newGameText("New Game", font, 50);
    newGameText.setPosition(100, 50);
    sf::Text loadGameText("Load Game", font, 50);
    loadGameText.setPosition(100, 150);
    sf::Texture temp;
    if (!temp.loadFromFile("Chess.jpg")) // img ==> file name for image
    {
        throw("Unable to load img");
    }
    sf::Sprite s(temp);
    s.setScale(0.5, 0.5);
    s.setPosition(0, 0);
   
    while (window.isOpen()) {

        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }

            else if (event.type == sf::Event::MouseButtonPressed) {
                if (newGameText.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y)) {
                    ch = 'S';
                    window.close();
                }
                else if (loadGameText.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y)) {
                    ch = 'O';
                    window.close();
                }
            }
        }

        window.clear();
        window.draw(s);
        window.draw(newGameText);
        window.draw(loadGameText);
        
        window.display();
    }
    if (ch == 'S')
    {
        Chess C;
        C.play();
    }
    else
    {
        ifstream rdr("Save.txt");
        Chess C(rdr);
        C.play();
    }
    return 0;
}
