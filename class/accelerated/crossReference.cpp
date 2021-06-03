//
// Created by user on 2021-06-03.
//
#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>

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

map<string, vector<int> > xref(istream& in, vector<string> (*find_words)(const string&) = split) {
    map<string, vector<int> > ret;

    int lineNumber = 0;
    string line;
    while (getline(in, line)) {
        ++lineNumber;

        vector<string> words = find_words(line);

        typedef vector<string>::const_iterator vec_citer;
        for(vec_citer iter = words.cbegin(); iter != words.cend(); ++iter) {
            ret[*iter].push_back(lineNumber);
        }
    }

    return ret;
}

int main() {
    map<string, vector<int> > ret = xref(cin);
    typedef map<string, vector<int> >::const_iterator map_citer;
    for (map_citer iter = ret.cbegin(); iter != ret.cend(); ++iter) {
        cout << iter->first << " : ";
        typedef vector<int>::const_iterator vec_citer;
        for (vec_citer iter2 = iter->second.cbegin(); iter2 != iter->second.cend(); ++iter2)
            cout << *iter2 << " ";

        cout << endl;
    }

    return 0;
}