#include <iostream>
#include <clocale>
#include "Room.h"
#include "Building.h"
#include "BuildingDatabase.h"
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
	Building building;
	Room rum1("Livingroom",20),
	     rum2("Bedroom",30),
		 rum3("Bedroom",40);

	building.Add(rum1);
	building.Add(rum2);
	building.Add(rum3);

	cout << building.List() << endl;

	building.Search();
}
void Main3_5()
{	
	Building building;
	Room rum1("Livingroom",20),
	     rum2("Bedroom",30),
		 rum3("Bedroom",40);

	building.Add(rum1);
	building.Add(rum2);
	building.Add(rum3);

//	building.WriteToFile();
}
void Main3_6()
{
	Building building;

	//building.ReadFromFile();
	cout << building.List() << endl;

	cout << "Area av alla byggnader: "
		 << building.TotalArea()
		 << endl;
}
void Main4()
{
	BuildingDatabase database;
	database.Menu();
}


int main()
{
	setlocale(LC_ALL, "swedish");
	//Main3_1_2();
	//Main3_3();
	//Main3_4();
	//Main3_5();
	//Main3_6();
	Main4();
	system("pause");
}
