#pragma once
#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
using namespace std;
class Room
{
private:
	double area;
/*	enum type_of_room
	{
		Kitchen,
		Living,
		Bed
	}; */
	string type_of_room;

public:

	Room(void)
	{
		
	}
	Room(string type, double area2 = 0)
	{	
		type_of_room = type;
		area=area2;
	}
	~Room(void)
	{
	}

	void SetArea(double area2) { area=area2; }
	double GetArea() {	return area; }

	void SetType(string type) { type_of_room = type; }
	string GetType() { return type_of_room; }
	void Read()
	{
		cout << "Ange rummets funktion: ";
		cin >> type_of_room;
		cout << "Ange rummets area: ";
		cin >> area;
	}
	void Write()
	{
		cout << type_of_room
			 << " " << area
			 << endl;
	}

	friend ostream& operator<<(ostream& out, const Room& Rum)
	{//cout
		out << "(" << Rum.type_of_room
			<< "," << Rum.area
			<< ")";
		return out;
	}
	
	friend istream & operator>>(istream &in, Room &Rum)
	{//På formen (type,area)
		string s;
		//getline(stream, s, '(');
		char c;
		in >> c;

		getline(in, Rum.type_of_room, ',');
		
		getline(in, s, ')');
		istringstream iss(s);
		iss >> Rum.area;

		return in;
	}


};

