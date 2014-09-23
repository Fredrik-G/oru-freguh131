#include "dice.h"
#include <M:\Desktop\år2\OOP\Filer\console.h>

dice::dice()
{

	srand(time(NULL));

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
			board[i][j] = 0;
	}
}


dice::~dice()
{
}

void dice::empty_board(void)
{
	cout << "|" << board[0][0] << "| |" <<  board[0][1] << "|" << board[0][2] << "\n"

		 << "|" << board[1][0] << "| |" << board[1][1] << "|" << board[1][2] << "\n"

		 << "|" << board[2][0] << "| |" << board[2][1] << "|" << board[2][2] << "\n";
}
void dice::throw_dice2(int siffra)
{
	int left, middle_x, right, top, middle_y, bottom;
	left = 0;
	middle_x = 3;
	right = 5;

	top = 0;
	middle_y = 1;
	bottom = 2;

	if (siffra == 1) {
		Course::Console::gotoxy(middle_x, middle_y);
		cout << "x|";
	}
	if (siffra == 2) {
		Course::Console::gotoxy(left, top);
		cout << "|x";
		Course::Console::gotoxy(right, bottom);
		cout << "x|";
	}
	if (siffra == 3) {
		Course::Console::gotoxy(left, top);
		cout << "|x";
		Course::Console::gotoxy(middle_x, middle_y);
		cout << "x|";
		Course::Console::gotoxy(right, bottom);
		cout << "x|";
	}
	if (siffra == 4) {
		Course::Console::gotoxy(left, top);
		cout << "|x";
		Course::Console::gotoxy(right, top);
		cout << "x|";
		Course::Console::gotoxy(right, bottom);
		cout << "x|";
		Course::Console::gotoxy(left, bottom);
		cout << "|x";
	}
	if (siffra == 5) {
		Course::Console::gotoxy(left, top);
		cout << "|x"; //vänster uppe
		Course::Console::gotoxy(right, top);
		cout << "x|"; //uppe höger
		Course::Console::gotoxy(right, bottom);
		cout << "x|"; //nere höger
		Course::Console::gotoxy(left, bottom);
		cout << "|x";
		Course::Console::gotoxy(left, middle_y);
		cout << "|x"; //vänster mitt
		Course::Console::gotoxy(right, middle_y);
		cout << "x|"; //mitt höger
	}
	if (siffra == 6) {
		Course::Console::gotoxy(right, top);
		cout << "x|"; //uppe höger
		Course::Console::gotoxy(right, bottom);
		cout << "x|"; //nere höger
		Course::Console::gotoxy(left, top);
		cout << "|x"; //vänster uppe
		Course::Console::gotoxy(left, bottom);
		cout << "|x"; //vänster nere
		Course::Console::gotoxy(middle_x, middle_y);
		cout << "x|"; //mitt mitt

	}
}
void dice::throw_dice(int siffra)
{
	if (siffra == 1) {
		system("cls");
		cout << "| | | | \n";
		cout << "| |x| | \n";
		cout << "| | | | \n";
	} 
	if (siffra == 2) {
		system("cls");
		cout << "|x| | | \n";
		cout << "| | | | \n";
		cout << "| | |x| \n";
	}
	if (siffra == 3) {
		system("cls");
		cout << "|x| | | \n";
		cout << "| |x| | \n";
		cout << "| | |x| \n";
	}
	if (siffra == 4) {
		system("cls");
		cout << "|x| |x| \n";
		cout << "| | | | \n";
		cout << "|x| |x| \n";
	}
	if (siffra == 5) {
		system("cls");
		cout << "|x| |x| \n";
		cout << "|x| |x| \n";
		cout << "|x| |x| \n";
	}
	if (siffra == 6) {
		system("cls");
		cout << "|x| |x| \n";
		cout << "| |x| | \n";
		cout << "|x| |x| \n";
	}
}