# 🚀 Lộ trình trở thành IoT Embedded Engineer

> **Bắt đầu:** Tháng 6/2026  
> **Mục tiêu:** IoT Embedded Engineer chuyên nghiệp  
> **Nền tảng hiện tại:** C/C++, Python cơ bản, Mạng máy tính, ESP32

---

## 📊 TỔNG QUAN

```
GÀ MỜ ──→ JUNIOR ──→ MIDDLE ──→ SENIOR ──→ EXPERT
(Hiện tại)  (6 tháng)  (1.5 năm)  (3 năm)    (5+ năm)
```

| Giai đoạn | Thời gian | Mục tiêu | Mức lương (VN) |
|:---:|:---:|-----------|:---:|
| **1. Nền tảng C** | Đã xong ✅ | Con trỏ, bitwise, struct | — |
| **2. Firmware cơ bản** | 2-3 tháng | GPIO, UART, I2C, SPI, Timer, ISR | — |
| **3. RTOS + WiFi** | 2-3 tháng | FreeRTOS, ESP-IDF, MQTT | — |
| **4. Backend + Cloud** | 2-3 tháng | Python FastAPI, Database, MQTT Broker | — |
| **5. Flagship Project** | 3-4 tháng | Gậy dò đường thông minh | — |
| **6. Đi làm Junior** | Bắt đầu | IoT Embedded Engineer | $500-800 |
| **7. Lên Middle** | Sau 1.5 năm | Độc lập dự án, mentor Junior | $800-1500 |
| **8. Lên Senior** | Sau 3 năm | Thiết kế hệ thống, dẫn team nhỏ | $1500-2500 |
| **9. Expert/Architect** | Sau 5+ năm | Chuyên sâu 1 mảng, khó thay thế | $2500-5000 |

---

## 🎯 GIAI ĐOẠN 1: NỀN TẢNG C (ĐÃ XONG ✅)

| Đã học | Mức độ |
|--------|:---:|
| Con trỏ, đa cấp, con trỏ hàm | ⭐⭐⭐⭐⭐ |
| Bit manipulation (SET/CLEAR/TOGGLE/READ) | ⭐⭐⭐⭐⭐ |
| Struct, union, packed, alignment | ⭐⭐⭐⭐ |
| Enum, typedef, macro, preprocessor | ⭐⭐⭐⭐⭐ |
| Function pointer, callback pattern | ⭐⭐⭐⭐ |
| Memory layout (stack, heap, .data, .bss) | ⭐⭐⭐ |
| Circular buffer (cơ bản) | ⭐⭐⭐ |

---

## 🎯 GIAI ĐOẠN 2: FIRMWARE CƠ BẢN (2-3 tháng)

### Tháng 1: Ngoại vi cơ bản

| Tuần | Chủ đề | Thực hành | Board |
|:---:|--------|-----------|:---:|
| 1 | **GPIO Input/Output** | LED nhấp nháy, đọc nút nhấn, debounce | ESP32 |
| 2 | **UART** | Serial console, debug printf, gửi/nhận dữ liệu | ESP32 |
| 3 | **I2C** | Đọc cảm biến nhiệt độ/độ ẩm (BMP280, DHT20) | ESP32 |
| 4 | **SPI** | Giao tiếp màn hình OLED, SD card module | ESP32 |

### Tháng 2: Ngắt & Timer

| Tuần | Chủ đề | Thực hành | Board |
|:---:|--------|-----------|:---:|
| 5 | **Timer cơ bản** | Delay chính xác không blocking | ESP32 |
| 6 | **PWM** | Điều khiển độ sáng LED, servo motor | ESP32 |
| 7 | **External Interrupt** | Ngắt ngoài từ nút nhấn, cảm biến PIR | ESP32 |
| 8 | **ADC** | Đọc cảm biến ánh sáng (LDR), pin | ESP32 |

### Tháng 3: Giao thức nâng cao & Tổng hợp

| Tuần | Chủ đề | Thực hành | Board |
|:---:|--------|-----------|:---:|
| 9 | **I2C nâng cao** | EEPROM, RTC DS3231 | ESP32 |
| 10 | **SPI nâng cao** | TFT LCD, Flash memory W25Q | ESP32 |
| 11 | **1-Wire (tùy chọn)** | Cảm biến DS18B20 | ESP32 |
| 12 | **Data Logger Project** | Đọc 3 cảm biến → lưu SD card | ESP32 |

