// #define LINE A0  // Chọn chân analog, ví dụ A0
// int val = 0;
// int LED = 13;
// int threshold = 512;  // Ngưỡng để xác định HIGH hoặc LOW

// void setup() {
//     pinMode(LED, OUTPUT);
//     Serial.begin(9600); // Khởi động Serial Monitor với baud rate 9600
// }

// void loop() {
//     val = analogRead(LINE); // Đọc tín hiệu analog từ cảm biến
    
//     Serial.print("Giá trị Analog LINE: ");
//     Serial.println(val); // In giá trị đọc được từ LINE

//     if (val > threshold) { // Nếu tín hiệu lớn hơn ngưỡng, bật LED
//         digitalWrite(LED, HIGH);
//         Serial.println("LED: ON");
//     } else { // Nếu tín hiệu nhỏ hơn ngưỡng, tắt LED
//         digitalWrite(LED, LOW);
//         Serial.println("LED: OFF");
//     }
    
//     delay(500); // Thêm delay để tránh in quá nhanh
// }

#define LINE A0
int val = 0;
int LED = 13;
int limit = 512;

void setup() {
  pinMode(LED, OUTPUT); // thiết lập LED là đầu ra
  Serial.begin(9600);
}

void loop() {
  val = analogRead(LINE);

  Serial.print("Gia tri analog: ");
  Serial.println(val);

  if(val > limit) {
    digitalWrite(LED, HIGH);
    Serial.println("ON");
  } else {
    digitalWrite(LED, LOW);
    Serial.println("OFF");
  }
  delay(500);
}
