//
// Created by stellar on 2023/1/5.
//
#include <stdio.h>

#include "common.h"

void testWhile(int num);

void testFor();

void testArray();

void testOutMemory();

int main() {
    brWithStr("testWhile");
    testWhile(30);
    brWithStr("testFor");
    testFor();
    brWithStr("testArray");
    testArray();
    brWithStr("testOutMemory");
    testOutMemory();
}

void testWhile(int num) {
    int i = 0;
    while (i++ < num) {
        printf("%d\n", i);
        if (i >= 20) {
            printf("end1\n");
            break;
        }
    }
}

void testFor() {
    for (int i = 0; i < 9; ++i) {
        printf("%d ", i);
    }
    printf("\n");
}

void testArray() {
    //虽然内存占用错误了(这会导致程序出错),但是没有任何提示,intArr[21]所占用得内存可能是其他有用的内存
    int intArr[20];
    intArr[21] = -1;
    printf("%d\n", intArr[21]);
    printf("testArray\n");

    char str[] = "hhx";
    //等同于
    char str1[] = {'h', 'h', 'x', '1', '\0'};

    printf("%s\n", str);
    printf("%s\n", str1);
}

void testOutMemory() {
    int arr[3] = {1, 2, 3};
    for (int i = 0; i < 10; ++i) {
        printf("%#llx ", arr[i]);
        flush();
    }
}

