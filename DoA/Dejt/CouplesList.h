#pragma once
#include "../Forward_List/forward_list.h"
#include "Couple.h"
class CouplesList
{
private:
	forward_list<Couple> couplesList;
public:

	CouplesList()
	{
	}
	void AddCouple(Couple couple)
	{
		couplesList.push_front(couple);
	}
	void Sort()
	{//Sortera på flicknamn
		;
	}
	void PrintCouplesList()
	{
		for (auto &a : couplesList)
			a.value.PrintCouple();
	}
	void SortCouplesList()
	{

	}

	~CouplesList()
	{
	}


	
};

