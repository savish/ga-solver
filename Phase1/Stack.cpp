//Sonelisiwe Njozela 11272882
//Andrea Chalmers 11256339
#include "Stack.h"

Stack::Stack()
{
	top = 0;
}
		

Stack::Stack(const Stack& other)
{
	this->top = new Node(other.top->element);
	Node* tmpThis = this->top;
	Node* tmpOther = other.top->next;
	
	while(tmpOther)
	{
		tmpThis->next = new Node(tmpOther->element);
		tmpThis = tmpThis->next;
		tmpOther = tmpOther->next;
	}
}
		

Stack& Stack::operator=(const Stack& other)
{
	if(this == &other)
		return *this;
	
	if(top)
	{
		clear();
	}
	
	this->top = new Node(other.top->element);
	Node* tmpThis = this->top;
	Node* tmpOther = other.top->next;
	
	while(tmpOther)
	{
		tmpThis->next = new Node(tmpOther->element);
		tmpThis = tmpThis->next;
		tmpOther = tmpOther->next;
	}
	
	return *this;
	
}

Stack::~Stack()
{
	clear();
}
		

Expression Stack::pop()
{
	if(top)
	{
		Expression el = top->element;
		Node* tmp = top;
		top = top->next;
		tmp->next = 0;
		delete tmp;
		return el;
	}
	else
	{
		throw "ERROR: Cannot pop from empty stack";	
	}
}
		

void Stack::push(Expression val)
{
	if(top)
	{
		Node* newTop = new Node(val,top);
		top = newTop;
		newTop = 0;
	}
	else
	{
		top = new Node(val);
	}
}

bool Stack::isEmpty()
{
	return !top;
}
		
void Stack::clear()
{
	while(top)
		pop();
}