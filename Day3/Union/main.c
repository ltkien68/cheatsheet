#include <stdio.h>
#include <stdint.h>

typedef union {
    uint8_t data;
    struct {
        uint8_t BIT0: 1;
        uint8_t BIT1: 1;
        uint8_t BIT2: 1;
        uint8_t BIT3: 1;
        uint8_t BIT4: 1;
        uint8_t BIT5: 1;
        uint8_t BIT6: 1;
        uint8_t BIT7: 1;
    } BITS;
} DATA;

DATA data;

int main() {

    data.BITS.BIT3 = 1; // dùng bitwise
    data.data |= 1; // thay đổi trực tiếp giá trị từng bit qua union

    printf("%d\n", data.data);

    return 0;
}