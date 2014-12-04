#pragma once
#include "../Forward_List/forward_list.h"
#include "Person.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include <string>
class Dating
{
private:
	forward_list<Person> personList;
public:

	Dating()
	{
		//Person kalle("kalle");
		//Person namn("namn");
		//personList.push_front(kalle);
		//personList.push_front(namn);

		//for (auto it = personList.begin(); it != personList.end(); it++)
		//{
		//	cout << it->value;
		//}
	}
	void readFile(string fileName)
	{		
		
		string s, row;
		ifstream fin;
		fin.open(fileName);

		if (!fin.good())
		{
			cout << "Filen " << fileName << "går ej att öppna\n";
			return;
		}

		while (getline(fin, row))
		{		
			istringstream iss(row);
			getline(iss, s, '=');

			if (s == "person")
			{//Läser en en ny person
				Person person;
				iss >> person;
				if (!fin.eof())
				{
					personList.push_front(person);
				}
			}
			else if (s == "interest")
			{//Läser in personens intressen
				getline(iss, s, '\n');
				personList.front().AddInterest(s);
				           //^funkar forwardlist.front()???
			}


		}
		fin.close();

	}
	~Dating()
	{
	}
};

