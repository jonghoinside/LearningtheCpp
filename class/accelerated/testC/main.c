//
// Created by user on 2021-06-02.
//
#include <stdio.h>
#include "solution.h"

int main(void) {
    char string[300] = "my name is name";
    char * str = string;
    printf("question is '%s'\n", string);

    str = solution(str);
    printf("answer is '%s'\n", string);

    return 0;
}