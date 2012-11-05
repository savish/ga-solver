#include "Gene.h"

void Gene::Mutate(double mutationProbability, int seedmod)
{
	double randGen = GAUtility::GenerateRandomProbability(seedmod);
	if (randGen < mutationProbability)
	{
		allele = GAUtility::GenerateRandomNumber(-20,20,seedmod);
	}
}