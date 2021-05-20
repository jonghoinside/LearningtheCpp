#ifndef SAFEARRAY_H
#define SAFEARRAY_H
#include "array.h"

class SafeArray : public Array {    //  부모(public)쪽의 상속을 어디로 할건지 
private:
    static const int SAFEARRAY_SIZE;
public:
    //SafeArray();
    explicit SafeArray(int size = SafeArray::SAFEARRAY_SIZE);
    SafeArray(const int *pArr, int size);
    SafeArray(const SafeArray& rhs);
    virtual ~SafeArray();

    //SafeArray *operator&() { return this; }
    //const SafeArray *operator&() const { return this; }

    SafeArray& operator=(const SafeArray& rhs);

    bool operator==(const SafeArray& rhs) const;

    virtual int& operator[](int index);
    virtual const int& operator[](int index) const;
};

#endif