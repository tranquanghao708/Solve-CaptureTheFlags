# Writeup : Chall 5

**mục lục**

- 1.debug kiểu read quá số lượng trong program

- 2.phân tích strcmp

- 3.thử một sai lầm vào program và debug với gdb runtime xem flow sequences

- 4.dùng printf shell để transmit exactly sequences vào program tránh newline `\n`

- 5.phân tích condition

- 5.1.xác định vị trí local_1b và local_1c

- 6.generating payload và lấy flags

---

## 1.debug kiểu read quá số lượng trong program

![alt text](image/image0.png)

- ta thấy read đọc vượt tới 16 byte trong khi đó array chỉ chứa 12 byte vậy OOB (out of bount) rồi, chưa tới ngưỡng BOF

## 2.phân tích strcmp

![alt text](image/image1.png)

- ta thấy payload lần một được hardcode trong program là `normal_user`

## 3.thử một sai lầm vào program và debug với gdb runtime xem flow sequences

- dùng shell trực tiếp vào normal_user, kết quả system thêm newline gây fails và strcmp trả **value $$\large\neq$$ 0**

![alt text](image/image2.png)

- debug với gdb, ni tới phần read, nó vào shell input rồi nhập `normal_user` tiếp tục ni tiếp khi tới call strcmp ta có :

![alt text](image/image3.png)

- strcmp sai vì newline, rõ ràng nó đã thêm `\n` sau khi enter sequences input vào program

## 4.dùng printf shell để transmit exactly sequences vào program tránh newline `\n`

- để transmit chính xác vào program mà ko bị thêm cái gì vào, ta dùng :

> printf "normal_user" | ./representing_strings

![alt text](image/image4.png)

- chính thức qua ải newline, tới ải tiếp theo

## 5.phân tích condition

![alt text](image/image5.png)

- condition = `(local_1c == '\x01') && (local_1b == '\x02)`, vậy `local_1c` và `local_1b` = Đã được gán gì đâu? , nhưng nhớ lại read đọc quá vùng array (oob) vậy ta có hypothesis : `"nếu đọc oob, nhớ lại BOF ta ghi đè RIP để return tới hàm win gọi đó là ret2win vậy ở đây nó so sánh \x01 và \x02, khái niệm representing_strings là biểu diễn chuỗi dưới góc nhìn memory vậy thử xác định vị trí local 1c và 1b và gán xem sao"`

#### 5.1.xác định vị trí local_1b và local_1c

- local_1b nằm ở vaddr là `result verify + 0x3` và local1c cũng vậy. Assembly show :

![alt text](image/image6.png)

**Vậy proof gì để chứng minh là program sẽ đọc và compare tại vị trí đó? hình stack đâu? :**

#### 6.generating payload và lấy flags

- Trước hết, strcmp chỉ read sequences khi nó gặp null byte `\0` là dừng, nhưng read đọc oob ở array thì việc đầu tiên là phải thêm nullbyte trước cho dừng strcmp đi, xong mới tới payload là `\1` và `\2`

> payload = normal_user\0\1\2

![alt text](image/image7.png)