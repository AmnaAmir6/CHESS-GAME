#include"Player.h"

Player::Player(string _N, Color _C)
{
	this->Name = _N;
	this->C = _C;
}

string Player::getName()
{
	return this->Name;
}

Color Player::getColor()
{
	return this->C;
}
