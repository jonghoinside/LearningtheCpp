#ifndef QUEUE_H
#define QUEUE_H

class Queue {
private:
	void *pArr;
	int eleSize;
	int size;
	int front;
	int rear;
public:
	Queue(int size, int eleSize);
	~Queue();

	void push(const void *pData);
	void pop(void* pData);
};

#endif
