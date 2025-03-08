int LED = 13; // biến led lưu chân số 13
int LIGHT =  0; // biến light lưu chân số 0
int val = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(LED, OUTPUT); // cài đặt chân 13 là output
  Serial.begin(9600); // khởi động giao tiếp serial với tốc độ 9600
}

void loop() {
  // put your main code here, to run repeatedly:
  val = analogRead(LIGHT); // đọc giá trị từ chân A0
  Serial.println(val);
  if(val < 700) {
    digitalWrite(LED, LOW);
  } else {
    digitalWrite(LED, HIGH);
  }
  delay(10);
}

// VCC: chân cấp nguồn
// GNG: chân nối đất
// DO: chân xuất tín hiệu

// số 31

