#include <iostream>
#include "boundArray.h"
#include "complex.h"

int main() {
    BoundArray<int> arr1(6, 10);

    for (int i = arr1.lower(); i <= arr1.upper(); ++i)
        std::cout << arr1[i] << " ";
    std::cout << std::endl;

    Complex nums[] = {Complex(3,4), Complex(8,8), Complex(5,8), Complex(6,7)};

    BoundArray<Complex> arr2(1, 2, nums);

    for (int i = arr2.lower(); i <= arr2.upper(); ++i)
        std::cout << arr2[i] << " ";
    std::cout << std::endl;

    BoundArray<Complex> arr3 = arr2;
    arr3 = arr2;
    try {
        for (int i = arr3.lower() - 1; i <= arr3.upper(); ++i)
            std::cout << arr3[i] << " ";
        std::cout << std::endl;
    } catch(InvalidIndex& e) {
        std::cout << "exception has occurred! index : " << e.invalid() << std::endl;
    }

    return 0;
}