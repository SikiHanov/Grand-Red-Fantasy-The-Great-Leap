#pragma once

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
	BuildingType(unsigned int pTypeID) { mTypeID = pTypeID; }

	bool operator==(BuildingType rVal);

private:
	unsigned mTypeID;
};

class IndustryType
{
public:
	IndustryType(unsigned int pTypeID) { mTypeID = pTypeID; }

	bool operator==(IndustryType rVal);
private:
	unsigned mTypeID;
};

class NatureType
{
public:
	NatureType(unsigned int pTypeID) { mTypeID = pTypeID; }

	bool operator==(NatureType rVal);
private:
	unsigned mTypeID;
};