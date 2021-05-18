#ifndef STACK_H
#define STACK_H

class Stack {
private:
	int *pArr;
	int size;
	int tos;
public:
	Stack(int size);		// constructor
	~Stack();				// destructor
	
	void push(int data);
	int pop();
};

#endif
