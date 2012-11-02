//Sonelisiwe Njozela 11272882
//Andrea Chalmers 11256339

#ifndef EXPRESSION_H
#define EXPRESSION_H

#include <string>
#include <cmath>
#include <sstream> // Convert string to integer
#include <vector>
#include <cctype>

#include "GAUtility.h"
#include "ExpressionType.h"

// Component class (composite pattern)

class Expression
{
	/*TODO: You have to finish this class to represent a
	mathematical expression.  All your operators and
	operands could directly or indirectly inherit from
	this class.
	*/	

private:
	std::vector<Expression> children;

protected:
	int value;
	std::string name; 
	ExpressionType type;

public:
	Expression() : name(""), value(0), type(EXPRESSION) {}
	Expression(int value) : name(""), value(value), type(EXPRESSION) {}
	Expression(std::string name, int value=0) : name(name), value(value), type(EXPRESSION) {}
	virtual int Value() { return value; }
	virtual std::string Name() { return name; }
	virtual ExpressionType Type() { return type; }
	virtual void setValue(int inputVal) { value = inputVal; }

	// Composite pattern methods
	void AddChild(Expression newChild) { children.push_back(newChild); }
	Expression ChildAtIndex(int index) { return children[index]; }
	Expression *PointerToChildAtIndex(int index) { return &(children[index]); }
	std::vector<Expression> Children() { return children; }
	int NumberOfChildren() { return (int)children.size(); }
	
	// Operator overloading
	Expression operator+(const Expression& other);
	Expression operator-(const Expression& other);
	Expression operator/(const Expression& other);
	Expression operator*(const Expression& other);
	Expression operator^(const Expression& other);

	// Operations on expressions
	Expression neg();
	Expression sqt();
	Expression lgm();
	Expression abv();
	Expression mxm(const Expression& other);

};

#endif
