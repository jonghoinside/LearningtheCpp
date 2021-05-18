#include <cassert>
#include <iostream>
#include "rational.h"

Rational::Rational() {
	this->mol = 0.0;
	this->den = 1.0;
}
Rational::Rational(double mol) {
	this->mol = mol;
	this->den = 1.0;
}
Rational::Rational(double mol, double den) {	
	assert(den != '0');
	
	
	this->mol = mol;
	this->den = den;
}
Rational::~Rational() {

}
 
double Rational::molecular() {
	return this->mol;
}
double Rational::denominator() {
	return this->den;
}

void Rational::molecular(double mol) {
	this->mol = mol;
}
void Rational::denominator(double den) {
	this->den = den;
}
