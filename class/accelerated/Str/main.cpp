//
// Created by user on 2021-06-08.
//
#include <iostream>
#include <cstring>
#include "str.h"

using std::cin;
using std::cout;
using std::endl;

int main() {
    Str s1 = "hello, world";
    Str s2(10, 'A');
    const char *str = "wonderful tonight";
    Str s3(str, str + strlen(str));
    Str s4;

    cin >> s4;
    cout << "s4 : " << s4 << endl;

    Str s5 = "hello";
    Str s6 = ", ";
    s5 += s6;
    s5 += "world";      // Str tmp("world");    s5 += tmp;  tmp::~Str();

    s6 = s5 + " ROS";
    char s7[10];
    s6.copy(s7, 5);
//    Str s7 = "hello, " + "world";         //   "hello, " + "world";    ::operator("hello", "world"); 전역함수여야 가능하다. "hello".operator("world"); x


    const char * str1 = s6.c_str();
    cout << "str : " << str1 << endl;

    const char * str2 = s6.data();
    cout << "str : ";
    for (int i = 0; i < s6.size(); ++i)
        cout << str2[i];
    cout << endl;

    char * str3 = new char[s6.size() + 1];
    s6.copy(str3, s6.size());
    str3[s6.size()] = '\0';
    cout << str3 << endl;

    cout << "s1 : " << s1 << endl;
    cout << "s5 : " << s5 << endl;
    cout << "s6 : " << s6 << endl;
    cout << "s7 : " << s7 << endl;

    return 0;
}