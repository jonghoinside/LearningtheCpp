#include <iostream>
#include "complex.h"
#include "array.h"

int main() {
    int nums1[] = {1, 2, 3, 4, 5};
    Array<int> arr1(nums1, 5);

    double nums2[] = {1.1, 2.2, 3.3, 4.4, 5.5};
    Array<double> arr2(nums2, 5);

    for (int i = 0 ; i < arr1.size(); ++i)
        std::cout << arr1[i] << " ";
    std::cout << std::endl;

    for (int i = 0 ; i < arr2.size(); ++i)
        std::cout << arr2[i] << " ";
    std::cout << std::endl;

    Array<float> arr3;

    Array<Complex> arr4, arr5;

    if(arr4 == arr5)
        std::cout << "equal" << std::endl;
    else
        std::cout << "not equal" << std::endl;

    return 0;
}