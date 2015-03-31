#pragma once
#include "MultiMedia.h"

using namespace std;

class MultiMediaRegister
{
public:
	int quit;
	MultiMediaRegister(MMV *pekare);
	~MultiMediaRegister();
	int Quit() { return quit;}
	MMV *p;

	void meny();

	void Add();
	void Delete();
	void List();
	void Search();
	void Sort();
	void WriteToFile();
	void ReadFromFile();

};
