//Sonelisiwe Njozela 11272882
//Andrea Chalmers 11256339
#ifndef OPERATORFACTORY_H
#define OPERATORFACTORY_H

#include <string>
#include "Operator.h"

namespace OperatorFactory
{
	int OperatorPrecedence(std::string operatorName);
	Operator CreateOperator(std::string operatorName);
}

#endif