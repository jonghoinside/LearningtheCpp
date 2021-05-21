#include <iostream>
#include "complex.h"

int main() {
	std::cout << "1.1\n";
	Complex c1(3.0, 4.0);
	std::cout << "1.2\n";
	Complex c2 = 3.0;
	std::cout << "1.3\n";
	Complex c3;
	std::cout << "1.4\n";
	Complex c4 = c1;
	
	std::cout << "1.5\n";
	c3 = c2 = c1;
	std::cout << "1.6\n";
	c2 = 3.0;
	
	std::cout << "1.7\n";
	++c3;		// c3.operator++()
	c3++;		// c3.operator++(0)		//구별하기 위해서 의미없는 0 : dummy 값 넣음
	
	if (c1 == c2)
		std::cout << "c1 and c2 are equal" << std::endl;
	else
		std::cout << "c1 and c2 are not equal" << std::endl;
	
//	std::cout << "Complex c1 is (" << c1.getreal() << ", " << c1.getimag() << "i)" << std::endl;
	std::cout << "Complex c1 is " << c1 << std::endl;
	std::cout << "Complex c2 is " << c2 << std::endl;
	std::cout << "Complex c3 is " << c3 << std::endl;
	std::cout << "Complex c4 is " << c4 << std::endl;
	
	return 0;
}
