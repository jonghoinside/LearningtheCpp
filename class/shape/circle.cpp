#include "circle.h"

Circle::Circle(int x, int y, int radius)
: Shape(x, y), radius_(radius) {

}

double Circle::area() const {
    return 3.141592 * radius_ * radius_;
}

int Circle::radius() const {
    return radius_;
}