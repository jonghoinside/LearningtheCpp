#include "complex.h"
/*
Complex::Complex() {
	this->re = 0.0;
	this->im = 0.0;
}

Complex::Complex(double re) {
	this->re = re;
	this->im = 0.0;
}
*/ 
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

Complex& Complex::operator=(const Complex& rhs) {
	this->re = rhs.re;
	this->im = rhs.im;
	return *this;
}

const Complex Complex::operator+(const Complex& rhs) {
//	const 를 안붙이면 연산의 오른쪽에도 상수가 아닌 변수가 될 수 도 있다.
	Complex re(this->re + rhs.re, this->im + rhs.im);
	return re;
}

bool Complex::operator==(const Complex& rhs) {
	return (this->re == rhs.re && this->im == rhs.im);
}


double Complex::real(){
	return this->re;
}
double Complex::imag(){
	return this->im;
}

void Complex::real(double re){
	this->re = re;
}
void Complex::imag(double im){
	this->im = im;
}
