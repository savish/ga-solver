#ifndef CHROMOSOME_H
#define CHROMOSOME_H

#include <cmath>
#include <vector>
#include "Gene.h"
#include "GAUtility.h"
#include "Equation.h"

typedef std::vector<Gene> GeneList;

class Chromosome
{	
private:
	GeneList genes;	
	int fitness;
	
public:
	Chromosome() {}
	Chromosome(GeneList genes): genes(genes) {}
	static Chromosome *GenerateRandom(int size, int seedMod);
	
	GeneList getGenes() { return genes; }
	Gene *getGene(int index) { return &genes[index]; }
	void setGeneAtIndex(int index, Gene geneToSet) { genes[index] = geneToSet; }
	void AddGene(Gene geneToAdd) { genes.push_back(geneToAdd); }
	int getFitness() { return fitness; }
	
	typedef GeneList::iterator iterator;
	typedef GeneList::const_iterator const_iterator;
	iterator begin() { return genes.begin(); }
	iterator end() { return genes.end(); }
	
	void EvaluateFitness();
};

#endif