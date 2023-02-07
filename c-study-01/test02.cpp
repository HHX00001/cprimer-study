//
// Created by stellar on 2022/12/16.
//

#include <cstdio>
#include "myH.c"

int testMain();

void testDefine();

void testMain1();

int main() {
//    testMain();
//    testDefine();
    testMain1();
    return 0;
}

void testMain1() {
    int num = 99999;
    printf("%d", num);
}

int testMain() {
    int num;
    num = 1;

    printf("I am a ");
    printf("computer\n");
    printf("my favourite number is %d\n", num);
    return 0;
}

void testDefine() {
    //在myH头文件中把；定义为;
    //太强了,啥都能定义
//    printf("%.20lf", PI)；
}
