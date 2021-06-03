//
// Created by user on 2021-06-03.
//
#include <iostream>
#include <vector>
#include <string>
#include <cctype>
#include <algorithm>

using namespace std;

bool is_not_space(char c) {
    return !isspace(c);
}

bool is_space(char c) {
    return isspace(c);
}
vector<string> split(const string& s) {
    vector<string> words;

    for (string::const_iterator it = s.cbegin(); it != s.cend() ; ) {
        it = find_if(it, s.cend(), is_not_space);

        string::const_iterator it2 = find_if(it, s.cend(), is_space);
        if (it != it2) {
            words.push_back(string(it, it2));
        }

        it = it2;
    }
    return words;
}

string::size_type width(const vector<string>& words) {
    string::size_type max = 0;

    typedef vector<string>::const_iterator vec_citer;
    for (vec_citer iter = words.begin(); iter != words.end(); ++iter) {
        max = ::max(max, iter->size());
    }
    return max;
}

vector<string> frame(const vector<string>& words) {
    vector<string> result;
    const string::size_type maxLen = width(words);
    string border(maxLen + 4, '*');

    result.push_back(border);
    typedef vector<string>::const_iterator vec_iter;
    for (vec_iter iter = words.begin(); iter != words.end(); ++iter)
        result.push_back("* " + *iter + string(maxLen - iter->size(), ' ') + " *");
    result.push_back(border);
    return result;
}

int main() {
//    const string s = "knocking on the heaven's door";
    string s;
    while (getline(cin, s)) {
        const vector<string> words = split(s);

//        typedef vector<string>::const_iterator vec_citer;
//        for (vec_citer iter = words.begin(); iter != words.end(); ++iter)
//            cout << *iter << endl;

        vector<string> frame_word = frame(words);
        typedef vector<string>::const_iterator vec_citer;
        for (vec_citer iter = frame_word.begin(); iter != frame_word.end(); ++iter)
            cout << *iter << endl;

    }

    return 0;
}