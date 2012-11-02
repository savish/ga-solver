//Andrea Chalmers 11256339
//Sonelisiwe Njozela 11272882
#include <iostream>
#include "Equation.h"

using namespace std;

void testCase1()
{
	/*
	Creating Equation objects.  Notice that all operators and operands
	are seperated by spaces.  This will make it more convenient to tokenize
	*/
	Equation equation1("x + y + sqrt 25 - 3 = z ^ 3 - y");
	/*Testing equation1*/
	equation1.instantiateVariable('x',5);//Set x = 5
	equation1.instantiateVariable('y',3);//Set y = 3
	equation1.instantiateVariable('z',2);//Set z = 2
	
	/*
	The output of the following statements should be:
	
	Left: 10
	Right: 5
	Difference: 5
	*/
	cout<<"Left: "<<equation1.evaluateLHS()<<endl;
	cout<<"Right: "<<equation1.evaluateRHS()<<endl;
	cout<<"Difference: "<<equation1.RHSdistanceFromLHS()<<endl;
	
	/*
	Change y's value
	*/
	equation1.instantiateVariable('y',5);
	
	/*
	The output of the following statements should be:
	
	Left: 12
	Right: 3
	Difference: 9
	*/
	cout<<"Left: "<<equation1.evaluateLHS()<<endl;
	cout<<"Right: "<<equation1.evaluateRHS()<<endl;
	cout<<"Difference: "<<equation1.RHSdistanceFromLHS()<<endl;
	
	/*
	Testing equation2 with the copy constructor
	*/
	
	Equation equation2 = equation1;
	equation2.instantiateVariable('z',3);
	/*
	The output of the following statements should be:
	
	Left: 12
	Right: 22
	Difference: 10
	*/
	cout<<"Left: "<<equation2.evaluateLHS()<<endl;
	cout<<"Right: "<<equation2.evaluateRHS()<<endl;
	cout<<"Difference: "<<equation2.RHSdistanceFromLHS()<<endl;
	
}

void testCase2()
{
	try
	{
		Equation equation3("(y - (x + 3) ^ y) * 5 / 2 = log 20 - y");
		equation3.instantiateVariable('x',3);
		
		/*
		The following code should throw an exception as the variable y has no value
		*/
		cout<<"Left: "<<equation3.evaluateLHS()<<endl;
		cout<<"Right: "<<equation3.evaluateRHS()<<endl;
		cout<<"Difference: "<<equation3.RHSdistanceFromLHS()<<endl;
	}
	catch(string ex)
	{
		cout<<"Exception thrown"<<endl;
	}
}


int main(int argc, char** argv)
{
	testCase1();
	testCase2();
	
}