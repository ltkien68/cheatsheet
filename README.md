# QUY TẮC CON TRỎ (POINTER)

## 📌 Quy tắc vàng

| # | Quy tắc |
|---|---------|
| 1 | **Hậu tố (`x++`) ưu tiên CAO NHẤT** → luôn chạy trước |
| 2 | **Tiền tố (`++x`) và `*` ngang hàng** → kết hợp **PHẢI → TRÁI** |
| 3 | **`++` đằng TRƯỚC** → TĂNG trước, IN sau (in giá trị **MỚI**) |
| 4 | **`++` đằng SAU** → IN trước, TĂNG sau (in giá trị **CŨ**) |
| 5 | **Có `*`** → tác động **GIÁ TRỊ** \| **Không `*`** → tác động **CON TRỎ** |
| 6 | **`printf` đánh giá tham số từ PHẢI sang TRÁI** |

---

## 📊 Bảng thứ tự ưu tiên (rút gọn)

| Mức ưu tiên | Toán tử | Chiều kết hợp |
|:---:|----------|:---:|
| **1 (cao nhất)** | `()` `[]` `->` `.` | Trái → Phải |
| **1** | `x++` `x--` (hậu tố) | Trái → Phải |
| **2** | `++x` `--x` (tiền tố) | **Phải → Trái** |
| **2** | `*` (dereference) | **Phải → Trái** |
| **2** | `&` (address-of) | **Phải → Trái** |

---

## 🔍 Phân tích 5 biểu thức cơ bản

```c
int arr[] = {1, 2, 3, 4, 5};
int *ptr = arr;  // ptr → arr[0]
```

| Biểu thức | Phân tích | Tăng gì? | ptr di chuyển? | Trả về |
|-----------|-----------|:---:|:---:|:---:|
| `++*ptr` | `++(*ptr)` | **GIÁ TRỊ** | KHÔNG | Giá trị **MỚI** |
| `(*ptr)++` | `(*ptr)++` | **GIÁ TRỊ** | KHÔNG | Giá trị **CŨ** |
| `*++ptr` | `*(++ptr)` | **CON TRỎ** | CÓ | Giá trị vị trí **MỚI** |
| `*ptr++` | `*(ptr++)` | **CON TRỎ** | CÓ | Giá trị vị trí **CŨ** |
| `++*ptr++` | `++(*(ptr++))` | **CẢ HAI** | CÓ | Giá trị **MỚI** tại vị trí cũ |
