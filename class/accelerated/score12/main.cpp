//
// Created by user on 2021-06-09.
//
#include <iostream>
#include <stdexcept>
#include <algorithm>
#include <vector>
#include "core.h"
#include "grad.h"

using namespace std;

bool compare_core_ptr(const Core* c1, const Core* c2) {
    return ::compare(*c1, *c2);
}

int main() {
    vector<Core*> students;
    Core* pRecord;

    char ch;
    while (cin >> ch) {
        if (ch == 'U')
            pRecord = new Core;
        else
            pRecord = new Grad;
        pRecord->read(cin);

        students.push_back(pRecord);
    }

    ::sort(students.begin(), students.end(), compare_core_ptr);

    vector<Core *>::const_iterator  iter;
    for (iter = students.cbegin(); iter != students.cend(); ++iter) {
        cout << (*iter)->name() << " ";
        try {
            double final_grade = (*iter)->grade();
            cout << final_grade << endl;
        } catch (domain_error e) {
            cout << e.what() << endl;
        }

        delete (*iter);
    }

    return 0;
}