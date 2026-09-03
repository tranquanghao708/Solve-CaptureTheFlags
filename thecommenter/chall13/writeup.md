# Chall13 : Float casting

**index**

- [1.Số thực khi ép kiểu sang số nguyên xảy ra hiện tượng gì?](#1số-thực-khi-ép-kiểu-sang-số-nguyên-xảy-ra-hiện-tượng-gì)

- [2.Phân tích hàm lệnh và condiction của đoạn decompile](#2phân-tích-hàm-lệnh-và-condiction-của-đoạn-decompile)

	- [2.1.Hàm lệnh ép kiểu float sang int rồi lại sang float](#21hàm-lệnh-ép-kiểu-float-sang-int-rồi-lại-sang-float)

- [3.Giải chall13](#3giải-chall13)

	- [3.1.Vì sao lại có thể giải được chall13](#31vì-sao-lại-có-thể-giải-được-chall13)

---

## 1.Số thực khi ép kiểu sang số nguyên xảy ra hiện tượng gì?

hiện tượng ép kiểu số thực sang số nguyên giống cơ chế làm tròn [round toward zero](https://github.com/tranquanghao708/CSAPP-learning/blob/main/writeup/floating-point_number/writeup.md#34round-toward-zero). Cụ thể, khi số thực vô biến float như `3.9` nhưng khi ép kiểu sang `int` hay hệ số ko dấu `unsigned int` thì nó sẽ là `3` nhưng nếu ép lại sang float thì sẽ xảy ra hiện tượng mất độ chính xác như `3.0` thay vì `3.9`:

<div align="center">

| số thực gốc | sau khi ép sang int | sau khi ép lại sang float |
|-|-|-|
| 3.9 | 3 | 3.0 |
| 1.2 | 1 | 1.0 |
| 9.9 | 9 | 9.0 |

> xảy ra hiện tượng mất độ chính xác khi ép lại sang float

</div>
