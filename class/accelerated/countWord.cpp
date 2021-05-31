//
// Created by ajh07 on 2021-05-31.
//

#include <iostream>
#include <vector>

using namespace std;

istream& read_word(istream& in, vector<string>& words, vector<int>& count) {
    string word;

    while (cin >> word) {
        int i;
        for (i = 0; i < words.size(); ++i)
            if (word == words[i])
                break;

        if (i == words.size()) {
            words.push_back(word);
            count.push_back(1);
        } else
            ++count[i];
    }
    return in;
}

int main() {
    vector<string> words;
    vector<int> count;
    cout << "please input the word : ";
    read_word(cin, words, count);

    for (int i = 0; i < words.size(); ++i)
        cout << words[i] << " : " << count[i] << endl;

    return 0;
}