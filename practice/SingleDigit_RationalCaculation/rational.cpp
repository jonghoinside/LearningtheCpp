#include <cstdlib>
#include <cassert>
#include "rational.h"

char board[][50] = {
	" [1]       [2]        ",
	"_____     _____        _____",
	"|   |     |   |        |   |",
	"-----     -----        -----",
	"-----     -----  =     -----",
	"_____     _____        _____",
	"|   |     |   |        |   |",
	"-----     -----        -----"
};
void printBoard() {
	system("clear");
	for (int i = 0 ; i < 8 ; ++i)
		printf("%s\n", &board[i][0]);
}
void Rational::setBoard(int inputCount) {
//  인풋카운트가 0일 때는 첫번째 레셔널값 (2,2) (6,2)
//  인풋카운트가 1일 때는 두번째 레셔널값 (2,12) (6,12)
//  인풋카운트가 2일 때는 세번째 레셔널값 (2,22) (6,22)
    if ( num_ * den_ < 0 ) 
        board[4][20] = '-';
    if ( inputCount < 2) {
        board[2][2 + inputCount*10] = ((num_ > 0) ? num_ : -num_) + '0';     // 왼쪽 위
        board[6][2 + inputCount*10] = ((den_ > 0) ? den_ : -den_) + '0';     // 왼쪽 아래
    } else {
        board[2][5 + inputCount*10] = ((num_ > 0) ? num_ : -num_) + '0';     // 왼쪽 위
        board[6][5 + inputCount*10] = ((den_ > 0) ? den_ : -den_) + '0';     // 왼쪽 아래
    }
}

std::ostream& operator<<(std::ostream& out, const Rational& rhs){
    out << rhs.num_ << " / " << rhs.den_;
    return out;
}
void Rational::doAbbreviation() {
	int num = num_;
	int den = den_;
	
	int remain;
	while(remain = num%den) {
		num = den;
		den = remain;
	}

	num_ /= den;
	den_ /= den;
}
Rational::Rational(long num, long den) {
    assert(den != 0);

    num_ = num;
    den_ = den;

    doAbbreviation();
}
Rational::Rational(const Rational& rhs) {
    num_ = rhs.num_;
    den_ = rhs.den_;

    doAbbreviation();
}
long Rational::getNum() {
    return num_;
}
long Rational::getDen() {
    return den_;
}
void Rational::setRational(long num, long den) {
    num_ = num;
    den_ = (den == 0) ? 1 : den;

    doAbbreviation();
}
Rational& Rational::operator=(const Rational& rhs) {
    num_ = rhs.num_;
    den_ = rhs.den_;

    return *this;
}
const Rational Rational::operator+(const Rational& rhs) {
    return Rational(num_ * rhs.den_ + den_ * rhs.num_ , den_ * rhs.den_);
}
const Rational Rational::operator-(const Rational& rhs) {
    return Rational(num_ * rhs.den_ - den_ * rhs.num_ , den_ * rhs.den_);
}
const Rational Rational::operator*(const Rational& rhs) {
    return Rational(num_ * rhs.num_ , den_ * rhs.den_);
}
const Rational Rational::operator/(const Rational& rhs) {
    Rational answer(rhs.den_, rhs.num_);
    return *this * answer;
}