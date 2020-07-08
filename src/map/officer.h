#pragma once
#include "include.h"

class Officer
{
public:
	bool mfSetName(string pName) { mName = pName; return true; }
private:
	string mName;
};