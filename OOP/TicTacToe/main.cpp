#include <iostream>
#include <string>
#include <conio.h>
#include <M:\Desktop\�r2\OOP\TicTacToe\TicTacToe.h>
#include <M:\Desktop\�r2\OOP\Filer\Console.h>
//using namespace std;
using namespace Course;
int main()
{
		system("title TicTacToe");
		system("color 1f");

		TicTacToe bord1;	

		bord1.PrintBoard();
		Console::setcursor(1, 100); //Initierar en cursor 
		bord1.setCursor(1, 1); //Placerar cursorn i mitten av bordet.

		int c, ritat = 0, antal_drag = 0,klart=0;
		bool spelare = true;

		do

		{ //G�r detta tills man trycker p� ESC

 			c = bord1.keyboard();

			if ((c == 13 ) && ritat == 0 && klart != 1)
			{

				if (spelare)
				{
					ritat = bord1.PrintMove(spelare);
					spelare = !spelare;
					antal_drag++;

					if (antal_drag >= 5)
					
						klart = bord1.CheckWinner();

					/*if (antal_drag >= 8)
					{
						Console::gotoxy(12, 8);
						cout << "Oavgjort...";
					}*/
					
				}
				else if (!spelare)
				{
					ritat = bord1.PrintMove(spelare);
					spelare = !spelare;
					antal_drag++;

					if (antal_drag >= 5)
						klart=bord1.CheckWinner();

				}
			}
			else if (c != 13 && c != -1)
				//Medlemsfunktionen 'keyboard' returner -1 om man inte r�r tangentbordet
				//s� h�r g�rs en kontroll s� att variabeln 'ritat' endast nollst�ll d� man tryckt en annan tangent �n 'f'.
			{
				ritat = 0;
			}
		/*	while (antal_drag > 9 && klart==0)
			{
				Console::gotoxy(12, 8);
				cout << "Oavgjort...";
				klart = 1;
			}*/
			
		
			
		} while (c !=  27); //27=ESC
		

	return 0;
}