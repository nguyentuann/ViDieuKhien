#include <Servo.h>

Servo myServo;

// Joystick
#define JOYSTICK_X_PIN A0

// Cảm biến sóng âm
#define TRIG_PIN 11
#define ECHO_PIN 10

// Cảm biến gas
#define GAS A1

// Cảm biến ánh sáng
#define LIGHT 3

// Dò line
#define LINE 2

// Hồng ngoại
#define MOVE 6

void setup() {
  myServo.attach(9);  // gắn servo vào chân D9
  Serial.begin(9600);

  pinMode(JOYSTICK_X_PIN, INPUT);
  pinMode(GAS, INPUT);
  pinMode(LIGHT, INPUT);
  pinMode(LINE, INPUT);
  pinMode(MOVE, INPUT);

  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
}

void loop() {
  int condition = joystick();
  Serial.print("condition: ");
  Serial.println(condition);

  if (condition == 0) {
    quay(0, 90);

  } else if (condition == 1) {
    quay(0, 180);
  } else {
    
  }
}

void quay(int start, int end) {
  Serial.println("Quay tu " + String(start) + " toi " + String(end) + " roi nguoc lai");

  myServo.write(start);
  delay(500);
  myServo.write(end);
  delay(500);
}

int joystick() {
  int xValue = analogRead(JOYSTICK_X_PIN);
  Serial.println(xValue);
  if (xValue < 300) return 0;
  else if (xValue >= 300 && xValue <= 700) return 2;
  else return 1;
}

int khiGas() {
  int value = analogRead(GAS);
  Serial.println(value);
  return value > 400 ? 1 : 0;
}

int doLine() {
  int value = digitalRead(LINE);
  return value == LOW ? 1 : 0;
}

int songAm() {
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);

  long duration = pulseIn(ECHO_PIN, HIGH, 30000);

  if (duration == 0) {
    return 1;
  }

  float distance = duration * 0.034 / 2;
  Serial.println(distance);

  return (distance < 10) ? 0 : 1;
}

int hongNgoai() {
  return digitalRead(MOVE);  // Trả về 1 nếu phát hiện chuyển động
}

int anhSang() {
  return !digitalRead(LIGHT);
}
