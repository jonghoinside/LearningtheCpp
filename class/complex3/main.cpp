#include <iostream>
#include "complex.h"

int main() {
	Complex c1(3.0, 4.0);
	Complex c2 = 3.0;
	Complex c3;
	Complex c4 = c1;
	
	c3 = c2 = c1;
	c2 = 3.0;

	std::cout << "input c2 and c3 : ";
	std::cin >> c2 >> c3;
	
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
