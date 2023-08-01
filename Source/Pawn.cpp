#include "Pawn.h"
#include "HelpingFunction.h"
#include"Board.h"
#include<iostream>
using namespace std;


Pawn::Pawn(int _r, int _c, Color _C,char ch, Board* _B) :Piece(_r, _c, _C, _B, false, ch)
{
	isFirst = true;
	isPromoted = false;
}

void Pawn::Draw(sf::RenderWindow& window)
{
	sf::Texture temp;
	if (C == WHITE)
	{
		if (!temp.loadFromFile("whitePawn.png")) // img ==> file name for image  
		{
			throw("Unable to load img");
		}
	}
	else
	{
		if (!temp.loadFromFile("blackPawn.png")) // img ==> file name for image  
		{
			throw("Unable to load img");
		}
	}
	sf::Sprite s(temp);
	s.setScale(1.5, 1.5);
	
	s.setPosition(ci * 71, ri * 71); // position of image
	window.draw(s);
}

void Pawn::changeIsFirst(bool _isFirst)
{
	this->isFirst = _isFirst;
}

bool Pawn::isLegalMove(int sri, int sci, int dri, int dci)
{
	isFirst = true;
	if (C == BLACK && sri > 1)
		isFirst = false;
	else if (C == WHITE && sri < 6)
		isFirst = false;
	if (C == BLACK && sri == 7)
	{
		isPromoted = true;
	}
	else if (C == WHITE && sri == 0)
	{
		isPromoted = true;
	}
	if (isFirst)
	{
		if (C == BLACK)
		{
			if (isVertical(sci, dci) && (sri - dri == -2 || sri - dri == -1) && (isVerticalPathClear(B, sri, sci, dri, dci)) && (B->getPieceAt(dri, dci) == nullptr))
				return true;
			else if (isDiagnol(sri, sci, dri, dci) && (sri - dri == -1) && abs(sci - dci) == 1 && (B->getPieceAt(dri, dci) != nullptr))
				return true;
			return false;
		}
		else
		{
			if (isVertical(sci, dci) && (sri - dri == 2 || sri - dri == 1) && (isVerticalPathClear(B, sri, sci, dri, dci)) && (B->getPieceAt(dri, dci) == nullptr))
				return true;
			else if (isDiagnol(sri, sci, dri, dci) && (sri - dri == 1) && abs(sci - dci) == 1 && (B->getPieceAt(dri, dci) != nullptr))
				return true;
			return false;
		}
	}
	else
	{
		if (C == BLACK)
		{
			if (isVertical(sci, dci) && sri - dri == -1 && (B->getPieceAt(dri, dci) == nullptr))
				return true;
			else if (isDiagnol(sri, sci, dri, dci) && (sri - dri == -1) && abs(sci - dci) == 1 && (B->getPieceAt(dri, dci) != nullptr))
				return true;
			return false;
		}

		else
		{
			if (isVertical(sci, dci) && sri - dri == 1 && (B->getPieceAt(dri, dci) == nullptr))
				return true;
			else if (isDiagnol(sri, sci, dri, dci) && (sri - dri == 1) && abs(sci - dci) == 1 && (B->getPieceAt(dri, dci) != nullptr))
				return true;
			return false;
		}
	}
}



