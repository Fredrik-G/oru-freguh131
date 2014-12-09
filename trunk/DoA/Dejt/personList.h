#pragma once
#include "../Forward_List/forward_list.h"
#include "Person.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include <string>
#include <iostream>
using namespace std;
class PersonList
{
private:
	forward_list<Person> personList;
public:

	PersonList()
	{
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
	void erasePerson(string name)
	{
		for (auto &a : personList)
		{
			;
		}
	}
	forward_list<Person> GetList()
	{
		return this->personList;
	}
	void PrintList()
	{
		for (auto &a : personList)
		{
			a.value.printPerson();
		}
	}
	~PersonList()
	{
	}
};

