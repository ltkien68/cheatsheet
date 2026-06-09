#include <stdio.h>
#include <stdint.h>



int main() {
    uint32_t x = 0xDEADBEEF;
    uint8_t *ptr = (uint8_t*)&x;

    for (int i = 0; i < sizeof(x); i++) {
        printf("%d = %hhu \n", i + 1, *ptr);
        ptr++;
    }

    return 0;
}