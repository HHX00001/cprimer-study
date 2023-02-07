//
// Created by stellar on 2022/12/20.
//
#include <stdio.h>
#ifndef FIRST_COMMON_H
#define FIRST_COMMON_H

extern void brWithStr(const char *str) {
    printf("---------%s------------\n", str);
}

extern void br() {
    brWithStr("");
}

extern void flush() {
    fflush(stdout);
}

#endif //FIRST_COMMON_H
