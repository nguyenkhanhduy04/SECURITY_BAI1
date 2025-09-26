# BÀI TẬP 1:
TÌM HIỂU CÁC PHƯƠNG PHÁP MÃ HOÁ CỔ ĐIỂN <br>
Caesar <br>
Affine <br>
Hoán vị <br>
Vigenère <br>
Playfair <br>

-------------------------------------------------------------------------------------------
Với mỗi phương pháp, hãy tìm hiểu:<br>
Tên gọi<br>
Thuật toán mã hoá, thuật toán giải mã<br>
Không gian khóa<br>
Cách phá mã (mà không cần khoá)<br>
Cài đặt thuật toán mã hoá và giải mã bằng code C++ và bằng html+css+javascript<br>

# BÀI LÀM: <br>#

Caesar: <br>
- Tên gọi: Caesar cipher
- Thuật toán mã hóa: C = (P + k) mod 26
- Thuật toán giải mã: P = (C - k) mod 26
- Không gian mã hóa: 26 khả năng (k = 0..25). Nếu k=0 thì không mã hóa.
- Cách phá mã ( mà không cần khóa) :
    + Brute force thử 25 khả năng và đọc kết quả (rất nhỏ).
    + Tần suất (frequency analysis) dùng tần suất ký tự (ví dụ E thường nhất).
    + Đối với văn bản ngắn, brute force đọc nhanh là phổ biến.
- Kết quả chạy code:

Affine: 
- Tên gọi: Affine cipher: ánh xạ tuyến tính modulo 26: E(x) = (a*x + b) mod 26
- Thuật toán mã hóa: C = (a * P + b) mod 26
- Thuật toán giải mã: P = a^{-1} * (C - b) mod 26
- Không gian mã hóa: 
    + a phải nguyên tố cùng nhau với 26 (gcd(a,26)=1). Các a hợp lệ: 1,3,5,7,9,11,15,17,19,21,23,25 → 12 giá trị.
    + b ∈ {0..25} → 26 giá trị <br>
       => Tổng 12 * 26 = 312 khả năng
      
- Cách phá mã ( mà không cần khóa) :
    + Brute force 312 khả năng (rất nhỏ).
    + Tần suất ký tự (phân tích tần suất) có thể tìm a và b bằng hệ phương trình từ hai ký tự thường gặp (ví dụ E và T).
    + Có thể dùng known-plaintext attack nếu biết một số cặp.
      
- Kết quả chạy code:

Hoán Vị: 
- Tên gọi: Columnar transposition cipher
- Thuật toán mã hóa:
    + Chọn khóa là một chuỗi ký tự (ví dụ "ZEBRA") — ta gán thứ tự số cho từng cột theo thứ tự chữ cái của khóa (Z=5,E=2,...).
    + Viết plaintext theo hàng với số cột = độ dài khóa, điền thêm ký tự pad nếu cần
    + Đọc ciphertext theo cột theo thứ tự số khóa (từ cột nhỏ nhất tới lớn).
- Thuật toán giải mã:
    + Biết độ dài khóa n, chia ciphertext thành các phần ứng với mỗi cột (các cột có thể khác độ dài nếu padding).
    + Điền từng cột theo thứ tự đã cho, rồi đọc theo hàng.
- Không gian mã hóa: Số hoán vị của n ký tự = n! (giai thừa). Ví dụ khóa 6 ký tự → 720 khả năng.
      
- Cách phá mã ( mà không cần khóa) :
    + Brute force thử các hoán vị (n! — nhanh với n nhỏ, khó với n lớn).
    + Dựa vào dạng văn bản: dùng chỉ số ngẫu nhiên hay phân tích n-gram khi thử các hoán vị.
    + Kết hợp với suy đoán khe (crib) — biết một từ xuất hiện trong plaintext để tìm hoán vị.
      
- Kết quả chạy code:

Vigenère:
- Tên gọi: Vigenère cipher — cipher dạng polyalphabetic dùng từ khóa lặp.
- Thuật toán mã hóa: C_i = (P_i + K_{i mod m}) mod 26
- Thuật toán giải mã: P_i = (C_i - K_{i mod m}) mod 26
- Không gian mã hóa: Mọi chuỗi ký tự độ dài m: 26^m. Nếu m không biết, keyspace rất lớn.
- Cách phá mã ( mà không cần khóa) :
    + Kasiski examination: tìm khoảng cách giữa các chuỗi trùng lập (trigrams...) để suy ra độ dài khóa.
    + Index of Coincidence (IoC) để ước tính độ dài khóa.
    + Khi độ dài khóa m được biết, mỗi tập chữ cùng vị trí modulo m là Caesar cipher đơn; phân tích tần suất từng nhóm để tìm dịch chuyển (brute force từng nhóm 26 khả năng).
    + Nếu key ngắn, brute force trên không gian 26^m có thể khả thi với m nhỏ.
      
- Kết quả chạy code:

PLayFair:
- Tên gọi: Playfair cipher — mã thay thế theo cặp (digraph), dùng ma trận 5x5.
- Thuật toán mã hóa:
  + Nếu X và Y ở cùng hàng: thay bằng ký tự bên phải (vòng quanh).
  + Nếu cùng cột: thay bằng ký tự bên dưới (vòng quanh).
  + Nếu cùng khác hàng & cột: thay bằng 2 chữ cái thuộc cùng hàng nhưng ở cột đối xứng tạo thành rectangle (X -> chữ cùng hàng X nhưng cột của Y, Y -> chữ cùng hàng Y nhưng cột của X).
- Thuật toán giải mã:
  + Ngược lại: cùng hàng → lấy bên trái; cùng cột → lấy bên trên; khác hàng & cột → như mã hóa nhưng đổi cột tương ứng.
  
- Không gian mã hóa:Khóa tạo ma trận bằng cách viết key (loại trùng lặp) rồi phần còn lại của bảng chữ cái → số ma trận khả dĩ = 25! /? nhưng nếu dùng khóa chữ thì không gian khóa liên quan đến chuỗi khóa; thực tế khóa thường là chuỗi chữ (một từ), rất lớn nhưng không khổng lồ theo cách sử dụng.
- Cách phá mã ( mà không cần khóa) :
    + Phân tích digraph (tần suất bigram) — Playfair giữ cấu trúc digraph, có tần suất bigram đặc trưng.
    + Brute-force khóa (khó nếu không có crib), nhưng tấn công dựa trên heuristic & hill-climbing (được dùng trong mật mã học cổ điển) có thể phục hồi bảng.
    + Known-plaintext attack: nếu biết vài cặp, có thể suy ra các vị trí trong bảng.
      
- Kết quả chạy code:
