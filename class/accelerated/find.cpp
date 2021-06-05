//
// Created by user on 2021-06-04.
//
#include <iostream>
#include <vector>
#include <list>
#include <iterator>
#include <algorithm>

using namespace std;

template <typename In, typename T>
In my_find(In begin, In end, const T& val) {
    while (begin != end && *begin != val)
        ++begin;

    return begin;
}

template <typename In, typename Out>
Out my_copy(In begin, In end, Out dest) {
    while (begin != end)
        *dest++ = *begin++;

    return dest;
}

template <typename For, typename T>
void my_replace(For begin, For end, const T& val, const T& val2) {
    while (begin != end) {
        if (*begin == val)
            *begin = val2;
        ++begin;
    }
}

template <typename Bi>
void my_reverse(Bi begin, Bi end) {
    while (begin != end) {
        --end;
        if (begin != end) {
            auto tmp = *begin;
            *begin = *end;
            *end = tmp;
            ++begin;
        }
    }
}

template <typename Ran, typename T>
bool my_binary_search(Ran begin, Ran end, const T& val) {
    while (begin < end) {
        Ran mid = begin + (end - begin) / 2;
        if (val < *mid)
            end = mid;
        else if (val > *mid)
            begin = mid + 1;
        else
            return true;
    }
    return false;
}

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    vector<int> nums(arr, arr + 5);
    list<int> nums2;
    my_copy(nums.cbegin(), nums.cend(), back_inserter(nums2));
    my_replace(nums2.begin(), nums2.end(), 3, 6);
    my_reverse(nums2.begin(), nums2.end());

/*
    list<int>::const_iterator iter;
    for(iter = nums2.cbegin(); iter != nums2.cend(); ++iter) {
        cout << *iter << " ";
    }
    cout << endl;
*/

    copy(nums2.cbegin(), nums2.cend(), ostream_iterator<int>(cout, " "));

    vector<int> nums3;
    // for 문 대신에 copy 함수 사용
    copy(istream_iterator<int>(cin), istream_iterator<int>(), back_inserter(nums3));
    copy(nums3.cbegin(), nums3.cend(), ostream_iterator<int>(cout, " "));

//    vector<int>::const_iterator it = find(nums.cbegin(), nums.cend(), 3);
    auto it = my_find(nums.cbegin(), nums.cend(), 3);

    if(it != nums.cend())
        cout << "found" << endl;
    else
        cout << "not found" << endl;

    return 0;
}