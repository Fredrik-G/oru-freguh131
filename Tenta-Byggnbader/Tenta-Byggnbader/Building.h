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
	string info;
	int ID;
public:

	Building(void){ info=""; ID = -1;}

	~Building(void){}
	int GetID() { return ID; }
	void SetID(int ID) { this->ID=ID; }
	string GetInfo() { return info; }
	void SetInfo(string info) { this->info=info; }

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
	void Read()
	{
		cout << "Ange byggnadens namn: ";
        cin >> info;
        cout << "Ange rum, avsluta med 0." << endl;
        while(1)
        {
			Room rum;
			rum.Read();
			if (rum.GetType() != "0" && rum.GetArea() != 0)
				roomVector.push_back(rum);
			else
				return;
		}
	}
	void Write()
	{
		cout << ID << " " << info << endl;
	}

	void WriteToFile(string filename)
	{
		ofstream fout;
		filename += ".txt";
		fout.open(filename);
		fout << "Building " << info << endl;
		for(auto &a : roomVector)
			fout << a << endl;

		fout.close();
	}
	void ReadFromFile(string filename)
	{
		roomVector.clear();
		Room rum;
		ifstream fin;
		filename += ".txt";
		fin.open(filename);
		if ( !fin.good() )
		{
			cout << "Filen " << filename << "går ej att öppna\n";
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
	friend istream & operator>>(istream &in, Building &byggnad)
	{//På formen (id,info)
		string s;
		char c;
		in >> c;

		getline(in, s, ',');
		istringstream iss(s);
		iss >> byggnad.ID;

		getline(in, byggnad.info, ')');

		return in;
	}
};

