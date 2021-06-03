//
// Created by user on 2021-06-03.
//

#include <iostream>
#include <list>
#include <vector>
#include <algorithm>
#include <stdexcept>
#include <ios>
#include <iomanip>
#include <string>
#include <numeric>

using namespace std;

struct Student_info {
    string name;
    double midterm;
    double finalterm;
    vector<double> homework;
};

typedef vector<Student_info> container;

double average(const vector<double>& vec) {
    return accumulate(vec.cbegin(), vec.cend(), 0.0) / vec.size();
}

double median(vector<double>& vec) {
    sort(vec.begin(), vec.end());
    const int mid = vec.size() / 2;

//    if (vec.size() % 2 == 1)
//        return vec[mid];
//    else
//        return (vec[mid] + vec[mid -1]) / 2;

    return ((vec.size() % 2 == 1) ? vec[mid] : (vec[mid] + vec[mid -1]) / 2) ;
}

double grade(double midterm, double finalterm, double homework) {
    return 0.2 * midterm + 0.4 * finalterm + 0.4 * homework;
}

double grade(double midterm, double finalterm, const vector<double>& homework) {
    if(homework.size() == 0)
        throw domain_error("student has done no homework");

    vector<double> tmp = homework;
    return grade(midterm, finalterm, median(tmp));
}

double grade(const Student_info& s) {
    return grade(s.midterm, s.finalterm, s.homework);
}

double grade_aux(const Student_info& s) {
    try {
        return grade(s);
    }
    catch (domain_error) {
        return grade(s.midterm, s.finalterm, 0);
    }
}

double average_grade(const Student_info& s) {
    return grade(s.midterm, s.finalterm, average(s.homework));
}

istream& read_hw(istream& in, vector<double>& homework) {
    if (in ) {
        homework.clear();
        double x;

        while (in >> x)
            homework.push_back(x);

        in.clear();
    }

    return in;
}

istream& read(istream& in, Student_info& s) {
    in >> s.name >> s.midterm >> s.finalterm;
    read_hw(in, s.homework);
    return in;
}

bool compare(const Student_info& s1, const Student_info& s2) {
    return s1.name < s2.name;
}

bool fgrade(const Student_info& s) {
    return ::grade(s) < 60;
}

bool pgrade(const Student_info& s) {
    return !::grade(s);
}

container extract_fails(container& students) {
    container fail;

    remove_copy_if(students.cbegin(), students.cend(), back_inserter(fail), pgrade);
    students.erase(remove_if(students.begin(), students.end(), fgrade), students.end());

    return fail;
}

container extract_fails(container& students) {
    container::const_iterator iter = stable_partition(students.begin(), students.end(), pgrade);

    container fail(iter, students.cend());
    students.erase(iter, students.end());

    return fail;
}

//container extract_fails(container& students) {
//    container fail;
//
//
//
//    typedef container::iterator container_iter;
//    for(container_iter iter = students.begin(); iter != students.end(); ) {
//        if (fgrade(*iter)) {
//            fail.push_back(*iter);
//            iter = students.erase(iter);
//        } else
//            ++iter;
//    }
//
//    return fail;
//}

bool did_all_hw(const Student_info& s) {
    return find(s.homework.cbegin(), s.homework.cend(), 0) == s.homework.cend();
}

double median_analysis(const container& students) {
    vector<double> grades;
    transform(students.cbegin(), students.cend(), back_inserter(grades), grade_aux);

    return median(grades);
}

double median_average(const container& students) {
    vector<double> grades;
    transform(students.cbegin(), students.cend(), back_inserter(grades), average_grade);

    return median(grades);
}

void write_analysis(ostream& out, const string& name, double (*analysis)(const container&),
                    const container& did, const container& didnt) {
    out << name << " : median(did) = " << analysis(did) << ", median(didnt) = " << analysis(didnt) << endl;
}

int main() {
    container did, didnt;

//    int maxLen = 0;
    string::size_type maxLen = 0;

    Student_info record;
    while (read(cin, record)) {
        if (did_all_hw(record))
            did.push_back(record);
        else
            didnt.push_back(record);
    }

    if (did.empty()) {
        cout << "no Student did all the homework" << endl;
        return 1;
    }

    if (didnt.empty()) {
        cout << "every student did all the homework" << endl;
        return 1;
    }

    write_analysis(cout, "median", median_analysis, did, didnt);
    write_analysis(cout, "average", median_average, did, didnt);

    return 0;
}