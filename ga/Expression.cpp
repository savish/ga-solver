//Sonelisiwe Njozela 11272882
//Andrea Chalmers 11256339
#include "Expression.h"

using namespace std;

//Add any implementation you may require for the Expression class here
Expression Expression::operator+(const Expression& other)
{
	return Expression(value + other.value);
}

Expression Expression::operator-(const Expression& other)
{
	return Expression(value - other.value);
}

Expression Expression::operator/(const Expression& other)
{
	if (other.value != 0) 
		return Expression(value / other.value);
	else 
		throw string("Division by zero is undefined");
}

Expression Expression::operator*(const Expression& other)
{
	return Expression(value * other.value);
}

Expression Expression::operator^(const Expression& other)
{
	double ans = pow((double)value, (double)other.value);
	return Expression((int) ans);
}

Expression Expression::neg()
{
	return Expression( -1 * value);
}
Expression Expression::sqt()
{
	double ans = 0;
	if (value==0)
	{
		if (GAUtility::IsNumber(name)) 
		{
			int val = GAUtility::ConvertToInt(name);
			if (val>-1) { ans = sqrt((double)val); }
			else { ans = 0; }
		}
	}
	else
	{
		if (value>-1) { ans = sqrt((double)value); }
		else { ans = 0; }
	}
	return Expression((int) ans);
}
Expression Expression::lgm()
{
	double ans = log10((double)value);
	return Expression((int)ans);
}
Expression Expression::abv()
{
	int ans = (value<0) ? -1*value : value;
	return Expression(ans);
}
Expression Expression::mxm(const Expression& other)
{
	return (value >= other.value) ? 
		Expression(value) : Expression(other.value);
}