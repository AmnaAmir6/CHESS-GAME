#pragma once
#include"HelpingFunction.h"

class Board;

class Piece
{
protected:
	int ri, ci;
	char sym;
	Color C;
	Board* B;
	bool isKing;
	bool isFirst;
public:
	Piece(int _r, int _c, Color _C, Board* _B, bool _isKing, char c='-', bool isFirst = true);
	void Move(int _r, int _c);
	virtual void Draw(sf::RenderWindow& window) = 0;
	virtual bool isLegalMove(int sri, int sci, int dri, int dci) = 0;
	bool IsKing();
	bool IsFirst();
	void setIsFirst(bool First);
	Color getColor();
	char getSym();
	int getRowIndex();
	int getColIndex();
	bool isHorizontal(int sri, int dri);
	bool isVertical(int sci, int dci);
	bool isDiagnol(int sri, int sci, int dri, int dci);
	bool isHorizonPathClear(Board* _B, int sri, int sci, int dri, int dci);
	bool isVerticalPathClear(Board* _B, int sri, int sci, int dri, int dci);
	bool isDiagonalPathClearL2R(Board* _B, int sri, int sci, int dri, int dci);
	bool isDiagonalPathClearR2L(Board* _B, int sri, int sci, int dri, int dci);
	bool isL2RDiagnol(int sri, int sci, int dri, int dci);
};

