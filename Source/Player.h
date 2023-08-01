#pragma once
#include"HelpingFunction.h"
#include<string>
using namespace std;

class Player
{
private:
	string Name;
	Color C;
public:
	Player(string _N, Color _C);
	string getName();
	Color getColor();
};

