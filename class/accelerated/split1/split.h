//
// Created by user on 2021-06-04.
//

#ifndef ACCELERATED_SPLIT_H
#define ACCELERATED_SPLIT_H
#include <string>
#include <algorithm>

using namespace std;

bool not_space(char c);
bool space(char c);

template <typename IO, typename Func>
IO my_find_if(IO begin, IO end, Func func) {
    IO iter;
    for(iter = begin; iter != end; ++iter) {
        if (func(*iter))
            break;
    }

    return iter;
}

template <typename Out>
void split(const string& s, Out os) {
    string::const_iterator  iter = s.begin();
    while (iter != s.end()) {
        iter = my_find_if(iter, s.end(), not_space);
        string::const_iterator iter2 = my_find_if(iter, s.end(), space);

        if (iter != iter2)
            *os++ = string(iter, iter2);

        iter = iter2;
    }
}

#endif //ACCELERATED_SPLIT_H
