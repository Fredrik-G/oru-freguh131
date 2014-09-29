#include "Memory.h"
#include <iostream>
#include <iomanip>
#include <conio.h>
#include <clocale>
#include <M:\Desktop\år2\OOP\Filer\Console.h>

using namespace MemorySpace;

Memory::Memory()
{

}

Memory::Memory(int r, int c)
{ //R=rad, C=kolumn
	cvv = new vector<vector<Card>>(r);
	row=2;
	column=2;
	xcursor = ycursor = 0;

	r_size=r;
	c_size=c;

	for (int i = 0; i < r_size; i++)
	{
		(*cvv)[i] = vector<Card>(c);
	}

	for (int rad = 0; rad < r_size; rad++)
	{
		for (int kolumn = 0; kolumn < c_size; kolumn++)
		{
			(*cvv)[rad][kolumn] = Card('F', 'B' );
		}
	}
}

void Memory::PrintBoard()
{
	for (int rad = 0; rad < r_size; rad++)
	{
		cout << "|";
		for (int kolumn = 0; kolumn < c_size ; kolumn++)
		{
			cout << (*cvv)[rad][kolumn].GetBack();
			if ( kolumn == c_size - 1 )
				cout << "|" << "\n"; 
			else
				cout << " ";
		}
	}
}

int Memory::Keyboard()
{
	if (_kbhit()) //"Keyboard hit"
	{
		int c = _getch(); //Läser av vilken tangent som användes och sparar värdet i "c"
		bool spelare=true;


		if ( (c == 'w' || c=='W' ) && row>1 )
		{
			row--;
			ycursor--; //Går upp ett steg om W trycks ned.
			setCursor(xcursor, ycursor);
		}
		else if ( (c == 's' || c == 'S') && row<r_size)
		{
			row++;
			ycursor++;
			setCursor(xcursor, ycursor);
		}
		else if ( (c == 'a' || c == 'A') && column>1)
		{
			column--;
			xcursor = xcursor-2;
			setCursor(xcursor, ycursor);
		}

		else if ( (c == 'd' || c == 'D') && column<c_size)
		{
			column++;
			xcursor = xcursor+2;
			setCursor(xcursor, ycursor);
		}
		
		return c;

	}
	return -1;
}
void Memory::flip()
{
	(*cvv)[row-1][column-1].flip();
	cout << (*cvv)[row-1][column-1].GetFront();
}

void Memory::setCursor(int x, int y)
{
	xcursor = x;
	ycursor = y;
	Course::Console::gotoxy(xcursor, ycursor);

}






Memory::~Memory()
{
}
