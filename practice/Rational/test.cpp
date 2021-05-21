#include <stdlib.h>
#include <math.h>
#include <limits>
#include "rational2.h"
	
Rational toRational(double x, int iterations){
	if(x == 0.0 || x < numeric_limits<long>::min() || x > numeric_limits<long>::max() ) {
		//return Rational(0,1);
	}
	//	return *this; //sign; //* toRational(sign* x, 1.0e12, iterations);
	
}

	
	
