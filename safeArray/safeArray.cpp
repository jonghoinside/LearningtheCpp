#include <cassert>
#include "safeArray.h"

const int SafeArray::SAFEARRAY_SIZE = 10;

SafeArray::SafeArray(int size) 
: Array(size) {

}
SafeArray::SafeArray(const int *pArr, int size)
: Array(pArr, size) {

}
SafeArray::SafeArray(const SafeArray& rhs) 
: Array( (Array)rhs){

}
SafeArray::~SafeArray() {

}
SafeArray& SafeArray::operator=(const SafeArray& rhs) {
    this->Array::operator=((Array)rhs);

    return *this;
}
bool SafeArray::operator==(const SafeArray& rhs) const{
    return this->Array::operator==((Array)rhs);
}
int& SafeArray::operator[](int index) {
//    assert(index >= 0 && index < this->size());      //assert(index >= 0 && index < this->Array::size());
    assert(index >= 0 && index < this->Array::size_);
    return this->Array::operator[](index);          // 부모 쪽에 있는 함수를 사용하면서 기능을 추가하는 예제 모습
}
const int& SafeArray::operator[](int index) const {
//    assert(index >= 0 && index < this->size());
    assert(index >= 0 && index < this->Array::size_);

    return this->Array::operator[](index);
}