#include <iostream>
#include "stack.h"

int main() {
	Stack s1(100);		// Stack s1 = 100; ???
	Stack s2;				// Stack s2(10)
//	Stack s3 = s1;		// ???
//	s2 = s1;				// ???

	s1.push(100);
	s1.push(200);
	s1.push(300);

	std::cout << s1;

	while ( !s1.empty()) {
		std::cout << "s1 pop() : " << s1.pop() << std::endl;
	}
	
	return 0;
}
