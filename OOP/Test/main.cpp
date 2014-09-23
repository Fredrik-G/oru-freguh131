#include <iostream>
#include <string>
#include <clocale>
#include <cstdlib>
#include <ctime>
#include <conio.h>
#include <clocale>
#include <cctype>
#include <M:\Desktop\år2\OOP\Filer\console.h>
#include <M:\Desktop\år2\OOP\Test\dice.h>

using namespace std;

int main()
{
	setlocale(LC_ALL, "swedish");
	dice spelplan;

	int random;

	system("color 1f");

	while (1) {
	
		if (_kbhit()) {
			system("cls");
			random = rand() % 6 + 1;

			spelplan.empty_board();
			spelplan.throw_dice2(random);
			//spelplan.throw_dice(random);

			Course::Console::gotoxy(20,20);
			system("pause");
		}
	}
	return 0;
}