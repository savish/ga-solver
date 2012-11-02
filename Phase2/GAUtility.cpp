#include "GAUtility.h"

namespace GAUtility
{
	double GenerateRandomProbability(int seedMod)
	{
		double ans;
		srand(time(NULL));
		ans = rand()/(7329.1398+(seedMod*5));
		ans = ans - (int)ans;
		return ans;
	}
	
	int GenerateRandomNumber(int min, int max, int seedMod)
	{
		return (int)(min + (GAUtility::GenerateRandomProbability(seedMod) * (max-min)));
	}
}