#include "Init.h"

LandTypeInitRule::LandTypeInitRule( vector<BuildingType> pSpecBC, vector<IndustryType> pSpecIC, vector<NatureType> pSpecNC,
									unsigned int pBC, unsigned int pIC, unsigned int pNC, unsigned int pCC
									)
{
	mSpecBuildingChunk = pSpecBC;
	mSpecIndustryChunk = pSpecIC;
	mSpecNatureChunk = pSpecNC;

	mBuildingChunk = pBC;
	mIndustryChunk = pIC;
	mNatureChunk = pNC;
	mCurrentCapacity = pCC;
}