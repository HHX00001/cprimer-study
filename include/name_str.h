//
// Created by stellar on 2023/2/9.
//

#ifndef NAME_STR
#define NAME_STR

#include <string.h>

#define SLEN 32

struct full_name_struct {
    char first_name[SLEN];
    char second_name[SLEN];
};

typedef struct full_name_struct full_name;

extern void make_full_name(full_name *);

extern void show_full_name(const full_name *);

#endif //#NAME_STR

