#include "Rook.h"
#include<iostream>
#include"HelpingFunction.h"
using namespace std;

Rook::Rook(int _r, int _c, Color _C,char ch, Board* _B) :Piece(_r, _c, _C, _B,false, ch )
{
}

void Rook::Draw(sf::RenderWindow& window)
{
    sf::Texture temp;
    if (C == WHITE)
    {
        if (!temp.loadFromFile("whiteRook.png")) // img ==> file name for image
        {
            throw("Unable to load img");
        }
    }
    else
    {
        if (!temp.loadFromFile("blackRook.png")) // img ==> file name for image
        {
            throw("Unable to load img");
        }
    }
    sf::Sprite s(temp);
    s.setScale(1.5, 1.5); // (width and heigth of image to be printed)

    s.setPosition(ci * 71, ri * 71); // position of image
    window.draw(s);
}

bool Rook::isLegalMove(int sri, int sci, int dri, int dci)
{
    if (isVertical(sci, dci))
        return isVerticalPathClear(B, sri, sci, dri, dci);
    else if (isHorizontal(sri, dri))
        return isHorizonPathClear(B, sri, sci, dri, dci);
    else
        return false;
}
