#include <stdio.h>
#include <stdint.h>

#define PI 3.14

#ifdef PI
void mFunction() {
    printf("PI = %f \n", PI);
}
#else
void mFunction() {
    printf("PI = %d \n", 0);
}
#endif

int main() {

    mFunction();

    return 0;
}