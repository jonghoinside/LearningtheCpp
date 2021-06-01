//
// Created by ajh07 on 2021-06-01.
//

#include <stdio.h>

struct BowlingScore {
    char name[20];
    int age;
    int scoreFirst;
    int scoreSecond;
    int scoreThird;
    double average;
};

void getAverage(struct BowlingScore* man) {
    man->average = (double)(man->scoreFirst + man->scoreSecond + man->scoreThird) / 3;
}

int main(void) {
    struct BowlingScore entry[4];
    for (int i = 0 ; i < 4 ; ++i) {
        scanf("%s %d %d %d %d", entry[i].name, &entry[i].age, &entry[i].scoreFirst, &entry[i].scoreSecond, &entry[i].scoreThird);
        getAverage(&entry[i]);
    }

    for (int i = 0 ; i < 4 ; ++i)
        printf("%s average score is %f\n", entry[i].name, entry[i].average);

    return 0;
}