#include <iostream>
//#include <cstdio>
#include "queue.h"

int main() {
	
	Queue s1(100), s2(10);
	
	s1.push(100);
	s1.push(200);
	s1.push(300);
	
	std::cout << "s1 1st pop() : " << s1.pop() << std::endl;
	std::cout << "s1 2nd pop() : " << s1.pop() << std::endl;
	std::cout << "s1 3rd pop() : " << s1.pop() << std::endl;
	
	s1.push(900);
	s1.push(800);
	s1.push(700);
	
	std::cout << "s1 1st pop() : " << s1.pop() << std::endl;
	std::cout << "s1 2nd pop() : " << s1.pop() << std::endl;
	std::cout << "s1 3rd pop() : " << s1.pop() << std::endl;
	
	return 0;
}
