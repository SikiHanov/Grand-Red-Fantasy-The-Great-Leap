#pragma once
#include <string>
using namespace std;

class Officer
{
public:
	bool mfSetName(string pName) { mName = pName; return true; }
private:
	string mName;
};