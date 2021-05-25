#include "rectangle.h"

Rectangle::Rectangle(int x, int y, int width, int height)
: Shape(x, y), width_(width), height_(height) {

}

double Rectangle::area() const {
    return width_ * height_;
}