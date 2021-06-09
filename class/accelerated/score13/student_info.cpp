//
// Created by user on 2021-06-07.
//
#include <vector>
#include <iostream>
#include <string>
#include "student_info.h"
#include "core.h"
#include "grad.h"

using std::vector;
using std::istream;
using std::string;

bool Student_info::compare(const Student_info& s1, const Student_info& s2) {
    return s1.name() < s2.name();
}

Student_info::Student_info()
: cp(0) {

}
Student_info::Student_info(istream& in) {
    this->read(in);
}
Student_info::Student_info(const Student_info& rhs) {
    if (rhs.cp )
        this->cp = rhs.cp->clone();
}
Student_info::~Student_info() {
    delete this->cp;
}
Student_info& Student_info::operator=(const Student_info& rhs) {
    if (this != &rhs) {
        delete this->cp;

        if (rhs.cp )
            this->cp = rhs.cp->clone();
    }

    return *this;
}

istream& Student_info::read(istream& in) {
    char ch;
    in >> ch;
    if (ch == 'U')
        this->cp = new Core(in);
    else
        this->cp = new Grad(in);

    return in;
}
double Student_info::grade() const {
    return this->cp->grade();
}
string Student_info::name() const {
    return this->cp->name();
}
bool Student_info::valid() const {
    return this->cp;
}