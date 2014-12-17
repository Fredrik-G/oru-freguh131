#pragma once
#include <fstream>
#include <iostream>
#include <map>
#include <string>
#include <algorithm> //std::max_element

using namespace std;
class wordCounter
{
private:
	map<string,int> wordsCount;
public:

	wordCounter(void)
	{
	}
	void readFile(string fileName)
	{
		string word;
		ifstream fin;
		fin.open(fileName);

		if (!fin.good())
		{
			cout << "Filen " << fileName << "g�r ej att �ppna\n";
			return;
		}

		while (fin.good())
		{
			fin >> word;

			//kollar om ordet som l�stes in finns i wordsCount
			if(wordsCount.find(word) == wordsCount.end())
				//tilldela v�rdet 1 om det �r ett nytt ord.
				wordsCount[word]=1;
			else
				//annars �r det ett ord som redan fanns, �ka d� dess count.
				wordsCount[word]++;
		}
		fin.close();
	}
	static bool compare(pair<string,int> lop, pair<string,int> rop)
	{
		return lop.second<rop.second;
	}
	void printMostFrequent(int amount=1)
	{//amount=antal ord som ska skrivas ut. 
		cout<<"Ord:\tantal:\n";
		while(amount>0)
		{
			auto it = max_element(wordsCount.begin(), wordsCount.end(), &wordCounter::compare);
			cout<<it->first<<"\t"<<it->second<<endl;

			wordsCount.erase(it);
			amount--;
		}
	}
	~wordCounter(void)
	{
	}
};

