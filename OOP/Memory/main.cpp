#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include "memory.h"
#include <M:\Desktop\år2\OOP\Filer\Console.h>

using namespace MemorySpace;
int main ()
{
	
	Memory board(3,3);
	board.PrintBoard();
	Course::Console::setcursor(1, 100); //Initierar en cursor 
	board.setCursor(3, 1); //Placerar cursorn i mitten av bordet.

	int c;
	

	do
	{
		c = board.Keyboard();

		if ( c == 13)
		{
			board.flip();
				
		}
		

	} while (c !=  27); //27=ESC

	//system("pause");
	
	return 0;
}