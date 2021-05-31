//
// Created by user on 2021-05-31.
//
#include <iostream>
#include <string>
#include <vector>


using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

int main() {

    vector<string> words;
    string word;

    while(cin >> word) {
        words.push_back(word);
    }

    string maxString = words[0];
    string minString = words[0];
    for (int i = 1 ; i < words.size() ; ++i) {
        if (maxString.size() < words[i].size())
            maxString = words[i];

        if (minString.size() > words[i].size())
            minString = words[i];
    }

    cout << "maxString : " << maxString << endl;
    cout << "minString : " << minString << endl;

    return 0;
}