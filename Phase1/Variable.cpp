//Sonelisiwe Njozela 11272882
//Andrea Chalmers 11256339
#include "Variable.h"

using namespace std;

int Variable::Value()
{
	if (instantiated) 
		return value;
	else // TODO: include variable name in error message
		throw string("This variable has not been instantiated yet.");
}
