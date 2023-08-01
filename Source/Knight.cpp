#include "Knight.h"
#include<iostream>
#include"HelpingFunction.h"
using namespace std;

Knight::Knight(int _r, int _c, Color _C,char ch, Board* _B) :Piece(_r, _c, _C, _B, false, ch)
{
}

void Knight::Draw(sf::RenderWindow& window)
{
    sf::Texture temp;
    if (C == WHITE)
    {
        if (!temp.loadFromFile("whiteKnight.png")) // img ==> file name for image
        {
            throw("Unable to load img");
        }
    }
    else
    {
        if (!temp.loadFromFile("blackKnight.png")) // img ==> file name for image
        {
            throw("Unable to load img");
        }
    }
    sf::Sprite s(temp);
    s.setScale(1.5, 1.5); // (width and heigth of image to be printed)

    s.setPosition(ci * 71, ri * 71); // position of image
    window.draw(s);
}

bool Knight::isLegalMove(int sri, int sci, int dri, int dci)
{
    return (abs(sri - dri) == 2 && abs(sci - dci) == 1) || (abs(sri - dri) == 1 && abs(sci - dci) == 2);
}