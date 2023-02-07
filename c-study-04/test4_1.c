// talkback.c -- 演示与用户交互
#include <stdio.h>
#include <string.h> // 提供strlen()函数的原型

#include "common.h"

#define DENSITY 62.4 // 人体密度（单位：磅/立方英尺）

int main() {
    float weight, volume;
    int size, letters;
    char name[5]; // name是一个可容纳5个字符的数组
    printf("Hi! What's your first name?\n");
    flush();
    scanf("%s", name);
    printf("%s, what's your weight in pounds?\n", name);
    flush();
    scanf("%f", &weight);
    size = sizeof name;

    //strlen计算一个数组中有效字符的函数
    letters = strlen(name);
    volume = weight / DENSITY;
    printf("Well, %s, your volume is %2.2f cubic feet.\n",
           name, volume);
    fflush(stdout);
    printf("Also, your first name has %d letters,\n",
           letters);
    printf("and we have %d bytes to store it.\n", size);
    return 0;
}