#ifndef RATIONAL_H
#define RATIONAL_H

class Rationaltest {
public:
    int son_;
    int mom_;

    Rationaltest(int son = 0, int mom = 1);
    Rationaltest(const Rationaltest& rhs);

    Rationaltest& operator=(const Rationaltest& rhs);

    bool operator==(const Rationaltest& rhs);

    const Rationaltest operator+(const Rationaltest& rhs);

    void printRational();
};

#endif