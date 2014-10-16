#pragma once
#include <string>
#include <vector>
using namespace std;
class Result
{
private:
	string grade;
public:

	Result(){grade="N/A";}

	Result(string grade) 
	{
		this->grade=grade;
	}

	string GetResult(){ return grade; }

	~Result(){}
};

