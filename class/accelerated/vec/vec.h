//
// Created by user on 2021-06-07.
//

#ifndef ACCELERATED_VEC_H
#define ACCELERATED_VEC_H

#include <algorithm>
#include <memory>

template <typename T>
class Vec {
public:
    typedef T* iterator;
    typedef const T* const_iterator;
    typedef size_t size_type;
    typedef T value_type;
    typedef std::ptrdiff_t difference_type;
    typedef T& reference;
    typedef const T& const_reference;


    Vec();
    explicit Vec(size_type size, const T& val = T());
    Vec(const Vec<T>& rhs);
    ~Vec();
    Vec<T>& operator=(const Vec<T>& rhs);

    size_type size() const;
    T& operator[](int index);
    const T& operator[](int index) const;

    iterator begin();
    iterator end();

    const_iterator cbegin() const;
    const_iterator cend() const;

    void push_back(const T& val);

    iterator erase(iterator it);
    iterator erase(const T& val);
    void clear();

private:
    T* data;
    T* avail;
    T* limit;

    std::allocator<T> alloc;

    void create();
    void create(size_type n, const T& val);
    void create(const_iterator b, const_iterator e);
    void uncreate();

    void grow();
    void unchecked_append(const T&);
};

template <typename T>
Vec<T>::Vec() {
    this->create();
}
template <typename T>
Vec<T>::Vec(size_type size, const T& val) {
    this->create(size, val);
}
template <typename T>
Vec<T>::Vec(const Vec<T>& rhs) {
    this->create(rhs.cbegin(), rhs.cend());
}
template <typename T>
Vec<T>::~Vec() {
    this->uncreate();
}
template <typename T>
Vec<T>& Vec<T>::operator=(const Vec<T>& rhs) {
    if (this != &rhs) {
        this->uncreate();

        this->create(rhs.cbegin(), rhs.cend());
    }
    return *this;
}
template <typename T>
void Vec<T>::create() {
    this->data = 0;
    this->avail = 0;
    this->limit = 0;
}
template <typename T>
void Vec<T>::create(size_type n, const T& val) {
    this->data = this->alloc.allocate(n);
    std::uninitialized_fill(this->data, this->data + n, val);

    this->avail = this->data + n;
    this->limit = this->data + n;
}
template <typename T>
void Vec<T>::create(Vec<T>::const_iterator b, Vec<T>::const_iterator e) {
    this->data = this->alloc.allocate(e - b);
    std::uninitialized_copy(b, e, this->data);

    this->avail = this->data + (e - b);
    this->limit = this->data + (e - b);
}
template <typename T>
void Vec<T>::uncreate() {
    if(this->data ) {
        typename Vec<T>::iterator it = this->avail;
        while (it != this->data) {
            this->alloc.destroy(it);
            --it;
        }
        this->alloc.deallocate(this->data, this->limit - this->data);
    }
    this->data = this->limit = this->avail = 0;
}
template <typename T>
typename Vec<T>::size_type Vec<T>::size() const {
    return (this->avail - this->data);
}
template <typename T>
T& Vec<T>::operator[](int index) {
    return this->data[index];
}
template <typename T>
const T& Vec<T>::operator[](int index) const {
    return this->data[index];
}
template <typename T>
typename Vec<T>::iterator Vec<T>::begin() {
    return this->data;
}
template <typename T>
typename Vec<T>::iterator Vec<T>::end() {
    return this->avail;
}
template <typename T>
typename Vec<T>::const_iterator Vec<T>::cbegin() const {
    return this->data;
}
template <typename T>
typename Vec<T>::const_iterator Vec<T>::cend() const {
    return this->avail;
}
template <typename T>
void Vec<T>::push_back(const T &val) {
    if(this->avail == this->limit)
        this->grow();
    this->unchecked_append(val);
}
template <typename T>
typename Vec<T>::iterator Vec<T>::erase(const T& val) {
    typename Vec<T>::iterator it = this->data;
    if(this->data ) {
        while (it != this->avail) {
            if(*it == val)
                break;
            ++it;
        }
        if (it != this->avail) {
            this->alloc.destroy(it);
            std::copy(it + 1, this->avail, it);
            --this->avail;
            this->alloc.destroy(this->avail);
        }
    }
    return it;
}
template <typename T>
typename Vec<T>::iterator Vec<T>::erase(Vec<T>::iterator it) {
    this->alloc.destroy(it);
    std::copy(it + 1, this->avail, it);
    --this->avail;
    this->alloc.destroy(this->avail);

    return it;
}

template <typename T>
void Vec<T>::clear() {
    if(this->data ) {
        typename Vec<T>::iterator it = this->avail;
        while (it != this->data) {
            this->alloc.destroy(it);
            --it;
        }
        this->data = this->avail = 0;
    }
}

template <typename T>
void Vec<T>::grow() {
    typename Vec<T>::size_type  new_size;

    if (this->data )
        new_size = 1;
    else
        new_size = 2 * (this->limit - this->data);

    Vec<T>::iterator new_data = this->alloc.allocate(new_size);
    Vec<T>::iterator new_avail = std::uninitialized_copy(this->data, this->avail, new_data);

    this->uncreate();
    this->data = new_data;
    this->avail = new_avail;
    this->limit = this->data + new_size;
}
template <typename T>
void Vec<T>::unchecked_append(const T& val) {
    this->alloc.construct(this->avail, val);
    ++this->avail;
}

#endif //ACCELERATED_VEC_H