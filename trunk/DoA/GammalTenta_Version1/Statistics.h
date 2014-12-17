#pragma once
#include <string>
#include <array>
#include <fstream>
#include <sstream>
#include <iostream>
#include <string>
#include <iostream>
using namespace std;
class Statistics
{
private:
	//l�t nyckeln som �r inkomsten ge ett unikt index i din array
	array<int,1000001> totSalary;
public:

	Statistics(void)
	{
		clear();
	}	
	void readFile(string fileName)
	{
		string row;
		ifstream fin;
		fin.open(fileName);

		if (!fin.good())
		{
			cout << "Filen " << fileName << "g�r ej att �ppna\n";
			return;
		}

		while (getline(fin, row))
		{
			istringstream iss(row);
			int temp;
			iss >> temp;
			
			if(temp>=2e4 && temp<=1e6)
				totSalary[temp]++;
		}
		fin.close();
	}
	int calculate_mean()
	{
		//long long int=64bit=stort tal
		long long int sumOfSalary=0;
		int count = 0;
		for(auto i=0;i<totSalary.size();i++)
		{//totSalary[i] �r antalet med den l�nen, har tex. v�rdet 0,1,2, osv
		 //i �r nyckeln (l�nen)
		 //summan=l�nen g�nger antalet
			if(totSalary[i] != 0)
			{
				sumOfSalary += i*totSalary[i];
				count += totSalary[i];
			}
		}
		return sumOfSalary/count;
	}
	int calculate_median()
	{//funkar ej
		int count = 0;
		for(auto i=0;i<totSalary.size();i++)
		{
				count += totSalary[i];
		}
		if(count %2==0)
			return totSalary[count/2];
		else
			return totSalary[(count+1)/2];
	}


	//optimera inte denna funktion
	#pragma optimize("", off )
	void clear()
	{
		for(auto i=0;i<totSalary.size();i++)
			totSalary[i]=0;
	}
	~Statistics(void)
	{
	}
};

