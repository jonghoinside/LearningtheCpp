#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>
#include "safeArray.h"
// #define QUEUESIZE 10

template <typename T>
class Queue {
template <typename U>
friend std::ostream& operator<<(std::ostream& out, const Queue<U>& rhs);
private:
    static const int QUEUE_SIZE;

    SafeArray<T> arr_;
    int front_;
    int rear_;

    //not use..
    Queue(const Queue<T>& rhs);
    Queue<T>& operator=(const Queue<T>& rhs);

public:
    Queue(int size = QUEUE_SIZE);
    ~Queue();

    int size() const;

	bool full() const;
	bool empty() const;

	void push(const T& data);
	const T& pop();
};

#include <cassert>

template <typename T>
const int Queue<T>::QUEUE_SIZE = 10;
template <typename T>
std::ostream& operator<<(std::ostream& out, const Queue<T>& rhs) {
    out << "[";
    for (int i = rhs.front_ ; i < rhs.rear_ ; ++i ) {
        out << rhs.arr_[i];
        out << (( i + 1 != rhs.rear_) ? ", " : "");
    }
    out << "]" << std::endl;

    out << "size_ : " << rhs.arr_.size() << std::endl;
    out << "front_ : " << rhs.front_ << std::endl;
    out << "rear_ : " << rhs.rear_ << std::endl;
}
template <typename T>
Queue<T>::Queue(int size)
: arr_(size), front_(0), rear_(0) {
}
template <typename T>
Queue<T>::~Queue() {
}
template <typename T>
int Queue<T>::size() const{
    return arr_.size();
}
template <typename T>
bool Queue<T>::full() const{
    return rear_ == Queue::QUEUE_SIZE;
}
template <typename T>
bool Queue<T>::empty() const{
    return front_ == rear_;
}
template <typename T>
void Queue<T>::push(const T& data) {
    arr_[rear_++] = data;
}
template <typename T>
const T& Queue<T>::pop() {
    return arr_[front_++];
}

#endif