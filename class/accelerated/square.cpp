//
// Created by ajh07 on 2021-05-31.
//
#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

int main() {
    vector<int> nums;
    vector<int> numsSquare;

    for (int i = 1 ; i <= 100 ; ++i)
        nums.push_back(i);

    for (int i = 0 ; i < nums.size() ; ++i)
        numsSquare.push_back(nums[i] * nums[i]);

    int maxCount = numsSquare.back();
    int digitNum = 0;
    while(maxCount) {
        ++digitNum;
        maxCount /= 10;
    }

    int space = digitNum + 2;
    for (int i = 0 ; i < numsSquare.size() ; ++i)
        cout << setw(space) << i+1 ;
    cout << endl;
    for (int i = 0 ; i < numsSquare.size() ; ++i)
        cout << setw(space)<< numsSquare[i] ;
    cout << endl;

    return 0;
}

