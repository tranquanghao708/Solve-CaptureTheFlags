# Writeup : chall2

**mục lục**

- 1.unsigned Interger Overflow là gì?

- 2.giải mã condition trong program

- 3.Generation và lấy flags

---

## 1.unsigned Interger Overflow là gì?

- Là vượt Umax + 1 = $$\large2^{N}$$, ví dụ `1111 + 1 = 0000 (1carry)` lý giải chi tiết ở [two_complement_code](https://github.com/tranquanghao708/CSAPP-learning/blob/main/writeup/two-complement-code/two-complement-code.md)

## 2.giải mã condition trong program

- ghidra show :

![alt text](image0.png)

- Condiction :

```c
      if (length + offset < 0x401) {
          if (offset == 0xfffffff0) {
```

bypass length + offset bằng cách làm tràn số nguyên ko dấu unsigned overflow, `0xfffffff0 + 0x401 = 11111111111111111111111111110000 + 00000000000000000000010000000000 = 000000000000000000000001111110001 (1 carry)` :

![alt text](image1.png)

0x3f1 < 0x401 = True (bypassed), bây giờ để offset là 0xfffffff0 thì đơn giản là gán cái này là offset input thôi

## 3.Generation và lấy flags

offset = 4294967280 ( 0xfffffff0 )

lenght = 1024

![alt text](image2.png)

