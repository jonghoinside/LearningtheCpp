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
    vector<int> count;

    string word;

    while(cin >> word) {
        if (!words.empty()) {
            int i;
            for (i = 0; i < words.size(); ++i) {
                if (word == words[i]) {
                    ++count[i];
                    break;
                }
            }
            if (i == words.size()) {
                words.push_back(word);
                count.push_back(1);
            }
        } else {
            words.push_back(word);
            count.push_back(1);
        }
    }

    for (int i = 0 ; i < words.size() ; ++i) {
        cout << words[i] << " : " << count[i] << endl;
    }

    return 0;
}