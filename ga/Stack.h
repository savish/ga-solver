//Sonelisiwe Njozela 11272882
//Andrea Chalmers 11256339
#ifndef STACK_H
#define STACK_H

#include "Node.h"

class Stack
{
	public:
		Stack();
		Stack(const Stack& other);
		Stack& operator=(const Stack& other);
		~Stack();
		Expression pop();
		void push(Expression val);
		bool isEmpty();
		Node* top;
	
	private:
		void clear();
		
};

#endif
