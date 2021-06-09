//
// Created by user on 2021-06-09.
//
#include <iostream>
#include <string>
#include <algorithm>
#include <iterator>
#include "grade.h"
#include "core.h"

using std::istream;
using std::string;
using std::copy;
using std::istream_iterator;
using std::back_inserter;

bool compare(const Core& c1, const Core& c2) {
    return c1.name() < c2.name();
}
Core* Core::clone() const {
    return new Core(*this);
}

istream& Core::read_common(istream& in) {
    in >> this->n >> this->midterm >> this->finalterm;

    return in;
}
istream& Core::read_hw(istream& in) {
    if (in ) {
        homework.clear();

        ::copy(istream_iterator<double>(in), istream_iterator<double>(), back_inserter(this->homework));

        in.clear();
    }

    return in;
}

Core::Core()
: midterm(0), finalterm(0.0) {  // n(), homework()

}
Core::Core(istream& in) {
    this->read(in);
}
string Core::name() const {
    return this->n;
}
double Core::grade() const {
    return ::grade(this->midterm, this->finalterm, this->homework);
}
istream& Core::read(istream& in) {
    this->read_common(in);
    this->read_hw(in);

    return in;
}