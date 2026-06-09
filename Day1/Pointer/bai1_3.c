#include <stdio.h>
#include <stdint.h>

void write_reg(uint32_t *base, int index, uint32_t value) {
    *(base + index) = value;
}

void read_reg(uint32_t *base, int index) {
    printf("registers[%d] = %lu\n", index, *(base + index));
}

int main() {
    uint32_t registers[8];

    write_reg(registers, 2, 6);

    read_reg(registers, 2);

    return 0;
}