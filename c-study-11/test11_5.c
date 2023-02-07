//
// Created by stellar on 2023/1/17.
//
#include <stdio.h>
#include <string.h>

#include "common.h"

void testStrlen();

void testStrcat();

int main() {
    brWithStr("testStrlen");
    testStrlen();
    brWithStr("testStrcat");
    testStrcat();
}

void testStrlen() {
    char str[] = {'h', 'h', 'x', 'a', '\0', '0'};
    char *str1 = &str[3];
    printf("the length of str is %llu\n", strlen(str));
    printf("the length of str1 is %llu\n", strlen(str1));
}

void testStrcat() {
    //str2的字符串append到str1后面
    //就算append之后str1的长度超出了限制,依然可以正常打印
    //所以使用不当的情况下会出现内存地址溢出的问题
    char str1[16] = "hhx";
    char str2[16] = "123456789012345";
    strcat(str1, str2);

    printf("the result is %s\n", str1);

    //另一个方法,参数多了一个最大添加字符数
    strncat(str1, str2, 13);

}
