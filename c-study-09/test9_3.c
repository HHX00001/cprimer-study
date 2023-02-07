//
// Created by stellar on 2023/1/6.
//
#include <stdio.h>

#include "common.h"

void recursion(int i);

void toBinary(unsigned long i);

int main() {
    brWithStr("recursion");
//    recursion(1);
    brWithStr("toBinary");
    toBinary(-1);
}

void recursion(int i) {
    printf("level_in\t%d the location of i is %p\n", i, &i);
    if (i < 3) {
        recursion(i + 1);
    }
    printf("level_out\t%d the location of i is %p\n", i, &i);
}

void toBinary(unsigned long i) {
    if (i < 1) return;
    int r = i % 2;
    toBinary(i / 2);
    printf("%d", r == 1 ? 1 : 0);
}
