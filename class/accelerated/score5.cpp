//
// Created by user on 2021-06-01.
//

//
// Created by user on 2021-05-31.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <stdexcept>
#include <ios>
#include <iomanip>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::sort;
using std::max;
using std::vector;
using std::string;
using std::istream;
using std::domain_error;
using std::streamsize;
using std::cerr;

struct Student_info {
    string name;
    double finalScore;
//    double midterm;
//    double finalterm;
//    vector<double> homework;
};

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

//double grade(const Student_info& s) {
//    return grade(s.midterm, s.finalterm, s.homework);
//}

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
    double midterm, finalterm;
    vector<double> homework;

    in >> s.name >> midterm >> finalterm;

    read_hw(in, homework);
    if (in )
        s.finalScore = grade(midterm, finalterm, homework);

    return in;
}

//istream& read(istream& in, Student_info& s) {
//    in >> s.name >> s.midterm >> s.finalterm;
//    read_hw(in, s.homework);
//    return in;
//}

bool compare(const Student_info& s1, const Student_info& s2) {
    return s1.name < s2.name;
}

int main() {
    vector<Student_info> students;

    Student_info s;
//    for (int i = 0 ; i < 5 ; ++i) {
//        read(cin, s);
//        students.push_back(s);
//    }

    while(read(cin, s)) {
        students.push_back(s);
    }

    sort(students.begin(), students.end(), compare);

    vector<string>::size_type maxLen = 0;
    for (vector<Student_info>::size_type i = 0; i != students.size(); ++i) {
        maxLen = max(maxLen, students[i].name.size());
    }

    for (vector<Student_info>::size_type i = 0; i != students.size(); ++i) {
        cout << students[i].name << string(maxLen - students[i].name.size() + 1, ' ');
        try {
            std::streamsize prec = cout.precision();
            cout << std::setprecision(3);
            cout << "Your final score : " << students[i].finalScore << endl;
            cout << std::setprecision(prec);
        } catch (domain_error& e) {
            cerr << e.what() << endl;
            return 1;
        }
    }
    return 0;
}