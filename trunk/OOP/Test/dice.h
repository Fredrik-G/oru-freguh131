#pragma once
#include <string>
#include <iostream>
#include <iomanip>
#include <cstdlib>
using namespace std;

class dice
{
private:
	char board[3][3];
public:
	dice();
	~dice();
	void empty_board(void);
	void throw_dice(int siffra);
	void throw_dice2(int siffra);

};

