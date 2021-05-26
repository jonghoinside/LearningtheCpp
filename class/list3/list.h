#ifndef LIST_H
#define LIST_H
#include <iostream>
#include <cassert>

template <typename T>
class Node {
template <typename U>
friend class List;
private:
	T data;
	Node<T> *next;

	Node(const T& d, Node<T> *n);
	//	not use.. 정의를 안했기 때문에
	Node();
	Node(const Node<T>&);

};
template <typename T>
class List {
template <typename U>
friend std::ostream& operator<<(std::ostream& out, const List<U>& rhs);
private:
	Node<T> *ptr_;

	void printList(std::ostream& out) const;
public:
	List();
	List(const List<T>& rhs);
	~List();

	List<T>& operator=(const List<T>& rhs);
	bool operator==(const List<T>& rhs) const;

	void insertFirstNode(const T& data);
	void insertNode(const T& prevData, const T& data);
	void deleteNode(const T& data);
};
template <typename T>
Node<T>::Node(const T& d, Node<T> *n)
: data(d), next(n) {
}
template <typename T>
void List<T>::printList(std::ostream& out) const{
	Node<T> *ptr = ptr_->next;

	out << "[";
	while (ptr ) {
		out << ptr->data;
		out << ((ptr->next) ? ", " : "");

		ptr = ptr->next;
	}
	out << "]";
}
template <typename T>
std::ostream& operator<<(std::ostream& out, const List<T>& rhs) {
	rhs.printList(out);

	return out;
}
template <typename T>
List<T>::List() {
	this->ptr_ = new Node<T>(-1, NULL);
	assert(ptr_);
}
template <typename T>
List<T>::List(const List<T>& rhs) {
	ptr_ = new Node<T>(-1, NULL);
	assert(ptr_);

	Node<T> *p = rhs.ptr_->next;
	Node<T> *p2 = ptr_;

	while (p ) {
		p2->next = new Node<T>(p->data, NULL);
		assert(p2->next);

		p = p->next;
		p2 = p2->next;
	}
}
template <typename T>
List<T>::~List() {
	Node<T> *p;
	p = ptr_;
	
	while (p ) {
		Node<T>* tmp = p;
		p = p->next;
		delete tmp;
	}
}
template <typename T>
List<T>& List<T>::operator=(const List<T>& rhs) {
	if (this != &rhs) {
		Node<T> *p = ptr_;

		while (p ) {
			Node<T> *tmp = p;
			p = p->next;
			delete tmp;
		}
		
		ptr_ = new Node<T>(-1, NULL);
		assert(ptr_);

		p = rhs.ptr_->next;
		Node<T> *p2 = ptr_;

		while (p ) {
			p2->next = new Node<T>(p->data, NULL);
			assert(p2->next);

			p = p->next;
			p2 = p2->next;
		}
	}
}
template <typename T>
bool List<T>::operator==(const List<T>& rhs) const {
	Node<T> *p = this->ptr_->next;
	Node<T> *p2 = rhs.ptr_->next;

	while (p ) {
		if (p->data != p2->data)
			break;
		p = p->next;
		p2 = p2->next;
	}

	return (p == NULL);
}
template <typename T>
void List<T>::insertFirstNode( const T& data) {
	Node<T> *tmp = new Node<T>(data, ptr_->next);
	assert(tmp );
	ptr_->next = tmp;
}
template <typename T>
void List<T>::insertNode( const T& prevData, const T& data) {
	Node<T>* p = ptr_->next;
	while (p ) {
		if(p->data == prevData)
			break;
		p = p-> next;
	}
	if (p ) {
		Node<T> *tmp = new Node<T>(data, p->next);
		assert(tmp );
		p->next = tmp;
	}
}
template <typename T>
void List<T>::deleteNode(const T& data) {
	Node<T>* p1 = ptr_->next;
	Node<T>* p2 = ptr_;
	
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

#endif