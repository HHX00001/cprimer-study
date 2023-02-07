//
// Created by stellar on 2022/12/20.
//
#include <stdio.h>

void testPrintf2();

void testPrintf1();

void testSizeOf();

int main() {
//    testPrintf2();
    testSizeOf();
}

void testSizeOf() {
    printf("%lld", sizeof(long long int));
}

void testPrintf1() {
    printf("%d\n", 1);
    //如果参数和占位符数量对不是,那么多出来的占位符会随机打印
    printf("%d,%d,%d\n", 2);
}

void testPrintf2() {
    //进制打印
    int num = 100;
    printf("dec = %d;octal = %o;hex = %x\n", num, num, num);

    //打印的时候占位符加上#符号 带上进制的前缀
    printf("dec = %d;octal = %#o;hex = %#x;hex = %#X\n", num, num, num, num);
}


