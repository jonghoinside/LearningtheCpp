#include <iostream>
#include "array.h"
#include "safeArray.h"

int main() {
    int nums1[] = {1, 2, 3, 4, 5};
    SafeArray<int> arr1(nums1, 5);

    for (int i = 0 ; i < arr1.size(); ++i)
        std::cout << arr1[i] << " ";
    std::cout << std::endl;

    double nums2[] = {1.1, 2.2, 3.3, 4.4, 5.5};
    SafeArray<double> arr2(nums2, 5);

    for (int i = 0 ; i < arr2.size(); ++i)
        std::cout << arr2[i] << " ";
    std::cout << std::endl;

    return 0;
}