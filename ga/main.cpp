#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <ctype.h>
#include "Population.h"
#include "GAUtility.h"
#include "Equation.h"

using namespace std;

#define POP_SIZE 50
#define CHROM_SIZE 4 
#define MUT_PROB 0.15
#define CROSS_POINTS 2
#define RESOLUTION 10
#define MAX_GEN 200

void testGene()
{
	cout << endl << "Gene Tests..." << endl << endl;
	
	Gene *gene;
	string outVal;
	
	cout << "1. Testing full constructor" << endl;
	gene = new Gene(34, "varY");
	outVal = ((gene->getAllele() == 34) && (gene->getName() == "varY")) ? "passed" : "failed";
	cout << "- Test " << outVal << endl << endl;
	
	cout << "2. Testing allele mutator" << endl;
	gene->setAllele(90);
	outVal = (gene->getAllele() == 90) ? "passed" : "failed";
	cout << "- Test " << outVal << endl << endl;
	gene = 0;
}

void testChromosome()
{
	cout << endl << "Chromosome Tests..." << endl << endl;
	
	Chromosome *c;
	string outVal;
	GeneList geneList;
	
	cout << "1. Testing empty constructor" << endl;
	c = new Chromosome();
	outVal = (c != 0) ? "passed" : "failed";
	cout << "- Test " << outVal << endl << endl;
	
	cout << "2. Testing gene addition" << endl;
	c->AddGene(Gene(37, "geneX"));
	outVal = (c->getGene(0)->getName() == "geneX") ? "passed" : "failed";
	cout << "- Test " << outVal << endl << endl;
	c = 0;
	
	cout << "3. Testing gene list constructor" << endl;
	geneList.push_back(Gene(32, "geneW"));
	geneList.push_back(Gene(37, "geneX"));
	geneList.push_back(Gene(31, "geneY"));
	geneList.push_back(Gene(38, "geneZ"));
	c = new Chromosome(geneList);
	outVal = (c->getGene(2)->getAllele() == 31) ? "passed" : "failed";
	cout << "- Test " << outVal << endl << endl;

	cout << "4. Testing iterator" << endl;
	for (Chromosome::iterator gene = c->begin(); gene < c->end(); gene++)
	{
		cout << gene->getName() << endl;
	}
	c = 0;
}

void testParentUnit()
{
	cout << endl << "Parent Unit Tests..." << endl << endl;
	
	ParentUnit *parentUnit;
	GeneList geneList;
	ChromosomeList chromosomeList;
	string outVal;
	
	cout << "1. Testing loaded constructor" << endl;
	geneList.push_back(Gene(32, "geneW"));
	geneList.push_back(Gene(37, "geneX"));
	geneList.push_back(Gene(31, "geneY"));
	geneList.push_back(Gene(38, "geneZ"));
	Chromosome c = Chromosome(geneList);
	chromosomeList.push_back(c);
	parentUnit = new ParentUnit(chromosomeList);
	outVal = (parentUnit->getParent(0)->getGene(2)->getName() == "geneY") ? "passed" : "failed";
	cout << "- Test " << outVal << endl << endl;
	
}

void testPopulation()
{
	cout << endl << "Population Tests..." << endl << endl;
	
	Population *population;
	GeneList geneList;
	ChromosomeList chromosomeList;
	string outVal;
	
	cout << "1. Testing loaded constructor" << endl;
	geneList.push_back(Gene(32, "geneW"));
	geneList.push_back(Gene(37, "geneX"));
	geneList.push_back(Gene(31, "geneY"));
	geneList.push_back(Gene(38, "geneZ"));
	Chromosome c = Chromosome(geneList);
	chromosomeList.push_back(c);
	population = new Population(chromosomeList);
	outVal = (population->getChromosome(0)->getGene(2)->getName() == "geneY") ? "passed" : "failed";
	cout << "- Test " << outVal << endl << endl;
}

