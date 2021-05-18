#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include "queue.h"

Queue::Queue(int size, int eleSize) {
	this->pArr = malloc(eleSize * size);
	assert(this->pArr );
	
	this->eleSize = eleSize;
	this->size = size;
	this->front = 0;
	this->rear = 0;
}

Queue::~Queue(){
	free(this->pArr);
}

void Queue::push(const void* pData) {
//	ps->array[ps->tos] = data;
	assert(this->rear != this->size);
	
//	this->pArr[this->tos] = data;
	memcpy( (unsigned char *)this->pArr + this->rear*this->eleSize, pData, this->eleSize);
	
	++this->rear;
}

void Queue::pop(void* pData) {
	assert((this->rear == 0 || this->rear == this->front && this->rear != 0) == 0);
	
	memcpy(pData, (unsigned char *)this->pArr + this->front++*this->eleSize, this->eleSize);
	
//	*pRe = this->pArr[this->tos];
}
