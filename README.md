# DA-CSLT
Đồ án cơ sở lập trình - kỳ 3 - quản lý thư viện;
-------------------------------------------------

Chi tiết về đồ án trong file word đính kèm

-------------------------------------------------

Cấu trúc dữ liệu: <br>
- file base.h khai báo lớp CTDL & inline các hàm nhỏ <br>
- các file sach.cpp, dssach.cpp, user.cpp, dsuser.cpp chứa các định nghĩa hàm <br>

Cấu trúc file input/output: <br>
- file input cho <b><i>danh sách sách</i></b> có định dạng mỗi dòng: <br>
mã_sách|tên_sách|tên_tác_giả|số_bản <br>
*mã_sách là string 6 chữ số, bắt đầu = "000001" <br>
*tên_sách, tên_tác_giả là string không dấu <br>

- file input cho <b><i>danh sách user</i></b> có định dạng: <br>
  1 dòng ghi: <br>
  mã_user|họ_tên|cmnd/mssv|số_sách <br>
  *mã_user là string 5 chữ số, bắt đầu = "00001" <br>
  *họ_tên tương tự là string không dấu <br>
  *cmnd/mssv là string 9 chữ số <br>
  *số_sách = n là số sách mà người dùng đang mượn của thư viện <br>
  n dòng tiếp theo có định dạng giống với input <b><i> danh sách sách </i></b> <br>
-------------------------------------------------

Giao diện chương trình: <i> đang phát triển </i>

-------------------------------------------------

Báo cáo đồ án: <i> chưa thực hiện </i>
