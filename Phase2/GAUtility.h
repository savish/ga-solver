#ifndef GAUTILITY_H
#define GAUTILITY_H

#include <ctime>
#include <cstdlib>

namespace GAUtility
{
	double GenerateRandomProbability(int seedMod);
	int GenerateRandomNumber(int min, int max, int seedMod);
};

#endif