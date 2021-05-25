#ifndef SHAPE_H
#define SHAPE_H

class Shape {
protected:
    int x_;
    int y_;

public:
    Shape(int x, int y);
    // Shape(const Shape& rhs);
    virtual ~Shape() {}
    // Shape& operator=(const Shape& rhs);
    // Shape *operator&() {return this;}
    // const Shape *operator&() const {return this;}

    void move(int x, int y);
    virtual double area() const = 0;    // pure virtual func. 순수 가상 함수
};

#endif