# 📌 Firmware C Patterns Cheatsheet

> **Dùng cho:** Embedded C, GPIO Driver, HAL Design  
> **Cập nhật:** 10/06/2026

---

## 1. 🎯 Cấu trúc chuẩn của một GPIO Driver

```c
// ===== 1. TYPEDEF =====
typedef uint8_t Register;           // Đại diện thanh ghi 8-bit

// ===== 2. ENUM TRẠNG THÁI =====
typedef enum {
    LED_OFF = 0,                    // Luôn gán = 0 cho rõ ràng
    LED_ON  = 1
} LED_STATUS;

// ===== 3. PIN DEFINITIONS (dùng số bit, không dùng mask) =====
#define RED_PIN    5               // Bit 5
#define GREEN_PIN  1               // Bit 1

// ===== 4. BITWISE MACROS =====
#define SET_BIT(reg, bit)    ((reg) |= (1UL << (bit)))
#define CLEAR_BIT(reg, bit)  ((reg) &= ~(1UL << (bit)))
#define READ_BIT(reg, bit)   (((reg) >> (bit)) & 1UL)

// ===== 5. CALLBACK TYPEDEF =====
typedef void (*CommandFunc)(Register*);  // Con trỏ hàm

// ===== 6. BIẾN TRẠNG THÁI TOÀN CỤC =====
LED_STATUS led_status = LED_OFF;

// ===== 7. HÀM ĐIỀU KHIỂN =====
void led_on(Register *reg) {
    led_status = LED_ON;           // Cập nhật cờ
    SET_BIT(*reg, LED_PIN);        // Thao tác thanh ghi
}

// ===== 8. HÀM KIỂM TRA HỆ THỐNG =====
SystemStatus check(Register reg) {
    if (READ_BIT(reg, ERROR_PIN)) return ERROR;
    if (motor_status != ON)       return MOTOR_FAULT;
    return OK;
}

// ===== 9. MAIN =====
int main() {
    Register gpio = 0x00;
    CommandFunc cmd;
    SystemStatus sys;

    cmd = led_on;                  // Gán hàm
    cmd(&gpio);                    // Gọi hàm qua con trỏ

    sys = check(gpio);
    if (sys == OK) { ... }
}
```

---

## 2. 📋 Các pattern dễ quên

### Pattern 1: Con trỏ hàm (Callback)

```c
// Khai báo kiểu
typedef void (*CommandFunc)(Register*);

// Khai báo biến
CommandFunc cmd;

// Gán và gọi
cmd = led_on;
cmd(&gpio);  // = led_on(&gpio)
```

**Tại sao dùng?** Để đổi hàm linh hoạt lúc runtime, lưu vào mảng, truyền như tham số.

---

### Pattern 2: Enum trạng thái + Biến cờ

```c
// Enum luôn gán = 0 cho giá trị đầu tiên
typedef enum {
    LED_OFF = 0,
    LED_ON  = 1
} LED_STATUS;

// Biến cờ toàn cục
LED_STATUS led1_status = LED_OFF;

// Cập nhật trong hàm
void led_on(Register *reg) {
    led1_status = LED_ON;   // Nhớ cập nhật!
    SET_BIT(*reg, LED_PIN);
}
```

**Tại sao cần?** Vì đọc trạng thái từ thanh ghi không phải lúc nào cũng được (thanh ghi write-only, hoặc cần biết trạng thái mong muốn).

---

### Pattern 3: Hàm kiểm tra hệ thống

```c
SystemStatus systemCheck(Register reg) {
    // Kiểm tra theo thứ tự ưu tiên: khẩn cấp → thường
    if (READ_BIT(reg, EMERGENCY_PIN))  return EMERGENCY_STOP;
    if (READ_BIT(reg, OVERHEAT_PIN))   return OVERHEAT;
    if (motor1_status != MOTOR_ON)     return MOTOR_FAULT;
    return OK;
}
```

**Nguyên tắc:** Kiểm tra lỗi nghiêm trọng TRƯỚC, OK ở CUỐI.

---

### Pattern 4: Sử dụng con trỏ hàm trong if/switch

```c
LightCommand cmd;

if (mode == PRIORITY) {
    cmd = red_on;      // Xe cứu thương → đèn đỏ
} else {
    cmd = green_on;    // Bình thường → đèn xanh
}

cmd(&gpio);  // Gọi hàm đã chọn
```

---

### Pattern 5: Macro BIT với tham số `reg` là CON TRỎ

```c
// Khi reg là con trỏ: Register *reg
SET_BIT(*reg, PIN);    // Phải dereference: *reg

// Khi reg là biến thường: Register reg
SET_BIT(reg, PIN);     // Không cần *
```

---

## 3. ⚠️ Lỗi thường gặp & Cách tránh

| Lỗi | Sai | Đúng |
|-----|-----|------|
| **Quên dereference** | `SET_BIT(reg, PIN)` | `SET_BIT(*reg, PIN)` |
| **`=` thay `==`** | `if (sys = OK)` | `if (sys == OK)` |
| **Quên cập nhật cờ** | Chỉ `SET_BIT`, không `status = ON` | Làm cả 2 |
| **Dùng mask thay số bit** | `#define LED 0x08` | `#define LED 3` |
| **Quên `volatile` cho ISR** | `int flag = 0;` | `volatile int flag = 0;` |
| **READ_BIT sai** | `((reg) << (bit)) & 1` | `((reg) >> (bit)) & 1` |

---

## 4. 📐 Sơ đồ tổ chức code

```
1. typedef        → Kiểu dữ liệu tùy chỉnh
2. enum           → Trạng thái, mã lỗi
3. #define        → Pin, macro bitwise
4. typedef hàm    → Con trỏ hàm
5. Biến toàn cục  → Trạng thái
6. Hàm điều khiển → Bật/tắt thiết bị
7. Hàm kiểm tra   → systemCheck()
8. main()         → Logic chính
```

---

## 5. 🔄 Quy trình viết 1 module mới

```
1. Định nghĩa PIN (#define)
2. Tạo enum trạng thái
3. Tạo biến cờ trạng thái
4. Viết hàm on/off (SET + cập nhật cờ)
5. Viết hàm kiểm tra
6. Test trong main() với callback
```

---

## 6. 💡 Mẹo nhớ nhanh

```
"Muốn điều khiển GPIO, cần 5 thứ:"

PIN → ENUM → BIẾN CỜ → HÀM ON/OFF → CALLBACK
 ↓       ↓        ↓          ↓           ↓
#define  typedef  LED_STATUS  void led_on  CommandFunc cmd
```

---

## 7. 📝 Code mẫu tối giản (copy & chỉnh sửa)

```c
#include <stdio.h>
#include <stdint.h>

typedef uint8_t Register;

typedef enum { OFF = 0, ON = 1 } State;
typedef enum { OK = 0, ERROR = 1 } Status;
typedef void (*Cmd)(Register*);

#define PIN  3
#define SET(reg, bit)  ((reg) |= (1UL << (bit)))
#define CLR(reg, bit)  ((reg) &= ~(1UL << (bit)))
#define RD(reg, bit)   (((reg) >> (bit)) & 1UL)

State stt = OFF;

void on(Register *r)  { stt = ON;  SET(*r, PIN); }
void off(Register *r) { stt = OFF; CLR(*r, PIN); }

Status check(Register r) {
    if (stt != ON) return ERROR;
    return OK;
}

int main() {
    Register gpio = 0x00;
    Cmd cmd = on;
    cmd(&gpio);

    if (check(gpio) == OK) printf("OK\n");
    return 0;
}
```