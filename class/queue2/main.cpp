#include <iostream>
#include "queue.h"

int main() {
    Queue q1(100);
    Queue q2;

    q1.push(100);
    q1.push(200);
    q1.push(300);

    std::cout << q1;

    while( !q1.empty() ) {
        std::cout << "q1 is " << q1.pop() << std::endl;
    }

    return 0;
}