#include <iostream>
#include <string>
#include <ios>
#include <iomanip>

using std::cin;
using std::cout;
using std::endl;
using std::string;

int main() {
    cout << "please enter your name : ";
    string name;
    cin >> name;

    cout << "hello, " + name << endl;

    cout << "please enter your midterm finalterm score : ";
    int midterm, finalterm;
    cin >> midterm >> finalterm;

    int count = 0;
    int sum = 0;

    int homework;
    while (cin >> homework) {
        ++count;
        sum += homework;
    }
    std::streamsize prec = cout.precision();
    cout << std::setprecision(3);
    cout << "Your final score : " << 0.2 + midterm + 0.4 * finalterm + 0.4 * sum << endl;
    cout << std::setprecision(prec);
    
    return 0;
}