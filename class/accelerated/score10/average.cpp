//
// Created by user on 2021-06-07.
//
#include <vector>
#include <numeric>
#include "average.h"

double average(const vector<double>& vec) {
    return accumulate(vec.cbegin(), vec.cend(), 0.0) / vec.size();
}