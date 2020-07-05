#include "population.h"

//Add  pNumber to mPopulation
bool Population::mfAddPopulation(unsigned int pNumber)
{
	mPopulation = mPopulation + pNumber;
	return true;
}

//Subtract pNumber from mPopulation
bool Population::mfCutPopulation(unsigned int pNumber)
{
	if (mPopulation < pNumber)
		return false;

	mPopulation = mPopulation - pNumber;
	return true;
}