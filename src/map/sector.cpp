#include "sector.h"

/*		class Area		*/

//search a Chunk(class is pChunk,type is pTar)
//if this Chunk in vector, return true
//else return false
template <typename T>
bool Area::pfSearchChunk(ChunkType pChunk, T pTar)
{
	//std::find() (#include <algorith>
	if (pChunk == Building)
	{
		if (find(mBuildingVector.begin(),mBuildingVector.end(), pTar) != mBuildingVector.end())
			return true;
		else
			return false;
	}
	else if (pChunk == Industry)
	{
		if (find(mIndustryVector.begin(), mIndustryVector.end(), pTar) != mIndustryVector.end())
			return true;
		else
			return false;
	}
	else if (pChunk == Nature)
	{
		if(find(mNatureVector.begin(), mNatureVector.end(), pTar) != mNatureVector.end())
			return true;
		else
			return false;
	}
	else
	{
		return false
	}
}

/*		Area Building Operation		*/

//Build a BuildingChunk in Area
bool Area::mfBuildBuildingChunk(BuildingType pType)
{
	if (mCurrentCapacity == 0)
		return false;

	if (mBuildingChunk == 0)
		return false;

	mBuildingVector.push_back(pType);
	mBuildingChunk--;
	mCurrentCapacity--;
	return true;
		
}

//Build a IndustryChunk in Area
bool Area::mfBuildIndustryChunk(IndustryType pType)
{
	if (mCurrentCapacity == 0)
		return false;

	if (mIndustryChunk == 0)
		return false;

	mIndustryVector.push_back(pType);
	mIndustryChunk--;
	mCurrentCapacity--;
	return true;
}

//Build a NatureChunk in Area
bool Area::mfBuildNatureChunk(NatureType pType)
{
	if (mCurrentCapacity == 0)
		return false;

	if (mNatureChunk == 0)
		return false;

	mNatureVector.push_back(pType);
	mNatureChunk--;
	mCurrentCapacity--;
	return true;
}

//Destroy a BuildingChunk in Area
bool Area::mfDestroyBuilding(BuildingType pType)
{
	//std::find() (#include <algorith>
	auto iter = find(mBuildingVector.begin(), mBuildingVector.end(), pType);
	if (iter != mBuildingVector.end())
	{
		mBuildingVector.erase(iter);
		mBuildingChunk++;
		mCurrentCapacity++;
		return true;
	}
	else
		return false;
}

//Destroy a IndustryType in Area
bool Area::mfDestroyIndustry(IndustryType pType)
{
	//std::find() (#include <algorith>
	auto iter = find(mIndustryVector.begin(), mIndustryVector.end(), pType);
	if (iter != mIndustryVector.end())
	{
		mIndustryVector.erase(iter);
		mIndustryChunk++;
		mCurrentCapacity++;
		return true;
	}
	else
		return false;
}

//Destroy a NatureChunk in Area
bool Area::mfDestroyNature(NatureType pType)
{
	//std::find() (#include <algorith>
	auto iter = find(mNatureVector.begin(), mNatureVector.end(), pType);
	if (iter != mNatureVector.end())
	{
		mNatureVector.erase(iter);
		mNatureChunk++;
		mCurrentCapacity++;
		return true;
	}
	else
		return false;
}

//Increase population in Area
bool Area::mfAddPopulation(unsigned int pNumber)
{
	if (mAreaPopulation.mfAddPopulation(pNumber))
		return true;
	else
		return false;
}

//Decrease population in Area
bool Area::mfCutPopulation(unsigned int pNumber)
{
	if (mAreaPopulation.mfCutPopulation(pNumber))
		return true;
	else
		return false;
}

//

//