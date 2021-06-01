//
// Created by user on 2021-06-01.
//

#include <iostream>
#include <vector>
#include <string>
#include <cctype>
#include <algorithm>
#include <iomanip>

using namespace std;

vector<string> split(const string& s) {
    vector<string> words;

    for(string::size_type i = 0 ; i != s.size() ; ) {
        while (i != s.size() && isspace(s[i]))
            ++i;

        string::size_type j = i;
        while(j != s.size() && !isspace(s[j]))
            ++j;

        if (i != j) {
            words.push_back(s.substr(i, j - i));
            i = j;
        }
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
    for (vec_iter iter = words.begin(); iter != words.end(); ++iter) {
        int leftSpace, rightSpace;
        leftSpace = (maxLen - iter->size()) / 2;
        rightSpace = maxLen - iter->size() - leftSpace;
        result.push_back("* " + string(leftSpace, ' ') + *iter + string(rightSpace, ' ') + " *");
    }
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