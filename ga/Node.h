//Sonelisiwe Njozela 11272882
//Andrea Chalmers 11256339
#ifndef NODE_H
#define NODE_H

#include "Expression.h"

class Stack;
class Queue;

class Node
{
	friend class Stack;
	friend class Queue;
	
	public:
		Node(Expression el, Node* n = 0)
		{
			element = el;
			next = n;	
		}
		
	Expression element;
		
	private:
		Node* next;
};

#endif
