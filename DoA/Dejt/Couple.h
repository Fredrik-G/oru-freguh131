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
	
	~Couple()
	{
	}
};

