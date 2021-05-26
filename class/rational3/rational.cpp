#include "rational.h"

std::istream& operator>>(std::istream& in, Rational& rhs) {
	int num = 0;
	int den = 1;

	in >> num;
	if (in.peek() == '/') {
		in.ignore();
		in >> den;
	}
	if (in )
		rhs = Rational(num, den);

	return in;
}

std::ostream& operator<<(std::ostream& out, const Rational& rhs) {
	out << rhs.num << " / " << rhs.den;
	return out;
}

static int getGCD(int num, int den) {
	int remain;
	while(remain = num%den) {
		num = den;
		den = remain;
	}
	return den;
}

void Rational::doAbbreviation() {
	int gcd = getGCD(this->num, this->den);
	this->num = num / gcd;
	this->den = den / gcd;
}

Rational::Rational(int num, int den) {
	this->num = num;
	this->den = den;
	this->doAbbreviation();
}
Rational::Rational(const Rational& rhs) {
	this->num = rhs.num;
	this->den = rhs.den;
}
Rational::~Rational() {
	
}
Rational& Rational::operator=(const Rational& rhs) {
	this->num = rhs.num;
	this->den = rhs.den;
	return *this;
}
bool Rational::operator==(const Rational& rhs) {
	return (this->num == rhs.num && this->den == rhs.den);
}
const Rational Rational::operator+(const Rational& rhs) {
	return Rational(this->num * rhs.den + this->den * rhs.num, this->den * rhs.den);
}
Rational& Rational::operator++() {
	this->num += this->den;
	return *this;
}
Rational Rational::operator++(int ) {
	Rational tmp = *this;
	this->num += this->den;
	return tmp;
}