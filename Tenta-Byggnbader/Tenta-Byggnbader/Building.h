#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "Room.h"
using namespace std;
class Building
{
private:
	vector<Room> roomVector;
public:

	Building(void)
	{
	}

	~Building(void)
	{
	}

	void Add(Room rum)
	{
		roomVector.push_back(rum);
	}
	void Search()
	{
		string type;
		cout << "Ange rummets funktion: ";
		cin >> type;

		for(auto &a : roomVector)
		{
			if(type.compare(a.GetType()) == 0 )
			{
				cout << a << endl;
				return;
			}
		}	
		cout << "Rummet med funktionen " << type << " hittades inte i registret\n";
	}
	void Delete()
	{
		string type;
		int a_iterations = -1;
		cout << "Ange rummets funktion: ";
		cin >> type;

		for(auto &a : roomVector)
		{
			a_iterations++;
			if(type.compare(a.GetType()) == 0 )
			{
				roomVector.erase( roomVector.begin() + a_iterations );
				return;
			}
		}	
		cout << "Rummet med funktionen " << type << " hittades inte i registret\n";
	}
	string List()
	{
		ostringstream oss;
		string s;

		for (int i=0; i<roomVector.size(); i++)
			oss << roomVector[i] << endl;	

		return oss.str();
	}

	void WriteToFile()
	{
		ofstream fout;
		fout.open("buildings.txt");
		
		for(auto &a : roomVector)
		{
			fout << a << endl;
		}

		fout.close();
	}
	void ReadFromFile()
	{
		roomVector.clear();
		Room rum;
		ifstream fin;
		fin.open("buildings.txt");
		if ( !fin.good() )
		{
			cout << "Filen buildings.txt går ej att öppna\n";
			return;
		}
		while( !fin.eof() )
		{
			fin >> rum;
			
			if( !fin.eof() )
			{
				roomVector.push_back(rum);
			}

		}
		fin.close();
	}
	double TotalArea()
	{
		double totalArea = 0;

		for(auto &a : roomVector)
		{
			totalArea += a.GetArea();
		}
		return totalArea;
	}

};

