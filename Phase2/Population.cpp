#include "Population.h"

void Population::SelectParents(int numberOfPairs)
{
	
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