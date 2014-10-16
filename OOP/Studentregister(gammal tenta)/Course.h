#pragma once
#include <string>
#include <vector>
#include "Result.h"
using namespace std;
class Course
{
private:
	string name;
	vector<Result> resultVector;
public:

	Course() { name="";} 
	Course(string name){ this->name=name; }
	
	void SetCourse(string kurs){ name=kurs; }
	string GetCourse(){	return name; }

	void AddResult(string grade)
	{
		resultVector.push_back(grade);
	}
	string GetResult()
	{
		string result="";
		int r_iterations = 0;
		for(auto &r : resultVector)
		{
			r_iterations++;
			result += r_iterations;
			result += ":" + r.GetResult() + " ";
		}
		return result;
	}

	~Course(){ }
};

