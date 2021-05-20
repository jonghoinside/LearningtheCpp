#include <cassert>
#include "queue.h"

const int Queue::QUEUE_SIZE = 10;

std::ostream& operator<<(std::ostream& out, const Queue& rhs) {
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
Queue::Queue(int size)
: arr_(size), front_(0), rear_(0) {
}
Queue::~Queue() {
}
int Queue::size() const{
    return arr_.size();
}
bool Queue::full() const{
    return rear_ == Queue::QUEUE_SIZE;
}
bool Queue::empty() const{
    return front_ == rear_;
}
void Queue::push(int data) {
    arr_[rear_++] = data;
}
int Queue::pop() {
    return arr_[front_++];
}