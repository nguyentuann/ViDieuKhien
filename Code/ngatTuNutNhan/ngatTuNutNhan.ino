#define LED 13
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(LED, OUTPUT);
  attachInterrupt(0, displayMicros, RISING);
  attachInterrupt(1, displayMillis, RISING);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(LED, HIGH);
  delay(500);
  digitalWrite(LED, LOW);
  delay(500);
}

void displayMicros() {
  Serial.write("micros()=");
  Serial.println(micros());
}

void displayMillis() {
  Serial.write("millis()=");
  Serial.println(millis());
}
