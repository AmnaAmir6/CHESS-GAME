#include <SFML/Graphics.hpp>
#include"Chess.h"
#include"Player.h"
#include"Board.h"
#include"Piece.h"
#include"Queen.h"
#include"Rook.h"
#include"Bishop.h"
#include"Knight.h"
#include<time.h>
#include<fstream>
#include<iostream>
#include<iomanip>
using namespace std;
#include<vector>
#include<string>


Chess::Chess()
{
    Ps[0] = new Player("Amna", BLACK);
    Ps[1] = new Player("Mariam", WHITE);
    ifstream rdr("Read.txt");
    B = new Board(rdr, Turn);
    U.push_back(*B);
    srand(time(0));
    Time[0] = 60;
    Time[1] = 60;
    Turn = rand() % 2;
    Ts.push_back(Turn);
    window.create(sf::VideoMode(1000, 600), "Chess Game");
    font.loadFromFile("arial.ttf");
    sri = 0, sci = 0;
    dri = 0, dci = 0;
}

Chess::Chess(ifstream& rdr)
{
    Ps[0] = new Player("Amna", BLACK);
    Ps[1] = new Player("Mariam", WHITE);
    B = new Board(rdr, Turn);
    U.push_back(*B);
    srand(time(0));
    Time[0] = 60;
    Time[1] = 60;
    Ts.push_back(Turn);
    sri = 0, sci = 0;
    dri = 0, dci = 0;
    font.loadFromFile("arial.ttf");
    window.create(sf::VideoMode(1000, 600), "Chess Game");
}

void Chess::displayCheck(sf::RenderWindow& window)
{
    sf::Text text("CHECK", font, 40);
    text.setFillColor(sf::Color::Red);
    text.setOutlineColor(sf::Color::Yellow);
    text.setOutlineThickness(0.2);
    text.setPosition(700, 300);
    window.draw(text);
}

void Chess::turnChange()
{
    Turn = (Turn + 1) % 2;
}

bool Chess::clickedUndo(int r,int c)
{
    if (r == 7 && c == 12 )//&& c >= 17 && c <= 20)
        return true;
    return false;
}

void Chess::Undo()
{
    R.push_back(*B);
    Turn = Ts.back();
   /* Board NB(U.back());
    B = &NB;*/
    for (int r = 0; r < 8; r++)
    {
        for (int c = 0; c < 8; c++)
        {
            B->setPieceAt(U.back().getPieceAt(r, c), r, c);
        }
    }
    if (U.size() > 1)
    {
        U.pop_back();
        Ts.pop_back();
    }
}

bool Chess::clickedRedo(int r,int c)
{
    if (r == 7 && c == 13)// && c >= 17 && c <= 20)
        return true;
    return false;
}

void Chess::Redo()
{
    //Turn = Ts.back();
    /*if (R.size() > 0)
    {
        Board NB(R.back());
        B = &NB;
    }*/
    if (R.size() > 1)
    {
        R.pop_back();
    }
    if (R.size() > 0)
    {
        for (int r = 0; r < 8; r++)
        {
            for (int c = 0; c < 8; c++)
            {
                B->setPieceAt(R.back().getPieceAt(r, c), r, c);
            }
        }
    }
    //if (U.size() > 1)
    //{
    //    U.pop_back();
    //    Ts.pop_back();
    //}
}

