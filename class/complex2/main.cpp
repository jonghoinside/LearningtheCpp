#include <iostream>
#include "complex.h"

int main() {
	Complex c1;
	//Complex c2(3.0);
	Complex c2 = 3.0;	//	마찬가지로 3.0은 int형, Complex형으로 변환 가능한지 보고 들어간다. 그때 Complex class 생성자 중에 double값을 인자로 받는 생성자가 있는지 찾고 있으면 그 생성자를 통해 3.0을 넣는다.
//	int i = 3.14; 		// 3.14는 double형 int형으로 변환이 가능한지 보고 소수점 날리고 넣는다.
	
	Complex c3(3.0, 4.0);
	//Complex c4(c3);
	Complex c4 = c3;
	
//	c1.real(c3.real());
//	c1.imag(c3.imag());
	c1 = c3;
	// c1.operator(c3) or operator=(c1, c3)
	
	c2 = 4.0;		// Complex tmp(4.0); c2.operator=(tmp), tmp.complex()
	c2 = 4;		// int --> double
	
	c3 = c2 = c1;
	
	c4 = c1 + c2;		//	c1.operator=(c1.operator+(c2))
						//	operator=(c4, operator+(c1, c2))
	
	if (c1 == c3)			// c1.operator==(c3) or operator==(c1, c3)
		std::cout << "c1 and c3 are equal" << std::endl;
	else
		std::cout << "c1 and c3 are not equal" << std::endl;
	
	std::cout << "c1 : (" << c1.real() << ", " << c1.imag() << "i)" << std::endl;
	std::cout << "c2 : (" << c2.real() << ", " << c2.imag() << "i)" << std::endl;
	std::cout << "c3 : (" << c3.real() << ", " << c3.imag() << "i)" << std::endl;
	std::cout << "c4 : (" << c4.real() << ", " << c4.imag() << "i)" << std::endl;
	
	return 0;
}
