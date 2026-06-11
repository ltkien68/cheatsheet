# 📌 Extern trong C

> **Dùng cho:** Chia sẻ biến/hàm giữa nhiều file trong cùng project  
> **Cập nhật:** 11/06/2026

---

## 1. 🎯 Khái niệm

> `extern` khai báo một biến hoặc hàm **được định nghĩa ở file khác**.  
> Cho phép nhiều file `.c` **dùng chung 1 biến toàn cục**.

---

## 2. 📐 Cấu trúc chuẩn

```
project/
├── lib.h      ← extern int x; (khai báo)
├── lib.c      ← int x = 10;  (định nghĩa thật)
└── main.c     ← #include "lib.h" → dùng x
```

| File | Viết gì? |
|------|----------|
| **lib.h** | `extern int x;` (chỉ khai báo, KHÔNG gán giá trị) |
| **lib.c** | `int x = 10;` (định nghĩa thật, CHỈ 1 lần) |
| **main.c** | `#include "lib.h"` → dùng `x` bình thường |

---

## 3. 📝 Ví dụ đầy đủ

### sensor.h
```c
#ifndef SENSOR_H
#define SENSOR_H

extern float temperature;      // Khai báo: biến này ở file .c
extern int error_count;
extern void sensor_read(void); // Hàm cũng có thể extern

#endif
```

### sensor.c
```c
#include "sensor.h"

float temperature = 25.0;      // Định nghĩa thật
int error_count = 0;

void sensor_read(void) {
    temperature += 0.5;
    if (temperature > 30.0) {
        temperature = 25.0;
        error_count++;
    }
}
```

### main.c
```c
#include <stdio.h>
#include "sensor.h"            // Include là dùng được

int main() {
    sensor_read();
    printf("Temp = %.1f, Errors = %d\n", temperature, error_count);
    return 0;
}
```

---

## 4. 🔧 Compile nhiều file

```bash
# Liệt kê TẤT CẢ file .c
gcc main.c sensor.c -o program.exe

# Hoặc dùng wildcard
gcc *.c -o program.exe
```

---

## 5. ⚠️ Quy tắc vàng

| Quy tắc | Giải thích |
|---------|------------|
| **Chỉ 1 lần định nghĩa** | `int x = 5;` chỉ xuất hiện 1 lần trong TOÀN BỘ project |
| **Nhiều lần extern** | `extern int x;` có thể có ở nhiều file .h |
| **Không gán giá trị trong .h** | `extern int x = 5;` → LỖI! |
| **Include guard** | Luôn dùng `#ifndef` / `#pragma once` trong .h |

---

## 6. ❌ Lỗi thường gặp

| Lỗi | Nguyên nhân | Cách sửa |
|-----|-------------|----------|
| `undefined reference` | Quên compile file .c chứa định nghĩa | `gcc main.c sensor.c` |
| `multiple definition` | Định nghĩa biến 2 lần | Xóa `int x = ...` ở 1 file, giữ `extern int x` |
| `extern int x = 5` | Gán giá trị trong .h | Chỉ `extern int x;`, gán ở .c |

---

## 7. 🆚 So sánh extern vs static

| | `extern` | `static` (toàn cục) |
|:---:|:---:|:---:|
| **Phạm vi** | Toàn bộ project | Chỉ trong 1 file .c |
| **Dùng chung?** | ✅ Có | ❌ Không |
| **Ẩn dữ liệu** | Không | Có (bảo mật hơn) |
| **Dùng khi** | Cần chia sẻ biến | Chỉ dùng nội bộ file |

---

## 8. 💡 Mẹo nhớ

```
extern = "Biến này ở file KHÁC, tao chỉ mượn thôi!"
         └─ Không tạo ra biến mới
         └─ Chỉ trỏ tới biến đã tồn tại

static = "Biến này của RIÊNG tao, đừng đứa nào đụng vào!"
         └─ Mỗi file có bản sao riêng
         └─ Không liên quan gì nhau
```