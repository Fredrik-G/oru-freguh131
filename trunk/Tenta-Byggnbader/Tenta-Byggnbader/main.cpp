#include <iostream>
#include <clocale>
#include "Room.h"
#include "Building.h"
using namespace std;

void Main3_1_2()
{
	Room kitchen;
	Room livingroom("Livingroom");
	Room bedroom("Bedroom",20);

	kitchen.SetArea(10);
	livingroom.SetArea(10);

	cout << livingroom.GetType() 
		 << " " << livingroom.GetArea()
		 << endl;

	Room rum;
	rum.Read();
	rum.Write();
}
void Main3_3()
{
	Room rum;
	cout << "Ange nytt rum på formen (funktion,area): ";
	cin >> rum;

	cout << rum << endl;
}
void Main3_4()
{
	Building buildingRegister;
	Room rum1("Livingroom",20),
	     rum2("Bedroom",30),
		 rum3("Bedroom",40);

	buildingRegister.Add(rum1);
	buildingRegister.Add(rum2);
	buildingRegister.Add(rum3);

	cout << buildingRegister.List() << endl;

	buildingRegister.Search();
}
void Main3_5()
{	
	Building buildingRegister;
	Room rum1("Livingroom",20),
	     rum2("Bedroom",30),
		 rum3("Bedroom",40);

	buildingRegister.Add(rum1);
	buildingRegister.Add(rum2);
	buildingRegister.Add(rum3);

	buildingRegister.WriteToFile();
}
void Main3_6()
{
	Building buildingRegister;

	buildingRegister.ReadFromFile();
	cout << buildingRegister.List() << endl;

	cout << "Area av alla byggnader: "
		 << buildingRegister.TotalArea()
		 << endl;
}


int main()
{
	setlocale(LC_ALL, "swedish");
	//Main3_1_2();
	//Main3_3();
	//Main3_4();
	//Main3_5();
	Main3_6();
	system("pause");
}
