#ifndef POPULATION_H
#define POPULATION_H

#include <vector>
#include "ParentUnit.h"

typedef std::vector<ParentUnit> ParentUnitList;

class Population
{
private:
	ChromosomeList population;
	ParentUnitList parents;
	
	void SwapChromosomes(int i, int j);
	
public:
	Population() { }
	Population(ChromosomeList population) : population(population) { }
	
	Chromosome *getChromosome(int index) { return &population[index]; }
	void AddChromosome(Chromosome inputChromosome) { population.push_back(inputChromosome); }
	ChromosomeList getPopulation() { return population; }
	ParentUnit *getParentUnit(int index) { return &parents[index]; }
	void clearPopulation() { population.clear(); }
	
	void SelectParents(int numberOfPairs);
	void RankFitness();
	
	typedef ChromosomeList::iterator iterator;
	typedef ChromosomeList::const_iterator const_iterator;
	iterator begin() { return population.begin(); }
	iterator end() { return population.end(); }
	
	Population& operator=(const Population& other);
	
};

#endif