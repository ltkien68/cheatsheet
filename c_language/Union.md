# 📌 Union trong C

> **Dùng cho:** Tiết kiệm bộ nhớ, truy cập cùng dữ liệu qua nhiều kiểu, ánh xạ thanh ghi  
> **Cập nhật:** 11/06/2026

---

## 1. 🎯 Khái niệm

> Union là kiểu dữ liệu cho phép **nhiều thành phần con DÙNG CHUNG 1 vùng nhớ**.  
> Tại một thời điểm, **chỉ 1 thành phần có giá trị hợp lệ**.  
> **Kích thước union = kích thước thành phần LỚN NHẤT**.

---

## 2. 📐 Cú pháp cơ bản

```c
// Khai báo
typedef union {
    uint8_t  byte_val;    // 1 byte
    uint16_t word_val;    // 2 byte
    uint32_t dword_val;   // 4 byte ← lớn nhất
} DataUnion;

// Sử dụng
DataUnion data;
data.dword_val = 0x12345678;   // Ghi 4 byte
printf("%02X\n", data.byte_val); // Đọc 1 byte (byte thấp)
```

---

## 3. 📊 So sánh Struct vs Union

| | Struct | Union |
|:---:|:---:|:---:|
| **Bộ nhớ** | Cấp riêng cho từng member | **Dùng chung 1 vùng** |
| **Kích thước** | Tổng + padding | **Bằng member lớn nhất** |
| **Dùng khi** | Cần tất cả member cùng lúc | **Chỉ dùng 1 member tại 1 thời điểm** |
| **Tất cả member** | Đều có giá trị hợp lệ | **Chỉ 1 member hợp lệ** |

---

## 4. 🔍 Sơ đồ bộ nhớ

```
Struct (8 byte):              Union (4 byte):
┌────┬────┬────┬────┐         ┌────────────┐
│ a  │pad │ b  │ c  │         │ a (1B)     │
│ 1B │1B  │2B  │4B  │         │ b   (2B)   │ chồng
└────┴────┴────┴────┘         │ c     (4B) │ lên
      8 byte                  └────────────┘
                                    4 byte
```

---

## 5. 📝 Ví dụ: Đọc thanh ghi 32-bit

```c
typedef union {
    uint32_t reg;          // Cả thanh ghi
    struct {
        uint8_t byte0;     // Byte thấp (bit 0-7)
        uint8_t byte1;     // Byte 1 (bit 8-15)
        uint8_t byte2;     // Byte 2 (bit 16-23)
        uint8_t byte3;     // Byte cao (bit 24-31)
    } bytes;
    struct {
        uint16_t low;      // Halfword thấp (bit 0-15)
        uint16_t high;     // Halfword cao (bit 16-31)
    } halfwords;
} Register32;

Register32 reg;
reg.reg = 0x12345678;

reg.bytes.byte0;          // 0x78
reg.bytes.byte3;          // 0x12
reg.halfwords.low;        // 0x5678
reg.halfwords.high;       // 0x1234
```

---

## 6. 🔧 Ứng dụng trong Embedded

### a) Ánh xạ thanh ghi phần cứng

```c
typedef union {
    uint32_t REG;
    struct {
        uint32_t ENABLE    : 1;   // Bit 0
        uint32_t MODE      : 2;   // Bit 1-2
        uint32_t PRESCALER : 8;   // Bit 3-10
        uint32_t RESERVED  : 21;  // Bit 11-31
    } bits;
} TimerReg;

TimerReg *timer = (TimerReg*)0x40000000;
timer->bits.ENABLE = 1;     // Bật timer, không ảnh hưởng bit khác
```

### b) Chuyển đổi kiểu dữ liệu

```c
typedef union {
    float    f;
    uint32_t raw;
} FloatConverter;

FloatConverter fc;
fc.f = 3.14;
printf("Hex: 0x%08X\n", fc.raw);  // Xem biểu diễn nhị phân của float
```

### c) Tiết kiệm bộ nhớ

```c
typedef union {
    struct { int x, y; } point;   // Khi dùng làm tọa độ
    struct { int w, h; } size;    // Khi dùng làm kích thước
    uint32_t raw[2];              // Khi cần gửi thô
} Shape;

// 3 cách dùng, cùng 1 vùng nhớ, chỉ 8 byte!
```

---

## 7. ⚠️ Lưu ý

| Lưu ý | Giải thích |
|-------|------------|
| **Chỉ 1 member hợp lệ tại 1 thời điểm** | Ghi member này, đọc member khác → giá trị không xác định |
| **Kích thước = member lớn nhất** | Không phải tổng các member |
| **Không có padding giữa các member** | Các member bắt đầu CÙNG địa chỉ |
| **Dùng struct trong union** | Phổ biến để chia nhỏ thanh ghi |

---

## 8. 💡 Mẹo nhớ

```
Struct: MỖI member MỘT vùng nhớ riêng
Union:  TẤT CẢ member CHUNG 1 vùng nhớ

→ Struct: Dùng khi cần LƯU NHIỀU giá trị cùng lúc
→ Union:  Dùng khi cần TIẾT KIỆM bộ nhớ hoặc TRUY CẬP ĐA KIỂU
```