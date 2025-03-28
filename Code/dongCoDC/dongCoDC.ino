#define TRIG_PIN 9
#define ECHO_PIN 10
#define BUTTON_PIN 2
#define ENA_PIN 5
#define IN1_PIN 6
#define IN2_PIN 7

// Code này điều khiển động cơ bằng kênh A 

const int min_distance = 10;
const int max_distance = 50;
const int min_speed = 30;
const int max_speed = 255;
int direction = 1;
bool lastButtonState = LOW;
void setup() {
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  pinMode(BUTTON_PIN, INPUT);
  pinMode(ENA_PIN, OUTPUT);
  pinMode(IN1_PIN, OUTPUT);
  pinMode(IN2_PIN, OUTPUT);
  Serial.begin(9600);
}

long getDistance() {
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);

  long duration = pulseIn(ECHO_PIN, HIGH, 50000);
  if (duration == 0) {
    return max_distance;
  } else {
    return duration * 0.0343 / 2;
  }
}

void setMotorSpeed(int speed, int dir) {
  if (dir == 1) {
    digitalWrite(IN1_PIN, HIGH); // Q1 và Q4 bật -> thuận
    digitalWrite(IN2_PIN, LOW);
  } else {
    digitalWrite(IN1_PIN, LOW);
    digitalWrite(IN2_PIN, HIGH); // Q2 và Q3 bật -> nghịch
  }

  if (speed == max_speed) {
    digitalWrite(ENA_PIN, HIGH); // đặt ENA_PIN = 1 (5V) <=> PWM = 100%
  } else {
    analogWrite(ENA_PIN, speed);
  }
}

void loop() {
  bool button_state = digitalRead(BUTTON_PIN);
  if (button_state && !lastButtonState) {
    direction = -direction;
    delay(200);
  }
  lastButtonState = button_state;
  long distance = getDistance();
  int speed;
  if (distance <= min_distance) {
    speed = max_speed;
  } else {
    speed = map(distance, min_distance, max_distance, max_speed, min_speed); 
    speed = constrain(speed, min_speed, max_speed); // nhốt speed trong khoảng giới hạn
  }

  setMotorSpeed(speed, direction);

  Serial.print("Khoang cach: ");
  Serial.print(distance);
  Serial.print(" cm | Toc do: ");
  Serial.print(speed);
  Serial.print(" | Chieu quay: ");
  Serial.println(direction == 1 ? "Thuan" : "Nguoc");
  delay(100);
}