---

## 🎯 GIAI ĐOẠN 3: RTOS + WiFi + MQTT (2-3 tháng)

### Tháng 4: FreeRTOS

| Tuần | Chủ đề | Thực hành |
|:---:|--------|-----------|
| 13 | **Task cơ bản** | Tạo 3 task: LED blink, UART log, Sensor read |
| 14 | **Queue** | Gửi dữ liệu cảm biến giữa các task |
| 15 | **Semaphore & Mutex** | Đồng bộ truy cập SPI bus, UART |
| 16 | **Software Timer** | Đọc cảm biến định kỳ không cần delay |

### Tháng 5: WiFi + MQTT

| Tuần | Chủ đề | Thực hành |
|:---:|--------|-----------|
| 17 | **WiFi Station/AP** | Kết nối WiFi, SmartConfig |
| 18 | **MQTT cơ bản** | Publish nhiệt độ lên HiveMQ Cloud |
| 19 | **MQTT nâng cao** | Subscribe điều khiển LED từ xa |
| 20 | **OTA Update** | Nạp firmware qua WiFi |

---

## 🎯 GIAI ĐOẠN 4: BACKEND + CLOUD (2-3 tháng)

### Tháng 6: Python Backend

| Tuần | Chủ đề | Thực hành |
|:---:|--------|-----------|
| 21 | **FastAPI cơ bản** | Viết API CRUD cho thiết bị IoT |
| 22 | **MQTT Client Python** | Server nhận dữ liệu từ ESP32 qua MQTT |
| 23 | **Database** | SQLite → PostgreSQL |
| 24 | **WebSocket** | Real-time dashboard hiển thị dữ liệu |

### Tháng 7: Cloud & Deploy

| Tuần | Chủ đề | Thực hành |
|:---:|--------|-----------|
| 25 | **Docker** | Đóng gói server thành container |
| 26 | **Deploy Render.com** | Server online 24/7 miễn phí |
| 27 | **Push Notification** | Firebase Cloud Messaging |
| 28 | **Monitoring** | Health check, logging, alert |

---

## 🎯 GIAI ĐOẠN 5: FLAGSHIP PROJECT (3-4 tháng)

```
🦯 GẬY DÒ ĐƯỜNG THÔNG MINH CHO NGƯỜI KHIẾM THỊ

┌─────────────────────────────────────────────────────┐
│ ESP32-CAM + 3x HC-SR04 + Motor Rung + Buzzer        │
│         │                                           │
│         ▼                                           │
│   MQTT → FastAPI Server → PostgreSQL                │
│         │                                           │
│         ▼                                           │
│   Mobile App (Flutter) + Web Dashboard              │
│   - Theo dõi vị trí real-time                       │
│   - Nhận cảnh báo khi có vật cản                    │
│   - Nhận thông báo khẩn cấp                         │
└─────────────────────────────────────────────────────┘
```

| Version | Tính năng | Thời gian |
|:---:|-----------|:---:|
| **V1** | Cảm biến siêu âm + Rung + Còi | 3-4 tuần |
| **V2** | WiFi + MQTT → Server → Database | 3-4 tuần |
| **V3** | Camera + OCR đọc văn bản | 4-6 tuần |
| **V4** | Mobile App + Dashboard + Test thực tế | 4-6 tuần |

---

## 🎯 GIAI ĐOẠN 6-9: ĐI LÀM & THĂNG TIẾN

| Mốc | Vị trí | Kinh nghiệm | Công việc chính | Mức lương (VN) |
|:---:|--------|:---:|-----------------|:---:|
| **Bắt đầu** | Junior IoT Embedded | 0-1 năm | Sửa lỗi, thêm tính năng nhỏ, test, học codebase | $500-800 |
| **1.5 năm** | Middle | 1.5-3 năm | Độc lập module, mentor fresher, review code | $800-1500 |
| **3 năm** | Senior | 3-5 năm | Thiết kế hệ thống, dẫn team 2-3 người, quyết định công nghệ | $1500-2500 |
| **5+ năm** | Expert/Architect | 5+ năm | Chuyên sâu 1 mảng, tư vấn giải pháp, khó thay thế | $2500-5000 |

