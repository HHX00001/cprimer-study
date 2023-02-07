//
// Created by stellar on 2023/2/2.
//
#include <stdio.h>
#include "common.h"

void report_count();

void accumulate(int k);

int count = 0;//外部链接

int main() {
    int value;
    register int i;
    printf("enter a number\n");
    flush();
    while (scanf("%d", &value) == 1 && value > 0) {
        ++count;
        for (i = value; i >= 0; i--) {
            accumulate(i);
        }
        printf("enter a number\n");
        flush();
    }
    report_count();
    return 0;
}

void report_count() {
    printf("Loop executed %d times\n", count);
}
