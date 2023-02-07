#include <stdio.h>
#include "common.h"

void alarm();

void escape();

void testFloatDouble();

int main() {
    testFloatDouble();
}

/**
 * 在linux环境下,下面的方法会响铃
 */
void alarm() {
    printf("\a");
}

/**
 * 和书上的例子不太一样
 */
void escape() {
    float salary;
    printf("\aEnter your monthly salary:");
    printf(" $________\b\b\b\b\b\b\b\b");
    scanf("%f", &salary);
    printf("your annual salary is $%.2f", salary * 12);
}

void testFloatDouble() {
    float f = -3.1415;
    float f1 = 3.1415;
    double d = 3.1415;
    printf("%#llx\n", f);
    printf("%#llx\n", d);
    fflush(stdout);
}

