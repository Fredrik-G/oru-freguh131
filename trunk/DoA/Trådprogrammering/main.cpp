#include <thread>

#include "Game.h"
#include "Player.h"

using namespace std;

int main()
{
	Game asd;
	thread t1(asd);
	t1.join();


	system("Pause");
}
