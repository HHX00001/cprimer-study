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

void testTypedef();

void testComplexType();

void testPtrFunc();

int main() {
    brWithStr("testUnion");
//    testUnion();
    brWithStr("testEnum");
//    testEnum();
    brWithStr("testTypedef");
//    testTypedef();
    brWithStr("testComplexType");
//    testComplexType();
    brWithStr("testPtrFunc");
    testPtrFunc();
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

    enum spectrum color = red;

    enum levels {
        low = 10, medium = 100, high = 2000
    };
}

void testTypedef() {
    typedef unsigned char BYTE;
    BYTE a, *aptr, aaa[10];
    *aptr = 10;

    typedef char *STRING;
    STRING str = "aaaaa";
    printf("%s\n", str);

}

void testComplexType() {
    //数组指针
    //1.首先计算(),ptr是指针
    //2.该指针指向一个长度为10的数组
    int (*ptr)[10];
    //指针数组
    //1.首先计算[10],说明ptr1是数组
    //2.再计算*,ptr1的数组元素是指向int的指针
    int *ptr1[10];
    int i = 1;
    *ptr[0] = i;
    ptr1[0] = &i;
    printf("success\n");
}

void toUpper(char *);

void toLower(char *);

void testPtrFunc() {
    void (*f)(char *);

    const int STRLEN = 20;
    char str[STRLEN];

    printf("enter a str:\n");
    s_gets(str, STRLEN);
    f = toLower;
    //
    f(str);
    printf("the result of converting a str to lowercase is:\n%s\n", str);
    br();

    printf("enter a str:\n");
    s_gets(str, STRLEN);
    f = toUpper;
    (*f)(str);
    printf("the result of converting a str to uppercase is:\n%s\n", str);
    printf("%s\n", str);
}

/**
 * 字符串转大写(不可以修改字面量)
 * @param str
 */
void toUpper(char *str) {
    char *temp = str;
    while (*temp != '\0') {
        if (*temp > 96 && *temp < 123) {
            *temp -= 32;
        }
        temp++;
    }
}

/**
 * 字符串转小写(不可以修改字面量)
 * @param str
 */
void toLower(char *str) {
    char *temp = str;
    while (*temp != '\0') {
        if (*temp > 64 && *temp < 91) {
            *temp += 32;
        }
        temp++;
    }
}

