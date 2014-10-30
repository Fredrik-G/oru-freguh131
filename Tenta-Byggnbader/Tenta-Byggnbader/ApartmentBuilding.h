#pragma once
#include "residentialbuilding.h"
class ApartmentBuilding :
	public ResidentialBuilding
{
private:
	int numberOfApartments;
public:

	ApartmentBuilding(void)
	{
		numberOfApartments = -1;
	}
	ApartmentBuilding(int numberOfApartments, int ID, string info)
		: ResidentialBuilding(ID, info)
	{
		this->numberOfApartments = numberOfApartments;
	}
	~ApartmentBuilding(void)
	{
	}

	void Print()
	{
		ResidentialBuilding::Print();
		Building::Print();
		cout << "Antal lägenheter: " << numberOfApartments;
	}


	void SetNumberOfApartments(int apartments) { numberOfApartments = apartments; }
	int GetNumberOfApartments() { return numberOfApartments; }
};

