#include <iostream>
#include "rational.h"

Rationaltest::Rationaltest(int son, int mom) {
    son_ = son;
    mom_ = mom;
}
Rationaltest::Rationaltest(const Rationaltest& rhs) {
    son_ = rhs.son_;
    mom_ = rhs.mom_;
}

void Rationaltest::printRational() {
    std::cout << son_ << " / " << mom_ << std::endl;
}

Rationaltest& Rationaltest::operator=(const Rationaltest& rhs) {
    this->mom_ = rhs.mom_;
    this->son_ = rhs.son_;

    return *this;
}
bool Rationaltest::operator==(const Rationaltest& rhs) {
    return (this->mom_ == rhs.mom_ && this->son_ == rhs.son_);
}
const Rationaltest Rationaltest::operator+(const Rationaltest& rhs) {
    return Rationaltest(this->son_ * rhs.mom_ + this->mom_ * rhs.son_ , this->mom_ * rhs.mom_);
}