#include <iostream>
#include "rational.h"

int main() {
	Rational r1(9, 12);
	Rational r2 = 3;
	Rational r3(3, 4);
	Rational r4 = r3;
	
	if (r1 == r3)
		std::cout << "r1 and r3 is equal" << std::endl;
	else
		std::cout << "r1 and r3 is not equal" << std::endl;
		
	std::cout << "r1 is " << r1.getMol() << " / " << r1.getDen() << std::endl;
	std::cout << "r2 is " << r2.getMol() << " / " << r2.getDen() << std::endl;
	std::cout << "r3 is " << r3.getMol() << " / " << r3.getDen() << std::endl;
	std::cout << "r4 is " << r4.getMol() << " / " << r4.getDen() << std::endl;
	
	r4 = r1 + r2;
	std::cout << "r1 + r2 is " << r4.getMol() << " / " << r4.getDen() << std::endl;
	
	r3 = r2 = r1;		//	dasisy-chain
	
	r4 = r3 + r4;
	std::cout << "r3 + r4 is " << r4.getMol() << " / " << r4.getDen() << std::endl;
	
	r4 = r1 + r3;
	std::cout << "r1 + r3 is " << r4.getMol() << " / " << r4.getDen() << std::endl;
	
	return 0;
}
