#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

typedef int* IntPtr;

int glo_var;

void fuction(IntPtr *g, IntPtr *s, IntPtr *l, IntPtr *m) {
    static int static_var;

    int local_var = 8;

    IntPtr mal_var = malloc(32);

    *g = &glo_var;
    *s = &static_var;
    *l = &local_var;
    *m = mal_var;
}

int main() {
    IntPtr glo_addr, static_addr, local_addr, mal_addr;

    fuction(&glo_addr, &static_addr, &local_addr, &mal_addr);

    printf("global: %p\n", glo_addr);
    printf("static: %p\n", static_addr);
    printf("local: %p\n", local_addr);
    printf("malloc: %p\n", mal_addr);

    free(mal_addr);

    return 0;
}