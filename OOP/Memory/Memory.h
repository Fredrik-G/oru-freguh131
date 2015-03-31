#pragma once
#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include "Player.h"
#include "Card.h"

using namespace std;

namespace MemorySpace
{
	class Memory
	{
	private:
			int r_size,c_size;
			int row;
			int column;
			int xcursor, ycursor;
			vector<Player> *pv;
			vector<vector<Card>> *cvv;
	public:
			Memory();
			~Memory();

			Memory(int r, int c);
			void PrintBoard();
			int Keyboard();
			void setCursor(int x, int y);
			void flip();
	};
}
typedef vector<Player> V;
typedef vector<vector<Card>> VVC;