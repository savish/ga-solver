//Sonelisiwe Njozela 11272882
//Andrea Chalmers 11256339
#ifndef EXPRESSIONFACTORY_H
#define EXPRESSIONFACTORY_H

#include <cctype>

#include "Expression.h"
#include "Constant.h"
#include "Variable.h"
#include "Operator.h"
#include "OperatorFactory.h"

namespace ExpressionFactory 
{
	Expression CreateExpression(std::string inputVal);
	bool IsOperator(std::string inputVal);
};

#endif