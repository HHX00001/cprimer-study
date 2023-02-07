//
// Created by stellar on 2023/1/6.
//
#include <stdio.h>
#include <ctype.h>
#include <iso646.h>

#include "common.h"

#define SPACE ' '

void testGetPutChar();

void testCType();

void testISO646();

int main() {
    brWithStr("testGetPutChar");
//    testGetPutChar();
    brWithStr("testCType");
//    testCType();
    brWithStr("testISO646");
    testISO646();
}

void testGetPutChar() {
    char ch;
    while ((ch = getchar()) != '\n') {
        if (SPACE == ch) {
            putchar(ch);
        } else {
            putchar(ch - 32);
        }
    }
}

void testCType() {
    char ch;
    while ((ch = getchar()) != '\n') {
        putchar(toupper(ch));
//        if (islower(ch)) {
//            putchar(toupper(ch));
//        } else {
//            putchar(ch);
//        }
    }
}

void testISO646() {
    if (1 and -3) {
        printf("hhh\n");
    }
}

