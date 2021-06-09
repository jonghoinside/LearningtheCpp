//
// Created by user on 2021-06-09.
//
#ifndef ACCELERATED_HANDLE_H
#define ACCELERATED_HANDLE_H

#include <stdexcept>

template <typename T>
class Handle {
public:
    Handle();
    Handle(T * ptr);
    Handle(const Handle<T>& rhs);
    ~Handle();

    Handle<T>& operator=(const Handle<T>& rhs);

    operator bool() const { return p; }
    T& operator*() const;
    T* operator->() const;
private:
    T * p;
};

template <typename T>
Handle<T>::Handle()
: p(0) {

}
template <typename T>
Handle<T>::Handle(T * ptr)
: p(ptr) {

}
template <typename T>
Handle<T>::Handle(const Handle<T>& rhs) {
    if(rhs.p )
        this->p = rhs.p->clone();
}
template <typename T>
Handle<T>::~Handle() {
    delete this->p;
}
template <typename T>
Handle<T>& Handle<T>::operator=(const Handle<T>& rhs) {
    if (this != &rhs) {
        delete this->p;

        this->p = (rhs.p ) ? rhs.p->clone() : 0;
    }
    return *this;
}
template <typename T>
T& Handle<T>::operator*() const {
    if (p )
        return *p;
    throw std::runtime_error("Unbound handle");
}
template <typename T>
T* Handle<T>::operator->() const {
    if (p )
        return p;
    throw std::runtime_error("Unbound handle");
}

#endif //ACCELERATED_HANDLE_H
