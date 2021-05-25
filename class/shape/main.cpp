#include <iostream>
#include <typeinfo>
#include "shape.h"
#include "rectangle.h"
#include "circle.h"

void printArea(const Shape *ps) {
    if (typeid(*ps) == typeid(Rectangle))                        //  runtime type identification (RTTI)
        std::cout << "rectangle ";
    else if (typeid(*ps) == typeid(Circle))
        std::cout << "circle ";

    std::cout << "area : " << ps->area() << std::endl;
}

int main() {
//    Shape s(100,200);
    Shape *shapes[5];
    shapes[0] = new Rectangle(50, 50, 100, 10);
    shapes[1] = new Circle(100, 100, 15);
    shapes[2] = new Rectangle(0, 0, 5, 10);
    shapes[3] = new Rectangle(200, 200, 50, 50);
    shapes[4] = new Circle(200, 100, 50);

    for (int i = 0 ; i < 5 ; ++i)
        printArea(shapes[i]);

    for (int i = 0 ; i < 5 ; ++i)
        delete shapes[i];

    return 0;
}