int ledpin = 13;
void setup() {
  Serial.begin(9600);
  pinMode(ledpin, OUTPUT);
}

void loop() {
  if (Serial.available() > 0) {
    String command = Serial.readStringUntil('\n'); // Đọc cả chuỗi đến khi xuống dòng
    command.toUpperCase();
    if (command == "ON") {
      digitalWrite(ledpin, HIGH);
      Serial.println("LED ON");
    } 
    else if (command == "OFF") {
      digitalWrite(ledpin, LOW);
      Serial.println("LED OFF");
    }
  }
}
