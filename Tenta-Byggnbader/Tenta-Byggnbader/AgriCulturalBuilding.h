#pragma once
#include "building.h"
class AgriCulturalBuilding :
	public Building
{
public:

	AgriCulturalBuilding(void)
	{
	}
	AgriCulturalBuilding(int ID, string info) : Building(ID, info)
	{
	}
	~AgriCulturalBuilding(void)
	{
	}
};

