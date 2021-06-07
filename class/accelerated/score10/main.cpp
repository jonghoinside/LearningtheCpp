//
// Created by user on 2021-06-07.
//
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#include <stdexcept>
#include <iomanip>
#include "student_info.h"
#include "grade.h"

using namespace std;

int main() {
    vector<Student_info> students;
    Student_info record;
    string::size_type maxlen = 0;

    while(record.read(cin)) {
        maxlen = max(maxlen, record.name().size());
        students.push_back(record);
    }

    sort(students.begin(), students.end(), ::compare);

    vector<Student_info>::const_iterator iter;
    for (iter = students.cbegin(); iter != students.cend(); ++iter) {
        cout << iter->name() << string(maxlen + 1 - iter->name().size(), ' ');

        try {
            double final_grade = iter->grade();
            streamsize prec = cout.precision();
            cout << " : " << setprecision(3) << final_grade << setprecision(prec) << endl;
        } catch (domain_error e) {
            cout << e.what() << endl;
        }
    }

    return 0;
}