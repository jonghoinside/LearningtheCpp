#ifndef RATIONAL_H
#define RATIONAL_H
#include <iostream>

class Rational {
friend std::ostream& operator<<(std::ostream& out, const Rational& rhs);
private:
	int num;
	int den;
	void doAbbreviation();
public:
	Rational(int num = 0, int den = 1);
	Rational(const Rational& rhs);
	~Rational();
	
	void setNum(int num);
	void setDen(int den);
	int getNum() const;
	int getDen() const;
	
	Rational& operator=(const Rational& rhs);
	bool operator==(const Rational& rhs) const;
	const Rational operator+(const Rational& rhs) const;
	Rational& operator++();
	Rational operator++(int );
	
	void printRational() const;
};


#endif
