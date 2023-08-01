#include "Bishop.h"
#include"HelpingFunction.h"
#include<iostream>
using namespace std;

Bishop::Bishop(int _r, int _c, Color _C,char ch, Board* _B) :Piece(_r, _c, _C, _B, false, ch)
{
}

void Bishop::Draw(sf::RenderWindow& window)
{
    sf::Texture temp;
    if (C == WHITE)
    {
        if (!temp.loadFromFile("whiteBishop.png")) // img ==> file name for image
        {
            throw("Unable to load img");
        }
    }
    else
    {
        if (!temp.loadFromFile("blackBishop.png")) // img ==> file name for image
        {
            throw("Unable to load img");
        }
    }
    sf::Sprite s(temp);
    s.setScale(1.5, 1.5); // (width and heigth of image to be printed)

    s.setPosition(ci * 71, ri * 71); // position of image
    window.draw(s);
}

bool Bishop::isLegalMove(int sri, int sci, int dri, int dci)
{
    if (isDiagnol(sri, sci, dri, dci))
    {
        if (isL2RDiagnol(sri, sci, dri, dci))
            return isDiagonalPathClearL2R(B, sri, sci, dri, dci);
        else
            return isDiagonalPathClearR2L(B, sri, sci, dri, dci);
    }
    return false;
}