#pragma once
#include"Piece.h"

class Knight :public Piece
{
public:
	Knight(int _r, int _c, Color _C,char ch, Board* _B);
	virtual void Draw(sf::RenderWindow& window);
	virtual bool isLegalMove(int sri, int sci, int dri, int dci);
};

