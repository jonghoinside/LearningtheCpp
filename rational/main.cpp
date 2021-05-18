#include <iostream>
#include "rational.h"

int main() {
	Rational r1;
	Rational r2(3.0);
	Rational r3(3.0, 4.0);
	
	r1.molecular(r3.molecular());
	r1.denominator(r3.denominator());
	
	std::cout << "r1 : " << r1.molecular() << " / " << r1.denominator() << std::endl;
	std::cout << "r2 : " << r2.molecular() << " / " << r2.denominator() << std::endl;
	std::cout << "r3 : " << r3.molecular() << " / " << r3.denominator() << std::endl;
	
	return 0;
}
