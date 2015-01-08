#pragma once
#include "circular_list.h"
class Josephus
{
private:
	circular_list people;
public:

	Josephus()
	{
	}
	void add(string name)
	{
		people.add(name);
	}
	int asd()
	{
		return people.count();
	}
	void eliminate()
	{//tar bort var 3e tills bara en är kvar
		if (people.count() >= 3)
		{
			int count = 1;
			while (people.count() != 1)
			{
				for (auto it = people.begin(); it != people.end(); it++)
				{
					count++;

					if (count == 3)
					{
						count = 1;
						cout << "Tar bort " << it->next->value << endl;
						people.erase_after(it);
					}
				}
			}
			cout << people.front() << " överlevde!\n";
		}
		else
			return;
	}
	void print()
	{
		people.print();
	}
	~Josephus()
	{
	}
};

