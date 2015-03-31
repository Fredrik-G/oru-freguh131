#include "TicTacToe.h"
#include <iostream>
#include <iomanip>
#include <conio.h>
#include <clocale>
using namespace std;

TicTacToe::TicTacToe()
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
			board[i][j] = 0;
	}

	xpos[0] = 8;
	xpos[1] = 12;
	xpos[2] = 16;
	ypos[0] = 0;
	ypos[1] = 2;
	ypos[2] = 4;

	xcursor = ycursor = 0;

	topleft = topmiddle = topright = middleleft = middlemiddle = middleright = bottomleft = bottommiddle = bottomright = -1;
}

int TicTacToe::GetPosX()
{
	int boardpos_x=0;
	int x = Console::wherex();

	if (x == 8) boardpos_x = 0;
	else if (x == 12) boardpos_x = 1;
	else if (x == 16) boardpos_x = 2;

	return boardpos_x;
}

int TicTacToe::GetPosY()
{
	int boardpos_y=0;
	int y = Console::wherey();

	if (y == 0) boardpos_y = 0;
	else if (y == 2) boardpos_y = 1;
	else if (y == 4) boardpos_y = 2;

	return boardpos_y;
}

int TicTacToe::PrintMove(bool spelare)
{
	int x = GetPosX(), y = GetPosY();

	if (x == 0 && y == 0 && topleft == -1)
	{
		if (spelare)
		{
			cout << 'x';
			spelare = !spelare;
			this->topleft = 1;
			return 1;
		}

		else if (!spelare)
		{
			cout << 'o';
			spelare = !spelare;
			this->topleft = 0;
			return 1;
		}
	}
	if (x == 1 && y == 0 && topmiddle == -1)
	{
		if (spelare)
		{
			cout << 'x';
			spelare = !spelare;
			this->topmiddle = 1;
			return 1;
		}

		else if (!spelare)
		{
			cout << 'o';
			spelare = !spelare;
			this->topmiddle = 0;
			return 1;
		}
	}
	if (x == 2 && y == 0 && topright == -1)
	{
		if (spelare)
		{
			cout << 'x';
			spelare = !spelare;
			this->topright = 1;
			return 1;
		}

		else if (!spelare)
		{
			cout << 'o';
			spelare = !spelare;
			this->topright = 0;
			return 1;
		}
	}
	if (x == 0 && y == 1 && middleleft == -1)
	{
		if (spelare)
		{
			cout << 'x';
			spelare = !spelare;
			this->middleleft = 1;
			return 1;
		}

		else if (!spelare)
		{
			cout << 'o';
			spelare = !spelare;
			this->middleleft = 0;
			return 1;
		}
	}
	if (x == 1 && y == 1 && middlemiddle == -1)
	{
		if (spelare)
		{
			cout << 'x';
			spelare = !spelare;
			this->middlemiddle = 1;
			return 1;
		}

		else if (!spelare)
		{
			cout << 'o';
			spelare = !spelare;
			this->middlemiddle = 0;
			return 1;
		}
	}
	if (x == 2 && y == 1 && middleright == -1)
	{
		if (spelare)
		{
			cout << 'x';
			spelare = !spelare;
			this->middleright = 1;
			return 1;
		}

		else if (!spelare)
		{
			cout << 'o';
			spelare = !spelare;
			this->middleright = 0;
			return 1;
		}
	}
	if (x == 0 && y == 2 && bottomleft == -1)
	{
		if (spelare)
		{
			cout << 'x';
			spelare = !spelare;
			this->bottomleft = 1;
			return 1;
		}

		else if (!spelare)
		{
			cout << 'o';
			spelare = !spelare;
			this->bottomleft = 0;
			return 1;
		}
	}
	if (x == 1 && y == 2  && bottommiddle == -1)
	{
		if (spelare)
		{
			cout << 'x';
			spelare = !spelare;
			this->bottommiddle = 1;
			return 1;
		}

		else if (!spelare)
		{
			cout << 'o';
			spelare = !spelare;
			this->bottommiddle = 0;
			return 1;
		}
	}
	if (x == 2 && y == 2 && bottomright == -1)
	{
		if (spelare)
		{
			cout << 'x';
			spelare = !spelare;
			this->bottomright = 1;
			return 1;
		}

		else if (!spelare)
		{
			cout << 'o';
			spelare = !spelare;
			this->bottomright = 0;
			return 1;
		}
	}


	return 0;

}

