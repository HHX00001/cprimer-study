//
// Created by stellar on 2022/12/16.
//

#include <cstdio>

#define PI 3.1415
#define ； ;

int testMain();

void testDefine();

void testMain1();

int main() {
    testMain();
    testDefine();
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
    //#define ； ;
    //太强了,啥都能定义
//    printf("%.20lf\n", PI)；
}
