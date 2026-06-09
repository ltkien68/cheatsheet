#include <stdio.h>

void swap(int *a, int *b) {
    *a ^= *b;
    *b ^= *a;
    *a ^= *b;
}

int main() {
    int a = 5;
    int b = 9;

    swap(&a, &b);

    printf("a = %d \nb = %d", a, b);

    return 0;
}