void Chess::doPromotion()
{
    int r = 0, c = 0;
    sf::RenderWindow Pwindow(sf::VideoMode(1000, 600), "Game Menu");
    sf::Text newGameText("Promotion", font, 50);
    newGameText.setPosition(400, 50);

    sf::Texture temp;
    if (!temp.loadFromFile("whiteQueen.png")) // img ==> file name for image
    {
        throw("Unable to load img");
    }
    sf::Sprite s1(temp);
    s1.setScale(1.5, 1.5);
    s1.setPosition(250, 300);

    sf::Texture temp2;
    if (!temp2.loadFromFile("whiteKnight.png")) // img ==> file name for image
    {
        throw("Unable to load img");
    }
    sf::Sprite s2(temp2);
    s2.setScale(1.5, 1.5);
    s2.setPosition(400, 300);

    sf::Texture temp3;
    if (!temp3.loadFromFile("whiteRook.png")) // img ==> file name for image
    {
        throw("Unable to load img");
    }
    sf::Sprite s3(temp3);
    s3.setScale(1.5, 1.5);
    s3.setPosition(550, 300);

    sf::Texture temp4;
    if (!temp4.loadFromFile("whiteBishop.png")) // img ==> file name for image
    {
        throw("Unable to load img");
    }
    sf::Sprite s4(temp4);
    s4.setScale(1.5, 1.5);
    s4.setPosition(700, 300);

    while (Pwindow.isOpen())
    {
        sf::Event event;
        while (Pwindow.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                Pwindow.close();
            }
            else if (event.type == sf::Event::MouseButtonPressed)
            {
                if (event.mouseButton.button == sf::Mouse::Left)
                {
                    sf::Vector2i p = sf::Mouse::getPosition(Pwindow);

                    c = p.x / 71;
                    r = p.y / 71;
                    Pwindow.close();
                }
            }
        }
        Pwindow.clear();
        Pwindow.draw(s1);
        Pwindow.draw(s2);
        Pwindow.draw(s3);
        Pwindow.draw(s4);

        Pwindow.draw(newGameText);
        Pwindow.display();
    }
    if (c == 3 || c==4)
    {
        if (B->getPieceAt(dri, dci)->getColor() == WHITE)
        {
            Piece* Pi = new Queen(dri, dci, WHITE, 'q', B);
            B->setPieceAt(Pi, dri, dci);
        }
        else
        {
            Piece* Pi = new Queen(dri, dci, BLACK, 'Q', B);
            B->setPieceAt(Pi, dri, dci);
        }
    }
    else if(c == 6 || c==5)
    {
        if (B->getPieceAt(dri, dci)->getColor() == WHITE)
        {
            Piece* Pi = new Knight(dri, dci, WHITE, 'n', B);
            B->setPieceAt(Pi, dri, dci);
        }
        else
        {
            Piece* Pi = new Knight(dri, dci, BLACK, 'N', B);
            B->setPieceAt(Pi, dri, dci);
        }
    }
    else if (c == 8 || c==7)
    {
        if (B->getPieceAt(dri, dci)->getColor() == WHITE)
        {
            Piece* Pi = new Rook(dri, dci, WHITE, 'r', B);
            B->setPieceAt(Pi, dri, dci);
        }
        else
        {
            Piece* Pi = new Rook(dri, dci, BLACK, 'R', B);
            B->setPieceAt(Pi, dri, dci);
        }
    }
    else if (c == 10 || c==9)
    {
        if (B->getPieceAt(dri, dci)->getColor() == WHITE)
        {
            Piece* Pi = new Bishop(dri, dci, WHITE, 'b', B);
            B->setPieceAt(Pi, dri, dci);
        }
        else
        {
            Piece* Pi = new Bishop(dri, dci, BLACK, 'B', B);
            B->setPieceAt(Pi, dri, dci);
        }
    }
}

void Chess::isPromotable()
{
    if((B->getPieceAt(dri,dci)->getSym() == 'P' && dri == 7) || (B->getPieceAt(dri, dci)->getSym() == 'p' && dri == 0))
    {
        doPromotion();
    }
}

void Chess::gameEnded(Player* P,char ch)
{
    B->displayBoard(window);
    sf::Texture temp;
    temp.loadFromFile("endgame.jpg");
    sf::Sprite s(temp);
    s.setScale(0.75, 0.75);
    s.setPosition(0, 0);
    
    if (ch == 'C')
    {
        sf::Text text1("CHECKMATE", font, 100);
        text1.setFillColor(sf::Color::White);
        text1.setOutlineColor(sf::Color::Red);
        text1.setOutlineThickness(2);
        text1.setPosition(200, 220);
        B->displayBoard(window);
        window.draw(text1);
        window.display();
        Sleep(5000);
        sf::Text text(P->getName() + " Wins ", font, 50);
        text.setFillColor(sf::Color::White);
        text.setOutlineColor(sf::Color::Yellow);
        text.setOutlineThickness(0.5);
        text.setPosition(400, 150);
        window.draw(s);
        window.draw(text);
    }
    else if (ch == 'S')
    {
        sf::Text text1("STALEMATE", font, 100);
        text1.setFillColor(sf::Color::White);
        text1.setOutlineColor(sf::Color::Red);
        text1.setOutlineThickness(2);
        text1.setPosition(200, 220);
        B->displayBoard(window);
        window.draw(text1);
        window.display();
        Sleep(5000);
        sf::Text text("DRAW - Game Ended ", font, 50);
        text.setFillColor(sf::Color::White);
        text.setOutlineColor(sf::Color::Yellow);
        text.setOutlineThickness(0.5);
        text.setPosition(400, 150);
        window.draw(s);
        window.draw(text);
    }
    else if (ch == 'T')
    {
        sf::Text text1("TIME'S UP", font, 100);
        text1.setFillColor(sf::Color::White);
        text1.setOutlineColor(sf::Color::Red);
        text1.setOutlineThickness(2);
        text1.setPosition(200, 220);
        window.draw(text1);
        window.display();
        Sleep(5000);
        sf::Text text(P->getName() + " Wins ", font, 50);
        text.setFillColor(sf::Color::White);
        text.setOutlineColor(sf::Color::Yellow);
        text.setOutlineThickness(0.5);
        text.setPosition(400, 150);
        window.draw(s);
        window.draw(text);
    }
    window.display();
    Sleep(5000);
    window.close();
}

