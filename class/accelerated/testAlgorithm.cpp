//
// Created by user on 2021-06-02.
//

#include <iostream>
#include <algorithm>
#include <vector>
#include <iterator>
#include <numeric>

using namespace std;

bool isEven(int data) {
    return (data%2 == 0);
}

int square(int data) {
    return data * data;
}

int main() {
    int arr1[] = {1, 2, 3, 4, 5};
    vector<int> nums1(arr1, arr1 + 5);

    int arr2[] = {6, 6, 6, 9, 10};
    vector<int> nums2(arr2, arr2 + 5);

    typedef vector<int>::const_iterator vec_iter;
//push_back 예제
//    for(vec_iter iter = nums2.cbegin(); iter < nums2.cend(); ++iter)
//        nums1.push_back(*iter);
//<vector> insert 함수 예제
//    nums1.insert(nums1.end(), nums2.cbegin(), nums2.cend());
//copy 함수 + <iterator> back_inserter 함수 예제
    copy(nums2.cbegin(), nums2.cend(), back_inserter(nums1));
//    copy_if(nums2.cbegin(), nums2.cend(), back_inserter(nums1), isEven);
//    copy_if(nums2.cbegin(), nums2.cend(), back_inserter(nums1), [](int n){return (n%2==0);});

    for(vec_iter iter = nums1.cbegin(); iter < nums1.cend(); ++iter)
        cout << *iter << " ";
    cout << endl;

    vec_iter iter = find(nums1.cbegin(), nums1.cend(), 11);
    if (iter != nums1.cend())
        cout << "found" << endl;
    else
        cout << "not found" << endl;

    iter = find_if(nums2.cbegin(), nums2.cend(), [](int n){return n == 6;});
    if (iter != nums1.cend())
        cout << "six found" << endl;
    else
        cout << "six not found" << endl;

    vector<int> nums3 = nums1;

    if (equal(nums1.cbegin(), nums1.cend(), nums3.cbegin()))
        cout << "nums1 and nums3 are equal" << endl;
    else
        cout << "nums1 and nums3 are not equal" << endl;

    int arr3[] = {3, 4, 5};

    iter = search(nums1.cbegin(), nums1.cend(), arr3, arr3 + 3);
    if (iter != nums1.cend())
        cout << "search found" << endl;
    else
        cout << "search not found" << endl;

//    double average = static_cast<double>(accumulate(nums1.cbegin(), nums1.cend(), 0)) / nums1.size();
    double average = accumulate(nums1.cbegin(), nums1.cend(), 0.0) / nums1.size();
    cout << "average is " << average << endl;

    vector<int> result;
//    for (vec_iter iter = nums1.cbegin(); iter != nums1.cend(); ++iter)
//        result.push_back(*iter * *iter);
//    transform(nums1.cbegin(), nums1.cend(), back_inserter(result), square);
    transform(nums1.cbegin(), nums1.cend(), back_inserter(result), [](int n){return n*n;});

    for (vec_iter iter = result.cbegin(); iter != result.cend(); ++iter)
        cout << *iter << " ";
    cout << endl;

    for(vec_iter iter = nums1.cbegin(); iter < nums1.cend(); ++iter)
        cout << *iter << " ";
    cout << endl;

    vector<int>::iterator iter2 = remove(nums1.begin(), nums1.end(), 3);
    remove(nums1.begin(), nums1.end(), 6);

//    nums1.erase(remove_if(nums1.begin(), nums1.end(), isEven), nums1.end());

    for(vec_iter iter = nums1.cbegin(); iter < nums1.cend(); ++iter)
        cout << *iter << " ";
    cout << endl;



    return 0;
}