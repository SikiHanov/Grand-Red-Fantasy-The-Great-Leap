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

//constructor of BuildingType
BuildingType::BuildingType(unsigned int pTypeID, unsigned int pCapacity)
{
	mTypeID = pTypeID;
	mCapacity = pCapacity;
}

//constructor of IndustryType
IndustryType::IndustryType(unsigned int pTypeID, unsigned int pProductID, unsigned int pProduction, unsigned int pWorker)
{
	mTypeID = pTypeID;
	mProductID = pProductID;
	mProduction = pProduction;
	mWorker = pWorker;
}

//