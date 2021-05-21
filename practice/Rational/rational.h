#ifndef RATIONAL_H
#define RATIONAL_H
#include <iostream>
using namespace std;

class Rational {
friend ostream& operator<< (ostream& out, const Rational& rhs);
private:
    long num;
    long den;
    long gcd(long, long);
public:
    Rational(long num = 0, long den = 1);
    Rational(const Rational& rhs);
    
    const Rational& operator+=(long num);
    const Rational& operator-=(long num);
    const Rational& operator*=(long num);
    const Rational& operator/=(long num);
    const Rational& operator++();
    const Rational operator++(int);
    const Rational& operator--();
    const Rational operator--(int);
};

const Rational operator+(const Rational& lhs, const Rational& rhs);
const Rational operator-(const Rational& lhs, const Rational& rhs);
const Rational operator*(const Rational& lhs, const Rational& rhs);
const Rational operator/(const Rational& lhs, const Rational& rhs);
bool operator==(const Rational& lhs, const Rational& rhs);
bool operator!=(const Rational& lhs, const Rational& rhs);
bool operator<=(const Rational& lhs, const Rational& rhs);
bool operator>=(const Rational& lhs, const Rational& rhs);
bool operator<(const Rational& lhs, const Rational& rhs);
bool operator>(const Rational& lhs, const Rational& rhs);

Rational rabs(const Rational& rhs);

#endif