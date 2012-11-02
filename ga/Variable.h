//Sonelisiwe Njozela 11272882
//Andrea Chalmers 11256339
#ifndef VARIABLE_H
#define VARIABLE_H

#include "Expression.h"

class Variable : public Expression
{
private:
	bool instantiated;

public:
	Variable() : Expression(), instantiated(false) { type = VARIABLE; }
	Variable(std::string name) : Expression(name), instantiated(false) { type = VARIABLE; }
	bool IsInstantiated() { return instantiated; }
	void SetValue(int inputVal) { value = inputVal; }

	virtual int Value();
};

#endif