#include "stack.h"
#include <cassert>

const int Stack::STACK_SIZE = 10;

std::ostream& operator<<(std::ostream& out, const Stack& rhs) {
    out << "[";
    for (int i = 0; i < rhs.tos_ ; ++i ) {
        out << rhs.arr_[i];
        out << ((i + 1 != rhs.tos_) ? ", " : "");
    }
    out << "]" << std::endl;

    out << "size : " << rhs.arr_.size() << std::endl;
    out << "tos : " << rhs.tos_ << std::endl;
}

Stack::Stack(int size) 
: arr_(size), tos_(0) { //  멤버변수로 다른 클래스를 사용할 경우 초기화 리스트에서만 초기화를 해줄 수 있다.
}

Stack::~Stack() {
}

int Stack::size() const {
    return arr_.size();
}

bool Stack::full() {
    return tos_ == Stack::STACK_SIZE;
}

bool Stack::empty() {
    return tos_ == 0;
}

void Stack::push(int data) {
    arr_[tos_] = data;
    ++tos_;
}

int Stack::pop() {
    --tos_;
    return arr_[tos_];
}