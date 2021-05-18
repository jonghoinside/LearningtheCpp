#include <cassert>
#include "rational.h"

std::ostream& operator<<(std::ostream& out, const Rational& rhs) {
	return out << rhs.num << "/" << rhs.den;
}
void Rational::doAbbreviation() {
	int num = this->num;
	int den = this->den;
	
	int remain;
	while(remain = num%den) {
		num = den;
		den = remain;
	}
	
	int gcd = den;
	this->num = this->num / gcd;
	this->den = this->den / gcd;
}
Rational::Rational(int num, int den) {
	assert(den != 0);
	
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
void Rational::setNum(int num) {
	this->num = num;
}
void Rational::setDen(int den) {
	this->den = den;
}
int Rational::getNum() const {
	return this->num;
}
int Rational::getDen() const {
	return this->den;
}
Rational& Rational::operator=(const Rational& rhs) {
	this->num = rhs.num;
	this->den = rhs.den;
	
	return *this;
}
bool Rational::operator==(const Rational& rhs) const {
	return (this->num == rhs.num && this->den == rhs.den);
}
const Rational Rational::operator+(const Rational& rhs) const {
	return Rational(this->num * rhs.den + this->den * rhs.num, this->den * rhs.den);
}
Rational& Rational::operator++() {
//	*this = *this + 1;
	this->num = this->num + this->den;
	
	return *this;
}
Rational Rational::operator++(int ) {
	Rational result(*this);
	this->operator++();
	
	return result;
}
