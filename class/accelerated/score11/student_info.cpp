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
: n(), finalScore(0.0) {

}
Student_info::Student_info(istream& in) {
    this->read(in);
}
istream& Student_info::read(istream& in) {
    double midterm, finalterm;
    vector<double> homework;

    in >> this->n >> midterm >> finalterm;
    this->read_hw(in, homework);

    if(in )
        this->finalScore = ::grade(midterm, finalterm, homework);

    return in;
}
string Student_info::name() const {
    return this->n;
}
double Student_info::getFinalScore() const {
    return this->finalScore;
}
istream& Student_info::read_hw(istream& in, vector<double>& homework) {
    if (in ) {
        homework.clear();
        double x;

        while (in >> x)
            homework.push_back(x);

        in.clear();
    }

    return in;
}