//
// Created by stellar on 2023/1/6.
//
#include <stdio.h>
#include <conio.h>

#include "common.h"

void echo();

void testConio();

void testEOF();

int main() {
    brWithStr("echo");
//    echo();
    brWithStr("testConio");
//    testConio();
    brWithStr("testEOF");
    testEOF();
}

void echo() {
    char ch;
    while ((ch = getchar()) != '#') {
        putchar(ch);
    }
}

void testConio() {
    char ch;
    while ((ch = getche()) != '#') {
        putchar(ch);
    }
}

void testEOF() {
    int ch;
    while ((ch = getchar()) != EOF) {
        putchar(ch);
    }
}
