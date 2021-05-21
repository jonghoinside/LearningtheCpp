#include <iostream>
#include "rational.h"

using std::cout;
using std::endl;

int main() {
	Rational r1(9, 12);
	Rational r2 = 3;
	Rational r3;
	Rational r4 = r1;
	
//	r3.setNum(r1.getNum());
//	r3.setDen(r1.getDen());
	r4 = r3 = r1;
	
	if (r1 == r3)
		cout << "r1 and r3 are equal" << endl;
	else
		cout << "r1 and r3 are not equal" << endl;
//	std::cout << "r1 is " << r1.getNum() << " / " << r1.getDen() << std::endl;
	
	r3 = r1 + r2;
	
	++r3;
	r3++;
	
	cout << "r1 is " << r1 << endl;
	cout << "r2 is " << r2 << endl;
	cout << "r3 is " << r3 << endl;
	cout << "r4 is " << r4 << endl;
	
	const Rational r5(8, 4);
	cout << "r5 is " << r5 << endl;
	
	return 0;
}
