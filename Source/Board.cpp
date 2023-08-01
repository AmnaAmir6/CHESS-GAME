#include <SFML/Graphics.hpp>
#include"Cell.h"
#include "Board.h"
#include"HelpingFunction.h"
#include"Piece.h"
#include"Pawn.h"
#include"King.h"
#include"Queen.h"
#include"Rook.h"
#include"Bishop.h"
#include"Knight.h"
#include"Player.h"
#include<iostream>
#include<fstream>
#include<iomanip>
using namespace std;

Board::Board()
{
	Ps = new Piece * *[8];
	for (int r = 0; r < 8; r++)
	{
		Ps[r] = new Piece * [8];
		for (int c = 0; c < 8; c++)
		{
			if (r == 6)
			{
				Ps[r][c] = new Pawn(r, c, WHITE,'p', this);
			}
			else if (r == 1)
			{
				Ps[r][c] = new Pawn(r, c, BLACK,'P', this);
			}
			else if (r == 7 && (c == 2 || c == 5))
			{
				Ps[r][c] = new Bishop(r, c, WHITE,'b', this);
			}
			else if (r == 0 && (c == 2 || c == 5))
			{
				Ps[r][c] = new Bishop(r, c, BLACK,'B', this);
			}
			
			else if (r == 7 && (c == 1 || c == 6))
			{
				Ps[r][c] = new Knight(r, c, WHITE,'n', this);
			}
			else if (r == 0 && (c == 1 || c == 6))
			{
				Ps[r][c] = new Knight(r, c, BLACK,'N', this);
			}
			else if (r == 7 && (c == 0 || c == 7))
			{
				Ps[r][c] = new Rook(r, c, WHITE,'r', this);
			}
			else if (r == 0 && (c == 0 || c == 7))
			{
				Ps[r][c] = new Rook(r, c, BLACK,'R', this);
			}
			else if (r == 7 && c == 4)
			{
				Ps[r][c] = new King(r, c, WHITE,'k', this);
			}
			else if (r == 0 && c == 4)
			{
				Ps[r][c] = new King(r, c, BLACK,'K', this);
			}
			else if (r == 7 && c == 3)
			{
				Ps[r][c] = new Queen(r, c, WHITE,'q', this);
			}
			else if (r == 0 && c == 3)
			{
				Ps[r][c] = new Queen(r, c, BLACK,'Q', this);
			}
			else
			{
				Ps[r][c] = nullptr;
			}
		}
	}
	Cs = new Cell * *[8];
	for (int r = 0; r < 8; r++)
	{
		Cs[r] = new Cell * [8];
		for (int c = 0; c < 8; c++)
		{
			if ((r + c) % 2 == 0)
				Cs[r][c] = new Cell(r * 71, c * 71, 75);
			else
				Cs[r][c] = new Cell(r * 71, c * 71, 45);
		}
	}
	PM = new bool* [8];
	for (int r = 0; r < 8; r++)
	{
		PM[r] = new bool[8];
	}
}

Board::Board(ifstream& rdr, int& turn)
{
	Ps = new Piece * *[8];
	char ch;
	for (int r = 0; r < 8; r++)
	{
		Ps[r] = new Piece * [8];
		for (int c = 0; c < 8; c++)
		{
			rdr >> ch;
			switch (ch)
			{
			case 'p':
				Ps[r][c] = new Pawn(r, c, WHITE,'p', this);
				break;
			case 'P':
				Ps[r][c] = new Pawn(r, c, BLACK,'P', this);
				break;
			case 'k':
				Ps[r][c] = new King(r, c, WHITE,'k', this);
				break;
			case 'K':
				Ps[r][c] = new King(r, c, BLACK,'K', this);
				break;
			case 'b':
				Ps[r][c] = new Bishop(r, c, WHITE,'b', this);
				break;
			case 'B':
				Ps[r][c] = new Bishop(r, c, BLACK,'B', this);
				break;
			case 'n':
				Ps[r][c] = new Knight(r, c, WHITE,'n', this);
				break;
			case 'N':
				Ps[r][c] = new Knight(r, c, BLACK,'N', this);
				break;
			case 'q':
				Ps[r][c] = new Queen(r, c, WHITE,'q', this);
				break;
			case 'Q':
				Ps[r][c] = new Queen(r, c, BLACK,'Q', this);
				break;
			case 'r':
				Ps[r][c] = new Rook(r, c, WHITE,'r', this);
				break;
			case 'R':
				Ps[r][c] = new Rook(r, c, BLACK,'R', this);
				break;
			case '-':
				Ps[r][c] = nullptr;
				break;
			}
		}
	}
	rdr >> turn;
	Cs = new Cell * *[8];
	for (int r = 0; r < 8; r++)
	{
		Cs[r] = new Cell * [8];
		for (int c = 0; c < 8; c++)
		{
			if ((r + c) % 2 == 0)
				Cs[r][c] = new Cell(r * 71, c * 71, 75);
			else
				Cs[r][c] = new Cell(r * 71, c * 71, 45);
		}
	}
	PM = new bool* [8];
	for (int r = 0; r < 8; r++)
	{
		PM[r] = new bool[8];
		for (int c = 0; c < 8; c++)
		{
			PM[r][c] = true;
		}
	}
}

