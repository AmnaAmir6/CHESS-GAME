#include "King.h"
#include<iostream>
#include"HelpingFunction.h"
using namespace std;

King::King(int _r, int _c, Color _C,char ch, Board* _B) :Piece(_r, _c, _C, _B, true, ch)
{
}

void King::Draw(sf::RenderWindow& window)
{
    sf::Texture temp;
    if (C == WHITE)
    {
        if (!temp.loadFromFile("whiteKing.png")) // img ==> file name for image
        {
            throw("Unable to load img");
        }
    }
    else
    {
        if (!temp.loadFromFile("blackKing.png")) // img ==> file name for image
        {
            throw("Unable to load img");
        }
    }
    sf::Sprite s(temp);
    s.setScale(1.5, 1.5); // (width and heigth of image to be printed)

    s.setPosition(ci * 71, ri * 71); // position of image
    window.draw(s);
}

bool King::isLegalMove(int sri, int sci, int dri, int dci)
{
    if (isHorizontal(sri, dri) && abs(sci - dci) == 1)
        return isHorizonPathClear(B, sri, sci, dri, dci);
    else if (isDiagnol(sri, sci, dri, dci) && abs(sri - dri) == 1 && abs(sci - dci) == 1)
    {
        if (isL2RDiagnol(sri, sci, dri, dci))
            return isDiagonalPathClearL2R(B, sri, sci, dri, dci);
        else
            return isDiagonalPathClearR2L(B, sri, sci, dri, dci);
    }
    else
        return isVertical(sci, dci) && isVerticalPathClear(B, sri, sci, dri, dci) && abs(sri - dri) == 1;
}