//
// Created by user on 2021-06-07.
//
#include <vector>
#include <iostream>
#include <string>
#include "grade.h"
#include "student_info.h"

using std::vector;
using std::istream;
using std::string;

bool compare(const Student_info& s1, const Student_info& s2) {
    return s1.name() < s2.name();
}

Student_info::Student_info()
: midterm(0.0), finalterm(0.0) {

}
Student_info::Student_info(istream& in) {
    this->read(in);
}
istream& Student_info::read(istream& in) {
    in >> this->n >> this->midterm >> this->finalterm;
    this->read_hw(in);

    return in;
}
double Student_info::grade() const {
    return ::grade(this->midterm, this->finalterm, this->homework);
}
string Student_info::name() const {
    return this->n;
}
bool Student_info::valid() const {
    return !this->homework.empty();
}
istream& Student_info::read_hw(istream& in) {
    if (in ) {
        this->homework.clear();
        double x;

        while (in >> x)
            this->homework.push_back(x);

        in.clear();
    }

    return in;
}