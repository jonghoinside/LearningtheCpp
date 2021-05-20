#ifndef STACK_H
#define STACK_H
#include <iostream>
#include "array.h"
//	#define STACKSIZE 10
//	extern const int STACK_SIZE;

class Stack {
friend std::ostream& operator<<(std::ostream& out, const Stack& rhs);
private:
	static const int STACK_SIZE;

	//	int* pArr_;
	//	int size_;
	Array arr_;
	int tos_;

	Stack(const Stack& rhs);
	Stack& operator=(const Stack& rhs);
	
public:
	Stack(int size = Stack::STACK_SIZE);
	~Stack();
	
	int size() const;
	bool full();
	bool empty();
	void push(int data);
	int pop();
	
	//	Stack* operator&() { return this; }
	//	const Stack* operator&() const { return this; }	// 함수 중복이지만 const까지 구별 가능함. 함수 이름 인자 개수 타입 + const
};

#endif
