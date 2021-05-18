//#include <stdio.h>
#include <iostream>
#include "queue.h"

int main() {
	
	Queue s1(100, sizeof(int));
	Queue s2(10, sizeof(double));
	
	int i;
	
	i = 100;			s1.push(&i);		//push(&i, sizeof(int));
	i = 200;			s1.push(&i);
	i = 300;			s1.push(&i);
	
	s1.pop(&i);		std::cout << "s1 1st pop() : " << i << std::endl;
	s1.pop(&i);		std::cout << "s1 2nd pop() : " << i << std::endl;
	s1.pop(&i);		std::cout << "s1 3rd pop() : " << i << std::endl;
	
	double d;
	
	d = 1.1;			s2.push(&d);
	d = 2.2;			s2.push(&d);
	d = 3.3;			s2.push(&d);
	
	s2.pop(&d);		std::cout << "s2 1st pop() : " << d << std::endl;
	s2.pop(&d);		std::cout << "s2 2nd pop() : " << d << std::endl;
	s2.pop(&d);		std::cout << "s2 3rd pop() : " << d << std::endl;
	
	return 0;
}
