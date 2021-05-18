#ifndef QUEUE_H
#define QUEUE_H
#include <iostream>
#define QUEUESIZE 10

class Queue {
friend std::ostream& operator<<(std::ostream& out, const Queue& rhs);
private:
    int* pArr_;
    int size_;
    int front_;
    int rear_;

    //not use..
    Queue(const Queue& rhs);
    Queue& operator=(const Queue& rhs);

public:
    Queue(int size = QUEUESIZE);
    ~Queue();

    int size() const;

	bool full() const;
	bool empty() const;

	void push(int data);
	int pop();
};

#endif