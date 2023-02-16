//
// Created by stellar on 2023/2/16.
//

#include <stdio.h>
#include "common.h"

#define MYTYPE(X) _Generic((X),\
int : "int",\
float : "float",\
double : "double",\
default : "other"\
)

void testGeneric();

int main() {
    brWithStr("testGeneric");
    testGeneric();
    return 0;
}

void testGeneric() {
    int d = 5;
    printf("%s\n", MYTYPE(d));
    printf("%s\n", MYTYPE(2.0 * d));
    printf("%s\n", MYTYPE(3L));
    printf("%s\n", MYTYPE(&d));
}
