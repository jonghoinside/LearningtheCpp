#include <iostream>
#include "rational.h"

int main() {
	Rational r1(9, 12);
	Rational r2(3);
	Rational r3;
	Rational r4 = r1;
	
	r3 = r2 = r1;
	r3 = 1;
	
	r4 = r1 + r2;

	Rational r5, r6;

	std::cout << "input r5 and r6 :";
	std::cin >> r5 >> r6;

	++r1;
	r1++;
	
	if (r3 == r1)
		std::cout << "r1 and r3 are equal" << std::endl;
	else
		std::cout << "r1 and r3 are not equal" << std::endl;
		
	std::cout << "r1 : " << r1 << std::endl;
	std::cout << "r2 : " << r2 << std::endl;
	std::cout << "r3 : " << r3 << std::endl;
	std::cout << "r4 : " << r4 << std::endl;
	std::cout << "r5 : " << r5 << std::endl;
	std::cout << "r6 : " << r6 << std::endl;
	
	return 0;
}
