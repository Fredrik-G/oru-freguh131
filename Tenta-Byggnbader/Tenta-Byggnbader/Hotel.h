#pragma once
#include "commercialbuilding.h"
class Hotel :
	public CommercialBuilding
{
private:
	int numberOfBeds;
public:

	Hotel(void)
	{
		numberOfBeds = -1;
	}
	Hotel(int numberOfBeds, int ID, string info) : CommercialBuilding(ID, info)
	{
		this->numberOfBeds = numberOfBeds;
	}
	~Hotel(void)
	{
	}

	void SetNumberOfBeds(int beds) { numberOfBeds = beds; }
	int GetNumberOfBeds() { return numberOfBeds; }
};

