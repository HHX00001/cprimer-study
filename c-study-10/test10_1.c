//
// Created by stellar on 2023/1/9.
//
#include <stdio.h>

#include "common.h"

void testNoDataArr();

void testSomeDataArr();

void testDesignate();

void testAddPtr();

void testArrSum();

//等同于int doTestArrSum(const int *intArr, int n);
int doTestArrSum(const int intArr[], int n);

void testOrder();

void testPtrOps();

void testConst();

void doTestConst(double *arrPtr, int i);

void testZippo();

void testZippo1();

void testBounds();

int main() {
    brWithStr("testNoDataArr");
    testNoDataArr();
    brWithStr("testSomeDataArr");
    testSomeDataArr();
    brWithStr("testDesignate");
    testDesignate();
    brWithStr("testBounds");
    testBounds();
    brWithStr("testAddPtr");
    testAddPtr();
    brWithStr("testArrSum");
    testArrSum();
    brWithStr("testOrder");
    testOrder();
    brWithStr("testPtrOps");
    testPtrOps();
    brWithStr("testConst");
    testConst();
    brWithStr("testZippo");
    testZippo();
    brWithStr("testZippo1");
    testZippo1();
}

void testNoDataArr() {
    int no_data[4];
    printf("%2s%14s\n", "i", "no_data[i]");
    for (int i = 0; i < 4; ++i) {
        printf("%2d%14d\n", i, no_data[i]);
    }
}

void testSomeDataArr() {
    int no_data[4] = {222, 4444};
    printf("%2s%14s\n", "i", "no_data[i]");
    for (int i = 0; i < 4; ++i) {
        printf("%2d%14d\n", i, no_data[i]);
    }
}

void testDesignate() {
    int no_data[4] = {[2] = 1, 11};
    printf("the size of no_data is %llu bytes\n", sizeof(no_data));
    printf("the size of no_data[0] is %llu bytes\n", sizeof(no_data[0]));
    printf("so the number of elements in no_data array is sizeof(no_data) / sizeof(no_data[0]) = %llu\n",
           sizeof(no_data) / sizeof(no_data[0]));
    printf("%2s%14s\n", "i", "no_data[i]");
    for (int i = 0; i < 4; ++i) {
        printf("%2d%14d\n", i, no_data[i]);
    }
}

void testBounds() {
    const int SIZE = 4;

    int val1 = 111;
    int intArr[SIZE];
    int val2 = 222;
    for (int i = -1; i < SIZE + 1; ++i) {
        intArr[i] = i;
    }
    printf("val1 = %d ,val2 = %d\n", val1, val2);
    printf("the location of val1         is %p\n", &val1);
    printf("the location of val2         is %p\n", &val2);
    printf("the location of intArr[-1]   is %p\n", &intArr[-1]);
    printf("the location of intArr[SIZE] is %p\n", &intArr[SIZE]);
}

void testAddPtr() {
    const int SIZE = 4;

    int intArr[SIZE];
    int *intPtr;

    double douArr[SIZE];
    double *douPtr;

    intPtr = intArr;
    douPtr = douArr;

    printf("%26s%13s\n", "short", "double");
    for (int i = 0; i < SIZE; ++i) {
        printf("pointers + %d: 0x%10p 0x%10p\n", i, intPtr + i, douPtr + i);
    }

    br();
    printf("*(intArr + 1) == intArr[1]: %d ,intArr +1 == &intArr[1]:%d\n", *(intArr + 1) == intArr[1],
           intArr + 1 == &intArr[1]);

}

void testArrSum() {
    int n = 10;
    int intArr[10];
    for (int i = 0; i < n; ++i) {
        intArr[i] = i + 1;
    }
    int res = doTestArrSum(intArr, n);
    printf("res = %d\n", res);
}

//等同于int doTestArrSum(const int *intArr, int n);
int doTestArrSum(const int intArr[], int n) {
    //这里是sizeof返回的是intArr变量的大小,也就是一个地址的大小,当前环境是64位,也就是8个字节
    printf("the size of intArr is %llu\n", sizeof(intArr));
    int sum = 0;
    for (int i = 0; i < n; ++i) {
        sum += intArr[i];
    }
    return sum;
}

void testOrder() {
    int data[2] = {100, 200};
    int moredata[2] = {300, 400};

    int *p1, *p2, *p3;
    p1 = p2 = data;
    p3 = moredata;
    printf(" *p1 = %d, *p2 = %d, *p3 = %d\n", *p1, *p2, *p3);
    printf("*p1++ = %d, *++p2 = %d, (*p3)++ = %d\n", *p1++, *++p2, (*p3)++);
    printf(" *p1 = %d, *p2 = %d, *p3 = %d\n", *p1, *p2, *p3);

    int sum = 0;
    int days[12] = {[0] = 31, [1] = 28};
    int *ptr = days;
    printf("ptr is %p sum is %d\n", ptr, sum);
    sum += *ptr++;
    printf("ptr is %p sum is %d\n", ptr, sum);
}

