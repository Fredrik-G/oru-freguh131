#pragma once
#include "commercialbuilding.h"
class FoodEnterpriseBuilding :
	public CommercialBuilding
{
protected:
	int maxNumberOfGuests;
public:

	FoodEnterpriseBuilding(void)
	{
		maxNumberOfGuests = -1;
	}
	FoodEnterpriseBuilding(int maxNumberOfGuests, int ID, string info) : CommercialBuilding(ID, info)
	{
		this->maxNumberOfGuests = maxNumberOfGuests;
	}
	~FoodEnterpriseBuilding(void)
	{
	}

	void SetMaxGuests(int max) { maxNumberOfGuests = max; }
	int GetMaxGuests() { return maxNumberOfGuests; }
};