void Chess::displayTime(Player* P, sf::RenderWindow& window, int& t)
{
    sf::Texture temp1;
    temp1.loadFromFile("timer.png");
    sf::Sprite s1(temp1);
    s1.setScale(0.4, 0.4);
    s1.setPosition(700, 0);
    window.draw(s1);
    sf::RectangleShape square1;
    square1.setSize(sf::Vector2f(81, 81));
    square1.setFillColor(sf::Color::Black); 
    square1.setPosition(710, 107);
    window.draw(square1);
    sf::RectangleShape square2;
    square2.setSize(sf::Vector2f(81, 81));
    square2.setFillColor(sf::Color::Black);
    square2.setPosition(815, 107);
    window.draw(square2);
    if (t % 10 == 0)
    {
        Time[Turn] -= 1;
        t = 0;
    }
    sf::Text T1(to_string(Time[0]), font, 35);
    T1.setPosition(730,115);
    sf::Text T2(to_string(Time[1]), font, 35);
    T2.setPosition(834, 115);
    sf::Text Player1(Ps[0]->getName(), font, 20);
    Player1.setFillColor(sf::Color(234, 45, 100));
    Player1.setPosition(725, 155);

    sf::Text Player2(Ps[1]->getName(), font, 20);
    Player2.setFillColor(sf::Color(234, 45, 100));
    Player2.setPosition(828, 155);
    if (Turn == 0)
    {
        T1.setFillColor(sf::Color::Red);
        T2.setFillColor(sf::Color::White);
        Player1.setFillColor(sf::Color(234, 45, 100));
        Player2.setFillColor(sf::Color::White);
        square1.setFillColor(sf::Color(35,0,0));
        window.draw(square1);
    }
    else
    {
        T2.setFillColor(sf::Color::Red);
        T1.setFillColor(sf::Color::White);
        Player2.setFillColor(sf::Color(234, 45, 100));
        Player1.setFillColor(sf::Color::White);
        square2.setFillColor(sf::Color(35, 0, 0));
        window.draw(square2);
    }
    window.draw(T2);
    window.draw(T1);

    window.draw(Player1);
    window.draw(Player2);
}

void Chess::play()
{
    int c, r, t = 0;
    bool selected = false;
    bool check = false;
    bool moved = false;
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
            else if(event.type == sf::Event::MouseButtonPressed)
            {
                if (event.mouseButton.button == sf::Mouse::Left) 
                {
                    sf::Vector2i p = sf::Mouse::getPosition(window);

                    c = p.x/71;
                    r = p.y/71;
                    if (r >= 0 && r < 8 && c >= 0 && c < 8)
                    {
                        if (!selected)
                        {
                            sri = r, sci = c;
                            if (!B->validSc(Ps[Turn], sri, sci))
                                selected = false;
                            else
                                selected = true;
                        }
                        else
                        {
                            dri = r, dci = c;
                            if (B->validDc(Ps[Turn], dri, dci) || B->Castling(sri, sci, dri, dci, Turn, Ps))
                            {
                                if (B->isValidMove(sri, sci, dri, dci) || B->Castling(sri, sci, dri, dci, Turn, Ps))
                                {
                                    if (!B->SelfCheck(sri, sci, dri, dci, Turn, Ps) || B->Castling(sri, sci, dri, dci, Turn, Ps))
                                    {
                                        if (B->Castling(sri, sci, dri, dci, Turn, Ps))
                                            B->doCastling(sri, sci, dri, dci);
                                        else
                                            B->Move(sri, sci, dri, dci);
                                        moved = true;
                                        selected = false;
                                    }
                                }
                                selected = false;
                            }
                            if (moved)
                            {
                                isPromotable();
                                if (B->CheckMate(Ps, Turn))
                                {
                                    gameEnded(Ps[Turn], 'C');
                                }
                                if (B->StaleMate(Turn, Ps))
                                {
                                    gameEnded(Ps[Turn], 'S');
                                }
                                check = false;
                                if (B->Check(Ps, Turn))
                                    check = true;

                                B->saveBoard("Save.txt", Turn);
                                U.push_back(*B);
                                Ts.push_back(Turn);
                                turnChange();
                                moved = false;
                            }
                        }
                    }
                    else if (clickedUndo(r,c))
                    {
                        Undo();
                    }
                    else if (clickedRedo(r,c))
                    {
                        Redo();
                    }
                }
            }       
        }
        window.clear();
        if (selected)
        {
            B->ComputeHighlight(Ps, sri, sci, Turn);
            B->Highlight();
        }
        else
        {
            B->UnHighlight();
        }
        if (check)
        {
            displayCheck(window);
        }
        t++;
        displayTime(Ps[Turn], window,t);
        B->displayBoard(window);
        if (Time[Turn] <= 0)
        {
            turnChange();
            gameEnded(Ps[Turn], 'T');
        }
    }
}