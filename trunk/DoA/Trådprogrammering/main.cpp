#include <thread>
#include <clocale>
//#include "Player.h"
#include "Game.h"
using namespace std;

int main()
{
	setlocale(LC_ALL, "swedish");
	system("color 1f");

	Game g;
	g.PlayGame();


	system("pause");
}
