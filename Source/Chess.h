#pragma once
#include"Board.h"
#include<vector>
#include<iostream>
using namespace std;

class Board;
class Player;

class Chess
{
private:
	int sri, sci, dri, dci;
	int Turn;
	Player* Ps[2];
	Board* B;
	//Board* TB;
	//bool** PM;
	vector<Board> U;
	vector<Board> R;
	int Time[2];
	vector<int>Ts;
	sf::RenderWindow window;
	sf::Font font;
	//char*** CB;
public:
	Chess();
	Chess(ifstream& rdr);
	void play();
	void displayCheck(sf::RenderWindow& window);
	void turnChange();
	bool clickedUndo(int r, int c);
	void isPromotable();
	void doPromotion();
	void Undo();
	bool clickedRedo(int r, int c);
	void Redo();
	void displayTime(Player* P, sf::RenderWindow& window, int& t);
	void TimeBaseWin();
	void gameEnded(Player* P,char ch);
};


