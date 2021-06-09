//
// Created by user on 2021-06-07.
//
#include <vector>
#include <stdexcept>
#include "grade.h"
#include "median.h"

using std::vector;
using std::domain_error;

double grade(double midterm, double finalterm, double homework) {
    return 0.2 * midterm + 0.4 * finalterm + 0.4 * homework;
}

double grade(double midterm, double finalterm, const vector<double>& homework) {
    if(homework.size() == 0)
        throw domain_error("student has done no homework");

    vector<double> tmp = homework;
    return grade(midterm, finalterm, median(tmp));
}