//Sonelisiwe Njozela 11272882
//Andrea Chalmers 11256339
#include "ExpressionFactory.h"

using namespace std;

namespace ExpressionFactory 
{
	Expression CreateExpression(string inputVal)
	{
		Expression result;

			// TODO: brackets
		if (GAUtility::IsNumber(inputVal))
			{
				result = Constant(GAUtility::ConvertToInt(inputVal));
			}
			else if(ExpressionFactory::IsOperator(inputVal)) 
			{
				result = OperatorFactory::CreateOperator(inputVal);
			}
			else 
			{
				result = Variable(inputVal);
			}
		// TODO: other operators

		return result;
	}

	bool IsOperator(string inputVal) 
	{
		if ((inputVal == "+") || 
			(inputVal == "-") || 
			(inputVal == "/") || 
			(inputVal == "*") ||
			(inputVal == "^") ||
			(inputVal == "sqrt") ||
			(inputVal == "log") ||
			(inputVal == "max") ||
			(inputVal == "abs") ||
			(inputVal == "(") ||
			(inputVal == ")") ||
			(inputVal == ","))
		{
			return true;
		}
		else
			return false;
	}
}