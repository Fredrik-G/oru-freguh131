#include "Card.h"


Card::Card(void)
{
	back = '?';
	front= 'M';
}


Card::Card(char front, char back)
{
	this->back = back;
	this->front= front;
}

Card::~Card(void)
{
}
