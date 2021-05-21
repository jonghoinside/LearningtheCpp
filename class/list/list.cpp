//	#include <stdio.h>
//	#include <stdlib.h>

#include <iostream>
#include <assert.h>
#include "list.h"

static Node* createNode(int data, const Node *next) {
	Node * tmp = new Node;
	
	tmp->data = data;
	tmp->next = (Node*)next;
	
	return tmp;
}

List::List() {	
	this->ptr = createNode(-1, NULL);
}
List::~List() {
	Node *p;
	p = this->ptr;
	
	while (p ) {
		Node* tmp = p;
		p = p->next;
		delete tmp;
	}
}

void List::printList() {
	Node *p;
	p = this->ptr->next;
	
	printf("[");
	while (p ) {
		printf("%d", p->data);
		printf((p->next )?",":"");
		p = p->next;
	}
	printf("]\n");
}

void List::insertFirstNode(int data) {
	this->ptr->next = createNode(data, this->ptr->next);
}

void List::insertNode(int prevData, int data) {
	Node* p = this->ptr->next;
	while (p ) {
		if(p->data == prevData)
			break;
		p = p-> next;
	}
	if (p ) {		
		p->next = createNode(data, p->next);
	}
}

void List::deleteNode(int data) {
	Node* p1 = this->ptr->next;
	Node* p2 = this->ptr;
	
	while(p1 ) {
		if (p1->data == data)
			break;
		
		p1 = p1->next;
		p2 = p2->next;
	}
	
	if (p1 ) {
		p2->next = p1->next;
		free(p1);
	}
}
