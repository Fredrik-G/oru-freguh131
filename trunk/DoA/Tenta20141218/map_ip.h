#pragma once
#include <fstream>
#include <sstream>
#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

class map_ip
{
private:
	struct data_v
	{
		string IP;
		vector<string> uppkopplingar;
		data_v(string IP)
		{
			this->IP = IP;
		}
		void AddUppkoppling(string ip2)
		{
			this->uppkopplingar.push_back(ip2);
		}
		friend bool operator<(const data_v &lop, const data_v &rop)
		{
			return lop.uppkopplingar.size() < rop.uppkopplingar.size(); 
		}

		//bool operator<(const data_v& struct1) const
		//{
		//	return (uppkopplingar.size() < struct1.uppkopplingar.size());
		//}
	};

	struct data_pq
	{
		string IP;
		//Vector med alla uppkopplingar
		vector<string> uppkopplingar;

		data_pq(string IP, vector<string> uppkopplingar)
		{
			this->IP = IP;
			this->uppkopplingar = uppkopplingar;
		}
		void AddUppkoppling(string ip2)
		{
			this->uppkopplingar.push_back(ip2);
		}
		friend bool operator<(const data_pq &lop, const data_pq &rop)
		{
			return lop.uppkopplingar.size() < rop.uppkopplingar.size();
		}
	};

	map<string, data_v> m;
	priority_queue<data_pq> queue;
public:

	map_ip()
	{
	}
	void readFile(string fileName)
	{
		string ip1,ip2,row;
		ifstream fin;
		fin.open(fileName);

		if (!fin.good())
		{
			cout << "Filen " << fileName << "går ej att öppna\n";
			return;
		}
		while (getline(fin, row))
		{		
			bool foundIP = false;
			istringstream iss(row);

			getline(iss, ip1, ' ');
			getline(iss, ip2, '\n');

			auto it = m.find(ip1);
			if (it == m.end())
				//ny ip
				m.emplace(ip1, data_v(ip1));
			else
				//denna ip fanns redan
				//lägg då till ip2 till ip1s uppkopplingar
				it->second.AddUppkoppling(ip2);	
		}
		fin.close();
	}
	void search(string ip)
	{//Visar alla uppkopplingar för ett visst IP
		auto it = m.find(ip);
		if (it != m.end())
		{
			cout << "IP " << ip << "har " << it->second.uppkopplingar.size() << " st uppkopplingar\n";
			cout << "Klicka för att visa dess uppkopplingar.";
			getchar();

			for (auto &a : it->second.uppkopplingar)
				cout << a << endl;
		}
		else
			cout << "Hittade inte " << ip<<endl;
	}
	void PrintMostFrequent(int antal)
	{//Visar IP med flest uppkopplingar.
	 //Parameter antal anger hur många IP som ska visas.
		for (auto &a : m)
		{//Fyll kön med hela mapen
			queue.push(data_pq(a.second.IP, a.second.uppkopplingar));
		}
		for (unsigned int i = 0; i < antal; i++)
		{
			cout << queue.top().IP << " antal: " << queue.top().uppkopplingar.size() << endl;
			queue.pop();
		}
	}
	~map_ip()
	{
	}
};

