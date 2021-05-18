#include <iostream>
#include <cassert>
#include "rational.h"

static int getGCD(int num, int den) {

	int remain;
	while (remain = num % den) {
		num = den;
		den = remain;
	}
	
	return den;
}

void Rational::doAbbreviation() {
	int gcd = getGCD(this->mol, this->den);
	
	this->mol = this->mol / gcd;
	this->den = this->den / gcd;
}

Rational::Rational(int mol, int den) {
	assert(den != 0);
	
	this->mol = mol;
	this->den = den;
	
	this->doAbbreviation();
}
Rational::Rational(const Rational& rhs) {
	this->mol = rhs.mol;
	this->den = rhs.den;
}
Rational::~Rational() {
	
}

Rational& Rational::operator=(const Rational& rhs) {
	this->mol = rhs.mol;
	this->den = rhs.den;
	
	return *this;
}
bool Rational::operator==(const Rational& rhs) {
	return (this->mol == rhs.mol && this->den == rhs.den);
//	return (this->num * rhs.den == rhs.num * this->den);
}
const Rational Rational::operator+(const Rational& rhs) {
/*
	int tmp_mol, tmp_den;
	
	tmp_mol = (this->mol * rhs.den) + (rhs.mol * this->den);
	tmp_den = this->den * rhs.den;
	
	if (tmp_mol%this->den == 0 && tmp_den%this->den == 0) {
		tmp_mol /= this->den;
		tmp_den /= this->den;
	}
	else if (tmp_mol%rhs.den == 0 && tmp_den%rhs.den == 0) {
		tmp_mol /= rhs.den;
		tmp_den /= rhs.den;
	}

	Rational tmp(tmp_mol, tmp_den);
	return tmp;
*/	
	return Rational((this->mol * rhs.den) + (rhs.mol * this->den), this->den * rhs.den);
}
int Rational::getMol() {
	return this->mol;
}
int Rational::getDen() {
	return this->den;
}
