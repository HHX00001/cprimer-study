//
// Created by stellar on 2023/2/9.
//

#include <string.h>

#define SLEN 32

struct full_name_struct {
    char first_name[SLEN];
    char second_name[SLEN];
};

typedef struct full_name_struct full_name;

void make_full_name(full_name *);

void show_full_name(const full_name *);
