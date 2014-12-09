#include "InterestTable.h"
#include <iostream>
#include <ostream>
#include <fstream>
#include <string>
#pragma once
using namespace std;
class Person
{
public:
	string firstName;
	InterestTable interests;
public:

	Person()
	{
		firstName  = "";
	}
	Person(string firstName)
	{
		this->firstName = firstName;
	}

	void AddInterest(string interest)
	{
		interests.AddIntrerest(interest);
	}
	
	vector<string> GetInterest()
	{
		return interests.GetInterest();
	}

	void printPerson()
	{
		vector<string> temp = interests.GetInterest();
		cout << firstName << " ";
		for (auto &a : temp)
			cout  << a << " ";
		cout << endl;
	}

	friend istream& operator>>(istream &in, Person &person)
	{//cin
     //"person=Kalle"
		string s;
		getline(in, person.firstName, '=');
		getline(in, s, '\n');
		return in;
	}

	friend ostream& operator<<(ostream &out, Person &person)
	{//cout
		out << person.firstName;
		vector<string> v = person.GetInterest();
		for (int i = 0; i < v.size(); i++)
		{
			out << v[i] << " ";
		}
		return out;
	}
	friend bool operator==(Person &lop, Person & rop)
	{
		return lop.firstName == rop.firstName;
		//return lop.firstName.compare(rop.firstName) == 0;
	}
	~Person()
	{
	}
};

