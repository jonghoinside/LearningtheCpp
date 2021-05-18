#ifndef STACK_H
#define STACK_H
#define STACKSIZE 10

class Stack {
private:
	int* pArr;
	int size;
	int tos;
	
	Stack(const Stack& rhs);
	Stack& operator=(const Stack& rhs);
	
public:
	Stack(int size = STACKSIZE);
	~Stack();
	
	
	//	Stack* operator&() { return this; }
	//	const Stack* operator&() const { return this; }	// 함수 중복이지만 const까지 구별 가능함. 함수 이름 인자 개수 타입 + const
};

#endif
