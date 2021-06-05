//
// Created by user on 2021-06-04.
//
#include <iostream>
#include <string>
#include <vector>
#include <iterator>
#include "split.h"

using namespace std;

int main() {
    string s;
    while (getline(cin, s)) {
        vector<string> words;
        split(s, back_inserter(words));

        copy(words.cbegin(), words.cend(), ostream_iterator<string>(cout, "\n"));
    }
    return 0;
}