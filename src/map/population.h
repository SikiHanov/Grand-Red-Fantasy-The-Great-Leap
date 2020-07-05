#pragma once

//class Population is used in class Area
class Population
{
public:
	bool mfAddPopulation(unsigned int pNumber);
	bool mfCutPopulation(unsigned int pNumber);
private:
	unsigned int mPopulation;
};