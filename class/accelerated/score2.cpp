#include <iostream>
#include <string>
#include <ios>
#include <iomanip>
#include <vector>
#include <algorithm>        // sort()

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

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

    double hw;
    while (cin >> hw) {
        homework.push_back(hw);
    }

    if (homework.size() == 0) {
        cout << "you must enter your grades please try again" << endl;
        return 1;
    }

    sort(homework.begin(), homework.end());

    double mid;
    if (homework.size() % 2 == 1)
        mid = homework[homework.size() / 2];
    else
        mid = (homework[homework.size() / 2] + homework[homework.size() / 2 - 1]) / 2;

    std::streamsize prec = cout.precision();
    cout << std::setprecision(3);
    cout << "Your final score : " << 0.2 + midterm + 0.4 * finalterm + 0.4 * mid << endl;
    cout << std::setprecision(prec);
    
    return 0;
}