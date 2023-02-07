//
// Created by stellar on 2023/2/7.
//
#include <stdio.h>
#include "common.h"

union hold {
    int digit;
    double bigf1;
    char letter;
};

void testUnion();

void testEnum();

int main() {
    brWithStr("testUnion");
    testUnion();
    brWithStr("testEnum");
    testEnum();
    return 0;
}

void testUnion() {
    union hold fit;
    union hold save[10];
    union hold *pu;

    //初始化
    union hold valA;
    valA.letter = 'R';
    union hold valB = valA;
    union hold valC = {88};
    union hold valD = {.bigf1 = 11};

    //使用
    //每次使用都会清理别的内容,相当于可以存多种类型数据的结构
    fit.bigf1 = 1;
    fit.digit = 2;
    fit.letter = 'R';

    printf("double = %.2f, int = %d, char = %c\n", fit.bigf1, fit.digit, fit.letter);

    pu = &fit;
    printf("double = %.2f, int = %d, char = %c\n", pu->bigf1, pu->digit, fit.letter);
}

void testEnum() {
    enum spectrum {
        red, yellow, blue, green
    };

    enum spectrum color;
    printf("enter a number\n");
    scanf("%d", &color);
    switch (color) {
        case red: {
            printf("red\n");
            break;
        }
        case yellow: {
            printf("yellow\n");
            break;
        }
        case blue: {
            printf("blue\n");
            break;
        }
        case green: {
            printf("green\n");
            break;
        }
        default: {
            printf("error");
            break;
        }
    }
}


