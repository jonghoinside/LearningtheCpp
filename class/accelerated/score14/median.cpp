//
// Created by user on 2021-06-07.
//
#include <vector>
#include <algorithm>
#include "median.h"

using std::vector;
using std::sort;

double median(vector<double>& vec) {
    sort(vec.begin(), vec.end());
    const int mid = vec.size() / 2;

    return ((vec.size() % 2 == 1) ? vec[mid] : (vec[mid] + vec[mid -1]) / 2) ;
}