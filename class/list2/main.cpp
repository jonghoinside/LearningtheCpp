#include <iostream>
#include "list.h"

int main() {
	List list1;
	list1.insertFirstNode(4);
	list1.insertFirstNode(3);
	list1.insertFirstNode(1);
	list1.insertNode(1, 2);
	list1.deleteNode(3);

	std::cout << list1 << std::endl;

	List list2 = list1;

	list2 = list1;

	std::cout << list2 << std::endl;

	if (list1 == list2)
		std::cout << "list1 and list2 are equal" << std::endl;
	else
		std::cout << "list1 and list2 are not equal" << std::endl;
	
	return 0;
}