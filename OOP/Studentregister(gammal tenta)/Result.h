#pragma once
#include <string>
#include <vector>
using namespace std;
class Result
{
private:
	char grade;
public:

	Result(){grade='/';}

	Result(char grade) 
	{
		this->grade=grade;
	}

	char GetResult(){ return grade; }

	~Result(){}
};

