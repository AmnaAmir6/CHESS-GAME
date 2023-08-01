#pragma once
#include"Piece.h"

class King :public Piece
{
public:
	King(int _r, int _c, Color _C,char ch, Board* _B);
	virtual void Draw(sf::RenderWindow& window);
	virtual bool isLegalMove(int sri, int sci, int dri, int dci);
};


