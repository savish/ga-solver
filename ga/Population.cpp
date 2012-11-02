#include "Population.h"

void Population::SelectParents(int numberOfPairs)
{
	RankFitness();
	
	int populationMaxIndex = numberOfPairs * 2 - 1; // n-1
	int pairLimit; //r
	int parent1ix, parent2ix;
	
	for (int ix = 0; ix < numberOfPairs; ix++)
	{
		pairLimit = GAUtility::GenerateRandomNumber(0,populationMaxIndex,0); //r
		parent1ix = GAUtility::GenerateRandomNumber(0,pairLimit,-7);
		parent2ix = GAUtility::GenerateRandomNumber(0,pairLimit,5);
	
		ParentUnit parentPair;
	
		parentPair.AddParent(population[parent1ix]);
		parentPair.AddParent(population[parent2ix]);
	
		parents.push_back(parentPair);
	}
}

void Population::SwapChromosomes(int i, int j)
{
	Chromosome temp = population[i];
	population[i] = population[j];
	population[j] = temp;
	
}

void Population::RankFitness()
{
	bool swapped = false;
	do
	{
		swapped = false;
		for (int i=0; i < population.size()-1; i++)
		{
			if (population[i+1].getFitness() < population[i].getFitness())
			{
				SwapChromosomes((i+1),i);
				swapped = true;
			}
		}
	}
	while (swapped);
}