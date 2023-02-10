//
// Created by stellar on 2023/2/9.
//
#include "name_str.h"

#include "common.h"
//如果没有#ifndef的话会出现重复定义声明
#include "name_str.h"

void testH();

int main() {
    brWithStr("testH");
    testH();
    return 0;
}

void testH() {
    full_name fullName;
    make_full_name(&fullName);
    show_full_name(&fullName);
}
