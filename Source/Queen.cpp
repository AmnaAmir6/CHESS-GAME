#include "Queen.h"
#include"Piece.h"
#include"Rook.h"
#include"Bishop.h"
#include"King.h"
#include<iostream>
#include"HelpingFunction.h"
using namespace std;

Queen::Queen(int _r, int _c, Color _C, char ch, Board* _B) :Piece(_r, _c, _C, _B,false ,ch )
{
}

void Queen::Draw(sf::RenderWindow& window)
{
    sf::Texture temp;
    if (C == WHITE)
    {
        if (!temp.loadFromFile("whiteQueen.png")) // img ==> file name for image
        {
            throw("Unable to load img");
        }
    }
    else
    {
        if (!temp.loadFromFile("blackQueen.png")) // img ==> file name for image
        {
            throw("Unable to load img");
        }
    }
    sf::Sprite s(temp);
    s.setScale(1.5, 1.5); // (width and heigth of image to be printed)

    s.setPosition(ci * 71, ri * 71); // position of image
    window.draw(s);
}

bool Queen::isLegalMove(int sri, int sci, int dri, int dci)
{
    Piece* R = new Rook(sri, sci, WHITE, 'R', B);
    Piece* K = new King(sri, sci, WHITE,'K', B);
    Piece* B_ = new Bishop(sri, sci, WHITE,'B', B);
    return R->isLegalMove(sri, sci, dri, dci) || K->isLegalMove(sri, sci, dri, dci) || B_->isLegalMove(sri, sci, dri, dci);
}