Board::Board(const Board& _B)
{
	Ps = new Piece * *[8];
	char ch;
	for (int r = 0; r < 8; r++)
	{
		Ps[r] = new Piece * [8];
		for (int c = 0; c < 8; c++)
		{
			if (_B.Ps[r][c] == nullptr)
				ch = '-';
			else
				ch = _B.Ps[r][c]->getSym();
			switch (ch)
			{
			case 'p':
				Ps[r][c] = new Pawn(r, c, WHITE, 'p', this);
				break;
			case 'P':
				Ps[r][c] = new Pawn(r, c, BLACK, 'P', this);
				break;
			case 'k':
				Ps[r][c] = new King(r, c, WHITE, 'k', this);
				break;
			case 'K':
				Ps[r][c] = new King(r, c, BLACK, 'K', this);
				break;
			case 'b':
				Ps[r][c] = new Bishop(r, c, WHITE, 'b', this);
				break;
			case 'B':
				Ps[r][c] = new Bishop(r, c, BLACK, 'B', this);
				break;
			case 'n':
				Ps[r][c] = new Knight(r, c, WHITE, 'n', this);
				break;
			case 'N':
				Ps[r][c] = new Knight(r, c, BLACK, 'N', this);
				break;
			case 'q':
				Ps[r][c] = new Queen(r, c, WHITE, 'q', this);
				break;
			case 'Q':
				Ps[r][c] = new Queen(r, c, BLACK, 'Q', this);
				break;
			case 'r':
				Ps[r][c] = new Rook(r, c, WHITE, 'r', this);
				break;
			case 'R':
				Ps[r][c] = new Rook(r, c, BLACK, 'R', this);
				break;
			case '-':
				Ps[r][c] = nullptr;
				break;
			}
		}
	}
	Cs = new Cell * *[8];
	for (int r = 0; r < 8; r++)
	{
		Cs[r] = new Cell * [8];
		for (int c = 0; c < 8; c++)
		{
			if ((r + c) % 2 == 0)
				Cs[r][c] = new Cell(r * 71, c * 71, 75);
			else
				Cs[r][c] = new Cell(r * 71, c * 71, 45);
		}
	}
	PM = new bool* [8];
	for (int r = 0; r < 8; r++)
	{
		PM[r] = new bool[8];
		for (int c = 0; c < 8; c++)
		{
			PM[r][c] = true;
		}
	}
	/*C = new char* [8];
	for (int r = 0; r < 8; r++)
	{
		C[r] = new char[8];
		for (int c = 0; c < 8; c++)
		{
			C[r][c] = _B.C[r][c];
		}
	}
	char ch;
	Ps = new Piece * *[8];
	for (int r = 0; r < 8; r++)
	{
		Ps[r] = new Piece * [8];
		for (int c = 0; c < 8; c++)
		{
			ch = C[r][c];
			switch (ch)
			{
			case 'P':
				Ps[r][c] = new Pawn(r, c, WHITE, this);
				break;
			case 'p':
				Ps[r][c] = new Pawn(r, c, BLACK, this);
				break;
			case 'K':
				Ps[r][c] = new King(r, c, WHITE, this);
				break;
			case 'k':
				Ps[r][c] = new King(r, c, BLACK, this);
				break;
			case 'B':
				Ps[r][c] = new Bishop(r, c, WHITE, this);
				break;
			case 'b':
				Ps[r][c] = new Bishop(r, c, BLACK, this);
				break;
			case 'N':
				Ps[r][c] = new Knight(r, c, WHITE, this);
				break;
			case 'n':
				Ps[r][c] = new Knight(r, c, BLACK, this);
				break;
			case 'Q':
				Ps[r][c] = new Queen(r, c, WHITE, this);
				break;
			case 'q':
				Ps[r][c] = new Queen(r, c, BLACK, this);
				break;
			case 'R':
				Ps[r][c] = new Rook(r, c, WHITE, this);
				break;
			case 'r':
				Ps[r][c] = new Rook(r, c, BLACK, this);
				break;
			case '-':
				Ps[r][c] = nullptr;
				break;
			}
		}
	}*/
}

