#pragma once
#include <string>
using namespace std;
class Course
{
private:
	string name;
public:

	Course() { } 
	Course(string name){ this->name=name; }
	
	~Course(){ }
};

