#include <iostream>
#include "list.h"
#include "complex.h"

int main() {
	List<int> list1;
	list1.insertFirstNode(4);
	list1.insertFirstNode(3);
	list1.insertFirstNode(1);
	list1.insertNode(1, 2);
	list1.deleteNode(3);

	std::cout << list1 << std::endl;

	List<int> list2 = list1;

	list2 = list1;

	std::cout << list2 << std::endl;

	if (list1 == list2)
		std::cout << "list1 and list2 are equal" << std::endl;
	else
		std::cout << "list1 and lsit2 are not equal" << std::endl;

	List<Complex> list3;
	list3.insertFirstNode(Complex(4,5));
	list3.insertFirstNode(Complex(3,4));
	list3.insertFirstNode(Complex(1,2));
	list3.insertNode(Complex(1,2), Complex(2,3));
	list3.deleteNode(Complex(3,4));

	std::cout << list3 << std::endl;
	
	return 0;
}