Board Board::operator=(const Board& _B)
{
	if (this == &_B)
		return *this;
	char ch;
	for (int r = 0; r < 8; r++)
	{
		for (int c = 0; c < 8; c++)
		{
			if (_B.Ps[r][c] == nullptr)
				ch = '-';
			else
				ch = _B.Ps[r][c]->getSym();
			switch (ch)
			{
			case 'p':
				_B.Ps[r][c] = new Pawn(r, c, WHITE, 'p', this);
				break;
			case 'P':
				_B.Ps[r][c] = new Pawn(r, c, BLACK, 'P', this);
				break;
			case 'k':
				_B.Ps[r][c] = new King(r, c, WHITE, 'k', this);
				break;
			case 'K':
				_B.Ps[r][c] = new King(r, c, BLACK, 'K', this);
				break;
			case 'b':
				_B.Ps[r][c] = new Bishop(r, c, WHITE, 'b', this);
				break;
			case 'B':
				_B.Ps[r][c] = new Bishop(r, c, BLACK, 'B', this);
				break;
			case 'n':
				_B.Ps[r][c] = new Knight(r, c, WHITE, 'n', this);
				break;
			case 'N':
				_B.Ps[r][c] = new Knight(r, c, BLACK, 'N', this);
				break;
			case 'q':
				_B.Ps[r][c] = new Queen(r, c, WHITE, 'q', this);
				break;
			case 'Q':
				_B.Ps[r][c] = new Queen(r, c, BLACK, 'Q', this);
				break;
			case 'r':
				_B.Ps[r][c] = new Rook(r, c, WHITE, 'r', this);
				break;
			case 'R':
				_B.Ps[r][c] = new Rook(r, c, BLACK, 'R', this);
				break;
			case '-':
				_B.Ps[r][c] = nullptr;
				break;
			}
		}
	}
	return *this;
}

void Board::DrawArrows(sf::RenderWindow& window)
{
	sf::Texture temp1;
	temp1.loadFromFile("undo.png");
	sf::Sprite s1(temp1);
	s1.setScale(0.1, 0.1);
	s1.setPosition(850, 520);
	window.draw(s1);
	sf::Texture temp2;
	temp2.loadFromFile("redo.png");
	sf::Sprite s2(temp2);
	s2.setScale(0.1, 0.1);
	s2.setPosition(920, 520);
	window.draw(s2);
}

void Board::displayBoard(sf::RenderWindow& window)
{
	int Brows = 8, Bcols = 8;
	int color;
	for (int ri = 0; ri < 8; ri++)
	{
		for (int ci = 0; ci < 8; ci++)
		{
			Cs[ci][ri]->drawCell(window);
			if (Ps[ri][ci] != nullptr)
			{
				Ps[ri][ci]->Draw(window);
			}
		}
	}
	DrawArrows(window);
	window.display();
	
}

Piece* Board::getPieceAt(int r, int c)
{
	return Ps[r][c];
}

bool Board::validSc(Player* P, int r, int c)
{
	if (r < 0 || r >= 8 || c < 0 || c >= 8)
		return false;
	if (Ps[r][c] != nullptr)
	{
		return Ps[r][c]->getColor() == P->getColor();
	}
	return false;
}

bool Board::validDc(Player* P, int r, int c)
{
	if (r < 0 || r >= 8 || c < 0 || c >= 8)
		return false;
	//Piece* p = B->getPieceAt(r, c);
	if (Ps[r][c] == nullptr)
		return true;
	return Ps[r][c]->getColor() != P->getColor();
}

bool Board::isValidMove(int sri, int sci, int dri, int dci)
{
    if (Ps[sri][sci]->isLegalMove(sri, sci, dri, dci))
        return true;
    else
        return false;
}

