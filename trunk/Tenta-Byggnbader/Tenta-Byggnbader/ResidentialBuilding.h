#pragma once
#include "building.h"
class ResidentialBuilding :
	public Building
{
public:

	ResidentialBuilding(void)
	{
	}
	ResidentialBuilding(int ID, string info) : Building(ID, info)
	{

	}

	~ResidentialBuilding(void)
	{
	}
};