void testPtrOps() {
    int urn[5] = {100, 200, 300, 400, 500};
    int *ptr1, *ptr2, *ptr3;
    ptr1 = urn; // 把一个地址赋给指针
    ptr2 = &urn[2]; // 把一个地址赋给指针
// 解引用指针，以及获得指针的地址
    printf("pointer value, dereferenced pointer, pointer address:\n");
    printf("ptr1 = %p, *ptr1 =%d, &ptr1 = %p\n", ptr1, *ptr1, &ptr1);
// 指针加法
    ptr3 = ptr1 + 4;
    printf("\nadding an int to a pointer:\n");
    printf("ptr1 + 4 = %p, *(ptr1 + 4) = %d\n", ptr1 + 4, *(ptr1 + 4));
    ptr1++; // 递增指针
    printf("\nvalues after ptr1++:\n");
    printf("ptr1 = %p, *ptr1 =%d, &ptr1 = %p\n", ptr1, *ptr1, &ptr1);
    ptr2--; // 递减指针
    printf("\nvalues after --ptr2:\n");
    printf("ptr2 = %p, *ptr2 = %d, &ptr2 = %p\n", ptr2, *ptr2, &ptr2);
    --ptr1; // 恢复为初始值
    ++ptr2; // 恢复为初始值
    printf("\nPointers reset to original values:\n");
    printf("ptr1 = %p, ptr2 = %p\n", ptr1, ptr2);
// 一个指针减去另一个指针
    printf("\nsubtracting one pointer from another:\n");
    printf("ptr2 = %p, ptr1 = %p, ptr2 - ptr1 = %td\n",
           ptr2, ptr1, ptr2 - ptr1);
// 一个指针减去一个整数
    printf("\nsubtracting an int from a pointer:\n");
    printf("ptr3 = %p, ptr3 - 2 = %p\n", ptr3, ptr3 - 2);
}

void testConst() {
    //如果声明表示该指针指向地址中的内容无法修改
    const double douArr[5] = {1, 2, 3, 4, 5};
    //非法
//    douArr[0] = 1;

    //将const值的指针赋给另一个非值const的指针会warning
    double *douPtr = douArr;
    *douPtr = 1;
    doTestConst(douArr, 5);

    //如此声明表示该指针的地址值无法修改
    double *const constPtr = douArr;
    //非法
//    constPtr = &douArr[1];

    //指向地址的值和该地址中包含的内容都无法修改
    double *const *cconstPtr = douArr;
    //全都非法
//    douArr[0] = 1;
//    douArr = &douArr[0];
}

void doTestConst(double *arrPtr, int i) {
    //doSomething
}

void testZippo() {
    int zippo[4][3] = {{0,  1,  2},
                       {10, 11, 12},
                       {20, 21, 22},
                       {30, 31, 32}};

    printf("zippo   :%p, zippo+1   :%p(the difference is 12 bytes)\n", zippo, zippo + 1);
    printf("zippo[0]:%p, zippo[0]+1:%p(the difference is 4 bytes)\n", zippo[0], zippo[0] + 1);
}

void testZippo1() {
//    int zippo[4][3] = {{0,  1,  2},
//                       {10, 11, 12},
//                       {20, 21, 22},
//                       {30, 31, 32}};
//    //声明一个指向二维数组的指针
//    int (*pz)[2] = zippo;
//
//    //ptrArr是一个有两个指针的数组
//    int * ptrArr[2];

    int zippo[4][2] = {{2, 4},
                       {6, 8},
                       {1, 3},
                       {5, 7}};
    int (*pz)[2];
    pz = zippo;
    printf(" pz = %p, pz + 1 = %p\n", pz, pz + 1);
    printf("pz[0] = %p, pz[0] + 1 = %p\n", pz[0], pz[0] + 1);
    printf(" *pz = %p, *pz + 1 = %p\n", *pz, *pz + 1);
    printf("pz[0][0] = %d\n", pz[0][0]);
    printf(" *pz[0] = %d\n", *pz[0]);
    printf(" **pz = %d\n", **pz);
    printf(" pz[2][1] = %d\n", pz[2][1]);
    printf("*(*(pz+2) + 1) = %d\n", *(*(pz + 2) + 1));
}

//错误的声明void addCols(int arr[][])
void addCols(int arr[][4]) {

}






