#include <iostream>
#include <cstdlib>
#include "rational.h"

using namespace std;

int main() {
    system("clear");
    int initMode;
    cout << "Input testMode number(0: + test,\v 1: - test,\v 2: / test,\v 3: * test) : ";
    cin >> initMode;
    while(initMode/4)
        cout << "Error : Input testMode 0 <= number < 5" << endl;
    board[4][7] = (initMode == 3) ? 42 : 43 + initMode*2;
    printBoard(); 
    int inputCount = 2;
    Rational rational[inputCount];
    for (int i = 0 ; i < inputCount ; ++ i) {
        long num = 0, den = 0;
        cout << "Input rational[" << i+1 << "] number : ";
        scanf("%ld/%ld", &num, &den);
        rational[i].setRational(num, den);
        rational[i].setBoard(i);
        printBoard();
    }
    
    Rational answer;
    switch(initMode) {
        case 0:
            answer = rational[0] + rational[1];
            break;
        case 1:
            answer = rational[0] - rational[1];
            break;
        case 2:
            answer = rational[0] / rational[1];
            break;
        case 3:
            answer = rational[0] * rational[1];
            break;
    }
    answer.setBoard(2);
    printBoard();

    cout << "answer is " << answer << endl;
    return 0;
}