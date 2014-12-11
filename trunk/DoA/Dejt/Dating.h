#pragma once
#include "../Forward_List/forward_list.h"
#include "PersonList.h"
#include "Couple.h"
#include "CouplesList.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include <string>
#include <iostream>
using namespace std;
class Dating
{
private:
	PersonList boys;
	PersonList girls;
	CouplesList couples;
public:

	Dating()
	{
	}
	void readFile(string boysFile, string girlsFile)
	{
		boys.readFile(boysFile);
		girls.readFile(girlsFile);
	}
	bool matchCouple(int min_matching_interest)
	{	
		forward_list<Person> boysList = boys.GetList();
		forward_list<Person> girlsList = girls.GetList();

		Person currentBoy = boysList.front();
		Person currentGirl = girlsList.front();
		while (!boysList.empty())
		{
			while (!girlsList.empty())
			{
				int matching_interest_count = 0;
				for (auto &b : currentBoy.GetInterest())
				{
					for (auto &g : currentGirl.GetInterest())
					{
						if (b == g)
							//ett intresse matchar
							matching_interest_count++;
					}
				}
				if (matching_interest_count >= min_matching_interest)
				{//Personerna intressen matchar varandra, para ihop.
					boys.erasePerson(currentBoy);
					girls.erasePerson(currentGirl);
										
					couples.AddCouple(Couple(currentBoy, currentGirl));
					break;
				}

				//Forts�tt med n�sta girl
				girlsList.pop_front();
				if (!girlsList.empty())
					currentGirl = girlsList.front();

			}//G�tt igenom alla girls
			//Forts�tt med n�sta boy
			if (girls.getSize() == 0)
				return true;

			boysList.pop_front();
			if (!boysList.empty())
				currentBoy = boysList.front();

			//Fyll girlsList med alla girls igen.		
			girlsList = girls.GetList();
			currentGirl = girlsList.front();
		}

		//Kolla om det inte hittades n�gra par/matchningar
		if (couples.getSize() == 0)
			return false;
		else if (couples.getSize() > 0)
			return true;
	}
	void PrintCouples()
	{
		couples.PrintCouplesList();
	}
	void SortCouples()
	{
		couples.Sort();
	}
	~Dating()
	{
	}
};

