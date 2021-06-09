//
// Created by user on 2021-06-09.
//

#ifndef ACCELERATED_CORE_H
#define ACCELERATED_CORE_H

#include <iostream>
#include <string>
#include <vector>

class Core {
friend class Student_info;
public:
    Core();
    explicit Core(std::istream& in);
    virtual ~Core() { }

    std::string name() const;
    virtual double grade() const;
    virtual std::istream& read(std::istream& in);
private:
    std::string n;
    double midterm;
    double finalterm;
    std::vector<double> homework;

    virtual Core* clone() const;
protected:
    std::istream& read_common(std::istream& in);
    std::istream& read_hw(std::istream& in);
};

bool compare(const Core& c1, const Core& c2);

#endif //ACCELERATED_CORE_H
