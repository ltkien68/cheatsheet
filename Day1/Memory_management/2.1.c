#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

typedef int* IntPtr;

int glo_var;

int main() {
    static int static_var = 6;
    int local_var = 8;
    int *mal_var = malloc(64);

    int *glo_ptr = &glo_var;
    int *static_ptr = &static_var;
    int *local_ptr = &local_var;


    printf("Global variable address: %p\n", glo_ptr);
    printf("Static variable address: %p\n", static_ptr);
    printf("Local variable address: %p\n", local_ptr);
    printf("Malloc variable address: %p\n", mal_var);

    free(mal_var);
    return 0;
}