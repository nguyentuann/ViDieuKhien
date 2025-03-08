const int infraredPin = 6;
const int LED = 13;
int ALARM = 4;
float sinVal;
float toneVal; 

void setup() {
  // put your setup code here, to run once:
  pinMode(LED, OUTPUT);
  pinMode(infraredPin, INPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  if (digitalRead(infraredPin) == HIGH) {
    digitalWrite(LED, HIGH);
    Serial.println("Co di chuyen");
  } else {
    digitalWrite(LED, LOW);
    Serial.println("Khong co gi");
  }


  // if (digitalRead(infraredPin) == HIGH) {
  //   for (int x = 0; x < 180; x++) {
  //     // Chuyển đổi sin function sang radian
  //     sinVal = sin(x * (3.1412 / 180));
  //     // Dùng sin function để tạo tần số âm thanh
  //     toneVal = 2000 + (int)(sinVal * 1000);
  //     // Phát tín hiệu từ buzzer
  //     tone(ALARM, toneVal);
  //     delay(2);
  //   }
  // } else {
  //   noTone(ALARM);
  // }
  // delay(100);
}

// cách hoạt động
// Khi có vật thể phát nhiệt (người, động vật) di chuyển vào vùng quét,
// cảm biến so sánh sự thay đổi tia hồng ngoại và xuất tín hiệu HIGH (1).
// Khi không có chuyển động, cảm biến xuất tín hiệu LOW (0).
