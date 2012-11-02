#include "ParentUnit.h"

ChromosomeList ParentUnit::Reproduce(int crossoverPoints)
{
	ChromosomeList offspring;
	bool crossoverFlag = false;
	
	int indexSwitch = parents[0].size() / (crossoverPoints + 1);
	int indexSwitchCounter = 0;
	int crossoverPointsCounter = 0;
	
	for (int ix = 0; ix < parents[0].size(); ix++)
	{
		// Make this happen only crossoverPoints number of times
		
		if (crossoverFlag)
		{
			offspring[0].AddGene(*parents[1].getGene(ix));
			offspring[1].AddGene(*parents[0].getGene(ix));
		}
		else
		{
			offspring[0].AddGene(*parents[0].getGene(ix));
			offspring[1].AddGene(*parents[1].getGene(ix));
		}
		
		while (crossoverPointsCounter < crossoverPoints) 
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
	
	return offspring;
}