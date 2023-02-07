//
// Created by stellar on 2023/1/6.
//
#include <stdio.h>

void mikado(int); /* 函数原型 */

int main() {
    int pooh = 2, bah = 5; /* main()的局部变量 */
    printf("In main(), pooh = %d and &pooh = %p\n", pooh, &pooh);
    printf("In main(), bah = %d and &bah = %p\n", bah, &bah);
    mikado(pooh);
    return 0;
}

void mikado(int bah) {
    int pooh = 10; /* mikado()的局部变量 */
    printf("In mikado(), pooh = %d and &pooh = %p\n", pooh, &pooh);
    printf("In mikado(), bah = %d and &bah = %p\n", bah, &bah);
}