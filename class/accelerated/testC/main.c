////
//// Created by user on 2021-06-02.
////
//#include <stdio.h>
//#include "solution.h"
//
//int main(void) {
//    char string[300] = "my name is name";
//    char * str = string;
//    printf("question is '%s'\n", string);
//
//    str = solution(str);
//    printf("answer is '%s'\n", string);
//
//    return 0;
//}


#include <stdio.h>
int main() {
    int num;
    scanf("%d", &num);
    int nums[num-1];
    for (int i = 0 ; i < num-1 ; ++i)
        scanf("%d", &nums[i]);

    int i, j;
    for (i  = 1 ; i <= num; ++i) {
        for (j = 0 ; j < num-1; ++j) {
            printf("%d %d %d\n", i, nums[j], i - nums[j]);
            if ( i - nums[j] == 0 )
                break;
        }

        if ( j != num-1 )
            continue;
        else
            break;
    }

    printf("%d", i);
}