#ifndef ARRAY_H
#define ARRAY_H
// #define ARRAY_SIZE 10
//extern const int ARRAY_SIZE;


class Array {
private:
    static const int ARRAY_SIZE;

    int* pArr_;
protected:
    int size_;
public:
    explicit Array(int size = Array::ARRAY_SIZE);
    Array(const int* pArr, int size);
    Array(const Array &rhs);
    virtual ~Array();
//    Array* operator&() {return this;}
//    const Array* operator&() const {return this};
    Array& operator=(const Array& rhs);

    bool operator==(const Array &rhs) const;

    virtual int& operator[](int index);
    virtual const int& operator[](int index) const;

    int size() const;
};

#endif