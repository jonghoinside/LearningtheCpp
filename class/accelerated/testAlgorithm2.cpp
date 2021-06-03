//
// Created by user on 2021-06-03.
//
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    vector<string> words = {"hello ", "world"};
//    while(cin >> s) {
//        words.push_back(s);
//    }

    string answer;
//    for (int i = 0; i < words.size(); ++i)
//        for (int j = 0; j < words[j].size(); ++j)
//            for (int k = 0; words[j][k]; ++k)
//                answer.push_back(words[j][k]);
//    cout << answer << endl;

    string::iterator iter1 = answer.begin();
    typedef vector<string>::iterator vec_iter;
    vec_iter iter2 = words.s;
    while(iter2 != words.end()) {
        copy(iter2, words.end(), iter2);
    }

    return 0;
}