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
using std::vector;
using std::string;
using std::istream;
using std::domain_error;
using std::streamsize;
using std::cerr;

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

int main() {
    cout << "please enter your name : ";
    string name;
    cin >> name;

    cout << "hello, " + name << endl;

    cout << "please enter your midterm finalterm score : ";
    int midterm, finalterm;
    cin >> midterm >> finalterm;

    cout << "please enter your homework scores : ";
    vector<double> homework;

    read_hw(cin, homework);

    try {
        std::streamsize prec = cout.precision();
        cout << std::setprecision(3);
        cout << "Your final score : " << grade(midterm, finalterm, homework) << endl;
        cout << std::setprecision(prec);
    } catch (domain_error& e) {
        cerr << "you must enter your grades please try again" << endl;
        return 1;
    }

    return 0;
}