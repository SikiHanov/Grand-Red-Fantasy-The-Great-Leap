#pragma once
#include "include.h"

/*
enum BuildingType
{
	Hut = 1,
	Cabana = 2,
};

enum IndustryType 
{
	LoggingCamp = 1,

	FarmLand = 5,

};

enum NatureType 
{
	Barren = 0,
	Grass = 1,
	Tree = 2,
};
*/

class BuildingType
{
public:
	BuildingType(unsigned int pTypeID,unsigned int pCapacity);

	bool operator==(BuildingType rVal);

private:
	unsigned int mTypeID;

	unsigned int mCapacity;	//Population capacity provided by buildings

};

class IndustryType
{
public:
	IndustryType(unsigned int pTypeID, unsigned int pProductID, unsigned int pProduction, unsigned int pWorker);

	bool operator==(IndustryType rVal);
private:
	unsigned int mTypeID;
	unsigned int mProductID;	//productID
	unsigned int mProduction;	//production of the IndustryChunk

	unsigned int mWorker;		//Number of workers needed to run the factory
};

class NatureType
{
public:
	NatureType(unsigned int pTypeID) { mTypeID = pTypeID; }

	bool operator==(NatureType rVal);
private:
	unsigned int mTypeID;
};

//All of BuildingType
list<BuildingType> _BuildingTypeList;

//All of IndustryType
list<IndustryType> _IndustryTypeList;

//All of NatureType
list<NatureType> _NatureTypeList;

map<unsigned int, BuildingType> _BuildingTypeMap;
map<unsigned int, IndustryType> _IndustryTypMap;
map<unsigned int, NatureType> _NatureTypeMap;