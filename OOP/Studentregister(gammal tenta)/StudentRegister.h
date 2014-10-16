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

	StudentRegister() {}

	void Menu()
	{	
		Student student;
		int option = 0;
		while(1)
		{
			setlocale(LC_ALL, "swedish");
			cout << endl;
			cout << "1. Lägg till en student\n"
					"2. Ta bort en student\n"
					"3. Lägg till ny kurs för en viss student\n"
					"4. Uppdatera resultat i en students kurs\n"
					"5. Visa en viss students kurser och resultat\n"
					"6. Lista alla studenter i registret\n"
					"7. Spara alla studenter till en textfil\n"
					"8. Läs in studenter från en textfil\n"
					"99. Avsluta programmet\n";
			cout << "Välj alternativ: ";
			cin >> option;
			cout << endl;
			switch(option)
			{
			case 1:
				cout << "Skriv in student på formen (förnamn,efternamn,inskrivningsår): ";
				cin >> student;
				Add(student);
				break;
			case 2:
				Delete();
				break;
			case 3:
				AddCourse();
				break;
			case 4:
				AddResult();
				break;
			case 5:
				ListCourses();
				break;
			case 6:
				ListStudents();
				break;
			case 7:
				WriteToFile();
				break;
			case 8:
				ReadFromFile();
				break;			

			case 99:
				return;
			default:
				cout << "Fel alternativ\n";
				break;		
			}
		}
	}
	
	void Add(Student Student)
	{
		studentVector.push_back(Student);
	}
	void Delete()
	{
		string name;
		int a_iterations=-1;
		cout << "Ange förnamn på den student till vill ta bort: ";
		cin >> name;

		for(auto &a : studentVector)
		{
			a_iterations++;
			if(name.compare(a.GetFirstName()) == 0 )
			{
				studentVector.erase( studentVector.begin() + a_iterations );
				return;
			}
		}	
		cout << "Studenten " << name << " hittades inte i registret\n";
	}
	void AddResult()
	{
		string name,course;
		char grade;
		cout << "Ange studentens namn: ";
		cin >> name;
		cout << "Ange kurs: ";
		cin >> course;
		cout << "\Ange resultat: ";
		cin >> grade;

		for(auto &s : studentVector)
		{
			if(name.compare(s.GetFirstName()) == 0 )
			{
				s.AddResult(course,grade);
				return;
			}
		}
		cout << "Studenten " << name << " hittades inte i registret\n";
	}

	void AddCourse()
	{
		string name,course,option;
		cout << "\nAnge studentens namn: ";
		cin >> name;

		for(auto &s : studentVector)
		{
			if(name.compare(s.GetFirstName()) == 0 )
			{
				cout << "\nAnge kurs. ";
				cin >> course;
				s.AddCourse(course);
					return;
			}

			}
		
		cout << "Studenten " << name << " hittades inte i registret\n";
	}
	void ListCourses()
	{
		string name;
		cout << "Ange studentens namn: ";
		cin >> name;

		for(auto &s : studentVector)
		{
			if(name.compare(s.GetFirstName()) == 0 )
			{
				s.ListCourses();
				return;
			}
		}
		cout << "Studenten " << name << " hittades inte i registret\n";
	}

	void ListStudents()
	{
		ostringstream oss;
		string s;

		for (int i=0; i<studentVector.size(); i++)
			oss << studentVector[i] << endl;	

		cout << oss.str();
	}

	void WriteToFile()
	{
		ofstream fout;
		fout.open("studenter.txt");
		
		for(auto &s : studentVector)
		{
			fout << s << endl;
		}
	fout.close();

	}
	void ReadFromFile()
	{
		studentVector.clear();
		Student student;
		ifstream fin;
		fin.open("studenter.txt");
		if ( !fin.good() )
		{
			cout << "Filen studenter.txt går ej att öppna\n";
			return;
		}
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

