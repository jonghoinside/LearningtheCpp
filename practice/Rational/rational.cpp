inline Rational& Rational::operator=(long rhs) {
num = rhs; den = 1;
return *this;
}
inline double toDouble (const Rational& r) {
return double(r.numerator())/r.denominator();
}
inline long trunc(const Rational& r) {
return r.numerator() / r.denominator();
}
inline long floor(const Rational& r) {
long q = r.numerator() / r.denominator();
return (r.numerator() < 0 && r.denominator() != 1) ? --q : q;
}
inline long ceil(const Rational& r) {
long q = r.numerator() / r.denominator();
return (r.numerator() >= 0 && r.denominator() != 1) ? ++q : q;
}
Rational toRational(double x, int iterations = 5);

