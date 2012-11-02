//Sonelisiwe Njozela 11272882
//Andrea Chalmers 11256339
#include "OperatorFactory.h"

using namespace std;

namespace OperatorFactory
{
	int OperatorPrecedence(string operatorName)
	{
		if ((operatorName == "+") ||
			(operatorName == "-"))
		{ 
			return 1; 
		}
		else if ((operatorName == "*")||
			(operatorName == "/"))
		{ 
			return 2; 
		}
		else if ((operatorName == "^") ||
			(operatorName == "max") ||
			(operatorName == "log") ||
			(operatorName == "abs") ||
			(operatorName == "sqrt"))
		{ 
			return 3; 
		}
		else return 0;
	}



	Operator CreateOperator(string operatorName)
	{
		if ((operatorName == "+") ||
			(operatorName == "-") ||
			(operatorName == "/") ||
			(operatorName == "*") ||
			(operatorName == "^") ||
			(operatorName == "max"))
		{
			return Operator(operatorName, OperatorPrecedence(operatorName));
		}
		else
		{
			return Operator(operatorName, OperatorPrecedence(operatorName),false);
		}
	}
}