//
// Created by user on 2021-06-09.
//
#include <iostream>
#include <algorithm>
#include "grad.h"

using std::istream;
using std::min;

Grad* Grad::clone() const {
    return new Grad(*this);
}

Grad::Grad()
: Core(), thesis(0.0) { // Core() 생략 가능

}
Grad::Grad(istream& in) { // Core() 생략 가능
    this->read(in);
}
double Grad::grade() const {
    return ::min(this->Core::grade(), thesis);
}
istream& Grad::read(istream& in) {
    this->Core::read_common(in);
    in >> thesis;
    this->Core::read_hw(in);

    return in;
}