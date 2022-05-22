```
Họ và tên: Lê Minh Đức
MSSV: 21020305
Lớp: K66CC
 ```
# Bài tập cuối kì LTNC - Flappy Laptop
## 1. Hướng dẫn cài đặt
- Cài đặt đầy đủ các thư viện SDL2, SDL2_ttf, C++.
- Nếu dùng Macbook
  - Kiểm tra lại đường link thư viện ở makefile.
  - Dùng lệnh `make` trong Terminal để chạy.
- Nếu dùng PC
  - Sửa lại makefile sao cho phù hợp với máy của mình hoặc tạo project trên Code::Blocks để chạy.
  - `make`
## 2. Mô tả chung
### *Ý tưởng*:
- Ý tưởng ban đầu là clone lại game **Flappy Bird** rồi sửa lại con chim thành học sinh, các cột thành các môn học. Nhưng trong quá trình xây dựng do các cột sinh random nên tên các môn học sẽ không được đầy đủ nên phải sửa lại, **Laptop** ở đây đại diện cho học sinh.
### *Cách chơi*:
- Click Start để bắt đầu chơi.
- Click chuột trái để điều khiển Laptop qua các ống.
## 3. Các chức năng đã cài đặt
- Hiệu ứng hình ảnh, âm thanh
- Menu điều khiển, tạm dừng
- Thông báo kết thúc game, có thể chơi lại
- Hai cách chơi: với máy hoặc với người
[*Video minh họa*](https://youtu.be/JCGWOHy1J6Y)
## 4. Các kỹ thuật lập trình
- Sử dụng con trỏ, mảng, xâu, các cấu trúc dữ liệu đơn giản.
- Sử dụng class và lập trình hướng đối tượng cơ bản.
- Sử dụng thư viện đồ hoạ SDL2.
- Tự vẽ lại 70% đồ hoạ sử dụng trong game.
## 5. Kết luận
- Đồ Hoạ của game còn rất đơn giản, code nhiều chỗ dài và chưa tối ưu.
### *Các điều tâm đắc rút ra được*:
- Hoàn thành một dự án lập trình cỡ trung bình và tự mình thiết kế.
- Học được các kĩ thuật lập trình như: 
  - Lập trình hướng đối tượng cơ bản.
  - Chia file.
  - Sử dụng các cấu trúc dữ liệu cơ bản.
  - Lập trình đồ hoạ.
  - Kĩ năng fixbug
### *Hướng phát triển*:
- Cải thiện đồ hoạ của game, thêm âm thanh.
- Thêm Leaderboard.
- Thêm nhiều chức năng liên quan đến Gameplay như add các khả năng thu nhỏ phóng to Laptop, các Abilities đặc biệt,...
## 6. Tham khảo
- [Lazy Foo' Production](https://lazyfoo.net/tutorials/SDL/)
- [Tutorial: Create 2D Game Engine using C++ and SDL - MadsyCode](https://www.youtube.com/watch?v=1KD4Ae0tX0g&list=PL-K0viiuJ2RctP5nlJlqmHGeh66-GOZR_)
- [How To Make Flappy Bird using SDL](https://www.youtube.com/watch?v=Qxt91Wq_jfo&list=PLICuKRn8LCNT2rPm9QVm7qNcQQ-FEAV8N)
- Các nguồn source code Flappy Bird trên mạng.
- Các file đồ hoạ gốc trên internet
