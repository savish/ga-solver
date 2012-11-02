#ifndef PARENTUNIT_H
#define PARENTUNIT_H

#include <vector>
#include "Chromosome.h"

typedef std::vector<Chromosome> ChromosomeList;

class ParentUnit
{
private:
	ChromosomeList parents;
	
public:
	ParentUnit() {}
	ParentUnit(ChromosomeList parents) : parents(parents) { }
	
	Chromosome *getParent(int index) { return &parents[index]; }
	void AddParent(Chromosome parent) { parents.push_back(parent); }
	ChromosomeList getParents() { return parents; }
	
	ChromosomeList Reproduce(int crossoverPoints);
};

#endif