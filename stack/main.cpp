//#include <cstdio>
#include <iostream>
#include "stack.h"

int main() {
	
	Stack s1(10);
	Stack s2(100);		// 생성자 호출됨
	
//	s1.initStack(100);
//	s2.initStack(10);
	 
	s1.push(100);
	s1.push(200);
	s1.push(300);
	
//	printf("s1 1st pop() : %d \n", s1.pop());
/*	
	std::cout << "s1 1st pop() : ";		// 식은 실행시간에 평가되면 하나의 결과값을 가진다.
	std::cout << sq.pop();					// 여기서 결과값은 cout이기 때문에 아래와 같이 쓸 수 있다.
	std::cout << std::endl;
*/	
	std::cout << "s1 1st pop() : " << s1.pop() << std::endl;
	std::cout << "s1 2nd pop() : " << s1.pop() << std::endl;
	std::cout << "s1 3rd pop() : " << s1.pop() << std::endl;
	
	s2.push(900);
	s2.push(800);
	s2.push(700);
	
	std::cout << "s2 1st pop() : " << s2.pop() << std::endl;
	std::cout << "s2 2nd pop() : " << s2.pop() << std::endl;
	std::cout << "s2 3rd pop() : " << s2.pop() << std::endl;
	
//	s1.cleanupStack();
//	s2.cleanupStack();
	
	return 0;			// 소멸자 호출됨
}
