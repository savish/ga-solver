#include "ParentUnit.h"

ChromosomeList ParentUnit::Reproduce(int crossoverPoints)
{
	ChromosomeList offspring;
	Chromosome cl;
	Chromosome cl2;
	
	bool crossoverFlag = false;
	
	int indexSwitch = parents[0].getGenes().size() / (crossoverPoints + 1);
	int indexSwitchCounter = 0;
	int crossoverPointsCounter = 0;
	
	for (int ix = 0; ix < parents[0].getGenes().size(); ix++)
	{
		
		// Make this happen only crossoverPoints number of times
		
		if (crossoverFlag)
		{
			cl.AddGene(*parents[1].getGene(ix));
			cl2.AddGene(*parents[0].getGene(ix));
			//offspring[0].AddGene(*parents[1].getGene(ix));
			//offspring[1].AddGene(*parents[0].getGene(ix));
		}
		else
		{
			cl.AddGene(*parents[0].getGene(ix));
			cl2.AddGene(*parents[1].getGene(ix));
			//offspring[0].AddGene(*parents[0].getGene(ix));
			//offspring[1].AddGene(*parents[1].getGene(ix));
		}
		
		if (crossoverPointsCounter < crossoverPoints) 
		{
			if (indexSwitchCounter==indexSwitch) 
			{
				crossoverFlag = !crossoverFlag;
				indexSwitchCounter = -1;
				crossoverPointsCounter++;
			}	
		}
		
		indexSwitchCounter++;
	}
	
	offspring.push_back(cl);
	offspring.push_back(cl2);
	
	return offspring;
}