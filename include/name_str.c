//
// Created by stellar on 2023/2/9.
//
#include <stdio.h>

#include "common.h"
#include "name_str.h"

void make_full_name(full_name *n_ptr) {
    printf("enter first name:\n");
    s_gets(n_ptr->first_name, SLEN);
    printf("enter second name:\n");
    s_gets(n_ptr->second_name, SLEN);
}

void show_full_name(const full_name *n_ptr) {
    printf("the first name is %s\n", n_ptr->first_name);
    printf("the second name is %s\n", n_ptr->second_name);
}