void Board::FindKing(int& ri, int& ci, Player* P)
{
    for (int r = 0; r < 8; r++)
    {
        for (int c = 0; c < 8; c++)
        {
            if (Ps[r][c] != nullptr)
            {
                if (Ps[r][c]->IsKing() && Ps[r][c]->getColor() == P->getColor())
                {
                    ri = r, ci = c;
                    break;
                }
            }
        }
    }
}

void Board::TChange(int &Turn)
{
	Turn = (Turn + 1) % 2;
}

bool Board::Check(Player* P[], int turn)
{
    TChange(turn);
    int kri, kci;
    FindKing(kri, kci,P[turn]);
    TChange(turn);
    for (int ri = 0; ri < 8; ri++)
    {
        for (int ci = 0; ci < 8; ci++)
        {
            if (Ps[ri][ci] != nullptr)
            {
                if (validSc(P[turn], ri, ci) && isValidMove(ri, ci, kri, kci))
                    return true;
            }
        }
    }
    return false;
}

bool Board::SelfCheck(int sri, int sci, int dri, int dci,int turn,Player* P[])
{
	Piece* tempP = Ps[dri][dci];// B->getPieceAt(_dri, _dci);
	Ps[dri][dci] = Ps[sri][sci];
   // B->setPieceAt(B->getPieceAt(_sri, _sci), _dri, _dci);
	Ps[sri][sci] = nullptr;
    //B->setPieceAt(nullptr, _sri, _sci);
    TChange(turn);
    bool SelfCheck = Check(P,turn);
	TChange(turn);
	Ps[sri][sci] = Ps[dri][dci];
	Ps[dri][dci] = tempP;
    //B->setPieceAt(B->getPieceAt(_dri, _dci), _sri, _sci);
    //B->setPieceAt(tempP, _dri, _dci);
    return SelfCheck;
}

bool Board::SelfCheck(int turn,Player*P[])
{
    TChange(turn);
    bool SelfCheck = Check(P,turn);
	TChange(turn);
    return SelfCheck;
}

bool Board::CheckMate(Player* P[], int turn)
{
    bool CM = true;
    TChange(turn);
    int kri, kci;
    FindKing(kri, kci,P[turn]);
    for (int ri = 0; ri < 8; ri++)
    {
        for (int ci = 0; ci < 8; ci++)
        {
            if (validDc(P[turn], ri, ci) && isValidMove(kri, kci, ri, ci) && !SelfCheck(kri, kci, ri, ci,turn,P))
                CM = false;
            if (ri == kri && ci == kci)
            {
                if (!SelfCheck(turn,P))
                    CM = false;
            }
        }
    }
    TChange(turn);
    return CM;
}

bool Board::StaleMate(int turn,Player*P[])
{
    bool CM = false;
    TChange(turn);
    for (int ri = 0; ri < 8; ri++)
    {
        for (int ci = 0; ci < 8; ci++)
        {
            if (validSc(P[turn], ri, ci))
            {
                for (int r = 0; r < 8; r++)
                {
                    for (int c = 0; c < 8; c++)
                    {
                        if (ri == r && ci == c)
                            continue;
                        else
                        {
                            if (isValidMove(ri, ci, r, c) && !SelfCheck(ri, ci, r, c,turn,P))
                                CM = true;
                        }

                    }
                }
            }
            if (CM)
            {
                TChange(turn);
                return false;
            }
        }
    }
    TChange(turn);
    if (!CM)
        return true;
    return false;
    //return CM;
}

void Board::ComputeHighlight(Player* P[], int sri, int sci, int turn)
{
	for (int ri = 0; ri < 8; ri++)
	{
		for (int ci = 0; ci < 8; ci++)
		{
			if (validDc(P[turn], ri, ci) && isValidMove(sri, sci, ri, ci) && !SelfCheck(sri, sci, ri, ci, turn,P))
				PM[ri][ci] = true;
			else
				PM[ri][ci] = false;
			// DrawBorder(sri * 8, sci * 8, 8, 8, 4);
		}
	}
}

void Board::Highlight()
{
    for (int ri = 0; ri < 8; ri++)
    {
        for (int ci = 0; ci < 8; ci++)
        {
			if (PM[ri][ci] == true)
			{
				Cs[ci][ri]->highlightCell(Ps[ri][ci]);
			}
        }
    }
}

