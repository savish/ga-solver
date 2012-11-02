#ifndef GENE_H
#define GENE_H

#include <string>
#include "GAUtility.h"

class Gene 
{
private:
	int allele;
	std::string name;
	
public:
	Gene() {}
	Gene(int allele, std::string name): allele(allele), name(name) { }
	
	int getAllele() { return allele; }
	void setAllele(int inputAllele) { allele = inputAllele; }
	std::string getName() { return name; }
	void setName(std::string inputName) { name = inputName; }

	void Mutate(double mutationProbability);
};

#endif