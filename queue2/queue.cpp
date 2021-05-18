#include <cassert>
#include "queue.h"

std::ostream& operator<<(std::ostream& out, const Queue& rhs) {
    out << "[";
    for (int i = rhs.front_ ; i < rhs.rear_ ; ++i ) {
        out << rhs.pArr_[i];
        out << (( i + 1 != rhs.rear_) ? ", " : "");
    }
    out << "]" << std::endl;

    out << "size_ : " << rhs.size_ << std::endl;
    out << "front_ : " << rhs.front_ << std::endl;
    out << "rear_ : " << rhs.rear_ << std::endl;
}
Queue::Queue(int size)
: pArr_(new int[size]), size_(size), front_(0), rear_(0) {
    assert(pArr_ );
 }
Queue::~Queue() {
    delete [] pArr_;
}
int Queue::size() const{
    return size_;
}
bool Queue::full() const{
    return rear_ == QUEUESIZE;
}
bool Queue::empty() const{
    return front_ == rear_;
}
void Queue::push(int data) {
    pArr_[rear_++] = data;
}
int Queue::pop() {
    return pArr_[front_++];
}