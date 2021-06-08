//
// Created by user on 2021-06-08.
//
#ifndef ACCELERATED_STR_H
#define ACCELERATED_STR_H

#include <algorithm>
#include <iterator>
#include "vec.h"

class Str {
friend std::istream& operator>>(std::istream& in, Str& rhs);
friend std::ostream& operator<<(std::ostream& out, const Str& rhs);

public:
    typedef char * iterator;
    typedef const char * const_iterator;
    typedef size_t size_type;

    Str();
    Str(size_type size, char val);
    Str(const char *str);       //explict Str s1 = "hello"; 가 가능할 수 있으니까 안쓴다.
//    Str(const char *b, const char *e);
//    Str(Vec<char>::const_iterator b, Vec<char>::const_iterator e);
    template <typename In>
    Str(In b, In e);
    ~Str();

    bool operator==(const Str& rhs) const;
    bool operator!=(const Str& rhs) const;

    char& operator[](int index);
    const char& operator[](int index) const;

    Str& operator+=(const Str& rhs);
    const Str operator+(const Str& rhs) const;
    const Str operator+(const char *str) const;

    operator bool() const;

    iterator begin();
    iterator end();
    const_iterator cbegin() const;
    const_iterator cend() const;

    size_type size() const;

    const char* c_str() const;
    const char* data() const;

    void copy(char * s, size_type len) const;

private:
    Vec<char> data_;
    mutable char * str_;
    mutable char * str2_;
};

template <typename In>
Str::Str(In b, In e)
: data_(0), str_(0) {
    std::copy(b, e, std::back_inserter(this->data_));
}

#endif //ACCELERATED_STR_H