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
		area=-1;
		type_of_room="";
	}
	Room(string type_of_room, double area = 0)
	{	
		this->type_of_room = type_of_room;
		this->area=area;
	}
	~Room(void)
	{
	}

	void SetArea(double area) { this->area=area; }
	double GetArea() {	return area; }
	void SetType(string type_of_room) { this->type_of_room = type_of_room; }
	string GetType() { return type_of_room; }

	void Read()
	{
		cout << "Ange rummets funktion: ";
		cin >> type_of_room;
		if(type_of_room == "0") return;
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

