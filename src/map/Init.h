#pragma once
#include <vector>
#include <map>
#include <fstream>
#include <iostream>
#include "build.h"
using namespace std;

//Used only in AreaInitMaps
class LandTypeInitRule
{
public:
	LandTypeInitRule(vector<BuildingType> pSpecBC, vector<IndustryType> pSpecIC, vector<NatureType> pSpecNC,
					unsigned int pBC, unsigned int pIC, unsigned int pNC, unsigned int pCC
					);
	unsigned int mfGetBuildingChunk() { return mBuildingChunk; }
	unsigned int mfGetIndustryChunk() { return mIndustryChunk; }
	unsigned int mfGetNatureChunk() { return mNatureChunk; }
	unsigned int mfGetCurrentCapacity() { return mCurrentCapacity; }

	vector<BuildingType> mfGetSpecBuildingChunk() { return mSpecBuildingChunk; }
	vector<IndustryType> mfGetSpecIndustryChunk() { return mSpecIndustryChunk; }
	vector<NatureType> mfGetSpecNatureChunk() { return mSpecNatureChunk; }
private:
	unsigned int mBuildingChunk;
	unsigned int mIndustryChunk;
	unsigned int mNatureChunk;
	unsigned int mCurrentCapacity;

	vector<BuildingType> mSpecBuildingChunk;
	vector<IndustryType> mSpecIndustryChunk;
	vector<NatureType> mSpecNatureChunk;
};

//used to initialize class Area, allocate Capatity for Area
//LandTypeID - LandTypeInitRule
map<unsigned int, LandTypeInitRule> _AreaInitMap;

//register of AreaInitMap
bool RegisterInit()
{
	fstream AreaInitFile;
	AreaInitFile.open("//Init//AreaInit.txt");

	string temp;
	while (getline(AreaInitFile, temp))
	{
		unsigned int pBC, pIC, pNC, pCC;
		vector<BuildingType> pSpecBC;
		vector<IndustryType> pSpecIC;
		vector<NatureType> pSpecNC;
		unsigned int pIndex;
		
		string tStr;

		for (string::iterator iter = temp.begin(); iter != temp.end(); iter++)
		{
			//index
			if (*iter == '$')
			{
				iter++;
				auto current = iter;
				while (*current!=' ')
				{
					tStr.push_back(*current);
					current++;
				}

				pIndex = atoi(tStr.c_str());
				iter = current + 1;
			}
			tStr.clear();

			//pBC
			if (*iter == '%')
			{
				iter++;
				auto current = iter;
				while (*current != ' ')
				{
					tStr.push_back(*current);
					current++;
				}

				pBC = atoi(tStr.c_str());
				iter = current + 1;
			}
			tStr.clear();

			//pIC
			if (*iter == '%')
			{
				iter++;
				auto current = iter;
				while (*current != ' ')
				{
					tStr.push_back(*current);
					current++;
				}

				pIC = atoi(tStr.c_str());
				iter = current + 1;
			}
			tStr.clear();

			//pNC
			if (*iter == '%')
			{
				iter++;
				auto current = iter;
				while (*current != ' ')
				{
					tStr.push_back(*current);
					current++;
				}

				pNC = atoi(tStr.c_str());
				iter = current + 1;
			}
			tStr.clear();

			//pCC
			if (*iter == '%')
			{
				iter++;
				auto current = iter;
				while (*current != ' ')
				{
					tStr.push_back(*current);
					current++;
				}

				pCC = atoi(tStr.c_str());
				iter = current + 1;
			}
			tStr.clear();

			//pSpecBC
			if (*iter == '#')
			{
				iter++;
				auto current = iter;
				while (*current != ' ' && *current != '#')
				{
					if (*current == '-')
					{
						pSpecBC.push_back(atoi(tStr.c_str));
						tStr.clear();
					}
					else
					{
						tStr.push_back(*current);
					}
					current++;
				}

				if(tStr.size()!=0)
					pSpecBC.push_back(atoi(tStr.c_str));
				iter = current + 1;
			}
			tStr.clear();

			//pSpecIC
			if (*iter == '#')
			{
				iter++;
				auto current = iter;
				while (*current != ' ' && *current != '#')
				{
					if (*current == '-')
					{
						pSpecIC.push_back(atoi(tStr.c_str));
						tStr.clear();
					}
					else
					{
						tStr.push_back(*current);
					}
					current++;
				}

				if (tStr.size() != 0)
					pSpecIC.push_back(atoi(tStr.c_str));
				iter = current + 1;
			}
			tStr.clear();

			//pSpecNC
			if (*iter == '#')
			{
				iter++;
				auto current = iter;
				while (*current != ' ' && *current != '#')
				{
					if (*current == '-')
					{
						pSpecNC.push_back(atoi(tStr.c_str));
						tStr.clear();
					}
					else
					{
						tStr.push_back(*current);
					}
					current++;
				}

				if (tStr.size() != 0)
					pSpecNC.push_back(atoi(tStr.c_str));
				iter = current + 1;
			}
			tStr.clear();

		}

		_AreaInitMap.insert(pair<unsigned int,LandTypeInitRule>(pIndex, LandTypeInitRule(pSpecBC,pSpecIC,pSpecNC,pBC,pIC,pNC,pCC)));
	}

	AreaInitFile.close();

	return true;
}

//