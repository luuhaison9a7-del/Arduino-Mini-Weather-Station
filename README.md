# Arduino-Mini-Weather-Station
Hệ thống giám sát môi trường dựa trên Arduino với giao tiếp I2C

# Mini Weather Station

## Overview
Dự án này sử dụng vi điều khiển Arduino để đo lường và hiển thị nhiệt độ, độ ẩm của môi trường theo thời gian thực. Hệ thống được thiết kế tối ưu với màn hình I2C giúp tiết kiệm chân cắm và thuật toán lọc lỗi cảm biến để đảm bảo dữ liệu hiển thị luôn chính xác.

## Hardware Stack
* Arduino Uno R3
* LCD 16x2 (I2C)
* Module DHT11
* Breadboard 
* Jumper wires

## Key Technical Features
* Thu thập dữ liệu thời gian thực: Đọc và cập nhật liên tục thông số nhiệt độ, độ ẩm của môi trường mỗi 2 giây, đảm bảo tính tức thời của hệ thống giám sát.
* Tích hợp chuẩn giao tiếp I2C: Tối ưu hóa tài nguyên phần cứng bằng cách sử dụng module I2C cho màn hình LCD. Giúp tiết kiệm tối đa các chân GPIO của vi điều khiển (chỉ sử dụng 2 chân tín hiệu SDA/SCL thay vì 6 chân như cách cắm dây song song truyền thống).
* Khả năng chịu lỗi & Xử lý ngoại lệ: Tích hợp thuật toán lọc nhiễu và xử lý lỗi (thông qua hàm `isnan()`). Hệ thống có khả năng tự động kiểm tra Checksum, phát hiện ngay lập tức các sự cố mất kết nối, lỏng cáp hoặc hỏng linh kiện để hiển thị cảnh báo an toàn thay vì xuất ra các dữ liệu rác.

## Wiring & Setup
<img width="2048" height="1536" alt="Mini Weather Station" src="https://github.com/user-attachments/assets/4cc8cbd3-e53d-426d-8569-4c3cbc0d40c0" />
<img width="1353" height="505" alt="Mini Weather Station Tindercad" src="https://github.com/user-attachments/assets/382e0250-00e2-48c4-ae6e-955db904b55b" />
<p align="center">Hình ảnh Tindercad mang tính chất minh họa một số linh kiện có thể khác so với mô hình thực tế</p>

<p align="center">*Dự án thực hành Cơ điện tử nền tảng - Đại học Sư phạm Kỹ thuật TP.HCM (HCMUTE) (14/04/2026).* 
</p>


