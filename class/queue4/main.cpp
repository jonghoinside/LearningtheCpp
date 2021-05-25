#include <iostream>
#include "queue.h"
#include "rational.h"
#include "complex.h"

int main() {
    Queue<int> q1;

    q1.push(100);
    q1.push(200);
    q1.push(300);

    std::cout << q1;

    while( !q1.empty() ) {
        std::cout << "q1 is " << q1.pop() << std::endl;
    }

    Queue<Rational> q2;

    q2.push(Rational(1, 2));
    q2.push(Rational(3, 4));
    q2.push(Rational(5, 6));

    std::cout << q2;

    while( !q2.empty() ) {
        std::cout << "q2 is " << q2.pop() << std::endl;
    }

    Queue<Complex> q3;

    q3.push(Complex(1, 2));
    q3.push(Complex(3, 4));
    q3.push(Complex(5, 6));

    std::cout << q3;

    while( !q3.empty() ) {
        std::cout << "q3 is " << q3.pop() << std::endl;
    }

    return 0;
}