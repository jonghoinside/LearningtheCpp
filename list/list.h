#ifndef LIST_H
#define LIST_H

class Node {
	int data;
	struct node* next;
};

class List {
	Node *ptr;
	List();
	~List();

	void printList();
	void insertFirstNode(int data);
	void insertNode(int prevData, int data);
	void deleteNode(int data);
};

#endif
