//
// Created by user on 2021-06-07.
//
#ifndef ACCELERATED_STUDENT_INFO_H
#define ACCELERATED_STUDENT_INFO_H

#include <iostream>
#include <vector>
#include <string>
#include "student_info.h"

class Student_info {
private:
    std::string n;
    double midterm;
    double finalterm;
    std::vector<double> homework;

    std::istream& read_hw(std::istream& in);
public:
    Student_info();
    Student_info(std::istream& in);

    std::istream& read(std::istream& in);
    double grade() const;

    std::string name() const;
    bool valid() const;
};

bool compare(const Student_info& s1, const Student_info& s2);

#endif //ACCELERATED_STUDENT_INFO_H
