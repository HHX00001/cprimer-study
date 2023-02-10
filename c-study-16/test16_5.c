//
// Created by stellar on 2023/2/9.
//
#include "common.h"

#include "name_str.h"

void testH();

int main() {
    testH();
    return 0;
}

void testH() {
    full_name fullName;
    make_full_name(&fullName);
    show_full_name(&fullName);
}
