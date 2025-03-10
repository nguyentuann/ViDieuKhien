int gas = A0;
int buzzer = 8;
int threshold = 100;
float sinValue;
float toneValue;

void setup() {
  pinMode(buzzer, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  int value = analogRead(gas);
  if (value > threshold) {
    for (int i = 0; i < 180; i++) {
      sinValue = sin(i * (3.1412 / 180));
      toneValue = 2000 + sinValue * 500; // chay tu 1500 den 2500
      tone(buzzer, toneValue);
      delay(50);
    }
  } else {
    noTone(buzzer);
  }

  delay(100);
}
