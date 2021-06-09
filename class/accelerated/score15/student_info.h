//
// Created by user on 2021-06-07.
//
#ifndef ACCELERATED_STUDENT_INFO_H
#define ACCELERATED_STUDENT_INFO_H

#include <iostream>
#include <vector>
#include <string>
#include "grad.h"
#include "core.h"
#include "ptr.h"

class Student_info {
private:
//    Core* cp;
    Ptr<Core> cp;
public:
    static bool compare(const Student_info& s1, const Student_info& s2);

    Student_info();
    explicit Student_info(std::istream& in);
    Student_info(const Student_info& rhs);

    ~Student_info();
    Student_info& operator=(const Student_info& rhs);

    std::istream& read(std::istream& in);
    double grade() const;

    void regrade(double final, double thesis);

    std::string name() const;
    bool valid() const;
};


#endif //ACCELERATED_STUDENT_INFO_H
