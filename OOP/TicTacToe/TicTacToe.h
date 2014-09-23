#pragma once
#include <M:\Desktop\år2\OOP\Filer\Console.h>
using namespace Course;
class TicTacToe
{
private:
	char board[3][3];
	int  xpos[3];
	int  ypos[3];
	int xcursor, ycursor;

	float topleft, topmiddle, topright, middleleft, middlemiddle, middleright, bottomleft, bottommiddle, bottomright;
public:
	TicTacToe();
	~TicTacToe();

	void setCursor(int x, int y);
	int PrintMove(bool spelare);
	int GetPosX();
	int GetPosY();
	int CheckWinner();
	int keyboard();
	void PrintBoard();
};

