#pragma once
#include "foodenterprisebuilding.h"
class CoffeHouse :
	public FoodEnterpriseBuilding
{
public:

	CoffeHouse(void)
	{
	}
	CoffeHouse(int maxNumberOfGuests, int ID, string info)
		: FoodEnterpriseBuilding(maxNumberOfGuests, ID, info)
	{

	}

	~CoffeHouse(void)
	{
	}
};

