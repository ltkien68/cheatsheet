# 📌 Bit Manipulation Macros

> **Tên gọi khác:** Register Manipulation Macros, GPIO Macros, Bitwise Macros  
> **Dùng trong:** Firmware C, Embedded Systems, Bare-metal Programming  
> **Cập nhật:** 10/06/2026

---

## 🎯 Mục đích

Dùng để **đọc/ghi/thay đổi một bit cụ thể** trong thanh ghi phần cứng (GPIO, Timer, UART, ADC...) mà không ảnh hưởng đến các bit khác.

---

## 📐 Cú pháp chuẩn

```c
#define SET_BIT(reg, bit)       ((reg) |= (1UL << (bit)))   // Bật bit lên 1
#define CLEAR_BIT(reg, bit)     ((reg) &= ~(1UL << (bit)))  // Xóa bit về 0
#define TOGGLE_BIT(reg, bit)    ((reg) ^= (1UL << (bit)))   // Đảo trạng thái bit
#define READ_BIT(reg, bit)      (((reg) >> (bit)) & 1UL)    // Đọc giá trị bit (0/1)
```

---

## 🔍 Giải thích chi tiết từng macro

### 1. SET_BIT — Bật bit lên 1

```c
#define SET_BIT(reg, bit)  ((reg) |= (1UL << (bit)))

// Ví dụ:
// reg  = 0000 0000 (0x00)
// bit  = 3
// 1<<3 = 0000 1000 (0x08)
// reg |= 0000 1000 → reg = 0000 1000 (0x08)
// Kết quả: bit 3 = 1, các bit khác KHÔNG đổi
```

**Nguyên lý:** OR với 1 luôn ra 1, OR với 0 giữ nguyên giá trị.

---

### 2. CLEAR_BIT — Xóa bit về 0

```c
#define CLEAR_BIT(reg, bit)  ((reg) &= ~(1UL << (bit)))

// Ví dụ:
// reg  = 0000 1000 (0x08)
// bit  = 3
// 1<<3 = 0000 1000
// ~    = 1111 0111
// reg &= 1111 0111 → reg = 0000 0000 (0x00)
// Kết quả: bit 3 = 0, các bit khác KHÔNG đổi
```

**Nguyên lý:** AND với 0 luôn ra 0, AND với 1 giữ nguyên giá trị.

---

### 3. TOGGLE_BIT — Đảo trạng thái bit

```c
#define TOGGLE_BIT(reg, bit)  ((reg) ^= (1UL << (bit)))

// Ví dụ:
// reg  = 0000 0000 (0x00)
// bit  = 3
// 1<<3 = 0000 1000
// reg ^= 0000 1000 → reg = 0000 1000 (0x08)
//
// Gọi lại lần 2:
// reg  = 0000 1000 (0x08)
// reg ^= 0000 1000 → reg = 0000 0000 (0x00)
// Kết quả: bit 3 đảo 0→1→0→1...
```

**Nguyên lý:** XOR với 1 đảo bit (0→1, 1→0), XOR với 0 giữ nguyên.

---

### 4. READ_BIT — Đọc giá trị bit

```c
#define READ_BIT(reg, bit)  (((reg) >> (bit)) & 1UL)

// Ví dụ:
// reg  = 0000 1000 (0x08)
// bit  = 3
// reg >> 3 = 0000 0001
// & 1UL    = 0000 0001 = 1
// Kết quả: trả về 0 hoặc 1
```

**Cách dùng trong if:**
```c
if (READ_BIT(PORTB, 3)) {
    // Bit 3 = 1
} else {
    // Bit 3 = 0
}
```

---

## 📊 Bảng nguyên lý phép toán bit

| Phép toán | Ký hiệu | Với 0 | Với 1 | Dùng để |
|-----------|:---:|:---:|:---:|---------|
| **OR** | `\|` | Giữ nguyên | **Luôn = 1** | `SET_BIT` |
| **AND** | `&` | **Luôn = 0** | Giữ nguyên | `CLEAR_BIT` |
| **XOR** | `^` | Giữ nguyên | **Đảo bit** | `TOGGLE_BIT` |

---

## 💡 Mẹo nhớ nhanh

```
OR  với 1 → SET (bật)
AND với 0 → CLEAR (tắt)
XOR với 1 → TOGGLE (đảo)
Dịch phải & 1 → READ (đọc)
```

---

## ⚠️ Lưu ý quan trọng

### 1. Luôn dùng `1UL` (Unsigned Long)

```c
// ✅ Đúng — an toàn trên thanh ghi 32-bit
#define SET_BIT(reg, bit)  ((reg) |= (1UL << (bit)))

// ❌ Sai — tràn số nếu bit > 15 trên hệ 16-bit
#define SET_BIT(reg, bit)  ((reg) |= (1 << (bit)))
```

### 2. Ngoặc đơn bao quanh tham số

```c
// ✅ Đúng — an toàn khi truyền biểu thức
#define SET_BIT(reg, bit)  ((reg) |= (1UL << (bit)))

// ❌ Sai — lỗi nếu gọi SET_BIT(*ptr, 3+1)
#define SET_BIT(reg, bit)  (reg |= 1UL << bit)
```

### 3. Với thanh ghi phần cứng thật, phải dùng `volatile`

```c
// Trên STM32/AVR thực tế
#define GPIOA_ODR  (*(volatile uint32_t*)0x40020014)
SET_BIT(GPIOA_ODR, 5);  // Bật PA5
```

---