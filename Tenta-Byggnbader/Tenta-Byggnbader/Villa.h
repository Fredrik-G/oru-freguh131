#pragma once
#include "residentialbuilding.h"
class Villa :
	public ResidentialBuilding
{
public:

	Villa(void)
	{
	}
	Villa(int ID, string info) : ResidentialBuilding(ID, info)
	{

	}
	~Villa(void)
	{
	}
};

