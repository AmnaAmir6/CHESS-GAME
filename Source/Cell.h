#pragma once
#include <SFML/Graphics.hpp>
using namespace std;

class Piece;
class Cell
{
	int ri;
	int ci;
	int clr;
	sf::RectangleShape square;
public:
	Cell(int _r,int _c, int clr);
	void drawCell(sf::RenderWindow& window);
	void highlightCell(Piece* P);
	void unHighlightCell();
};

