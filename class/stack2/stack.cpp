#include "stack.h"
#include <cassert>

std::ostream& operator<<(std::ostream& out, const Stack& rhs) {
    out << "[";
    for (int i = 0; i < rhs.tos_ ; ++i ) {
        out << rhs.pArr_[i];
        out << ((i + 1 != rhs.tos_) ? ", " : "");
    }
    out << "]" << std::endl;

    out << "size : " << rhs.size_ << std::endl;
    out << "tos : " << rhs.tos_ << std::endl;
}

Stack::Stack(int size) 
: pArr_(new int[size]), size_(size), tos_(0) {
    // this-> 는 생량이 가능 _(언더라인) 붙어있으면 this->가 있는걸로 알기
    // 멤버변수랑 지역변수가 이름이 같으면 생략 불가
    assert(this->pArr_);
}

Stack::~Stack() {
    delete [] pArr_;
}

int Stack::size() const {
    return size_;
}

bool Stack::full() {
    return tos_ == STACKSIZE;
}

bool Stack::empty() {
    return tos_ == 0;
}

void Stack::push(int data) {
    pArr_[tos_] = data;
    ++tos_;
}

int Stack::pop() {
    --tos_;
    return pArr_[tos_];
}