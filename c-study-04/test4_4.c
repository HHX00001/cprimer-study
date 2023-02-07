//
// Created by stellar on 2022/12/27.
//
#include <stdio.h>
#include "common.h"

void testPrintf();

void testPrintf1();

void testConvert();

void countPrintf();

void testScanf();

void testScanfWithWidth();

int main() {
    brWithStr("testPrintf");
    testPrintf();
    brWithStr("testPrintf1");
    testPrintf1();
    brWithStr("testConvert");
    testConvert();
    brWithStr("countPrintf");
    countPrintf();
    brWithStr("testScanf");
//    testScanf();
    brWithStr("testScanfWithWidth");
    testScanfWithWidth();
}

/**
 * 转换说明符,如:%d,%e,%g,%x\n
 * 表示要打印的数据格式
 */
void testPrintf() {
    float f = 0.0001;
    float f1 = 0.00001;

    //%g,打印浮点数,如果超过了4位则用%e的形式打印,否则%f
    printf("%g\n", f);
    printf("%g\n", f1);
}

/**
 * 标记符,如:-,+,数字,.数字,ll
 */
void testPrintf1() {
    int i = 123456;
    //整数宽度为8,右对齐,不够的空着
    printf("|%8d|\n", i);
    //整数宽度为8,右对齐,不够的空着
    printf("|%-8d|\n", i);
    //整数宽度为8,超过了的话8就无效了
    printf("|%8d|\n", 123456789);
    //整数宽度为8,.7表示生成前导0的数字个数为7,这里的.7和前导0的作用重复了
    printf("|%08.7d|\n", i);
    br();
    float a = 1.123456;
    float b = 1123456e-5;
    printf("|%.3f|\n", a);
    //保留4位有效数字
    printf("|%.4e|\n", b);
    printf("|%.4e|\n", b);
    //总长度为6(包含小数点和小数),左右对齐,右对齐时不够的补0
    printf("|%06.3f|\n", a);
    printf("|%-6.3f|\n", a);
    br();
    double Ld = 123.123;
    long double ld = 123.1234567;
    //printf中float类型的参数会被转换成double
    printf("|%ld,%08.3Lf|\n", 123, ld);
    fflush(stdout);
}

/**
 * printf根据说明转换,就是根据内存中十六进制的值转换成相应的数据
 */
void testConvert() {
    float n1 = 3.0;
    double n2 = 3.0;
    long n3 = 2000000000;
    long n4 = 1234567890;
    printf("%.1e %.1e %.1e %.1e\n", n1, n2, n3, n4);
    printf("%ld %ld\n", n3, n4);
    printf("%ld %ld %ld %ld\n", n1, n2, n3, n4);
    fflush(stdout);
}

void countPrintf() {
    int i = 111;
    int num = printf("abc%d\n", i);
    printf("the count of characters is %d\n", num);
}

void testScanf() {
    int age;
    float assets;
    char pets[30];
    printf("enter int float str:\n");
    flush();
    scanf("%d", &age);
    scanf("%f", &assets);
    scanf("%s", pets);
    printf("%d, %f, %s, %#llx\n", age, assets, pets, &age);
    flush();
    br();
    printf("please input a str of format int,str:\n");
    int res = scanf("%d,%s", &age, pets);
    printf("res = %d\n", res);
    flush();
}

void testScanfWithWidth() {
    unsigned int width;
    int num;
    printf("input the width of a number:\n");
    flush();
    scanf("%u", &width);
    printf("input the number:\n");
    flush();
    scanf("%d", &num);
    //用*指明打印的宽度
    printf("the input num is |%+0*d|\n", width, num);
}





