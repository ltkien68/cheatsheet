#include <stdio.h>
#include <stdint.h>

// ===== UNION CHO THANH GHI 32-BIT =====
typedef union {
    uint32_t reg;                    // Cả thanh ghi 32-bit
    struct {
        uint8_t byte0;               // Byte thấp (bit 0-7)
        uint8_t byte1;               // Byte 1 (bit 8-15)
        uint8_t byte2;               // Byte 2 (bit 16-23)
        uint8_t byte3;          // Byte cao (bit 24-31)
    } bytes;
    struct {
        uint16_t low;                // 16-bit thấp (bit 0-15)
        uint16_t high;               // 16-bit cao (bit 16-31)
    } halfwords;
} Register32;

int main() {

    // TODO: Gán giá trị 0x12345678 vào reg.reg
    // TODO: In ra từng byte (bytes.byte0, byte1, byte2, byte3)
    // TODO: In ra low và high (halfwords.low, halfwords.high)
    // TODO: Đổi byte3 thành 0xAB → in reg.reg mới
    // TODO: Dùng union để đọc bit 7 của reg

    Register32 reg;
    reg.reg = 0x12345678;

    printf("=== BYTES ===\n");
    printf("0x%02X\n", reg.bytes.byte0);
    printf("0x%02X\n", reg.bytes.byte1);
    printf("0x%02X\n", reg.bytes.byte2);
    printf("0x%02X\n", reg.bytes.byte3);

    printf("=== LOW.HIGH ===\n");
    printf("0x%04X\n", reg.halfwords.low);
    printf("0x%04X\n", reg.halfwords.high);

    reg.bytes.byte3 = 0xAB;
    printf("\n0x%08X\n", reg.reg);

    printf("=== BIT7 ===\n");
    printf("%d\n", (reg.bytes.byte0 >> 7) & 1);
    
    return 0;
}