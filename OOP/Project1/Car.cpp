#include "Car.h"


Car::Car()
{
	
	brand = "-";
	year = -1;
	price = 0;

	//this->brand = "-";
	//Car::year = -1;
}

Car::Car(string brand, int y, double p)
{
	this->brand = brand;
	this->year = y;
	this->price = p;
}

Car::~Car()
{
}

void Car::print()
{
	cout << "\t" << this->brand << "\t" << this->year << "\t" << this->price   << "\n";
}

void Car::WriteToConsole()
{
	cout << "M�rke=" << brand << endl;
	cout << "�r=" << year << endl;
	cout << "Pris=" << price << endl;
}
void Car::ReadFromConsole()
{

	cout << "Skriv m�rke=";
	cin >> brand;
	cout << "Skriv �r=";
	cin >> year;
	cout << "Skriv pris=";
	cin >> price;
}