int TicTacToe::CheckWinner()
{
	//Vågrätt
	if (topleft == 1 && topmiddle == 1 && topright == 1)
	{
		system("color 1a");
		Console::gotoxy(12, 10);
		cout << "X vinner!";
		return 1;
	}
	else if (middleleft == 1 && middlemiddle == 1 && middleright == 1)
	{
		system("color 1a");
		Console::gotoxy(12, 10);
		cout << "X vinner!";
		return 1;
	}
	else if (bottomleft == 1 && bottommiddle == 1 && bottomright == 1)
	{
		system("color 1a");
		Console::gotoxy(12, 10);
		cout << "X vinner!";
		return 1;
	}
	//Diagonalt
	else if (topleft == 1 && middlemiddle == 1 && bottomright == 1)
	{
		system("color 1a");
		Console::gotoxy(12, 10);
		cout << "X vinner!";
		return 1;
	}
	else if (topright == 1 && middlemiddle == 1 && bottomleft == 1)
	{
		system("color 1a");
		system("color 1a");
		Console::gotoxy(12, 10);
		cout << "X vinner!";
		return 1;
	}
	//Lodrätt
	else if (topleft == 1 && middleleft == 1 && bottomleft == 1)
	{
		system("color 1a");
		Console::gotoxy(12, 10);
		cout << "X vinner!";
		return 1;
	}
	else if (topmiddle == 1 && middlemiddle == 1 && bottommiddle == 1)
	{
		system("color 1a");
		Console::gotoxy(12, 10);
		cout << "X vinner!";
		return 1;
	}
	else if (topright == 1 && middleright == 1 && bottomright == 1)
	{
		system("color 1a");
		Console::gotoxy(12, 10);
		cout << "X vinner!";
		return 1;
	}

	//*****************************************************************

	//Vågrätt
	if (topleft == 0 && topmiddle == 0 && topright == 0)
	{
		system("color 1b");
		Console::gotoxy(12, 10);
		cout << "O vinner!";
		return 1;
	}
	else if (middleleft == 0 && middlemiddle == 0 && middleright == 0)
	{
		system("color 1b");
		Console::gotoxy(12, 10);
		cout << "O vinner!";
		return 1;
	}
	else if (bottomleft == 0 && bottommiddle == 0 && bottomright == 0)
	{
		system("color 1b");
		Console::gotoxy(12, 10);
		cout << "O vinner!";
		return 1;
	}
	//Diagonalt
	else if (topleft == 0 && middlemiddle == 0 && bottomright == 0)
	{
		system("color 1b");
		Console::gotoxy(12, 10);
		cout << "O vinner!";
		return 1;
	}
	else if (topright == 0 && middlemiddle == 0 && bottomleft == 0)
	{
		system("color 1b");
		Console::gotoxy(12, 10);
		cout << "O vinner!";
		return 1;
	}
	//Lodrätt
	else if (topleft == 0 && middleleft == 0 && bottomleft == 0)
	{
		system("color 1b");
		Console::gotoxy(12, 10);
		cout << "O vinner!";
		return 1;
	}
	else if (topmiddle == 0 && middlemiddle == 0 && bottommiddle == 0)
	{
		system("color 1b");
		Console::gotoxy(12, 10);
		cout << "O vinner!";
		return 1;
	}
	else if (topright == 0 && middleright == 0 && bottomright == 0)
	{
		system("color 1b");
		Console::gotoxy(12, 10);
		cout << "O vinner!";
		return 1;
	}

	return 0;
}

int TicTacToe::keyboard()
{
	if (_kbhit()) //"Keyboard hit"
	{
		int c = _getch(); //Läser av vilken tangent som användes och sparar värdet i "c"
		bool spelare=true;

		if ( (c == 'w' || c=='W' ) && (ycursor>0))
		{
			ycursor--; //Går upp ett steg om W trycks ned.
			setCursor(xcursor, ycursor);
		}
		else if ( (c == 'a' || c == 'A') && (xcursor>0))
		{
			xcursor--;
			setCursor(xcursor, ycursor);
		}
		else if ( (c == 's' || c == 'S') && (ycursor<2))
		{
			ycursor++;
			setCursor(xcursor, ycursor);
		}
		else if ( (c == 'd' || c == 'D') && (xcursor<2))
		{
			xcursor++;
			setCursor(xcursor, ycursor);
		}

		return c;

	}
	return -1;
}


void TicTacToe::setCursor(int x, int y)
{
	xcursor = x;
	ycursor = y;
	Console::gotoxy(xpos[xcursor], ypos[ycursor]);
}

void TicTacToe::PrintBoard()
{
	setlocale(LC_ALL, "swedish");
	cout << "\t" << " " << board[0][0] << "|" << " " << board[0][1] << " " << "|" << " " << board[0][2] << "\n"
		<< "       " << "-----------" << "\n"
		<< "\t" << " " << board[1][0] << "|" << " " << board[1][1] << " " << "|" << " " << board[1][2] << "\n"
		<< "       " << "-----------" << "\n"
		<< "\t" << " " << board[2][0] << "|" << " " << board[2][1] << " " << "|" << " " << board[2][2] << "\n";

	Console::gotoxy(8, 6);
	cout << "Gå runt med WASD, markera med Enter\n\tAvsluta med ESC";
}

TicTacToe::~TicTacToe()
{
}