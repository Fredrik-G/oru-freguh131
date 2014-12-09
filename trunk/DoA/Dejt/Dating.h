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
	void matchCouple(int min_matching_interest)
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
					boysList.erase(currentBoy);
					girlsList.erase(currentGirl);

					couples.AddCouple(Couple(currentBoy, currentGirl));
				}

				//Fortsätt med nästa girl
				girlsList.pop_front();
				if (!girlsList.empty())
					currentGirl = girlsList.front();

			}//Gått igenom alla girls
			//Fortsätt med nästa boy
			boysList.pop_front();
			if (!boysList.empty())
				currentBoy = boysList.front();
			//Fyll girlsList med alla girls igen.
			girlsList = girls.GetList();
			currentGirl = girlsList.front();
		}
	}
	void PrintCouples()
	{
		couples.PrintCouplesList();
	}
	~Dating()
	{
	}
};

