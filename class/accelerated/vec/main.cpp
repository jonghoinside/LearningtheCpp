//
// Created by user on 2021-06-07.
//
#include <iostream>
#include "vec.h"

using std::cout;
using std::endl;

int main() {
    Vec<int> vec(100, 10);
    Vec<int> vec2(10);
    Vec<int> vec3;

    vec3.push_back(5);
    vec3.push_back(4);
    vec3.push_back(3);
    vec3.push_back(6);
    vec3.push_back(2);
    vec3.push_back(1);

    vec3.erase(6);
    vec3.erase(vec3.begin() + 2);

    Vec<int> vec4 = vec3;

    vec2 = vec4;

    Vec<int>::const_iterator  iter;
    for (iter = vec2.cbegin(); iter != vec2.cend(); ++iter) {
        cout << *iter << " ";
    }
    cout << endl;

    return 0;
}