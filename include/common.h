//
// Created by stellar on 2022/12/20.
//
#include <stdio.h>
#include <string.h>

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

extern char *s_gets(char *str, int number) {
    char *ret_val;
    char *findENTER;
    ret_val = fgets(str, number, stdin);
    if (ret_val) {
        findENTER = strchr(ret_val, '\n');
        if (findENTER) {
            *findENTER = '\0';
        } else {
            while (getchar() != '\n');
        }
    }
    return ret_val;
}

#endif //FIRST_COMMON_H
