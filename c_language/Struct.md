# 📌 Struct — Alignment & Packed

> **Cập nhật:** 10/06/2026

---

## 📏 Kích thước struct được tính thế nào?

### Không phải lấy size lớn nhất!

Struct được căn chỉnh theo **alignment**:

| Bước | Mô tả |
|:---:|-------|
| 1 | **Alignment** = kích thước của **kiểu lớn nhất** trong struct |
| 2 | Mỗi thành viên được đặt ở **bội số của kích thước của nó** |
| 3 | Tổng kích thước struct là **bội số của alignment** |

---

## 🔍 Ví dụ so sánh

```c
// Ví dụ 1: Layout xấu — 12 byte
typedef struct {
    char  a;   // 1 byte + 3 byte padding
    int   b;   // 4 byte (phải nằm ở bội số của 4)
    char  c;   // 1 byte + 3 byte padding
} Bad;

// Sơ đồ bộ nhớ:
// [a][_][_][_][b][b][b][b][c][_][_][_]
//    ↑ 3 padding       ↑ 3 padding

// Ví dụ 2: Layout tốt — 8 byte
typedef struct {
    int   b;   // 4 byte
    char  a;   // 1 byte
    char  c;   // 1 byte + 2 byte padding
} Good;

// Sơ đồ bộ nhớ:
// [b][b][b][b][a][c][_][_]
//                   ↑ 2 padding
```

---

## 📦 `__attribute__((packed))` — Tắt padding

### Khi nào dùng?

- Gửi/nhận dữ liệu qua UART, SPI, I2C
- Ánh xạ struct vào vùng nhớ cố định
- Cần kích thước chính xác theo byte

### So sánh

```c
// Không packed — 12 byte
typedef struct {
    uint8_t  a;   // 1 + 1 padding
    uint16_t b;   // 2
    uint8_t  c;   // 1 + 3 padding
    uint32_t d;   // 4
} Unpacked;

// Có packed — 8 byte
typedef struct __attribute__((packed)) {
    uint8_t  a;   // 1
    uint16_t b;   // 2
    uint8_t  c;   // 1
    uint32_t d;   // 4
} Packed;
```

---

## 💡 Mẹo tối ưu

Sắp xếp thành viên từ **LỚN → NHỎ** để giảm padding:

```c
✅ Tốt:    double → int → short → char
❌ Xấu:    char → double → short → int
```