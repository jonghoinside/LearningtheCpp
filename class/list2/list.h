#ifndef LIST_H
#define LIST_H
#include <iostream>

class Node {
friend class List;
private:
	int data;
	Node *next;

	Node();
	Node(int d, Node *n);
	Node(const Node&);

};

class List {
friend std::ostream& operator<<(std::ostream& out, const List& rhs);
private:
	Node *ptr_;

	void printList(std::ostream& out) const;
public:
	List();
	List(const List& rhs);
	~List();

	List& operator=(const List& rhs);
	bool operator==(const List& rhs) const;

	void insertFirstNode(int data);
	void insertNode(int prevData, int data);
	void deleteNode(int data);
};

#endif