void Board::UnHighlight()
{
    for (int ri = 0; ri < 8; ri++)
    {
        for (int ci = 0; ci < 8; ci++)
        {
            if (PM[ri][ci] == true)
            {
				Cs[ci][ri]->unHighlightCell();
                /*int sr = ri * 8;
                int sc = ci * 8;
                if ((ri + ci) % 2 == 0)
                {
                    DrawBorder(sr, sc, 8, 8, 7);
                }
                else
                    DrawBorder(sr, sc, 8, 8, 8);*/
            }
        }
    }
}

void Board::setPieceAt(Piece* P, int r, int c)
{
	Ps[r][c] = P;
}

void Board::Move(int sri, int sci, int dri, int dci)
{
	Ps[sri][sci]->setIsFirst(false);
	Ps[sri][sci]->Move(dri, dci);
	Ps[dri][dci] = Ps[sri][sci];
	Ps[sri][sci] = nullptr;
	/*C[dri][dci] = C[sri][sci];
	C[sri][sci] = '-';*/
}

void Board::saveBoard(string fileName, int turn)
{
	ofstream wtr(fileName);
	for (int r = 0; r < 8; r++)
	{
		for (int c = 0; c < 8; c++)
		{
			if (Ps[r][c] == nullptr)
				wtr << "-";
			else
				wtr << Ps[r][c]->getSym();
		}
		wtr << endl;
	}
	wtr << turn << endl;
}

bool Board::Castling(int sri,int sci,int dri,int dci, int turn, Player* P[])
{
	if (Ps[sri][sci]->getSym() == 'K')
	{
		if (Ps[sri][sci]->IsFirst())
		{
			if (sri == 0 && sci == 4 && dri == 0)
			{
				if (sci - dci == 2 && Ps[0][0]->getSym() == 'R' && Ps[0][0]->IsFirst() == true)
				{
					if (SelfCheck(sri, sci, dri, dci, turn, P) || SelfCheck(turn, P))
						return false;
					for (int c = sci - 1; c > 0; c--)
					{
						if (Ps[sri][c] != nullptr || SelfCheck(sri, sci, dri, c, turn, P))
							return false;
					}
					return true;
				}
				if (sci - dci == -2 && Ps[0][7]->getSym() == 'R' && Ps[0][7]->IsFirst() == true)
				{
					if (SelfCheck(sri, sci, dri, dci, turn, P) || SelfCheck(turn, P))
						return false;
					for (int c = sci + 1; c < 7; c++)
					{
						if (Ps[sri][c] != nullptr || SelfCheck(sri, sci, dri, c, turn, P))
							return false;
					}
					return true;
				}
				else
					return false;
			}
			else
				return false;
		}
		else
			return false;
	}
	else if (Ps[sri][sci]->getSym() == 'k')
	{
		if (Ps[sri][sci]->IsFirst())
		{
			if (sri == 7 && sci == 4 && dri == 7)
			{
				if (sci - dci == 2 && Ps[7][0]->getSym() == 'r' && Ps[7][0]->IsFirst() == true)
				{
					if (SelfCheck(sri, sci, dri, dci, turn, P) || SelfCheck(turn, P))
						return false;
					for (int c = sci - 1; c > 0; c--)
					{
						if (Ps[sri][c] != nullptr || SelfCheck(sri, sci, dri, c, turn, P))
							return false;
					}
					return true;
				}
				if (sci - dci == -2 && Ps[7][7]->getSym() == 'r' && Ps[7][7]->IsFirst() == true)
				{
					if (SelfCheck(sri, sci, dri, dci, turn, P) || SelfCheck(turn, P))
						return false;
					for (int c = sci + 1; c < 7; c++)
					{
						if (Ps[sri][c] != nullptr || SelfCheck(sri, sci, dri, c, turn, P))
							return false;
					}
					return true;
				}
				else
					return false;
			}
			else
				return false;
		}
		else
			return false;
	}
	else
		return false;
}

void Board::doCastling(int sri, int sci, int dri, int dci)
{
    Move(sri, sci, dri, dci);
	if (sci > dci && sri==0)
	{
		Move(0, 0, dri, dci + 1);
	}
	else if (sci < dci && sri == 0)
	{
		Move(0, 7, dri, dci - 1);
	}
	else if (sci > dci && sri == 7)
	{
		Move(7, 0, dri, dci + 1);
	}
	else if (sci < dci && sri == 7)
	{
		Move(7, 7, dri, dci - 1);
	}
}
