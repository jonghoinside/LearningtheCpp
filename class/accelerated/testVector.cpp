//
// Created by user on 2021-06-02.
//

#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<int> nums;
    for (int i = 1; i <= 5 ; ++i)
        nums.push_back(i);

    typedef vector<int>::const_iterator vec_citer;
    for (vec_citer citer = nums.begin() ; citer != nums.end() ; ++citer)
        cout << *citer << " ";
    cout << endl;

    for (vec_citer citer = nums.cbegin() ; citer != nums.cend() ; ++citer)
        cout << *citer << " ";
    cout << endl;

    typedef vector<int>::const_reverse_iterator vec_criter;
    for (vec_criter criter = nums.crbegin() ; criter != nums.crend() ; ++criter)
        cout << *criter << " ";
    cout << endl;


    return 0;
}