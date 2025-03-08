int pin = 0;      // Chân analog để đọc giá trị từ biến trở (A0)
int value = 0;     // Biến lưu giá trị đọc từ biến trở
int interval = 500;  // Khoảng thời gian giữa các lần sáng, mặc định là 500ms
int currentPin = 4;  // Chân LED hiện tại đang sáng
bool forward = true;  // Biến để kiểm tra hướng sáng (trái sang phải hay phải sang trái)

void setup()
{
  for (int pin = 4; pin <= 13; pin++)
  {
    pinMode(pin, OUTPUT);  // Cấu hình các chân từ 4 đến 13 là OUTPUT
  }
}

void loop()
{
  value = analogRead(pin);   // Đọc giá trị từ biến trở
  interval = map(value, 0, 1023, 100, 1000);  // Chuyển đổi giá trị từ 0-1023 sang khoảng 100-1000ms
  
  // Tắt LED hiện tại
  digitalWrite(currentPin, LOW);
  
  // Cập nhật chân LED tiếp theo mà không cần đợi hết thời gian
  if (forward) {
    if (currentPin < 13) {
      currentPin++;  // Tiến tới chân LED tiếp theo
    } else {
      forward = false;  // Đổi hướng sáng khi đến chân 13
      currentPin--;  // Quay lại chân 12
    }
  } else {
    if (currentPin > 4) {
      currentPin--;  // Lùi lại chân LED trước đó
    } else {
      forward = true;  // Đổi hướng sáng khi đến chân 4
      currentPin++;  // Quay lại chân 5
    }
  }
  
  // Sáng LED mới
  digitalWrite(currentPin, HIGH);
  
  delay(interval);  // Đợi một thời gian trước khi tiếp tục sáng LED tiếp theo
}
