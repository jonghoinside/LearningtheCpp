//
// Created by user on 2021-06-09.
//
#ifndef ACCELERATED_PTR_H
#define ACCELERATED_PTR_H

#include <stdexcept>

template <typename T>
class Ptr {
public:
    Ptr();
    Ptr(T * ptr);
    Ptr(const Ptr<T>& rhs);
    ~Ptr();

    Ptr<T>& operator=(const Ptr<T>& rhs);

    void make_unique();

    operator bool() const { return p; }
    T& operator*() const;
    T* operator->() const;
private:
    T * p;
    std::size_t * refPtr;
};

template <typename T>
Ptr<T>::Ptr()
: p(0), refPtr(new std::size_t(1)) {

}
template <typename T>
Ptr<T>::Ptr(T * ptr)
: p(ptr), refPtr(new std::size_t(1)) {

}
template <typename T>
Ptr<T>::Ptr(const Ptr<T>& rhs)
: p(rhs.p), refPtr(rhs.refPtr) {
    ++(*this->refPtr);
}
template <typename T>
Ptr<T>::~Ptr() {
    --(*this->refPtr);
    if (*this->refPtr == 0) {
        delete this->p;
        delete this->refPtr;
    }
}
template <typename T>
void Ptr<T>::make_unique() {
    if (*this->refPtr != 1) {
        --(*this->refPtr);
        this->refPtr = new std::size_t(1);
        this->p = (this->p ) ? this->p->clone() : 0;
    }
}
template <typename T>
Ptr<T>& Ptr<T>::operator=(const Ptr<T>& rhs) {
    if (this != &rhs) {
        --(*this->refPtr);
        if (*this->refPtr == 0) {
            delete this->p;
            delete this->refPtr;
        }

        this->p = rhs.p;
        this->refPtr = rhs.refPtr;
        ++*this->refPtr;
    }
    return *this;
}
template <typename T>
T& Ptr<T>::operator*() const {
    if (p )
        return *p;
    throw std::runtime_error("Unbound Ptr");
}
template <typename T>
T* Ptr<T>::operator->() const {
    if (p )
        return p;
    throw std::runtime_error("Unbound Ptr");
}

#endif //ACCELERATED_Ptr_H