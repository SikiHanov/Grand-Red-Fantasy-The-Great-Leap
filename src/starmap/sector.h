#pragma once
#include <list>
#include <map>
using namespace std;


class StarMap
{
public:
	StarMap();
	StarMap(int iSize);
	StarMap(const StarMap &tarMap);
	map<int,StarDomain> getMapInfo();
	StarDomain getMapDomainInfo(int id);
private:
	map<int,StarDomain> mDomainMap;
};

class StarDomain
{
public:
	StarDomain();
	StarDomain(int iSize);
	StarDomain(const StarDomain &tarDomain);
	map<int, StarDomain> getDomainInfo();
	StarSector getDomainSectorInfo(int id);
private:
	map<int, StarSector> mSectorMap;
};

enum sectorType { solar = 0, gaia = 1, moon = 2, belt = 3, planet = 4, structure = 5, spacemark = 6, };

class StarSector
{
public:
	int id;
	int iSize;
	int iDomainId;
	sectorType emType;

	virtual void getSectorInfo() ;
	virtual void getSectorConn() ;
private:

};

class StarColonySector : public StarSector
{
public:

private:

};

class StarUnownedSector : public StarSector
{
public:

private:

};