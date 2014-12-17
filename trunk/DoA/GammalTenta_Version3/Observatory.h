#pragma once
#include <fstream>
#include <sstream>
#include <iostream>
#include <map>
#include <string>
#include <list>
using namespace std;
class Observatory
{
private:
	struct data
	{
		string coords;
		list<int> observatories;
		
		data(int observatory, string coords)
		{
			observatories.push_back(observatory);
			this->coords=coords;
		}
		void AddObservatory(int observatory)
		{
			observatories.push_back(observatory);
		}
	};
	map<string, data> m;
public:

	Observatory(void)
	{
	}
	void readFile(string fileName)
	{
		int observatory;
		string temp,time,coords,row;
		ifstream fin;
		fin.open(fileName);

		if (!fin.good())
		{
			cout << "Filen " << fileName << "g�r ej att �ppna\n";
			return;
		}

		while (getline(fin,row))
		{
			istringstream iss(row);
			getline(iss,temp,' ');
			//s=aktuell observatory(string)
			//g�r om till integer
			istringstream iss2(temp);
			iss2>>observatory;

			//L�s in tidpunkt
			getline(iss,time,' ');

			//L�s in koordinater
			getline(iss,coords,'\n');

			//kolla om tiden som l�stes in redan finns i mapen 
			auto it=m.find(time);
			if(it==m.end())
				//tiden fanns inte, dvs ny tid.
				m.emplace(time,data(observatory,coords));
			else
				//denna tidpunkt fanns redan
				//l�gg d� till detta observatory till listan som h�r ihop med den tidpunkten
				it->second.AddObservatory(observatory);
		}
		fin.close();
	}
	void print()
	{
		for(auto &a : m)
			if(a.second.observatories.size()>=2)
			{
				cout<<"Tid: "<<a.first<<" Riktning: "<<a.second.coords<<" Observatorier: ";
				for(auto &o : a.second.observatories)
					cout<<o<<" ";
				cout <<"\n";

			}
	}

	~Observatory(void)
	{
	}
};

