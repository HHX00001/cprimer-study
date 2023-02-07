#include <stdio.h>

int main() {
    float weight;
    float value;

    printf("please input a float:\n");
    scanf("%f", &weight);
    value = weight * 2;
    getchar();
    getchar();
    printf("%.2f", value);
    return 0;
}


