#include <assert.h>
#include "queue.h"

Queue::Queue(int size) {
	this->pArr = new int[size];
	assert(this->pArr );
	this->size = size;
	this->front = 0;
	this->rear = 0;
}

Queue::~Queue(){
	delete [] this->pArr;
}

void Queue::push(int data) {
	assert(this->rear != this->size);
	
	this->pArr[this->rear] = data;
	
	++this->rear;
}

int Queue::pop() {
	assert(this->rear != this->front);
	
	return this->pArr[this->front++];
}
