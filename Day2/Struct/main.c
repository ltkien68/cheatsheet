#include <stdio.h>
#include <stdint.h>

typedef struct {
    uint8_t x;
    uint16_t y;
    uint32_t z;
} StructType;

StructType p;
StructType *ptr;

int main() {
    ptr = &p;
    ptr->x = 2;

    printf("x = %hhu\n", p.x);
    printf("Size of struct = %d", sizeof(p));

    return 0;
}