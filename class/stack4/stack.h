#ifndef STACK_H
#define STACK_H
#include <iostream>
#include "safeArray.h"

template <typename T>
class Stack {

template <typename U>
friend std::ostream& operator<<(std::ostream& out, const Stack<U>& rhs);

private:
	static const int STACK_SIZE;

	SafeArray<T> arr_;
	int tos_;

	Stack(const Stack<T>& rhs);
	Stack& operator=(const Stack<T>& rhs);
	
public:
	Stack(int size = Stack<T>::STACK_SIZE);
	~Stack();

	//Stack<T> *operator&() { return this; }
	//const Stack<T> *operator&() const { return this; }

	int size() const;
	bool full() const;
	bool empty() const;
	void push(const T& data);
	const T& pop();
};

#include <cassert>

template <typename T>
const int Stack<T>::STACK_SIZE = 10;

template <typename T>
std::ostream& operator<<(std::ostream& out, const Stack<T>& rhs) {
    out << "[";
    for (int i = 0; i < rhs.tos_ ; ++i ) {
        out << rhs.arr_[i];
        out << ((i + 1 != rhs.tos_) ? ", " : "");
    }
    out << "]" << std::endl;

    out << "size : " << rhs.arr_.size() << std::endl;
    out << "tos : " << rhs.tos_ << std::endl;
}
template <typename T>
Stack<T>::Stack(int size) 
: arr_(size), tos_(0) {
}
template <typename T>
Stack<T>::~Stack() {
}
template <typename T>
int Stack<T>::size() const {
    return arr_.size();
}
template <typename T>
bool Stack<T>::full() const{
    return tos_ == Stack<T>::STACK_SIZE;
}
template <typename T>
bool Stack<T>::empty() const{
    return tos_ == 0;
}
template <typename T>
void Stack<T>::push(const T& data) {
    arr_[tos_] = data;
    ++tos_;
}
template <typename T>
const T& Stack<T>::pop() {
    --tos_;
    return arr_[tos_];
}

#endif
