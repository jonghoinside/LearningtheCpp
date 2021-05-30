#include <iostream>
#include <cassert>
#include "list.h"

Node::Node(int d, Node *n)
: data(d), next(n) {
}

void List::printList(std::ostream& out) const{
	Node *ptr = ptr_->next;

	out << "[";
	while (ptr ) {
		out << ptr->data;
		out << ((ptr->next) ? ", " : "");

		ptr = ptr->next;
	}
	out << "]";
}

std::ostream& operator<<(std::ostream& out, const List& rhs) {
	rhs.printList(out);

	return out;
}

List::List() {
	this->ptr_ = new Node(-1, NULL);
	assert(ptr_);
}
List::List(const List& rhs) {
	ptr_ = new Node(-1, NULL);
	assert(ptr_);

	Node *p = rhs.ptr_->next;
	Node *p2 = ptr_;

	while (p ) {
		p2->next = new Node(p->data, NULL);
		assert(p2->next);

		p = p->next;
		p2 = p2->next;
	}
}
List::~List() {
	Node *p;
	p = ptr_;
	
	while (p ) {
		Node* tmp = p;
		p = p->next;
		delete tmp;
	}
}

List& List::operator=(const List& rhs) {
	if (this != &rhs) {
		Node *p = ptr_;

		while (p ) {
			Node *tmp = p;
			p = p->next;
			delete tmp;
		}
		
		ptr_ = new Node(-1, NULL);
		assert(ptr_);

		p = rhs.ptr_->next;
		Node *p2 = ptr_;

		while (p ) {
			p2->next = new Node(p->data, NULL);
			assert(p2->next);

			p = p->next;
			p2 = p2->next;
		}
	}
	return *this;
}

bool List::operator==(const List& rhs) const {
	Node *p = this->ptr_->next;
	Node *p2 = rhs.ptr_->next;

	while (p ) {
		if (p->data != p2->data)
			break;
		p = p->next;
		p2 = p2->next;
	}

	return (p == NULL);
}

void List::insertFirstNode( int data) {
	Node *tmp = new Node(data, ptr_->next);
	assert(tmp );
	ptr_->next = tmp;
}

void List::insertNode( int prevData, int data) {
	Node* p = ptr_->next;
	while (p ) {
		if(p->data == prevData)
			break;
		p = p-> next;
	}
	if (p ) {
		Node *tmp = new Node(data, p->next);
		assert(tmp );
		p->next = tmp;
	}
}

void List::deleteNode(int data) {
	Node* p1 = ptr_->next;
	Node* p2 = ptr_;
	
	while(p1 ) {
		if (p1->data == data)
			break;
		
		p1 = p1->next;
		p2 = p2->next;
	}
	
	if (p1 ) {
		p2->next = p1->next;
		delete p1;
	}
}
