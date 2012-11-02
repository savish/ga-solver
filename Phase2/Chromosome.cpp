#include "Chromosome.h"

void Chromosome::EvaluateFitness()
{
	int ans = 0;
	
	for (int ix = 1; ix < genes.size(); ix++)
	{
		ans = ans + abs(genes[ix].getAllele() - genes[ix-1].getAllele());
	}
	fitness = ans;
}

Chromosome *Chromosome::GenerateRandom(int size, int seedMod)
{
	Chromosome *ans = new Chromosome();
	
	for (int i=0; i<size; i++)
	{
		seedMod = GAUtility::GenerateRandomNumber(-20,20,seedMod);
		ans->AddGene(Gene(seedMod,""));
	}
	return ans;
}
