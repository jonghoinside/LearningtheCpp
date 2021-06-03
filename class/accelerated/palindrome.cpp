//
// Created by user on 2021-06-03.
//
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

bool is_palindrome(const string& s) {
    return equal(s.cbegin(), s.cend(), s.crbegin());
}

int main() {
    vector<string> words;
    const char * strs[5] = {"civic", "korea", "madam", "breeze", "bts"};
    for (int i = 0; i < 5; ++i) {
        words.push_back(string(strs[i]));
    }
    typedef vector<string>::const_iterator vec_iter;
    for (vec_iter iter = words.cbegin(); iter != words.cend(); ++iter) {
        cout << *iter << " is palindrome : " << is_palindrome(*iter) << endl;
    }

    return 0;
}