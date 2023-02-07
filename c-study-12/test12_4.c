//
// Created by stellar on 2023/2/2.
//

#include <stdio.h>
#include <stdlib.h>

#include "common.h"

void testMallocAndFree();

int main() {
    printf("%llu\n", sizeof(char));
    brWithStr("testMallocAndFree");
    testMallocAndFree();
}

void testMallocAndFree() {
    double *ptd;
    int max;
    int number;
    int i = 0;

    puts("enter the maximum number of array");
    flush();
    if (scanf("%d", &max) != 1) {
        puts("read max error");
        flush();
        exit(EXIT_FAILURE);
    }

    ptd = (double *) malloc(max * sizeof(double));
    if (ptd == NULL) {
        puts("allocate memory error");
        flush();
        exit(EXIT_FAILURE);
    }

    puts("enter numbers");
    flush();
    while (i < max && scanf("%lf", &ptd[i]) == 1) {
        ++i;
    }

    printf("here are your %d numbers\n", number = i);
    flush();
    for (i = 0; i < number; ++i) {
        printf("%7.2f", ptd[i]);
        flush();
        if (i % 6 == 5) {
            putchar('\n');
        }
    }
    if (i % 6 != 0) {
        putchar('\n');
    }
    puts("Done");
    flush();
    free(ptd);
}


