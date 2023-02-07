//
// Created by stellar on 2022/12/26.
//
#include <stdio.h>
#include <string.h>
#include <limits.h>
#include <float.h>
#include <math.h>
#include "common.h"

//这里的PRAISE相当于长度为字符数+1(这里加的是非打印控制符\0所占的字节数1)的字符数组变量
#define PRAISE "You are an extraordinary being."

void testStr();

void testStrlenAndSizeof();

void testDefine();

int main(void) {
//    testStr();
    brWithStr("testStrlenAndSizeof");
    testStrlenAndSizeof();
    brWithStr("testDefine");
    testDefine();
    return 0;
}

void testStr() {
    char name[40];
    printf("What's your name?");
    scanf("%s", name);
    printf("Hello, %s.%s\n", name, PRAISE);
}

/**
 * 正常空格的ascii码是<b>32</b>,属于<b>打印字码</b>,打印出来的就是空格\n
 * 而c语言中的字符串结束符的ascii码是<b>0</b>,属于<b>非打印控制字符</b>,用来标记一个字符串的结束\n
 * 下面声明的字符数组如果按c语言中%s的格式打印,只会打印第一个\0之前的字符串("hhx")\n
 * char name[40] = "hhx\0abc\0efg";\n
 */
void testStrlenAndSizeof() {
    char name[40] = "hhx abc efg";
    /**
     * strlen(arg)返回字符串的有效长度(\0之前且不包括\0的字符数)\n
     * sizeof表示这个字符数组变量所占内存的字节数
     */
    printf("name has %llu letters, the size of name is %llu\n", strlen(name), sizeof(name));

    /**
     * sizeof(args) 和 sizeof args对于普通变量来说都可以\n
     * 但是如果参数是声明变量类型的关键字则只能使用sizeof args\n
     */
    printf("PRAISE has %llu letters, the size of PRAISE is %llu\n", strlen(PRAISE), sizeof PRAISE);
}

/**
 * 打印一些limits.h或float.h头文件中的符号常量
 */
void testDefine() {
    printf("the max of unsigned long long is %#llx\n", ULLONG_MAX);
    printf("float epsilon = %e\n", FLT_EPSILON);
    int fSigFig = pow(2, 23);
    long long int dSigFig = pow(2, 52);
    printf("the max sig fig of float is %d\n", fSigFig);
    printf("the max sig fig of double is %lld\n", dSigFig);
}

