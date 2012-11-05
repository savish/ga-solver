//Sonelisiwe Njozela 11272882
//Andrea Chalmers 11256339
#ifndef EQAUTION_H
#define EQAUTION_H

#include "Expression.h"
#include "ExpressionFactory.h"
#include "OperatorFactory.h"
#include "Queue.h"
#include "Stack.h"

#include <string>

using namespace std;

class Equation
{
	public:
		Equation(string eq);//If an equation is invalid, throw an exception string
		Equation(const Equation& other);
		Equation& operator=(const Equation& other);
		~Equation();
		int evaluateRHS();//If at least one variable does not have a value, throw an exception string
		int evaluateLHS();//If at least one variable does not have a value, throw an exception string
		void instantiateVariable(char name, int value);//If does not exist in the equation, throw an exception string
		int RHSdistanceFromLHS();//If at least one variable does not have a value, throw an exception string
		
		vector<string> getVariableNames() { return variableNames; } // returns the names of the variables in the equation


	private:
		Expression* left;//Left side of the equals
		Expression* right;//Right side of the equals	
		
		int rhsValue, lhsValue, variableCounter;
		string localEquation;
		bool IsValidEquation(string eqn);
		int EvaluateRPNExpression(Queue rpnExpression);
		Queue CreateRPNExpression(Expression inputExpression);
		Expression *ParseEquationToExpression(string toSplit);
		vector<string> variableNames;

};

#endif
