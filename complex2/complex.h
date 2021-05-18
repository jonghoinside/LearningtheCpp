#ifndef COMPLEX_H
#define COMPLEX_H

class Complex {
private :
	double re;
	double im;

public :
//	Complex();							// default constructor
//	Complex(double re);					// convert constructor
	Complex(double re = 0.0, double im = 0.0);		// default 인자는 뒤에서부터 사용됨
	// Complex(const Complex* pc); pointer는 못쓴다. Compex c4 = &c3이라는 이상한 형식이 되버린다.
	Complex(const Complex& rhs);		// left hand side / right hand side, rhs
											//	copy constructor 복사 생성자의 타입은 const T&타입의 레퍼런스다.
	~Complex();
	
	// void operator=(Complex C);		//	performance X
	// void operator=(const Complex* pc);		//	X			둘다 되긴 한다. 모양이 이상할뿐
	Complex& operator=(const Complex& rhs);		//	*=, -=, *=, /=, <<=, >>=
	
	const Complex operator+(const Complex& rhs);		// -, *, /
	bool operator==(const Complex& rhs);		//	!=, >, <, <=, >=
	
	double real();
	double imag();
	
	void real(double re);
	void imag(double im);
};

#endif
