#include "Piece.h"
#include"Board.h"
#include<iostream>
using namespace std;

Piece::Piece(int _r, int _c, Color _C, Board* _B,bool _isKing, char c, bool _isFirst)
{
    this->ri = _r;
    this->ci = _c;
    this->C = _C;
    this->B = _B;
    this->sym = c;
    this->isKing = _isKing;
    this->isFirst = _isFirst;
}

bool Piece::IsFirst()
{
    return isFirst;
}

void Piece::setIsFirst(bool First)
{
    this->isFirst = First;
}

bool Piece::IsKing()
{
    return isKing;
}

void Piece::Move(int _r, int _c)
{
    this->ri = _r;
    this->ci = _c;
}

Color Piece::getColor()
{
    return C;
}

bool Piece::isHorizontal(int sri, int dri)
{
    return dri == sri;
}

bool Piece::isVertical(int sci, int dci)
{
    return dci == sci;
}

bool Piece::isDiagnol(int sri, int sci, int dri, int dci)
{
    int dr = abs(sri - dri);
    int dc = abs(sci - dci);
    return dr == dc;
}

bool Piece::isHorizonPathClear(Board* _B, int sri, int sci, int dri, int dci)
{
    if (sci < dci)
    {
        for (int ci = sci + 1; ci < dci; ci++)
        {
            if (B->getPieceAt(sri, ci) != nullptr)
                return false;
        }
    }
    else
    {
        for (int ci = sci - 1; ci > dci; ci--)
        {
            if (B->getPieceAt(sri, ci) != nullptr)
                return false;
        }
    }
    return true;
}

bool Piece::isVerticalPathClear(Board* _B, int sri, int sci, int dri, int dci)
{
    if (sri < dri)
    {
        for (int ri = sri + 1; ri < dri; ri++)
        {
            if (B->getPieceAt(ri, sci) != nullptr)
                return false;
        }
    }
    else
    {
        for (int ri = sri - 1; ri > dri; ri--)
        {
            if (B->getPieceAt(ri, sci) != nullptr)
                return false;
        }
    }
    return true;
}

bool Piece::isDiagonalPathClearL2R(Board* _B, int sri, int sci, int dri, int dci)
{
    if (sri < dri&& sci < dci)
    {
        for (int ri = sri + 1, ci = sci + 1; ci < dci; ci++, ri++)
        {
            if (B->getPieceAt(ri, ci) != nullptr)
                return false;
        }
    }
    else if (sri > dri && sci > dci)
    {
        for (int ri = sri - 1, ci = sci - 1; ri > dri; ri--, ci--)
        {
            if (B->getPieceAt(ri, ci) != nullptr)
                return false;
        }
    }
    return true;
}

bool Piece::isDiagonalPathClearR2L(Board* _B, int sri, int sci, int dri, int dci)
{
    if (sri < dri && sci > dci)
    {
        for (int ri = sri + 1, ci = sci - 1; ri < dri; ri++, ci--)
        {
            if (B->getPieceAt(ri, ci) != nullptr)
                return false;
        }
    }
    else if (sri > dri && sci < dci)
    {
        for (int ri = sri - 1, ci = sci + 1; ri > dri; ri--, ci++)//ci=sri+1
        {
            if (B->getPieceAt(ri, ci) != nullptr)
                return false;
        }
    }
    return true;
}

bool Piece::isL2RDiagnol(int sri, int sci, int dri, int dci)
{
    int dr = sri - dri;
    int dc = sci - dci;
    if (dr == dc)
        return true;
    return false;
}

int Piece::getRowIndex()
{
    return ri;
}

int Piece::getColIndex()
{
    return ci;
}

char Piece::getSym()
{
    return sym;
}