---

## 📚 TÀI NGUYÊN HỌC TẬP

### Sách
| Giai đoạn | Sách |
|-----------|------|
| C cơ bản | The C Programming Language (K&R) |
| C nâng cao | C Programming: A Modern Approach |
| Firmware | Making Embedded Systems (Elecia White) |
| RTOS | Mastering the FreeRTOS Kernel |
| MQTT | HiveMQ MQTT Essentials (free ebook) |

### Online
| Giai đoạn | Link |
|-----------|------|
| ESP32 | [ESP-IDF Programming Guide](https://docs.espressif.com/projects/esp-idf/en/latest/) |
| FreeRTOS | [FreeRTOS Documentation](https://www.freertos.org/Documentation/RTOS_book.html) |
| FastAPI | [FastAPI Tutorial](https://fastapi.tiangolo.com/tutorial/) |
| MQTT | [HiveMQ MQTT Guide](https://www.hivemq.com/mqtt-essentials/) |
| Assembly | [Compiler Explorer (godbolt.org)](https://godbolt.org) |

### Blog & Cộng đồng
| Blog | Mô tả |
|------|-------|
| [Embedded Artistry](https://embeddedartistry.com) | Best practices cho firmware |
| [Interrupt Blog](https://interrupt.memfault.com) | Debug, RTOS, embedded Linux |
| [r/embedded](https://reddit.com/r/embedded) | Cộng đồng embedded |
| [Hackaday](https://hackaday.com) | Dự án phần cứng thực tế |

---

## 📋 CHECKLIST TRƯỚC KHI ĐI LÀM

### Kỹ thuật
- [ ] Viết được driver UART/I2C/SPI không cần copy-paste
- [ ] Đọc hiểu datasheet cảm biến mới trong 1 giờ
- [ ] Debug được crash/hard fault bằng JTAG/GDB
- [ ] Thiết kế được task FreeRTOS cho hệ thống 3-4 cảm biến
- [ ] Gửi được dữ liệu ESP32 → MQTT → Server → Dashboard
- [ ] Hiểu và áp dụng được volatile, static, extern
- [ ] Viết được circular buffer, state machine

### Công cụ
- [ ] Git/GitHub thành thạo (commit, branch, PR, rebase)
- [ ] VS Code + PlatformIO hoặc ESP-IDF
- [ ] Logic Analyzer / Oscilloscope cơ bản
- [ ] Wireshark bắt gói MQTT/TCP
- [ ] Docker cơ bản

### Dự án & CV
- [ ] GitHub 200+ commits với code sạch, README đẹp
- [ ] Flagship project chạy thật, có video demo
- [ ] CV đẹp, có project nổi bật
- [ ] Phỏng vấn thử ít nhất 3 công ty

### Ngoại ngữ
- [ ] Đọc hiểu datasheet tiếng Anh
- [ ] Viết README, comment code bằng tiếng Anh
- [ ] Giao tiếp cơ bản với khách hàng nước ngoài

---

## ⏱️ TIMELINE TỔNG

```
06/2026 ──→ 12/2026 ──→ 06/2027 ──→ 06/2028 ──→ 06/2030
  │           │           │           │           │
  │      Firmware     Junior      Middle      Senior
  │      + RTOS       Engineer    Engineer    Engineer
  │      + Cloud
  │
Hiện tại
```

---

## 🎯 MỤC TIÊU SMART

| Tiêu chí | Mục tiêu |
|----------|----------|
| **Specific** | Trở thành IoT Embedded Engineer |
| **Measurable** | Có job offer $700+ trước khi tốt nghiệp |
| **Achievable** | Học 4-6h/ngày, 5 ngày/tuần |
| **Relevant** | Phù hợp chuyên ngành Nhúng & IoT |
| **Time-bound** | 6 tháng sẵn sàng đi làm, 1.5 năm lên Middle |

---

> **"Code mỗi ngày, project mỗi tháng, việc làm trong 6 tháng."** 🚀