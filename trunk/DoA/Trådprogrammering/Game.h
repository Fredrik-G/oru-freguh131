#include <thread>
#include <mutex>
#include <deque>

#include <iostream>
#include <conio.h>
#include "../Console.h"
#pragma once

mutex sync;


class Game
{

private:
	char key;
public:

	Game(void)
	{
	}
	void fis()
	{
		cout<<"sdhfjgioasd\n\n\n";
	}

	void operator()()
	{//Detta är funktionen som exekveras i en tråd
		do
		{
			if(_kbhit())
			{
				key = _getch();
				sync.lock();
				
				if(key=='w')
					cout << "asd";

				sync.unlock();
			}

			sync.lock();
			fis();
			sync.unlock();
			this_thread::sleep_for(chrono::milliseconds(1336));

		}while(key != 27);
	}





	~Game(void)
	{
	}
};

