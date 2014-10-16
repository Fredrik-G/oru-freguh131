#pragma once
#include <iostream>
#include "course.h"
using namespace std;
class LanguageCourse : public Course
{
private:
	char gradeSpoken, gradeWritten;
public:

	LanguageCourse(){}
	void SetGradeSpoken(char grade){gradeSpoken=grade;}
	char GetGradeSpoken(){return gradeSpoken;}

	void SetGradeWritten(char grade){gradeWritten=grade;}
	char GetGradeWritten(){return gradeWritten;}

	virtual void print()
	{
		cout << "Betyg muntligt: "
			 << gradeSpoken 
			 << "\nBetyg skriftligt: "
			 << gradeWritten;
	}


	~LanguageCourse(){}
};

