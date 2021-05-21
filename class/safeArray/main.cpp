#include <iostream>
#include "array.h"
#include "safeArray.h"

int main() {
    int nums[] = {1, 2, 3, 4, 5};
    Array arr1(nums, 5);

    SafeArray arr2(nums, 5);

    for (int i = 0 ; i < arr1.size() ; ++i)
        std::cout << arr1[i] << " ";
    std::cout << std::endl;

    for (int i = 0 ; i < arr1.size() ; ++i)
        std::cout << arr2[i] << " ";
    std::cout << std::endl;

//    arr1[-1] = 1;

//    arr2[-1] = 1;

//  polymorphism    다형성
    Array *pArr = new SafeArray(nums, 5);

    (*pArr)[-1] = 1;        // (*pArr)[-1] == pArr->operator[](-1)      Array::operator[](-1) O  SafeArray::operator[](-1) X
                                                        //  virtual --> Array::operator[](-1) X  SafeArray::operator[](-1) O
    delete pArr;

    return 0;
}