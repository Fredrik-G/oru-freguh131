#include <iostream>
#include <clocale>
#include "Room.h"
#include "Building.h"
#include "BuildingDatabase.h"

#include "AgriCulturalBuilding.h"
#include "CommercialBuilding.h"
#include "ResidentialBuilding.h"
#include "ApartmentBuilding.h"
#include "Villa.h"
#include "Hotel.h"
#include "FoodEnterpriseBuilding.h"
#include "Restaurant.h"
#include "CoffeHouse.h"
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
void Main5_A_C()
{
	Building byggnad(1,"Hus");
	AgriCulturalBuilding ACB(2, "asd");
	ResidentialBuilding RB(3, "Bostadshus");

	CommercialBuilding CB(4, "Kommersiell byggnad");
	Hotel H(200, 5, "Hotell");
	FoodEnterpriseBuilding FEB(50, 6, "Mat");
	Restaurant R(30, 7, "McDonald's", "Snabbmat");
	CoffeHouse CH(20, 8, "Kaffe");

	vector<Building> databas;
	databas.push_back(byggnad);
	databas.push_back(ACB);
	databas.push_back(RB);
	databas.push_back(CB);
	databas.push_back(H);
	databas.push_back(FEB);
	databas.push_back(R);
	databas.push_back(CH);

	cout << "ID och info: \n";
	for(auto &a : databas)
	{
		a.Print();
	}

}


int main()
{
	//fin färg
	system("color 1f");
	setlocale(LC_ALL, "swedish");
	//Main3_1_2();
	//Main3_3();
	//Main3_4();
	//Main3_5();
	//Main3_6();
	//Main4();
	Main5_A_C();
	system("pause");
	return 0;
}
