#pragma once
#include"Piece.h"

class Pawn :public Piece
{
private:
	bool isFirst;
	bool isPromoted;
public:
	void changeIsFirst(bool _isFirst);
	Pawn(int _r, int _c, Color _C,char ch, Board* _B);
	virtual void Draw(sf::RenderWindow& window);
	virtual bool isLegalMove(int sri, int sci, int dri, int dci);
	bool isPromotablePawn();
};

