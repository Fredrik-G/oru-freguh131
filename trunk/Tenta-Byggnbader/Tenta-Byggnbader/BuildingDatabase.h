#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "Building.h"
#include "Room.h"
using namespace std;
class BuildingDatabase:
	public vector<Building>
{
private:
	
public:

	BuildingDatabase(void)
	{
	}
	~BuildingDatabase(void)
	{
	}
	void Menu()
	{	
		int option = 0;
		while(1)
		{
			//setlocale(LC_ALL, "swedish");
			cout << endl;
			cout << "1. L�gg till en byggnad\n"
					"2. Ta bort en byggnad\n"
					"3. Visa alla byggnader i en lista\n"
					"4. S�k efter en viss byggnad\n"
					"5. Ber�kna alla byggnaders totala yta\n"
					"6. L�s in en fil med byggnader\n"
					"7. Skriv alla byggnader till en fil\n"
					"99. Avsluta programmet\n";
			cout << "V�lj alternativ: ";
			cin >> option;
			cout << endl;
			switch(option)
			{
			case 1:
				NewBuilding();
				break;
			case 2:	
				DeleteBuilding();
				break;
			case 3:
				ListBuildings();
				break;
			case 4:
				Search();
				break;
			case 5:
				Area();
				break;
			case 6:
				ReadFile();
				break;
			case 7:
				WriteFile();
				break;			
			case 99:
				return;
			default:
				cout << "Fel alternativ\n";
				break;		
			}
		}
	}
	void NewBuilding()
	{
		Building byggnad;
		int id;
		cout << "Ange byggnadens unika ID: ";
		cin >> id;
		//Kolla s� id �r unikt
		for(auto &a : (*this))
		{
			if(a.GetID() == id)
			{
				cout << "ID m�ste vara unikt." << endl;
				return;
			}
		}
		//Kommer den hit s� �r id unikt
		byggnad.SetID(id);
		
		byggnad.Read();
		(*this).push_back(byggnad);

	}
	void DeleteBuilding()
	{
		int id, a_iterations = -1;
		cout << "Ange ID p� den byggnad du vill ta bort: ";
		cin >> id;

		for(int i=0; i<(*this).size(); i++)
		{
			a_iterations++;
			if((*this)[i].GetID() == id)
			{
				(*this).erase((*this).begin() + a_iterations);
				return;
			}
		}
		cout << "Byggnad med ID " << id << " hittades ej" << endl;
	}
	void Search()
	{
		int id;
		cout << "Ange ID p� den byggnad du vill visa: ";
		cin >> id;

		for(auto &a : (*this))
		{
			if(a.GetID() == id)
			{
				a.Write();
				return;
			}
		}
		cout << "Byggnad med ID " << id << " hittades ej" << endl;
	}

	void ListBuildings()
	{
		for (int i=0; i<(*this).size(); i++)
			(*this)[i].Write();	
	}
	void Area()
	{
		double totalArea = 0;
		for(auto &a : (*this))
			totalArea += a.TotalArea();
		cout << totalArea << endl;
	}

	void ReadFile()
	{
		(*this).clear();
		Building byggnad;
		ifstream fin;
		fin.open("(*this).txt");

		if ( !fin.good() )
		{
			cout << "Filen datasbas.txt g�r ej att �ppna\n";
			return;
		}
		while( !fin.eof() )
		{
			//L�ser in byggnad och dess rum
			fin >> byggnad;
			byggnad.ReadFromFile(byggnad.GetInfo());

			//L�gger till byggnaden i (*this)en
			if( !fin.eof() )
			{
				(*this).push_back(byggnad);
			}
		}
		fin.close();
	}
	void WriteFile()
	{	
		ofstream fout;
		fout.open("(*this).txt");
		for(auto &a : (*this))
		{	
			fout << "(" << a.GetID()
				 << "," << a.GetInfo()
				 << ")\n";		
			a.WriteToFile(a.GetInfo());
		}		
		fout.close();

	}

};

