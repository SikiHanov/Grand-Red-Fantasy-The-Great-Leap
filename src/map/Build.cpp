#include "build.h"

bool BuildingType::operator==(BuildingType rVal)
{
	if (mTypeID == rVal.mTypeID)
		return true;
	else
		return false;
}

bool IndustryType::operator==(IndustryType rVal)
{
	if (mTypeID == rVal.mTypeID)
		return true;
	else
		return false;
}

bool NatureType::operator==(NatureType rVal)
{
	if (mTypeID == rVal.mTypeID)
		return true;
	else
		return false;
}