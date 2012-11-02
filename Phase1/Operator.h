//Sonelisiwe Njozela 11272882
//Andrea Chalmers 11256339
#ifndef OPERATOR_H
#define OPERATOR_H

#include "Expression.h"

class Operator : public Expression
{
private:
	int precedence;
	bool binary, leftAssociative;

public:
	Operator() : Expression(), precedence(1), binary(true), leftAssociative(true) { type = OPERATOR; }
	Operator(std::string name, int precedence = 1, bool binary = true, bool leftAssociative = true) : 
		Expression(name), precedence(precedence), binary(binary), leftAssociative(leftAssociative) { 
			if (name == "(") type = LEFTBRACKET; else if (name == ")") type = RIGHTBRACKET; else if (name == ",") type = COMMA; else type = OPERATOR; }

	int Precedence() { return precedence; }
	bool IsBinary() { return binary; }

	Expression Operate(Expression e1, Expression e2 = 0);
};

#endif