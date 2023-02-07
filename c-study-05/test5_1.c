//
// Created by stellar on 2023/1/4.
//
#include <stdio.h>

int main() {
    printf("shoe size foot length(cm)\n");
    int shoeSize = 30;
    while (shoeSize <= 50) {
        printf("%9d %15.1f\n", shoeSize, (shoeSize + 10) / 2.0);
        shoeSize += 1;
    }

    //typedef关键字,为类型创建别名
    typedef unsigned long long int ull;
    printf("%llu\n", sizeof(ull));

    printf("%d\n", 'S');
    printf("%d\n", 'P');
    return 0;
}
