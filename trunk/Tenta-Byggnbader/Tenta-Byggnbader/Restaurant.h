#pragma once
#include "foodenterprisebuilding.h"
class Restaurant :
	public FoodEnterpriseBuilding
{
private:
	string kind_of_restaurant;
public:

	Restaurant(void)
	{
		kind_of_restaurant = "";
	}
	Restaurant(int maxNumberOfGuests, int ID, string info, string kind)
		: FoodEnterpriseBuilding(maxNumberOfGuests, ID, info)
	{
		kind_of_restaurant = kind;
	}
	~Restaurant(void)
	{
	}

	void SetKind(string kind) { kind_of_restaurant = kind; }
	string GetKind() { return kind_of_restaurant; }
};

