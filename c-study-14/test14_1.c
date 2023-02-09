//
// Created by stellar on 2023/2/3.
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "common.h"

#define MAX_TITLE  41
#define MAX_AUTHOR  31
#define MAX_BOOKS 10
#define MAX_NAME 16
#define MAX_COMMON_STRLEN 21


struct book {
    char title[MAX_TITLE];
    char author[MAX_AUTHOR];
    float value;
};

struct full_name {
    char first_name[MAX_NAME];
    char last_name[MAX_NAME];
    int letters_num;
};

struct guy {
    struct full_name name;
    char fav_food[MAX_COMMON_STRLEN];
    float income;
};

struct fund {
    char bank[MAX_COMMON_STRLEN];
    double bank_fund;
    char save[MAX_COMMON_STRLEN];
    double save_fund;
};

struct flex {
    int count;
    double average;
    double scores[];
};

struct full_name makeNameInfo();

extern char *s_gets(char *str, int n);

void testCreateStruct();

void testInitialStruct();

void testManyBooks();

void testNestedStruct();

void testPtrStruct();

void printIncome(float income);

void raiseIncome(float *ptr_income);

void testPassStructPtrAndStruct();

double getSumByStructPrt(const struct fund *money_info);

double getSumByStruct(struct fund money_info);

void testRetStruct();

void showNameInfo(struct full_name name);

void testSaveStructStrPtr();

void testFlex();

int main() {
    brWithStr("testCreateStruct");
//    testCreateStruct();
    brWithStr("testInitialStruct");
//    testInitialStruct();
    brWithStr("testManyBooks");
//    testManyBooks();
    brWithStr("testNestedStruct");
//    testNestedStruct();
    brWithStr("testPtrStruct");
//    testPtrStruct();
    brWithStr("testPassStructPtrAndStruct");
//    testPassStructPtrAndStruct();
    brWithStr("testRetStruct");
//    testRetStruct();
    brWithStr("testSaveStructStrPtr");
    testSaveStructStrPtr();
    //字面量
    brWithStr("literal");
//    showNameInfo((struct full_name) {"h", "hx", 3});
    brWithStr("testFlex");
//    testFlex();
    return 0;
}

void testCreateStruct() {
    struct book library;
    printf("enter book title\n");
    s_gets(library.title, MAX_TITLE);
//    scanf("%s", library.title);
    printf("enter book author\n");
    s_gets(library.author, MAX_AUTHOR);
    printf("enter book value\n");
    scanf("%f", &library.value);

    printf("book title: %s\n", library.title);
    printf("book author: %s\n", library.author);
    printf("book value: %.2f\n", library.value);
}

void testInitialStruct() {
    struct book library = {
            "javaee",
            "yiming",
            33
    };
    printf("library book title: %s\n", library.title);
    printf("library book author: %s\n", library.author);
    printf("library book value: %.2f\n", library.value);

    struct book gift = {
            .title = "fengrufeitun",
            .author = "moyan",
            .value = 50
    };
    br();
    printf("gift book title: %s\n", gift.title);
    printf("gift book author: %s\n", gift.author);
    printf("gift book value: %.2f\n", gift.value);
}

void testManyBooks() {
    struct book library[MAX_BOOKS];

    int book_num = 0;
    for (int i = 0; i < MAX_BOOKS; ++i) {
        printf("enter the book[%d] title\n", i + 1);
        if (NULL != s_gets(library[i].title, MAX_TITLE) && library[i].title[0] != '\0') {
            printf("enter the book[%d] author\n", i + 1);
            s_gets(library[i].author, MAX_AUTHOR);
            printf("enter the book[%d] value\n", i + 1);
            scanf("%f", &library[i].value);
            while (getchar() != '\n');
            book_num++;
        } else {
            break;
        }
    }

    if (book_num > 0) {
        for (int j = 0; j < book_num; ++j) {
            printf("[%d]book title: %s, book author: %s, book value: %.2f\n",
                   j + 1, library[j].title, library[j].author, library[j].value);
        }
    } else {
        printf("no books\n");
    }

}

