#include <stdio.h>

int main() {
    int arr[] = { 1, 2, 3, 4, 5 };
    int *ptr = arr;

    printf("%d %d %d %d %d %d", *ptr, ++*ptr++, (*ptr)++, *ptr++, *++ptr, ++*ptr);

    return 0;
}

/*
    ++*ptr => tăng *ptr = arr[0] = 1 + 1 = 2, in arr[0] = 2
    *++ptr = *(++ptr) => dịch ptr = arr[1], in arr[1] = 2
    *ptr++ => in arr[1] = 2, dịch ptr = arr[2]
    (*ptr)++ => in arr[2] = 3, tăng *ptr = arr[2] = 3 + 1 = 4
    ++*ptr++ = ++(*ptr++) =>  tăng *ptr = arr[2] = 4 + 1 = 5, dịch ptr = arr[3], in arr[2] = 5
    *ptr = arr[3] = 4
    -> 4 5 3 2 2 2
*/

