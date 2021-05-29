#ifndef COMPLEX_H
#define COMPLEX_H
#include <iostream>

class Complex {
friend std::istream& operator>>(std::istream& in, Complex& rhs);
friend std::ostream& operator<<(std::ostream& out, const Complex& rhs);

private:
	union {
		struct {
			double re;
			double im;
		};
		Complex *next;
	};

	static Complex *headOfFreeList;
	static const int BSIZE;
public:
	static void * operator new(size_t size);
	static void operator delete(void *ptr, size_t size);

	Complex(double re = 0.0, double im = 0.0);
	Complex(const Complex& rhs);
	~Complex();
	
	Complex& operator=(const Complex& rhs);
	Complex& operator=(double re);
	bool operator==(const Complex& rhs) const;
	bool operator!=(const Complex& rhs) const;
	
	const Complex operator+(const Complex& rhs) const;
	
	Complex& operator++();				// prefix
	
	Complex operator++(int );		// postfix
	
	double getreal(void) const;
	double getimag(void) const;
	
	void real(double re);
	void imag(double im);
};

#endif
