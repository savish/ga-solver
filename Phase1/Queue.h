
//Sonelisiwe Njozela 11272882
//Andrea Chalmers 11256339
#ifndef QUEUE_H
#define QUEUE_H

#include "Node.h"

class Queue
{
	public:
		Queue();
		Queue(const Queue& other);
		Queue& operator=(const Queue& other);
		~Queue();
		void enqueue(Expression val);
		Expression dequeue();
		bool isEmpty();
		
	private:
		void clear();
		Node* front;
		Node* back;
		
};

#endif
