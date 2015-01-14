#include <thread>
#include <mutex>
#include <deque>
#include <string>

#include <iostream>
#include <conio.h>
#include "../Console.h"

#include "Player.h"
using namespace std;
#pragma once

class Game
{
private:
	char key;
	Position p1pos, p2pos;
	Player p1;
	Player p2;

public:
	Game(){}
	void PlayGame()
	{	 
		Course::Console::gotoxy(XStart, YStart);
		for (int i=YStart; i<XLimit+1; i++)
			cout << "#";

		Course::Console::gotoxy(XStart, YStart);
		for (int i=XStart; i<YLimit; i++)
		{
			cout<<"#";
			Course::Console::gotoxy(XStart, i+1);
		}

		Course::Console::gotoxy(XLimit, XStart);
		for (int i=XStart; i<YLimit; i++)
		{
			cout<<"#";
			Course::Console::gotoxy(XLimit, i+1);
		}

		Course::Console::gotoxy(YStart, YLimit);
		for (int i=YStart; i<XLimit+1; i++)
			cout << "#";
		
		Course::Console::gotoxy(XLimit/2,1);
		cout<<"A=WASD";
		Course::Console::gotoxy(XLimit/2,2);
		cout<<"B=IJKL";


		p1.AddPlayer(XStart+2,YStart+2,'A', &player1);
		p2.AddPlayer(XLimit-2,YLimit-2,'B', &player2);

		PrintBoard();

		thread t1(*this), t2(p1), t3(p2);

		t1.join();
		t2.join();
		t3.join();
	}

	void PrintBoard()
	{
		if(!positions.empty())
		{
			if(Caught())
			{
				Course::Console::gotoxy(XLimit/2, YLimit+2);
				cout<<"B fångade A!";
			}
			else
			{			
				Position temp=positions.front();

				//Uppdatera spelarnas position
				if(temp.name=='A')
				{
					p1pos.name=temp.name;
					p1pos.x=temp.x;
					p1pos.y=temp.y;
				}
				else if(temp.name=='B')
				{
					p2pos.name=temp.name;
					p2pos.x=temp.x;
					p2pos.y=temp.y;
				}

				//"Töm" gamla position
				Course::Console::gotoxy(temp.oldX, temp.oldY);
				cout << " ";

				//Rita ut spelarens nya position
				Course::Console::gotoxy(temp.x, temp.y);
				cout << temp.name;

				positions.pop_front();
			}
		}
	}
	bool Caught()
	{
		if(p1pos.x > 0)
		{
			if((p1pos.x == p2pos.x) && (p1pos.y == p2pos.y))
				return true;
			else
				return false;
		}
		return false;
	}
	void operator()()
	{//Detta är funktionen som exekveras i en tråd
		do
		{
			if(_kbhit())
			{
				key = _getch();
				sync.lock();

				if(key==P1Up||key==P1Down||key==P1Left||key==P1Right)
					player1.push_front(key);
				else if(key==P2Up||key==P2Down||key==P2Left||key==P2Right)
					player2.push_front(key);

				sync.unlock();
			}

			sync.lock();
			PrintBoard();
			sync.unlock();
			this_thread::sleep_for(chrono::milliseconds(10));

		} while(key!=27);
	}


	~Game(void)
	{
	}
};

