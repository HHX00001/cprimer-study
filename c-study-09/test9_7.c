//
// Created by stellar on 2023/1/9.
//
#include <stdio.h>
#include "common.h"

void exchangeVar();

void doExchangeVar(int *p1, int *p2);

int main() {
    brWithStr("exchangeVar");
    exchangeVar();
}

void exchangeVar() {
    int n1 = 1;
    int n2 = 2;
    printf("before exchange, n1:%d, n2:%d\n", n1, n2);
    doExchangeVar(&n1, &n2);
    printf("after exchange, n1:%d, n2:%d\n", n1, n2);
}

void doExchangeVar(int *p1, int *p2) {
    int temp = *p1;
    *p1 = *p2;
    *p2 = temp;
    brWithStr("doExchangeVar completed");
}


