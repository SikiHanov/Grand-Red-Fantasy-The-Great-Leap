#pragma once
#include <list>
#include <map>
#include <string>
#include <vector>
#include <memory>
#include <algorithm>
#include "build.h"
#include "IDconstructor.h"
#include "population.h"
#include "Init.h"
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

//ChunkType is used to distinguish the type of chunk
//will be used in function pfSearchChunk(ChunkType pType)
enum ChunkType
{
	Building = 0,
	Industry = 1,
	Nature = 2
};

//class Area is used to preserve important parameter of Area,such as iChunk, iCapacity and iBuildingCapacity
//mBulidingChunk is used to stand for building capacity
//mIndustryChunk is used to stand for industry chunk capacity( such as Minning, farming and manufition)
//mNatureChunk is used to stand for nature chunk (such as undeveloped forest and ore field)
//mTotalCapacity is used to stand for total capacity that can be used to divide into building chunk ,iNatureChunk or industry chunk

class Area 
{
public:
	//default constructor
	Area(unsigned int pTypeID)
	{
		mAreaLandTypeID = pTypeID;

		auto iter = _AreaInitMap[pTypeID];

		mBuildingChunk = iter.mfGetBuildingChunk;
		mIndustryChunk = iter.mfGetIndustryChunk;
		mNatureChunk = iter.mfGetNatureChunk;
		mCurrentCapacity = iter.mfGetCurrentCapacity;

		mBuildingChunk = iter.mfGetSpecBuildingChunk;
		mIndustryChunk = iter.mfGetSpecIndustryChunk;
		mNatureChunk = iter.mfGetSpecNatureChunk;

		AreaID = MainIDConstructor.mfGetAreaID();
	}

	//copy constructor
	Area(Area& pArea)
	{
		mAreaLandTypeID = pArea.mAreaLandTypeID;
		mBuildingChunk = pArea.mBuildingChunk;
		mIndustryChunk = pArea.mIndustryChunk;
		mCurrentCapacity = pArea.mCurrentCapacity;

		mBuildingVector = pArea.mBuildingVector;
		mIndustryVector = pArea.mIndustryVector;
		mNatureVector = pArea.mNatureVector;

		AreaID = MainIDConstructor.mfGetAreaID();
	}

	bool mfSetName(string pName) { mAreaName = pName; return true; }

	/*		Area Building Operation		*/
	bool mfBuildBuildingChunk(BuildingType pType);
	bool mfBuildIndustryChunk(IndustryType pType);
	bool mfBuildNatureChunk(NatureType pType);

	bool mfDestroyBuilding(BuildingType pType);
	bool mfDestroyIndustry(IndustryType pType);
	bool mfDestroyNature(NatureType pType);

	/*		Area Population Operation		*/
	bool mfAddPopulation(unsigned int pNumber);
	bool mfCutPopulation(unsigned int pNumber);

//the funtion used by public funtion	
private:
	template<typename T> bool pfSearchChunk(ChunkType pChunk, T pTar);

	bool pfSetBuildingChunk(unsigned int para) { mBuildingChunk = para; return true; }
	bool pfSetIndustryChunk(unsigned int para) { mIndustryChunk = para; return true; }
	bool pfSetNatureChunk(unsigned int para) { mNatureChunk = para; return true; }
	bool pfSetTotalCapacity(unsigned int para) { mCurrentCapacity = para; return true; }

//private member
private:
	vector<BuildingType> mBuildingVector;	//preserve current buliding list
	vector<IndustryType> mIndustryVector;	//preserve current industry list
	vector<NatureType> mNatureVector;		//preserve current nature list

	// LandType is used to distinguish the use-type of Area in Sector
	// LandType will decide the BuildingCapacity of Area
	// Some of LandTypes will have the special building Chunk
	unsigned int mAreaLandTypeID;
	string mAreaName;
	unsigned int AreaID;					//unique ID it will never change

	unsigned int mBuildingChunk;
	unsigned int mIndustryChunk;
	unsigned int mNatureChunk;
	unsigned int mCurrentCapacity;		//mBuildingChunk + mIndustryChunk + mNatureChunk <= mCurrentCapacity

	Population mAreaPopulation;			//mAreaPopulation offer all operation of population
};

class Sector
{
public:

private:
	list<Area> mAreaList;
	unsigned int mCurrentAreaCapacity;	//mCurrentAreaCapacity + mAreaList.size() == totalAreaNum
};

class SectorMap
{

};

