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
    double finalScore;

    std::istream& read_hw(std::istream& in, std::vector<double>& homework);
public:
    Student_info();
    explicit Student_info(std::istream& in);

    std::istream& read(std::istream& in);

    std::string name() const;
    double getFinalScore() const;
};

bool compare(const Student_info& s1, const Student_info& s2);

#endif //ACCELERATED_STUDENT_INFO_H
