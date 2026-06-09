#include <stdio.h>
#include <stdint.h>

typedef struct {
    uint8_t data[16];
    uint8_t head;   // vị trí sẽ ghi tiếp theo
    uint8_t count;  // số phần tử hiện có
} SensorBuffer;

void push(SensorBuffer *buf, uint8_t val) {
    buf->data[buf->head] = val;
    buf->head = (buf->head + 1) % 16;  // vòng lại 0 khi đến 16
    buf->count++;
}

void pop(SensorBuffer *buf, uint8_t *out) {
    // tự tính vị trí đọc = (head - count + 16) % 16
    // gán vào *out
    // giảm count
    *out = buf->data[buf->head];
    buf->count--;
}
