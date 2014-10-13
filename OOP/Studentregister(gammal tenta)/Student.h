#pragma once
#include <string>
#include <clocale>
#include <iostream>
#include <sstream>
#include <fstream>
#include "Course.h"
using namespace std;
class Student
{
private:
	string firstName, secondName;
	int enrollmentYear;
public:
	
	Student()
	{
		firstName=secondName="";
		enrollmentYear=0;
	}
	
	Student(string firstName, string secondName, int enrollmentYear=2010)
	{
		this->firstName=firstName;
		this->secondName=secondName;
		this->enrollmentYear=enrollmentYear;
	}

	string GetFirstName() { return firstName; }
	void SetFirstName(string firstName){ this->firstName=firstName;	}

	string GetSecondName() { return secondName; }
	void SetSecondName(string secondName){ this->secondName=secondName;	}

	int GetYear() { return enrollmentYear; }
	void SetYear(int year){ this->enrollmentYear=year;	}

	void AddCourse(string kurs)
	{
		Course course(kurs);
	}
	void Read()
	{
		setlocale(LC_ALL, "swedish");
		cout << "Förnamn= ";
		cin >> firstName;
		cout << "Efternamn= ";
		cin >> secondName;
		cout << "Inskrivningsår= ";
		cin >> enrollmentYear;
	}

	void Write()
	{
		setlocale(LC_ALL, "swedish");
		cout << "Förnamn= " << firstName
			 << "\nEfternamn= " << secondName
			 << "\nInskrivningsår= " << enrollmentYear << endl;
	}

	friend ostream& operator<<(ostream& out, const Student& Student)
	{
		out << "(" << Student.firstName
			<< "," << Student.secondName
			<< "," << Student.enrollmentYear
			<< ")";
		return out;
	}
	

	friend istream & operator>>(istream &in, Student &Student)
	{//På formen (firstName,secondName,enrollmentYear)
		string s;

		//getline(stream, s, '(');
		char c;
		in >> c;

		getline(in, Student.firstName, ',');
		getline(in, Student.secondName, ',');
		
		getline(in, s, ')');
		istringstream iss(s);
		iss >> Student.enrollmentYear;

		return in;
	}

	~Student()
	{
	}
};

