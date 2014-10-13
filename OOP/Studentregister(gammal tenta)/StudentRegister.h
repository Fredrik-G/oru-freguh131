#pragma once
#include <string>
#include <clocale>
#include <iostream>
#include <vector>
#include "Student.h"
using namespace std;
class StudentRegister
{
private:
	vector<Student> studentVector;
public:

	StudentRegister()
	{
	}

	void Add(Student Student)
	{
		studentVector.push_back(Student);
	}
	string List()
	{
		ostringstream oss;

		string s;

		for (int i=0; i<studentVector.size(); i++)
			oss << studentVector[i] << endl;	

		return oss.str();
	}

	void WriteToFile()
	{
		ofstream fout;
		fout.open("studenter.txt");
		
		for(auto &a : studentVector)
		{
			fout << a << endl;
		}
	fout.close();

	}
	void ReadFromFile()
	{
		studentVector.clear();
		Student student;
		ifstream fin;
		fin.open("studenter.txt");

		while( !fin.eof() )
		{
			fin >> student;
			
			if( !fin.eof() )
			{
				studentVector.push_back(student);
			}

		}
		fin.close();
	}

	~StudentRegister()
	{
	}
};

