//
// Created by stellar on 2023/1/11.
//
#include <stdio.h>
#include "common.h"

#define MSG "I'm special"

void testStrings();

void testStrPtr();

void testAddress();

void testError();

void testGets();

void testFgets();

void testFgets1();

void testGets_s();

void testPrintf();

void testPuts();

void testMyPut();

void put1(const char *str);

int main() {
    brWithStr("testStrings");
    testStrings();
    brWithStr("testStrPtr");
    testStrPtr();
    brWithStr("testAddress");
    testAddress();
    brWithStr("testError");
//    testError();
    brWithStr("testGets");
//    testGets();
    brWithStr("testFgets");
//    testFgets();
    brWithStr("testFgets1");
//    testFgets1();
    brWithStr("testGets_s");
//    testGets_s();
    brWithStr("testPrintf");
//    testPrintf();
    brWithStr("testPuts");
//    testPuts();
    brWithStr("testMyPut");
    testMyPut();
}

void testStrings() {
    char words[127] = "I am a string";
    const char *pt1 = "Something is pointing at me";
    //自动加上换行符
    puts(words);
    puts(pt1);

    //字面量
    char greeting[50] = "Hello, and"" how are"" you";
    //等同于char greeting[50] = "Hello, and how are you"
}

void testStrPtr() {
    printf("%s, 0x%p, %c\n", "We", "are", *"space farers");
    char a = '\0';
}

void testAddress() {
    char msg1[] = MSG;
    char *msg2 = MSG;
    printf("address of \"I'm special\": %p\n", "I'm special");
    printf("         address of msg1: %p\n", msg1);
    printf("         address of msg2: %p\n", msg2);
    printf("         address of  MSG: %p\n", MSG);
}

void testError() {
    char *msg = MSG;
    //如果执行了下面的语句,则程序会出错,打印不出来
//    msg[0] = 'i';
    printf("%s\n", MSG);

    //这里字符串常量"hhx"被使用多次,但在每一次的使用中,使用的都是同一个"hhx"在内存中的地址
    //使用char str[]与char *str情况不同,可以简单理解为char str[]会创建一个新的字符串而不是复用同一个字符串
    //当前环境编译器不允许改变,会出现p1[0] = 'j';语句下面的语句无法执行的情况
    char *p1 = "hhx";
//    p1[0] = 'j';
    printf("hhx");
    printf("\n");
    printf("%s is studying\n", "hhx");
}

void testGets() {
    const int SIZE = 32;
    char words[SIZE];
    puts("input a string");
    //尽管输入的字符数大于了31(最后一个字符是非打印控制符'\0'),但是依然可以完整的显示,这是因为gets会占用words未分配的内存地址
    //如果该地址的内存有其他作用,则很有可能发生异常(如:该地址内存被一个变量占用,就会导致变量的值被意外修改)
    flush();
    gets(words);
    puts("your string is");
    printf("%s\n", words);
    puts(words);
    puts("that's all");
}

void testFgets() {
    const int SIZE = 32;
    char words[SIZE];
    fputs("input a string\n", stdout);
    flush();
    //fgets()最多读取SIZE-1个字符(最后一个字符留给'\0')
    //如果输入的字符串"小于"SIZE-1个,则会将('\0a'换行)也储存起来
    //对应着的,如果是SIZE-1个字符,则输出后不会换行
    //如果小于SIZE-1个字符,则输出后会换行

    //上面的理解不太好
    //换个理解:输入之后,对于多出的字符,会暂存在缓冲区
    //下一次调用的时候,会将缓冲区中上次未读完的字符读入words中
    //比如:这里如果输入SIZE-1个字符,这时缓冲区中实际有SIZE个字符(多的那一个是换行符)
    //会在第二次fgets的时候读入words
    //由于缓冲区中的字符数量大于SIZE-1个,所以第二次调用会读取上次读取剩下的内容('\n'),而不会阻塞等待用户输入
    fgets(words, SIZE, stdin);
    fputs(words, stdout);
    printf("interrupt\n");
    flush();
    fgets(words, SIZE, stdin);
    fputs(words, stdout);
    printf("interrupt\n");
    flush();
    printf("end\n");
}

void testFgets1() {
    const int SIZE = 16;
    char words[SIZE];
    puts("empty line to quit");
    flush();
    while (fgets(words, SIZE, stdin) != NULL && words[0] != '\n') {
        fputs(words, stdout);
    }
    flush();
}

void testGets_s() {
    const int SIZE = 16;
    char words[SIZE];
    puts("input something");
    flush();
    //不知道什么原因报错
//    while (gets_s(words, SIZE) != NULL) {
//        puts(words);
//    }
    puts("end");
    flush();
}

void testPrintf() {
    //printf和gets类似,读取过长的单词时会导致内存地址溢出,但可以使用转换说明(%s)控制读取的长度
    char name1[11], name2[11];
    int count;
    printf("please input two names\n");
    flush();
    count = scanf("%5s %10s", name1, name2);
    printf("read %d word, they are %s and %s\n", count, name1, name2);
}

void testPuts() {
    char str1[] = "An array was initialized to me.";
    const char *str2 = "A pointer was initialized to me";

    puts("a str");
    puts(str1);
    puts(str2);
    puts(&str1[3]);
    puts(str2 + 2);

    //结尾一定要有非打印控制字符'\0',否则函数不知道哪里是结束
    char dont[] = {'d', 'o', 'n', 't'};
    puts(dont);
}

void testMyPut() {
    char str[] = {'h', 'h', 'x'};
    put1(str);
    put1("\n");
    put1("abcd efgh");
}

void put1(const char *str) {
    while (*str) {
        putchar(*str++);
    }
}
