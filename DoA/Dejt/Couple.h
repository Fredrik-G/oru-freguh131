#pragma once
#include "Person.h"
class Couple
{
public:
	Person boy, girl;
public:

	Couple()
	{
	}
	Couple(Person boy, Person girl)
	{
		this->boy = boy;
		this->girl = girl;
	}
	void PrintCouple()
	{
		cout << boy.firstName << " och " << girl.firstName << endl;
	}
	friend bool operator<(Couple &lop, Couple &rop)
	{
		return (lop.girl.firstName.compare(rop.girl.firstName)) < 0;
		//returnar true om lop �r "mindre"
		//dvs om lop �r f�re i alfabetet
		//Tex "AAA".compare("AAB")<0 ger true f�r AAA �r f�re i alfabetet.
	}
	~Couple()
	{
	}
};

