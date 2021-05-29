#include <iostream>
#include <string>

using namespace std;

int main() {
    cout << "please enter your first name : ";
    string name;
    cin >> name;

    string  greeting = "Hello, " + name + "!";

    const int pad = 3;

    const string::size_type rows = 2 * pad + 3;                     // rows 7;
    const string::size_type cols = greeting.size() + 2* pad + 2;    // cols = size + 6;

    const int leftSpace = 3;
    const int rightSpace = 3;

    std::string space_greeting(greeting.size(), ' ');
    std::string space_Left(leftSpace, ' ');
    std::string space_Right(rightSpace, ' ');

    std::string star_greeting(greeting.size(), '*');
    std::string star_Left(leftSpace, '*');
    std::string star_Right(rightSpace, '*');

    cout << endl;
    for (int r = 0; r != rows; ++r) {

        cout << '*' << ((r == pad + 1) ? space_Left : ((r == 0 || r == rows - 1) ? star_Left : space_Left)) 
                    << ((r == pad + 1) ? greeting : ((r == 0 || r == rows - 1) ? star_greeting : space_greeting)) 
                    << ((r == pad + 1) ? space_Right : ((r == 0 || r == rows - 1) ? star_Right : space_Right)) << '*' << endl;
    }
    return 0;
}