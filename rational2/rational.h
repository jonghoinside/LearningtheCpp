#ifndef RATIONAL_H
#define RATIONAL_H

class Rational {
private:
	int mol;
	int den;
	
	void doAbbreviation();		// helper function or tool function
	
public:
	Rational(int mol = 0, int den = 1);
	Rational(const Rational& rhs);
	~Rational();
	
	Rational& operator=(const Rational& rhs);
	bool operator==(const Rational& rhs);
	const Rational operator+(const Rational& rhs);
	
	int getMol();
	int getDen();
};

#endif
