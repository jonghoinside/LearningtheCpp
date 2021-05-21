#ifndef COMPLEX_H
#define COMPLEX_H

class Complex {
private:
	double re;	//	real part
	double im;	// imaginary part
public:
	Complex();
	Complex(double re);
	Complex(double re, int im);
	~Complex();
	
	double real();
	double imag();
	
	void real(double re);
	void imag(double re);
	
//	void real(double re, int im);
//	void imag(double re, int im);
};

#endif
