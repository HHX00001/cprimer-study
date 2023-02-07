//
// Created by stellar on 2023/2/1.
//
#include <stdio.h>
#include "common.h"

int hhx = 1;
//使用了同一个project下另一个文件的外部静态变量
extern int global;

//如果没有#include "./global.c",下一行代码报错,因为无法使用别的文件的内部静态变量
//extern int inner;

//外部变量初始化只能用常量
//int hhx1 = 2 * hhx;

void loop(int count);

void testLinkage();

int main() {
    printf("global in global.c:global=%d\n", global);
    brWithStr("loop");
    loop(10);
    brWithStr("testLinkage");
    testLinkage();
}

void loop(int count) {
    int m;
    int i = 99;
    printf("before loop:i=%d\n", i);
    {
        int i;
        for (i = 0; i < count; ++i) {
            printf("in loop:i=%d\n", i);
        }
    }
    printf("after loop:i=%d\n", i);
}

void testLinkage() {

}

