//
// Created by stellar on 2023/2/10.
//

#include <stdio.h>
#include <string.h>
#include "common.h"

void brWithStr(const char *str) {
    printf("---------%s------------\n", str);
}

void br() {
    brWithStr("");
}

void flush() {
    fflush(stdout);
}

char *s_gets(char *str, int number) {
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
