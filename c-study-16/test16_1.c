//
// Created by stellar on 2023/2/9.
//
#include <stdio.h>
#include "common.h"

#define PF printf("NU\
MBER is "FMT", n is "FMT"\n", NUMBER, n);
#define NUMBER 1
#define FMT "%d"

#define SQUARE(X) X*X

#define PFSQ(X) printf("the square of "#X" is %d\n", (X)*(X))

#define X_NAME(n) x##n
#define PRINT_XN(n) printf("x"#n" is %d\n", x##n)

#define PR(X, ...) printf("Msg"#X": "__VA_ARGS__)

void testDefine();

void testFuncDefine();

void testStringifyMacro();

void testGlue();

void testVariableMarco();

int main() {
    brWithStr("testDefine");
//    testDefine();
    brWithStr("testFuncDefine");
//    testFuncDefine();
    brWithStr("testStringifyMacro");
//    testStringifyMacro();
    brWithStr("testGlue");
//    testGlue();
    brWithStr("testVariableMarco");
    testVariableMarco();
}

void testDefine() {
    int n = 3;
    PF;
}

/**
 * 类似函数, 但也是替换
 * 比如:在当前例子里,SQUARE(1 + 1)被替换成了1 + 1*1 + 1, 所以结果是3
 */
void testFuncDefine() {
    printf("SQUARE(3) : %d\n", SQUARE(3));
    printf("SQUARE(1 + 1) : %d\n", SQUARE(1 + 1));
}

/**
 * #X将宏字符串化
 */
void testStringifyMacro() {
    int i = 5;

    //相当于,printf("the square of ""i"" is %d\n", (i)*(i))
    PFSQ(i);
    PFSQ(3 + 1);
}

/**
 * ##把宏参数和宏本身组合成一个新的记号
 */
void testGlue() {
    int X_NAME(1) = 99;
    int X_NAME(2) = 312321;
    int x3 = 544;

    PRINT_XN(1);
    PRINT_XN(2);
    PRINT_XN(3);
}

void testVariableMarco() {
    PR(1, "%d,%d\n", 3, 4);
    PR(2, "%s\n", "hhhhhhh");
}
