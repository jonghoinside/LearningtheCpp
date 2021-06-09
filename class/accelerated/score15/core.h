//
// Created by user on 2021-06-09.
//

#ifndef ACCELERATED_CORE_H
#define ACCELERATED_CORE_H

#include <iostream>
#include <string>
#include <vector>

class Core {
template <typename U>
friend class Ptr;
public:
    Core();
    explicit Core(std::istream& in);
    virtual ~Core() { }

    //void regrade(double final);
    virtual void regrade(double final, double thesis);

    std::string name() const;
    virtual double grade() const;
    virtual std::istream& read(std::istream& in);
private:
    std::string n;

    virtual Core* clone() const;
protected:
    double midterm;
    double finalterm;
    std::vector<double> homework;

    std::istream& read_common(std::istream& in);
    std::istream& read_hw(std::istream& in);
};

bool compare(const Core& c1, const Core& c2);

#endif //ACCELERATED_CORE_H
