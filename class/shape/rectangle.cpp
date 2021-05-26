#include "rectangle.h"

Rectangle::Rectangle(int x, int y, int width, int height)
: Shape(x, y), width_(width), height_(height) {

}

double Rectangle::area() const {
    return width_ * height_;
}

int Rectangle::width() const {
    return width_;
}

int Rectangle::height() const {
    return height_;
}