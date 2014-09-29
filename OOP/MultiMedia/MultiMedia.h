#pragma once
#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

class MultiMedia
{
private:
	int year;
	string name,id;

public:
	MultiMedia();
	~MultiMedia();
	string& GetID() { return id; }
	string& GetName() { return name; }

	friend ostream & operator<<(ostream &stream, MultiMedia &m2);
	friend istream & operator>>(istream &stream, MultiMedia &m2);
	friend bool operator==(MultiMedia  &lop, MultiMedia &rop);
	friend bool operator<(MultiMedia &first, MultiMedia &last);

};

typedef vector<MultiMedia> MMV; //MultiMedia-vektor
typedef vector<MultiMedia>::iterator MMI; //Iterator på MMV (används för att gå igenom objekt i vektorn