#include "Chromosome.h"

using namespace std;

void Chromosome::EvaluateFitness(vector<Equation> equations)
{
	
	int sum = 0;
	
	for (int ix = 0; ix < equations.size(); ix++)
	{
		for (int ixGene = 0; ixGene < genes.size(); ixGene++)
		{
			try
			{
				equations[ix].instantiateVariable(genes[ixGene].getName()[0],genes[ixGene].getAllele())
			} catch(string ex) { }
		}
		sum = sum + abs(equations[ix].RHSdistanceFromLHS());
	}
	fitness = sum;
	
	/*
	int ans = 0;
	
	for (int ix = 1; ix < genes.size(); ix++)
	{
		ans = ans + abs(genes[ix].getAllele() - genes[ix-1].getAllele());
	}
	fitness = ans;
	*/
	
}

// Seedmod is passed by the calling loop (it is the loop index)
// specifically to ensure that the generated numbers vary.
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
