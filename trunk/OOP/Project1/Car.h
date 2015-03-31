#pragma once
#include <string>
#include <iostream>
#include <iomanip>
using namespace std;
class Car
{
private:
	string brand;
	int year;
	double price;

public:
	Car();
	Car(string brand, int y, double price);
	~Car();
	void print();

	void ReadFromConsole();
	void WriteToConsole();

	void setBrand(string b) { brand=b; }
	string getBrand() { return brand; }
};