int main(int argc, char** argv)
{
	// testGene();
	// testChromosome();
	// testParentUnit();
	// testPopulation();
	
	bool readingEquations = false;
	
	string line;
	string extract;
	string popSize = "POPULATION SIZE: ";
	string mut = "MUTATION: ";
	string genSize = "GENERATIONS: ";
	string crossPoints = "CROSSOVER POINTS: ";
	string res = "RESOLUTION: ";
	string eqs = "EQUATIONS: ";
	size_t found;
	
	int populationSize = 300;
	double mutation = 0.05;
	int generationSize = 5000;
	int crossoverPoints = 20;
	int resolution = 100;
	vector<string> equations;
	
	int chromosomeSize = 4;
	
	// Read and initialise parameters
	
	ifstream inputFile;
	inputFile.open("input.txt");
	
	if (!inputFile.is_open())
	{
		cout << "Unable to open the specified input file." << endl;
		return 1;
	}
	
	while (inputFile.good())
	{
		getline(inputFile, line);
		
		if (!readingEquations)
		{
		
			found = line.find(popSize);
			if (found!=string::npos)
			{	
				extract = line.substr(popSize.length());
				stringstream ss(extract);
				ss >> populationSize;
			}
		
			found = line.find(mut);
			if (found!=string::npos)
			{	
				extract = line.substr(mut.length());
				stringstream ss(extract);
				ss >> mutation;
			}
		
			found = line.find(genSize);
			if (found!=string::npos)
			{	
				extract = line.substr(genSize.length());
				stringstream ss(extract);
				ss >> generationSize;
			}
		
			found = line.find(crossPoints);
			if (found!=string::npos)
			{	
				extract = line.substr(crossPoints.length());
				stringstream ss(extract);
				ss >> crossoverPoints;
			}
		
			found = line.find(res);
			if (found!=string::npos)
			{	
				extract = line.substr(res.length());
				stringstream ss(extract);
				ss >> resolution;
			}
		
			found = line.find(eqs);
			if (found!=string::npos)
			{	
				readingEquations = true;
			}
		}
		else // reading equations
		{
			if (line.length() > 2)
				equations.push_back(line.substr(0,line.length()));
		}
		
	}
	
	// --
	// display values read in from text file
	// --
	
	cout << endl << popSize << populationSize << endl;
	cout << mut << mutation << endl;
	cout << genSize << generationSize << endl;
	cout << crossPoints << crossoverPoints << endl;
	cout << res << resolution << endl;
	cout << eqs << endl;
	
	for (int ix = 0; ix < equations.size(); ix++)
		cout << "\t" << equations[ix] << endl;
	
	cout << endl;
	
	// --
	
	vector<Equation *> inputEquations;
	Equation *eq;
	
	for (int ix = 0; ix < equations.size(); ix++)
	{
		eq = new Equation(equations[ix]);
		inputEquations.push_back(eq);
	}
	
	vector<string> allVariables;
	vector<string> uniqueVariables;
	
	// Identify variables
	for (int ix = 0; ix < inputEquations.size(); ix++)
	{
		for (int iix = 0; iix < inputEquations[ix]->getVariableNames().size(); iix++)
		{
			allVariables.push_back(inputEquations[ix]->getVariableNames()[iix]);
		}
	}
	
	for (int ix = 0; ix < allVariables.size(); ix++)
	{
		if (ix == 0) 
		{ 
			if (isalpha(allVariables[ix][0])) { uniqueVariables.push_back(allVariables[ix]); }
		}
		else
		{
			found = false;
			for (int iix = 0; iix < uniqueVariables.size(); iix++)
			{
				if (allVariables[ix] == uniqueVariables[iix]) { found = true; }
			}
			if (!found)
			{
				if (isalpha(allVariables[ix][0])) { uniqueVariables.push_back(allVariables[ix]); }
			} 
		}
	}
	
	chromosomeSize = uniqueVariables.size();
	
	try 
	{
	
		Population P;
		Population O;
	
		for (int ix = 0; ix < populationSize; ix++)
		{
			P.AddChromosome(*Chromosome::GenerateRandom(chromosomeSize,ix, uniqueVariables));
		}
		
		int G = 0;
		int res = 1;
		bool found = false;
		ChromosomeList cl;
	
		while (G < generationSize && found == false)	
		{
	
			for (int ix = 0; ix < populationSize; ix++)
			{
				P.getChromosome(ix)->EvaluateFitness(inputEquations);
			}
	
			P.RankFitness();
			
			
			if (res == resolution)
			{
				cout << endl << endl;
				cout << "Generation: " << G+1 << endl;
				cout << "Chromomsome: " << endl;
				for (int ix = 0; ix < chromosomeSize; ix++)
				{
					cout << P.getChromosome(0)->getGene(ix)->getName() << " = " << P.getChromosome(0)->getGene(ix)->getAllele() << endl;
				}
				cout << endl << "Fitness: " << P.getChromosome(0)->getFitness() << endl;
				cout << endl << "Solution: " << endl;
				
				for (int ix = 0; ix < inputEquations.size(); ix++)
				{
					for (int ixGene = 0; ixGene < chromosomeSize; ixGene++)
					{
						try
						{
							inputEquations[ix]->instantiateVariable(P.getChromosome(0)->getGene(ixGene)->getName()[0],P.getChromosome(0)->getGene(ixGene)->getAllele());
						} catch(string ex) { }
					}
					cout << inputEquations[ix]->evaluateLHS() << " = " << inputEquations[ix]->evaluateRHS() << endl;
				}
				
				res = 0;
			}
			
			
			/*
			
			for (int ix = 0; ix < populationSize; ix++)
			{
		
				cout << "[";
				for (int jx = 0; jx < chromosomeSize; jx++)
				{
					cout << P.getChromosome(ix)->getGene(jx)->getName() << ":" << P.getChromosome(ix)->getGene(jx)->getAllele();
					if (jx < chromosomeSize-1)
						cout << ",";
				}
				cout << "] : " << P.getChromosome(ix)->getFitness() << endl;
			}
			
			*/
			
			if (P.getChromosome(0)->getFitness() == 0 ) { found = true; }
			
			P.SelectParents(populationSize/2);
			
			/*
			cout << endl << endl;

			for (int ix = 0; ix < populationSize/2; ix++)
			{
		
				cout << "[";
				for (int jx = 0; jx < chromosomeSize; jx++)
				{
					cout << P.getParentUnit(ix)->getParent(0)->getGene(jx)->getName() << ":" << P.getParentUnit(ix)->getParent(0)->getGene(jx)->getAllele();
					if (jx < chromosomeSize-1)
						cout << ",";
				}
				cout << "] ";
				cout << "[";
				for (int jx = 0; jx < chromosomeSize; jx++)
				{
					cout << P.getParentUnit(ix)->getParent(1)->getGene(jx)->getName() << ":" << P.getParentUnit(ix)->getParent(1)->getGene(jx)->getAllele();
					if (jx < chromosomeSize-1)
						cout << ",";
				}
				cout << "]" << endl;
			}
			
			cout << endl << endl;
			*/
			
			for (int ix = 0; ix < (populationSize/2); ix++)
			{
				cl = P.getParentUnit(ix)->Reproduce(crossoverPoints);
				O.AddChromosome(cl[0]);
				O.AddChromosome(cl[1]);
			}
			
			/*
			for (int ix = 0; ix < populationSize; ix++)
			{
		
				cout << "[";
				for (int jx = 0; jx < chromosomeSize; jx++)
				{
					cout << O.getChromosome(ix)->getGene(jx)->getName() << ":" << O.getChromosome(ix)->getGene(jx)->getAllele();
					if (jx < chromosomeSize-1)
						cout << ",";
				}
				cout << "] : " << O.getChromosome(ix)->getFitness() << endl;
			}
			

			cout << endl << endl;
			*/
			
			for (int ix = 0; ix < populationSize; ix++)
			{
				for (int iix = 0; iix < chromosomeSize; iix++)
				{
					O.getChromosome(ix)->getGene(iix)->Mutate(mutation,ix+(ix*iix));
				}
			}
			
			/*
			
			for (int ix = 0; ix < populationSize; ix++)
			{
		
				cout << "[";
				for (int jx = 0; jx < chromosomeSize; jx++)
				{
					cout << O.getChromosome(ix)->getGene(jx)->getName() << ":" << O.getChromosome(ix)->getGene(jx)->getAllele();
					if (jx < chromosomeSize-1)
						cout << ",";
				}
				cout << "] : " << O.getChromosome(ix)->getFitness() << endl;
			}
			
			*/
			

			
			P = O;
			O.clearPopulation();
			
			G++;
			res++;
		}
		
		/*
		cout << endl; 
		// View genes
		for (int ix = 0; ix < populationSize; ix++)
		{
		
			cout << "[";
			for (int jx = 0; jx < chromosomeSize; jx++)
			{
				cout << parents->getChromosome(ix)->getGene(jx)->getName() << ":" << parents->getChromosome(ix)->getGene(jx)->getAllele();
				if (jx < chromosomeSize-1)
					cout << ",";
			}
			cout << "] : " << parents->getChromosome(ix)->getFitness() << endl;
		}
		*/
		
	} 
	catch (string ex) 
	{
		cout << ex << endl;
	}
	// inputFile.close();
}
