#include <iostream>
#include "complex.h"

Complex *Complex::headOfFreeList = NULL;
const int Complex::BSIZE = 256;

std::istream& operator>>(std::istream& in, Complex& rhs) {
	double re = 0.0;
	double im = 0.0;

	char c = 0;

	in >> c;

	if (c == '(') {
		in >> re >> c;
		if (c == ',')
			in >> im >> c;
		if (c == 'i')
			in >> c;
		if (c != ')')
			in.clear(std::ios::failbit);
		
	} else {
		in.putback(c);
		in >> re;
	}

	if (in )
		rhs = Complex(re, im);

	return in;
}

std::ostream& operator<<(std::ostream& out, const Complex& rhs) {
	out << "(" << rhs.re << ", " << rhs.im << "i)";
	
	return out;
}

void * Complex::operator new(size_t size) {
	if (size != sizeof(Complex))
		return ::operator new(size);
	
	Complex *p = headOfFreeList;

	if (p ) {
		headOfFreeList = headOfFreeList->next;
	} else {
		Complex * newBlock = reinterpret_cast<Complex *>(::operator new(BSIZE * sizeof(Complex)));
		for (int i = 0; i < BSIZE-1 ; ++i) {
			newBlock[i].next = &newBlock[i+1];
		}
		newBlock[BSIZE-1].next = NULL;

		p = &newBlock[0];
		headOfFreeList = &newBlock[1];
	}

	return p;
}

void Complex::operator delete(void *ptr, size_t size) {
	if (size != sizeof(Complex)) {
		::operator delete(ptr);
		return;
	}
	Complex * p = reinterpret_cast<Complex *>(ptr);
	p->next = headOfFreeList;
	headOfFreeList = p;
}

Complex::Complex(double re, double im) {
	this->re = re;
	this->im = im;
}
Complex::Complex(const Complex& rhs) {
	this->re = rhs.re;
	this->im = rhs.im;
}
Complex::~Complex() {

}
double Complex::getreal(void) const{
	return this->re;
}
double Complex::getimag(void) const{
	return this->im;
}
void Complex::real(double re) {
	this->re = re;
}
void Complex::imag(double im) {
	this->im = im;
}
Complex& Complex::operator=(const Complex& rhs) {
	this->re = rhs.re;
	this->im = rhs.im;
	return *this;
}
Complex& Complex::operator=(double re) {
	this->re = re;
	return *this;
}
bool Complex::operator==(const Complex& rhs) const{
	return (this->re == rhs.re && this->im == rhs.im);
}
bool Complex::operator!=(const Complex& rhs) const{
//	return !this->operator==(rhs);
	return (this->re != rhs.re || this->im != rhs.im);
}
const Complex Complex::operator+(const Complex& rhs) const{
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
