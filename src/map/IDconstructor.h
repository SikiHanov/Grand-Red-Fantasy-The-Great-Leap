#pragma once

// ID constructor will offer the unique ID for the constructor of Area, Sector etc. 
// WARNING: DO NOT DECLARE ANY NEW IDConstructor EXCEPT MainIDConstructor


class IDConstructor
{
public:
	unsigned int mfGetAreaID() { return mCurrentAreaID++; }
	unsigned int mfGetSectorID() { return mCurrentSectorID++; }
	unsigned int mfGetOfficerID() { return mCurrentOfficerID++; }
private:
	unsigned int mCurrentAreaID = 10000;
	unsigned int mCurrentSectorID = 1000;
	unsigned int mCurrentOfficerID = 10000;
};

// WARNING: DO NOT DECLARE ANY NEW IDConstructor EXCEPT MainIDConstructor

static IDConstructor MainIDConstructor;

