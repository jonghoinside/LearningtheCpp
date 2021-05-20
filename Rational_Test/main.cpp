#include <iostream>
#include "rational.h"

int main() {
    // 생성

    Rationaltest ra1;
    Rationaltest ra2(9); 
    Rationaltest ra3(9, 18);
    Rationaltest ra4 = ra2;
    // 치환
    ra1 = ra3;
    // 비교
    if (ra2 == ra4 && ra1 == ra3)
        std::cout << "wow!" <<std::endl;
    // + 연산
    ra4 = ra2 + ra3;

    // 출력
    ra1.printRational();
    ra2.printRational();
    ra3.printRational();
    ra4.printRational();

    // 소멸


    return 0;
}