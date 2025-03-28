int gas = A0;
int buzzer = 13;
int threshold = 400;
float sinValue;
float toneValue;
int LED = 13;

void setup() {
  pinMode(buzzer, OUTPUT);
  pinMode(LED, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  int value = analogRead(gas);
  Serial.println(value);
  // if (value > threshold) {
  //   for (int i = 0; i < 180; i++) {
  //     sinValue = sin(i * (3.1412 / 180));
  //     toneValue = 2000 + sinValue * 500; // chay tu 1500 den 2500
  //     tone(buzzer, toneValue);
  //   }
  // } else {
  //   noTone(buzzer);
  // }

  if(value > threshold) {
    digitalWrite(LED, HIGH);
  } else {
    digitalWrite(LED, LOW);
  }

  delay(100);
}
