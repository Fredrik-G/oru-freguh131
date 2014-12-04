#include <vector>
#pragma once
using namespace std;
class InterestTable
{
private:
	vector<string> interest;
public:

	InterestTable()
	{		
	}
	InterestTable(string interest)
	{
		this->interest.push_back(interest);
	}
	void AddIntrerest(string interest)
	{
		this->interest.push_back(interest);
	}
	vector<string> GetInterest()
	{
		return this->interest;
	}
	~InterestTable()
	{
	}
};

	