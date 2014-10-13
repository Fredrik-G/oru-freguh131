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
			
			cout << "1. Lägg till en student\n"
					"2. Ta bort en student\n"
					"3. Lägg till ny kurs för en viss student\n"
					"4. Uppdatera resultat i en students kurs\n"
					"5. Lista alla studenter i registret\n"
					"6. Spara alla studenter till en textfil\n"
					"7. Läs in studenter från en textfil\n"
					"99. Avsluta programmet \n";
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
			case 5:
				List();
				break;
			case 6:
				WriteToFile();
				break;
			case 7:
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
		string s;
		int a_iterations=-1;
		cout << "Ange förnamn på den student till vill ta bort: ";
		cin >> s;

		for(auto &a : studentVector)
		{
			a_iterations++;
			if(s.compare(a.GetFirstName()) == 0 )
			{
				studentVector.erase( studentVector.begin() + a_iterations );
				return;
			}
		}	
	}
	void AddCourse()
	{
		string name,course;
		cout << "Ange studentens namn: ";
		cin >> name;
		cout << "\nAnge kurs. ";
		cin >> course;

		for(auto &a : studentVector)
		{
			if(name.compare(a.GetFirstName()) == 0 )
				a.AddCourse(course);
		}
	}

	void List()
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

