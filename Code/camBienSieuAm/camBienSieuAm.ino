const int trigPin = 5;
const int echoPin = 3;
const int LED = 13;

long duration;
int distance;

void setup() {
  // Cấu hình chân trigPin là OUTPUT, echoPin là INPUT
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  // Khởi tạo Serial Monitor với baudrate 9600
  Serial.begin(9600);
  pinMode(LED, OUTPUT);
}

void loop() {
  // Phát xung để kích hoạt cảm biến
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);

  // Giữ trigPin ở mức HIGH trong 10 µs (10 micro giây).
  // Theo datasheet của HC-SR04, để cảm biến hoạt động đúng, cần phát xung cao (HIGH) ít nhất 10 µs.
  // Giải thích về xung siêu âm
  // Khi trigPin được giữ mức HIGH trong 10 µs, cảm biến sẽ phát 8 xung siêu âm liên tiếp với tần số 40 kHz.
  // Những xung này sẽ đi ra ngoài và gặp vật cản, sau đó phản hồi về cảm biến.

  digitalWrite(trigPin, LOW);

  // Đo thời gian phản hồi của xung
  duration = pulseIn(echoPin, HIGH);

  // Tính khoảng cách theo công thức: distance = (duration * tốc độ âm thanh) / 2
  distance = duration * 0.034 / 2;
  if (distance < 10) {
    digitalWrite(LED, HIGH);
  } else if (distance >= 10 && distance <= 20) {
    digitalWrite(LED, HIGH);
    delay(200);  
    digitalWrite(LED, LOW);
    delay(200); 
  } else {
    digitalWrite(LED, LOW);
  }

  // In kết quả ra Serial Monitor
  Serial.print("Distance Measured = ");
  Serial.print(distance);
  Serial.println(" cm");

  delay(500);  // Chờ 500ms trước khi đo tiếp
}
