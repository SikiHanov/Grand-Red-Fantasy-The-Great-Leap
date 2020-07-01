#pragma once
#include <list>
#include <map>
#include <string>
#include <vector>
#include <memory>
#include "build.h"
#include "IDconstructor.h"
using namespace std;

//sector.h is mainly used to preserve geographic information
//class: MainCity, Area, Sector, SectorMap

// MainCity class is the top layer of City Control System
// A MainCity class contain several Sector and a SectorMap displayed correlation between sectors
class MainCity
{
	string mCityName;
	list<Sector> mSectorList;

};

// LandType is used to distinguish the use-type of Area in Sector
// LandType will decide the BuildingCapacity of Area
// Some of LandTypes will have the special building Chunk
enum LandType
{
	WASTERLAND = 0,
	PLAIN = 1,
	FIELD = 2,
	RIVER = 3,
	LAKES = 4,
	HILLS = 5,
	FOREST = 6,
	MOUNTAIN = 7,

	MARSH = 8,
	RAINFOREST = 9,
	DESERT = 10

};

//class Area is used to preserve important parameter of Area,such as iChunk, iCapacity and iBuildingCapacity
//iBulidingChunk is used to stand for building capacity
//iIndustryChunk is used to stand for industry chunk capacity( such as Minning, farming and manufition)
//iNatureChunk is used to stand for nature chunk (such as undeveloped forest and ore field)
//iTotalCapacity is used to stand for total capacity that can be used to divide into building chunk ,iNatureChunk or industry chunk

class Area 
{
public:
	//default constructor
	Area(LandType pType = WASTERLAND)
	{
		mAreaLandType = pType;
		iBuildingChunk = 0;
		iIndustryChunk = 0;
		iTotalCapacity = 0;

		AreaID = MainIDConstructor.mfGetAreaID();
	}

	//constructor with parameter
	Area(LandType pType, unsigned int pBuildingChunk, unsigned int pIndustryChunk, unsigned int pTotalCapacity)
	{
		mAreaLandType = pType;
		iBuildingChunk = pBuildingChunk;
		iIndustryChunk = pIndustryChunk;
		iTotalCapacity = pTotalCapacity;

		AreaID = MainIDConstructor.mfGetAreaID();
	}

	//copy constructor
	Area(Area& pArea)
	{
		mAreaLandType = pArea.mAreaLandType;
		iBuildingChunk = pArea.iBuildingChunk;
		iIndustryChunk = pArea.iIndustryChunk;
		iTotalCapacity = pArea.iTotalCapacity;
		mBuildingVector = pArea.mBuildingVector;

		AreaID = MainIDConstructor.mfGetAreaID();
	}

	bool SetName(string pName) { AreaName = pName; return true; }
private:
	vector<BuildingType> mBuildingVector;	//preserve current buliding list
	LandType mAreaLandType;					//LandType of currentArea

	string AreaName;
	unsigned int AreaID;					//unique ID it will never change

	unsigned int iBuildingChunk;
	unsigned int iIndustryChunk;
	unsigned int iNatureChunk;
	unsigned int iTotalCapacity;		//iBuildingChunk + iIndustryChunk + iNatureChunk <= iTotalCapacity

};

class Sector
{
public:

private:
	list<Area> mAreaList;
};

class SectorMap
{

};

class LandCapacityRule
{
public:
	LandCapacityRule();


};