#ifndef BOUNDARRAY_H
#define BOUNDARRAY_H
#include <cassert>
#include "safeArray.h"

template <typename T>
class BoundArray : public SafeArray<T> {
private:
    int lower_;
    int upper_;
public:
    BoundArray(int lower, int upper);
    BoundArray(int lower, int upper, const T *pArr);
    BoundArray(const BoundArray<T>& rhs);
    virtual ~BoundArray() { }
    BoundArray<T>& operator=(const BoundArray<T>& rhs);
    // const BoundArray *operator&() const {return this;}

    virtual T& operator[](int index);
    virtual const T& operator[](int index) const;

    int lower() const;
    int upper() const;
    // int lower() const;
    // int upper() const;

};

template <typename T>
BoundArray<T>::BoundArray(int lower, int upper)
: SafeArray<T>(upper - lower + 1), lower_(lower), upper_(upper) {

}
template <typename T>
BoundArray<T>::BoundArray(int lower, int upper, const T *pArr)
: SafeArray<T>(upper - lower + 1), lower_(lower), upper_(upper) {
    for (int i = lower; i <= upper; ++i)
        this->SafeArray<T>::operator[](i - lower) = pArr[i];

}
template <typename T>
BoundArray<T>::BoundArray(const BoundArray<T>& rhs)
: SafeArray<T>(static_cast<SafeArray<T> >(rhs)), lower_(rhs.lower_), upper_(rhs.upper_) {

}

// emplate <typename T>
// BoundArray<T>::BoundArray(const BoundArray<T>& rhs)
// : SafeArray<T>(static_cast<SafeArray<T> >(rhs)), lower_(rhs.lower_), upper_(rhs.upper_) {

// }

template <typename T>
BoundArray<T>& BoundArray<T>::operator=(const BoundArray<T>& rhs) {
    this->SafeArray<T>::operator=(static_cast<SafeArray<T> >(rhs));
    lower_ = rhs.lower_;
    upper_ = rhs.upper_;
}

template <typename T>
T& BoundArray<T>::operator[](int index) {
//    assert(index >= lower_ && index <= upper_);
    if (index < lower_ || index > upper_)
        throw InvalidIndex(index);

    return this->SafeArray<T>::operator[](index - lower_);
}
template <typename T>
const T& BoundArray<T>::operator[](int index) const {
//    assert(index >= lower_ && index <= upper_);
    if (index < lower_ || index > upper_)
        throw InvalidIndex(index);

    return this->SafeArray<T>::operator[](index - lower_);
}
template <typename T>
int BoundArray<T>::lower() const {
    return lower_;
}
template <typename T>
int BoundArray<T>::upper() const {
    return upper_;
}

#endif