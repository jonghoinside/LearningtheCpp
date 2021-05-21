#ifndef QUEUE_H
#define QUEUE_H

class Queue{
private:
	int *pArr;
	int size;
	int front;
	int rear;
public:
	Queue(int size);
	~Queue();
	
	void push(int data);
	int pop();
};



#endif
