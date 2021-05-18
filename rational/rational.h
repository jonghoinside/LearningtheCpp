#ifndef RATIONAL_H
#define RATIONAL_H

class Rational {
private:
	double mol;
	double den;
public:
	Rational();
	Rational(double mol);
	Rational(double mol, double den);
	~Rational();
	
	double molecular();
	double denominator();
	
	void molecular(double mol);
	void denominator(double den);
};

#endif
