//Sonelisiwe Njozela 11272882
//Andrea Chalmers 11256339
#include "Queue.h"

Queue::Queue()
{
	front = back = 0;
}
		
Queue::Queue(const Queue& other)
{
	front = back = 0;
	Node* tmp = other.front;
	
	while(tmp)
	{
		this->enqueue(tmp->element);
		tmp = tmp->next;
	}
}
		
Queue& Queue::operator=(const Queue& other)
{
	if(this == &other)
		return *this;
	
	if(front)
		clear();
	
	Node* tmp = other.front;
	
	while(tmp)
	{
		this->enqueue(tmp->element);
		tmp = tmp->next;
	}
}
		
Queue::~Queue()
{
	clear();
}
		
void Queue::enqueue(Expression val)
{
	if(!front)
	{
		front = new Node(val);
		back = front;
	}
	else
	{
		back->next = new Node(val);
		back = back->next;
	}
		
}
		
Expression Queue::dequeue()
{
	if(!front)
		throw "ERROR: Cannot dequeue from empty queue";
	
	Expression returnValue = front->element;
	if(front == back)
	{
		delete front;
		front = back = 0;
	}
	else
	{
		Node* tmp = front;
		front = front->next;
		tmp->next = 0;
		delete tmp;
		tmp = 0;
	}
	
	return returnValue;
}
		
bool Queue::isEmpty()
{
	return !front;
}
		
void Queue::clear()
{
	while(front)
		dequeue();
}