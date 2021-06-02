//
// Created by user on 2021-06-02.
//
#include <stdio.h>
#include "solution.h"

char* solution(char * str) {
    int count = 1;
    for(int i = 0 ; str[i] ; ++i) {
        if(str[i] == ' ') {
            count = 1;
        } else {
            if(count%2 == 1)
                str[i] = str[i] + 'A' - 'a';
            ++count;
        }
    }

    return str;
}