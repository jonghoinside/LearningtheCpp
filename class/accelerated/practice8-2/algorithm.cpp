//
// Created by user on 2021-06-04.
//
#include "algorithm.h"

template <typename IO, typename T>
T my_accumulate(IO begin, IO end, T rhs) {
    for(auto iter = begin; iter != end; ++iter) {
        rhs += *iter;
    }
    return rhs;
}
template <typename IO, typename T>
IO find(IO begin, IO end, T rhs) {
    auto iter = begin;
    for(iter = begin; iter != end; ++iter) {
        if (*iter == rhs)
            break;
    }

    return iter;
}

template <typename IO, typename P>
IO find_if(IO begin, IO end, P (*fp)(IO)) {
    auto iter = begin;
    for(iter = begin; iter != end; ++iter) {
        if (fp(iter))
            break;
    }

    return iter;
}