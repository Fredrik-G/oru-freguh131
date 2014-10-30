#pragma once
#include "building.h"
class CommercialBuilding :
	public Building
{
public:

	CommercialBuilding(void)
	{
	}
	CommercialBuilding(int ID, string info) : Building(ID, info)
	{

	}
	~CommercialBuilding(void)
	{
	}
};

