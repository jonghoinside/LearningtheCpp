#include "complex.h"

std::ostream& operator<<(std::ostream& out, const Complex& rhs) {
	out << "(" << rhs.re << ", " << rhs.im << "i)";
	
	return out;
}

Complex::Complex(double re, double im) {
	std::cout << "1\n";
	this->re = re;
	this->im = im;
}
Complex::Complex(const Complex& rhs) {
	std::cout << "2\n";
	this->re = rhs.re;
	this->im = rhs.im;
}
Complex::~Complex() {

}
double Complex::getreal(void) {
	return this->re;
}
double Complex::getimag(void) {
	return this->im;
}
void Complex::real(double re) {
	this->re = re;
}
void Complex::imag(double im) {
	this->im = im;
}
Complex& Complex::operator=(const Complex& rhs) {
	std::cout << "3\n";
	this->re = rhs.re;
	this->im = rhs.im;
	return *this;
}
Complex& Complex::operator=(double re) {
	std::cout << "4\n";
	this->re = re;
	return *this;
}
bool Complex::operator==(const Complex& rhs) {
	return (this->re == rhs.re && this->im == rhs.im);
}
const Complex Complex::operator+(const Complex& rhs) {
	return Complex(this->re + rhs.re , this->im + rhs.im);
}
Complex& Complex::operator++() {
	this->re += 1.0;
	
	return *this;
}
Complex Complex::operator++(int ) {
	Complex tmp(*this);
	this->re += 1.0;
	
	return tmp;
}
