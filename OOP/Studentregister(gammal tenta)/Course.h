#pragma once
#include <string>
#include <vector>
#include "Result.h"
using namespace std;
class Course
{
private:
	string name;
	int year;
	vector<Result> resultVector;
public:

	Course() { name="";} 
	Course(string name){ this->name=name; }
	
	void SetCourse(string kurs){ name=kurs; }
	string GetCourse(){	return name; }

	void AddResult(char grade)
	{
		resultVector.push_back(Result(grade));
	}
	string GetResult()
	{
		ostringstream oss;
		int r_iterations = 0;
		for(auto &r : resultVector)
		{
			r_iterations++;
			oss << r_iterations;
			oss << ":" << r.GetResult() << " ";
		}
		return oss.str();
	}

	~Course(){ }
};

