#pragma once
#include<fstream>
using namespace std;

class Piece;
class Cell;
class Player;
class Board
{
private:
	Piece*** Ps;
	Cell*** Cs;
	bool** PM;
public:
	Board();
	Board(ifstream& rdr, int& turn);
	Board(const Board& _B);
	Board operator=(const Board& _B);
	void displayBoard(sf::RenderWindow& window);
	Piece* getPieceAt(int r, int c);
	void setPieceAt(Piece* P, int r, int c);
	void Move(int sri, int sci, int dri, int dci);
	void saveBoard(string fileName, int turn);
	bool validSc(Player* P, int r, int c);
	bool validDc(Player* P, int r, int c);
	bool isValidMove(int sri, int sci, int dri, int dci);
	void FindKing(int& ri, int& ci, Player* P);
	bool Check(Player* P[], int turn);
	void  TChange(int& turn);
	bool SelfCheck(int _sri, int _sci, int _dri, int _dci, int turn, Player* P[]);
	bool SelfCheck(int turn, Player* P[]);
	void ComputeHighlight(Player* P[], int sri, int sci, int turn);
	bool CheckMate(Player* P[], int turn);
	bool StaleMate(int turn, Player* P[]);
	void Highlight();
	void UnHighlight();
	void DrawArrows(sf::RenderWindow& window);
	//void DrawTimer(sf::RenderWindow& window);
	bool Castling(int sri, int sci, int dri, int dci, int turn, Player* P[]);
	void doCastling(int sri, int sci, int dri, int dci);
};

