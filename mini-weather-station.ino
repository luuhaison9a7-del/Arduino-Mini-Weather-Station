#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <DHT.h>

// 1. Cấu hình LCD I2C (Số nhà thường là 0x27, loại 16 cột, 2 dòng)
LiquidCrystal_I2C lcd(0x27, 16, 2);

// 2. Cấu hình DHT11
#define DHTPIN 2        // Cắm dây DATA của DHT11 vào chân số 2
#define DHTTYPE DHT11   // Khai báo loại cảm biến là DHT11
DHT dht(DHTPIN, DHTTYPE); // Khởi tạo "người đại diện" cho DHT11

void setup() {
  // Khởi động màn hình LCD
  lcd.init();
  lcd.backlight();
  
  // Khởi động cảm biến DHT
  dht.begin();
  
  // Màn hình chào mừng
  lcd.setCursor(0, 0);
  lcd.print("Trang thai: OK");
  delay(2000);
  lcd.clear();
}

void loop() {
  // BƯỚC 1: Đọc dữ liệu từ DHT11 (Thư viện tự làm toán, mình chỉ việc xài)
  float do_am = dht.readHumidity();
  float nhiet_do = dht.readTemperature();

  // BƯỚC 2: Kiểm tra Checksum (Nếu đọc trượt thì báo lỗi, không in bậy)
  if (isnan(do_am) || isnan(nhiet_do)) {
    lcd.setCursor(0, 0);
    lcd.print("Loi cam bien!   ");
    return; // Dừng tại đây, quay lại đầu loop thử đọc lại
  }

  // BƯỚC 3: In lên màn hình LCD
  // Dòng 1: In Nhiệt độ
  lcd.setCursor(0, 0);
  lcd.print("Nhiet do: ");
  lcd.print(nhiet_do, 1); // Lấy 1 chữ số thập phân
  lcd.write(0xDF);        // In ký tự độ (°) bằng mã Hexa
  lcd.print("C");

  // Dòng 2: In Độ ẩm
  lcd.setCursor(0, 1);
  lcd.print("Do am:    ");
  lcd.print(do_am, 1);
  lcd.print("%  ");

  // DHT11 là cảm biến chậm, bắt buộc phải nghỉ ngơi 2 giây giữa các lần đọc
  delay(2000); 
}