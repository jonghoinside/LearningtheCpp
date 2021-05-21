#ifndef RATIONAL_H
#define RATIONAL_H
#include <iostream>
#include <cstdio>

extern char board[][50];

class Rational {
friend std::ostream& operator<<(std::ostream& out, const Rational& rhs);
private:
    long num_;
    long den_;
    void doAbbreviation();
public:
    Rational(long num = 0, long den = 1);
    Rational(const Rational& rhs);

    long getNum();
    long getDen();
    void setRational(long num = 0, long den = 1);

    Rational& operator=(const Rational& rhs);

    const Rational operator+(const Rational& rhs);
    const Rational operator-(const Rational& rhs);
    const Rational operator*(const Rational& rhs);
    const Rational operator/(const Rational& rhs);

    void setBoard(int inputCount);
};

void printBoard();

#endif