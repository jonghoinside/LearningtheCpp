#include <iostream>
#include "complex.h"
#include "stack.h"

int main() {
	Stack<int> s1;

	s1.push(100);
	s1.push(200);
	s1.push(300);

	std::cout << s1;

	while ( !s1.empty()) {
		std::cout << "s1 pop() : " << s1.pop() << std::endl;
	}
	
	Stack<Complex> s2;

	s2.push(Complex(3, 4));
	s2.push(Complex(4, 5));
	s2.push(Complex(5, 6));

	std::cout << s2;

	while ( !s2.empty()) {
		std::cout << "s2 pop() : " << s2.pop() << std::endl;
	}

	return 0;
}
