#include "shape.h"

Shape::Shape(int x, int y)
: x_(x), y_(y){


}

void Shape::move(int x, int y)
{
    x_ += x;
    y_ += y;
}