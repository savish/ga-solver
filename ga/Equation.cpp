//Sonelisiwe Njozela 11272882
//Andrea Chalmers 11256339
#include "Equation.h"

//Add any implementation you may require for the Equation class here

Equation::Equation(string localEqn)
{
	variableCounter = 0;

	localEquation = (IsValidEquation(localEqn)) ? localEqn 
		: throw string("The specified equation is invalid");

	vector<string> localEquationSplit = GAUtility::SplitString(localEquation,"=");
	
	string tempEqn1 = GAUtility::SpaceString(localEquationSplit[0]);
	string tempEqn2 = GAUtility::SpaceString(localEquationSplit[1]);

	try 
	{
		left = ParseEquationToExpression(tempEqn1);
		right = ParseEquationToExpression(tempEqn2);
	} catch (...)
	{
		throw string("The specified equation is invalid");
	}

}

int Equation::evaluateLHS()
{
	if (variableCounter == 0)

		lhsValue = EvaluateRPNExpression(CreateRPNExpression(*left));
	else
		throw string("There is at least one uninitialised variable in the equation");
	return lhsValue;
}

int Equation::evaluateRHS()
{
	if (variableCounter == 0)
		rhsValue = EvaluateRPNExpression(CreateRPNExpression(*right));
	else
		throw string("There is at least one uninitialised variable in the equation");
	return rhsValue;
}

int Equation::RHSdistanceFromLHS() 
{
	int ans = evaluateRHS() - evaluateLHS();
	ans = (ans<0) ? -1*ans : ans;
	return ans;
	
}

Equation::Equation(const Equation& other)
{	
	rhsValue = other.rhsValue;
	lhsValue = other.lhsValue;
	variableCounter = other.variableCounter;
	localEquation = other.localEquation;

	left = new Expression();
	*left = *other.left;
	right = new Expression();
	*right = *other.right;
	
}

Equation::~Equation()
{
	delete left;
	left = 0;
	delete right;
	right = 0;
}

void Equation::instantiateVariable(char name, int value)
{
	bool variableIsFound = false;

	// TODO error for non existing variable
	for (int i = 0; i < left->NumberOfChildren(); i++) 
	{
		if (left->ChildAtIndex(i).Type() == VARIABLE)
		{
			if (left->ChildAtIndex(i).Name()[0] == name) 
			{
				left->PointerToChildAtIndex(i)->setValue(value);
				variableCounter = (variableCounter == 0) ? 0 : variableCounter-1;
				variableIsFound = true;
			}
		}	
	}

	for (int i = 0; i < right->NumberOfChildren(); i++) 
	{
		if (right->ChildAtIndex(i).Type() == VARIABLE)
		{
			if (right->ChildAtIndex(i).Name()[0] == name) 
			{
				right->PointerToChildAtIndex(i)->setValue(value);
				variableCounter = (variableCounter == 0) ? 0 : variableCounter-1;
				variableIsFound = true;
			}
		}	
	}

	if (!variableIsFound) throw string("The specified variable does not exist.");
}

int Equation::EvaluateRPNExpression(Queue rpnExpression)
{	
	Stack localStore;
	Expression currentChild, temp, op1, op2;
	Operator *currentOp;

	try 
	{
		while (!rpnExpression.isEmpty())
		{
			currentChild = rpnExpression.dequeue();
			if ((currentChild.Type() == CONSTANT) ||
				(currentChild.Type() == VARIABLE))
				localStore.push(currentChild);
			else
			{
				currentOp = static_cast<Operator *>(&currentChild);
				if (GAUtility::OperatorIsBinary(currentChild.Name()))
				{
					op2 = localStore.pop();
					op1 = localStore.pop();
					localStore.push(currentOp->Operate(op1,op2));
					currentOp = 0;
				}
				else 
				{
					op1 = localStore.pop();
					localStore.push(currentOp->Operate(op1));
					currentOp = 0;
				}
			}
		}

		if (localStore.isEmpty())
		{
			return 0;
		}
		else 
		{
			return localStore.pop().Value();
		}
	}
	catch (...)
	{
		throw string("Error evaluating expression.");
	}
}

Queue Equation::CreateRPNExpression(Expression inputExpression)
{
	Queue outputQueue;
	Stack operatorStack;

	Expression currentChild, topOfStack;

	for (int i = 0; i < inputExpression.NumberOfChildren(); i++)
	{
		currentChild = inputExpression.ChildAtIndex(i);

		if ((currentChild.Type() == CONSTANT) ||
			(currentChild.Type() == VARIABLE))
			outputQueue.enqueue(currentChild);
		else if (currentChild.Type() == OPERATOR)
		{
			if (!operatorStack.isEmpty()) {
				while (((OperatorFactory::OperatorPrecedence(currentChild.Name())) <=
					(OperatorFactory::OperatorPrecedence(operatorStack.top->element.Name())))) 
				{
					if (OperatorFactory::OperatorPrecedence(currentChild.Name()) < 3)
						outputQueue.enqueue(operatorStack.pop());
					else
						break;
					if (operatorStack.isEmpty()) { break; }
				}		
				operatorStack.push(currentChild);
			}
			else 
			{
				operatorStack.push(currentChild);
			}
		}
		else if (currentChild.Type() == LEFTBRACKET)
		{
			operatorStack.push(currentChild);
		}
		else if (currentChild.Type() == RIGHTBRACKET)
		{
			while (!(operatorStack.top->element.Type() == LEFTBRACKET))
			{
				outputQueue.enqueue(operatorStack.pop());
			}
			operatorStack.pop();
		}
		else if (currentChild.Type() == COMMA)
		{
			while (!(operatorStack.top->element.Type() == LEFTBRACKET))
			{
				outputQueue.enqueue(operatorStack.pop());
			}
		}
	}

	while (!operatorStack.isEmpty())
	{
		outputQueue.enqueue(operatorStack.pop());
	}

	return outputQueue;
}

bool Equation::IsValidEquation(string eqn)
{
	size_t found= eqn.find("=");
	if (found!=string::npos)
		return true;
	else
		return false;
}

Equation& Equation::operator=(const Equation& other)
{
	rhsValue = other.rhsValue;
	lhsValue = other.lhsValue;
	variableCounter = other.variableCounter;
	localEquation = other.localEquation;

	left = new Expression();
	*left = *other.left;
	right = new Expression();
	*right = *other.right;
}

Expression* Equation::ParseEquationToExpression(string toSplit)
{
	Expression *parsed = new Expression();
	Expression toAdd; 



	string emptyString = "";
	vector<string> expressionInputs = GAUtility::SplitString(toSplit, " ");
	vector<string>::iterator s;
	for (s = expressionInputs.begin(); s < expressionInputs.end(); s++)
	{
		if (*s != emptyString) 
		{
			toAdd = ExpressionFactory::CreateExpression(*s);
			if (toAdd.Type() == VARIABLE) variableCounter++;
			parsed->AddChild(toAdd);
		}
	}
	return parsed;
}