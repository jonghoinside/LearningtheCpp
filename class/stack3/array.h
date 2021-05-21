#ifndef ARRAY_H
#define ARRAY_H
#define ARRAY_SIZE 10

class Array {
private:
    int* pArr_;
    int size_;
public:
    explicit Array(int size = ARRAY_SIZE);
    Array(const int* pArr, int size);
    Array(const Array &rhs);
    ~Array();
//    Array* operator&() {return this;}
//    const Array* operator&() const {return this};
    Array& operator=(const Array& rhs);

    bool operator==(const Array &rhs) const;

    int& operator[](int index);
    const int& operator[](int index) const;

    int size() const;
};

#endif