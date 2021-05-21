#include <iostream>
#include "list.h"

int main() {
	List list();
//	initList();
	
	list.insertFirstNode(4);
	list.printList();
	
	list.insertFirstNode(3);
	list.printList();
	
	list.insertFirstNode(1);
	list.printList();
	
	list.insertNode(1, 2);
	list.printList();
	
	list.deleteNode(3);
	list.printList();
	
//	cleanupList();
	
	return 0;
}
