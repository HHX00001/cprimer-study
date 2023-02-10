//
// Created by stellar on 2023/2/9.
//
#include <stdio.h>
#include "name_str.h"
#include "common.h"
//如果没有#ifndef的话会出现重复定义声明
#include "name_str.h"


#if __STDC_VERSION__ == 201710L
#define MSG "success"
#else
#define MSG "error"
//如果不是C17,则编译时就会报错
#error NOT C17
#endif

void testH();

void testPreDef();

void why_me();

int main() {
    brWithStr("compile "MSG);
    brWithStr("testH");
//    testH();
    brWithStr("testPreDef");
    testPreDef();
    return 0;
}

void testH() {
    full_name fullName;
    make_full_name(&fullName);
    show_full_name(&fullName);
}

//重置#line的下一行行号为1000,重置当前文件名为cool.c
//#line 1000 "cool.c"
void testPreDef() {
    printf("The file is %s\n", __FILE__);
    printf("The date is %s\n", __DATE__);
    printf("The time is %s\n", __TIME__);
    printf("The version is %ld\n", __STDC_VERSION__);
    printf("This is line %d\n", __LINE__);
    printf("This function is %s\n", __func__);
    why_me();
}

void why_me() {
    printf("This function is %s\n", __func__);
    printf("This is line %d\n", __LINE__);
}