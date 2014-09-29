#pragma once
#include <iostream>
using namespace std;
//namespace MemorySpace
//{
	class Card
	{
		char front, back;
		bool isFlipped;
	public:
		Card(void);
		Card(char front, char back);

		char GetBack() { return back; }
		char GetFront() { return front; }
		~Card(void);

		void flip()
		{
			isFlipped=true;
		}
	};
//}

