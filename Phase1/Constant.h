//Sonelisiwe Njozela 11272882
//Andrea Chalmers 11256339
#ifndef CONSTANT_H
#define CONSTANT_H

#include "Expression.h"

class Constant : public Expression
{
public:
	Constant() : Expression("") { type = CONSTANT; }
	Constant(int value) : Expression(value) { type = CONSTANT; }
};

#endif