//
// Created by user on 2021-06-04.
//
#include <iostream>
#include <vector>
#include <algorithm>
#include <stdexcept>

using namespace std;

template<typename  T>
T median(vector<T>& vec) {
    typedef typename vector<T>::size_type vec_sz;
    vec_sz size = vec.size();

    if (size == 0)
        throw domain_error("median of an empty vector");

    sort(vec.begin(), vec.end());

    const int mid = size / 2;

    return ((size % 2 == 1) ? vec[mid] : (vec[mid] + vec[mid -1])) ;
}

int main() {
    string arr[] = {"hello", "world", "anjongho", "hi"};
    vector<string> nums(arr, arr + 4);

    cout << "median : " << median(nums) << endl;
    return 0;
}
