#include "Cell.h"
#include"Piece.h"
#include <SFML/Graphics.hpp>


Cell::Cell(int _r, int _c, int _clr)
{
	this->ri = _r;
	this->ci = _c;
	this->clr = _clr;
	square.setSize(sf::Vector2f(71, 71));
	square.setFillColor(sf::Color(clr, clr, clr));
	square.setPosition(ri, ci);
	square.setOutlineColor(sf::Color::Black);
	square.setOutlineThickness(0.5);
}
void Cell::drawCell(sf::RenderWindow& window)
{
	window.draw(square);
}

void Cell::highlightCell(Piece* P)
{
	square.setFillColor(sf::Color(255 * 0.8, 0.0, 255 * 0.8));
	if (P != nullptr)
	{
		square.setFillColor(sf::Color(200,0,0));
	}
	else
	{
		square.setFillColor(sf::Color(0,200,0));
	}
}

void Cell::unHighlightCell()
{
	square.setFillColor(sf::Color(clr, clr, clr));
}