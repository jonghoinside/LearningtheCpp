//
// Created by user on 2021-06-03.
//
#include <iostream>
#include <string>
#include <map>

using namespace std;

int main() {
    map<string, int> counters;

    string s;
    while(cin >> s) {
        ++counters[s];
    }
    typedef map<string, int>::const_iterator map_citer;
    for(map_citer iter = counters.cbegin(); iter != counters.cend(); ++iter) {
        cout << iter->first << " : " << iter->second << endl;
    }

    return 0;
}