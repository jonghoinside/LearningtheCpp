#include "complex.h"

Complex::Complex() {
	this->re = 0.0;
	this->im = 0.0;
}

Complex::Complex(double re){
	this->re = re;
	this->im = 0.0;
}

Complex::Complex(double re, int im){
	this->re = re;
	this->im = im;
}

Complex::~Complex(){
	
}

double Complex::real() {
	return this->re;
}

double Complex::imag() {
	return this->im;
}

void Complex::real(double re) {
	this->re = re;
}

void Complex::imag(double im) {
	this->im = im;
}
