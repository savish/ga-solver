//Sonelisiwe Njozela 11272882
//Andrea Chalmers 11256339
#include "Operator.h"

using namespace std;

Expression Operator::Operate(Expression e1, Expression e2)
{
	if (GAUtility::OperatorIsBinary(name)) 
	{
		if (name == "+") { return e1 + e2; } else 
		if (name == "-") { return e1 - e2; } else 
		if (name == "*") { return e1 * e2; } else 
		if (name == "/") { return e1 / e2; } else 
		if (name == "^") { return e1 ^ e2; } else 
		if (name == "max") { return e1.mxm(e2); } else
			return Expression();
	}
	else
	{
		if (name == "log") { return e1.lgm(); } else 
		if (name == "abs") { return e1.abv(); } else 
		if (name == "sqrt") { return e1.sqt(); } else
			return Expression();
	}
}