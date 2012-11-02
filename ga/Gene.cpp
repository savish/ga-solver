#include "Gene.h"

void Gene::Mutate(double mutationProbability)
{
	double randGen = GAUtility::GenerateRandomProbability(0);
	if (randGen < mutationProbability)
	{
		allele = GAUtility::GenerateRandomNumber(-20,20,0);
	}
}