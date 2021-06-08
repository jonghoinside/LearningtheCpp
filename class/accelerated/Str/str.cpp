//
// Created by user on 2021-06-08.
//
#include <algorithm>
#include <iterator>
#include <cstring>
#include <cctype>
#include "str.h"

using std::strlen;
using std::copy;
using std::back_inserter;
using std::isspace;
using std::equal;

std::istream& operator>>(std::istream& in, Str& rhs) {
    rhs.data_.clear();

    char c;
    while(in.get(c) && isspace(c))
        ;

    if(in ) {
        do {
            rhs.data_.push_back(c);
        } while(in.get(c) && !isspace(c));

        if (in )
            in.unget();
    }

    return in;
}
std::ostream& operator<<(std::ostream& out, const Str& rhs) {
    Vec<char>::size_type i;
    for (i = 0; i != rhs.data_.size(); ++i) {
        out << rhs.data_[i];
    }

    return out;
}

Str::Str()
: data_(), str_(0), str2_(0) {

}
Str::Str(size_type size, char val)
: data_(size, val), str_(0), str2_(0) {

}
Str::Str(const char *str)
: data_(), str_(0), str2_(0) {
    ::copy(str, str + strlen(str), back_inserter(this->data_));
}
Str::~Str() {
    if(this->str_ ) delete [] this->str_;
    if(this->str2_ ) delete [] this->str2_;
}
bool Str::operator==(const Str& rhs) const {
    if (this->size() != rhs.size())
        return false;

    return ::equal(this->data_.cbegin(), this->data_.cend(), rhs.data_.cbegin());
}
bool Str::operator!=(const Str& rhs) const {
    return !this->operator==(rhs);
}
char& Str::operator[](int index) {
    return this->data_[index];
}
const char& Str::operator[](int index) const {
    return this->data_[index];
}
Str& Str::operator+=(const Str& rhs) {
    Vec<char>::size_type i;
    ::copy(rhs.data_.cbegin(), rhs.data_.cend(), back_inserter(this->data_));

//    for(i = 0; i != rhs.data.size(); ++i)
//        this->data
    return *this;
}
const Str Str::operator+(const Str& rhs) const {
    Str result(*this);
    result += rhs;

    return result;
}
const Str Str::operator+(const char *str) const {
    Str result(*this);
    ::copy(str, str + strlen(str), back_inserter(result.data_));

    return result;
}
Str::operator bool() const {
    return this->data_.size() != 0;
}
Str::iterator Str::begin() {
    return this->data_.begin();
}
Str::iterator Str::end() {
    return this->data_.end();
}
Str::const_iterator Str::cbegin() const {
    return this->data_.cbegin();
}
Str::const_iterator Str::cend() const {
    return this->data_.cend();
}
Str::size_type Str::size() const {
    return this->data_.size();
}
const char* Str::c_str() const {
    if (this->str_)
        delete [] this->str_;

    this->str_ = new char[this->data_.size() + 1];
    ::copy(this->data_.cbegin(), this->data_.cend(), this->str_);
    this->str_[this->data_.size()] = '\0';
    return this->str_;
}
const char* Str::data() const {
    if (this->str2_)
        delete [] this->str2_;

    this->str2_ = new char[this->data_.size()];
    ::copy(this->data_.cbegin(), this->data_.cend(), this->str2_);
    return this->str2_;
}
void Str::copy(char * s, Str::size_type len) const{
    ::copy(this->data_.cbegin(), this->data_.cbegin()+len, s);
}