#pragma once
#include <thread>
#include <mutex>
#include <deque>

#define XStart 5
#define YStart 5
#define XLimit 74
#define YLimit 20

#define P1Up 'w'
#define P1Down 's'
#define P1Left 'a'
#define P1Right 'd'

#define P2Up 'i'
#define P2Down 'k'
#define P2Left 'j'
#define P2Right 'l'
using namespace std;

mutex sync;
deque<char> player1;
deque<char> player2;

class Position
{
public:
	int x, y, oldX, oldY;
	char name;

	Position(){}
};

deque<Position> positions;

class Player
{
private:
	int x, y;
	char name;	
	deque<char> *queue;
public:
	Player()
	{
		name='/';
		x=0;
		y=0;
	}
	Player(int x, int y, char name,  deque<char> *queue)
	{	
		this->x = x;
		this->y = y;
		this->name = name;
		this->queue = queue;
	}
	void AddPlayer(int x, int y, char name,  deque<char> *queue)
	{	
		this->x = x;
		this->y = y;
		this->name = name;
		this->queue = queue;
	}
	int GetX() {return x;}
	int GetY() {return y;}

	void operator()()
	{
		while (1)
		{
			sync.lock();
			Position pos;
			pos.oldX=x;
			pos.oldY=y;
			pos.name=name;

			if (!queue->empty())
			{
				if (queue->back()==P1Up || queue->back()==P2Up)
				{
					if (y != YStart+1)
						y--;
				}
				else if (queue->back()==P1Down || queue->back()==P2Down)
				{
					if (y != YLimit-1)
						y++;
				}
				else if (queue->back()==P1Left || queue->back() == P2Left)
				{
					if (x != XStart+1)
						x--;
				}
				else if (queue->back()==P1Right || queue->back()==P2Right)
				{
					if (x != XLimit-1)
						x++;
				}                       

				queue->pop_back();
			}

			pos.x=x;
			pos.y=y;
			positions.push_back(pos);

			sync.unlock();
			this_thread::sleep_for(chrono::milliseconds(100));
		}
	}

	~Player(void)
	{
	}
};