void testNestedStruct() {
    struct guy hhx = {
            {"h", "hx"},
            "rice",
            7000
    };

    printf("a guy's name is: %s%s\n", hhx.name.first_name, hhx.name.last_name);
    printf("his favourite food is: %s\n", hhx.fav_food);
    printf("his monthly income is: %.2f\n", hhx.income);
}

void testPtrStruct() {
    struct guy hhx = {
            {"h", "hx"},
            "rice",
            7000
    };

    struct guy *ptr_hhx = &hhx;

    printf("(*ptr_hhx).name.first_name: %s, ptr_hhx->name.last_name: %s\n",
           (*ptr_hhx).name.first_name, ptr_hhx->name.last_name);

    printIncome(hhx.income);
    raiseIncome(&hhx.income);
    printIncome(hhx.income);
}

void printIncome(float income) {
    printf("income is: %.2f\n", income);
}

void raiseIncome(float *ptr_income) {
    *ptr_income = 1.2 * *ptr_income;
}

void testPassStructPtrAndStruct() {
    struct fund money_info = {
            "Chinese bank",
            2000,
            "loan",
            3000
    };

    double sum = getSumByStructPrt(&money_info);
    double sum1 = getSumByStruct(money_info);

    printf("[1]the sum of fund is %.2f\n", sum);
    printf("[2]the sum of fund is %.2f\n", sum1);
}

/**
 * 传递结构的指针,这意味着可以修改原值
 * @param money_info
 * @return
 */
double getSumByStructPrt(const struct fund *money_info) {
    return money_info->bank_fund + money_info->save_fund;
}

/**
 * 传递结构值,当前函数中的数据为原结构数据的副本
 * @param money_info
 * @return
 */
double getSumByStruct(struct fund money_info) {
    return money_info.save_fund + money_info.bank_fund;
}

void testRetStruct() {
    struct full_name name;
    name = makeNameInfo();
    showNameInfo(name);
}

struct full_name makeNameInfo() {
    struct full_name result;
    printf("enter your first_name:\n");
    s_gets(result.first_name, MAX_NAME);
    printf("enter your last_name:\n");
    s_gets(result.last_name, MAX_NAME);

    result.letters_num = strlen(result.first_name) + strlen(result.last_name);
    return result;
}

void showNameInfo(struct full_name name) {
    printf("name:{first_name: %s, last_name: %s, letters_num: %d}\n",
           name.first_name, name.last_name, name.letters_num);
}

void testSaveStructStrPtr() {
    struct strStruct {
        char *str1;
        char *str2;
    };

    struct strStruct strStruct;

    //strStruct中有两个野指针
    printf("str1: *s,str2: %s\n", strStruct.str1, strStruct.str2);
}

/**
 * 伸缩型数组成员,必须放到最后的位置<br/>
 * 需要用malloc()函数分配内存空间,除去固定内存空间的成员所占用的空间<br/>
 * 剩下的都是数组的
 */
void testFlex() {
    printf("enter the number of score:\n");
    int number;
    if (scanf("%d", &number) == 0) {
        printf("number error\n");
        exit(EXIT_FAILURE);
    }
    struct flex *flex_ptr;
    flex_ptr = malloc(sizeof(struct flex) + number * sizeof(double));
    flex_ptr->count = number;

    double sum = 0;
    for (int i = 0; i < number; ++i) {
        double score;
        printf("[%d]enter the score\n", i + 1);
        scanf("%lf", &score);
        flex_ptr->scores[i] = score;
        sum += score;
    }
    flex_ptr->average = sum / number;
    printf("Scores : ");
    for (int i = 0; i < number; ++i) {
        printf("%.2f ", flex_ptr->scores[i]);
    }
    printf("\n");
    printf("Average: %.2f\n", flex_ptr->average);
}

