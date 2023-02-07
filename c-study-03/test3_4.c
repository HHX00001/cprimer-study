//
// Created by stellar on 2022/12/20.
//

/**
 * 这里的\<\>和""有不同含义\n
 * \<\>是先去系统类库中找\n
 * ""是先去当前项目中找
 */
#include <stdio.h>
#include <math.h>
#include "common.h"

//定义了一些最大值
#include <limits.h>

//inttypes.h头文件对int类型的约束
#include <inttypes.h>

void testPrintf1();

void testPrintf2();

void testOverflow();

void testOverflow1();

void testPrintfChar();

void testEmbeddedConst();

void testInttypes();

void testFloat();

int check_sys();

int main() {
    brWithStr("testPrintf1");
    testPrintf1();
    brWithStr("testPrintf2");
    testPrintf2();
    brWithStr("testOverflow");
    testOverflow();
    brWithStr("testOverflow1");
    testOverflow1();
    brWithStr("testPrintfChar");
    testPrintfChar();
    brWithStr("testEmbeddedConst");
    testEmbeddedConst();
    brWithStr("testInttypes");
    testInttypes();
    brWithStr("testFloat");
    testFloat();
    return 1;
}

void testPrintf1() {
    printf("%d\n", 1);
    //如果参数和占位符数量对不是,那么多出来的占位符会随机打印
    printf("%d,%#llx,%#X\n", 2);
}

void testPrintf2() {
    //进制打印
    int num = 100;
    printf("dec = %d;octal = %o;hex = %x\n", num, num, num);
    //打印的时候占位符加上#符号 带上进制的前缀
    printf("dec = %d;octal = %#o;hex = %#x;hex = %#X\n", num, num, num, num);
}

/**
 * printf相当于把读取内存中的字节数组并以规定的格式打印出来.\n
 * 若是读取到的低32位(int占用四个字节)为0xffffffff,\n
 * 占位符为<b>%d(32位有符号数)</b>,打印结果为-1\n
 * 占位符为<b>%u(32位无符号数)</b>,打印结果为2^32-1\n
 */
void testOverflow() {
    int i = 2147483647;
    unsigned int j = i * 2 + 1;
    printf("%d %d %d\n", i, i + 1, i + 2);
    printf("%u %u %u\n", j, j + 1, j + 2);
    br();
    //32位16进制打印(无视符号位,打印直接数)
    printf("%#x %#x %#x\n", i, i + 1, i + 2);
    printf("%#x %#x %#x\n", j, j + 1, j + 2);
    br();

    //8个字节能表示的最大的无符号数
    unsigned long long int num = pow(2, 64) - 1;
    //8个字节能表示的最大的有符号数
//    long long int num1 = 18446744073709551616 - 1;
    signed long long int num1 = powl(2, 9999);
    printf("sizeof(long long int) %llu bytes\n", sizeof(long long int));
    printf("%#llx\n", num);
    printf("%llu\n", num);
    br();
    printf("%#llx\n", num1);
}

void testOverflow1() {
    unsigned int i = 0x7fffffff;//有符号时是正数
    unsigned int j = 0x80000000;//有符号时是负数,数字位为2^32 - j
    printf("%d\n", i);
    printf("%u\n", i);
    printf("%d\n", j);
    printf("%u\n", j);
}


void testPrintfChar() {
    char a = 'a';//等价于 char a = 97;
    char A = 'A';//...

    printf("%#x\n", a);
    printf("%#x\n", A);
    printf("%d\n", a);
    printf("%d\n", A);
    br();
    //因为char类型只占一个字节,因此只有最后一个字节d被存储起来
    char abcd = 'abcd';
    printf("%#x\n", abcd);
    printf("%c\n", abcd);
    printf("%c, %c", '\n', '\r');
//    printf("%c, %c", '\r', '\n');
}

void testEmbeddedConst() {
    //ULONG_LONG_MAX定义在 limits.h头文件中:
    //ULONG_LONG_MAX = LONG_LONG_MAX * 2ULL + 1ULL
    //其中__LONG_LONG_MAX__应该是内嵌的8字节有符号数的最大值
    printf("max unsigned in 8bytes: %#llx\n", ULONG_LONG_MAX);
    _Bool a = 0;

    printf("%#llx\n", sizeof(intptr_t));
}

void testInttypes() {
    int32_t me32;
    me32 = 45933945;

    //宏(具体是啥不知道),PRId32在<b>不同的编译器的头文件</b>的定义是不同的
    //比如当前环境中一个int占4个字节
    //PRId32在就代表着d
    //但是如果在环境中int只占2个字节而long int占4个字节
    //那么可能PRId32就代表着ld
    printf("me32 = %" PRId32 "\n", me32);
    //等价于
//    printf("me32 = %" "d" "\n", me32);
    //等价于
//    printf("me32 = %d\n", me32);
}

void testFloat() {
    printf("size of float is %llu\n", sizeof(float));
    printf("size of double is %llu\n", sizeof(double));
    printf("size of long double is %llu\n", sizeof(long double));

    float f = -6.63e-10;
    printf("the value of variable f is %f, %e, %a\n", f, f, f);

    long double ld = 123.321e10;
    printf("the value of variable ld is %Lf, %Le, %La\n", ld, ld, ld);
}

int check_sys() {
    int a = 1;
    char *p = (char *) &a;
    return *p;  //大端返回0，小端返回1
}
