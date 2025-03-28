// CAM BIEN GAS
#define ENA 5
#define IN1 6
#define IN2 7
#define gas A0
const int Thuan_speed = 255;
const int Nghich_speed = 255;


void setup() {
  pinMode(ENA, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(gas, INPUT);
  Serial.begin(9600);
}

void loop() {
  long val = analogRead(gas);
  Serial.print(val);
  if (val > 500) {
    Serial.println("Quay nghich");
    // Quay ngược
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, HIGH);
    analogWrite(ENA, Nghich_speed);
  } else {
    // Quay thuận
    Serial.println("Quay thuan");
    digitalWrite(IN1, HIGH);
    digitalWrite(IN2, LOW);
    analogWrite(ENA, Thuan_speed);
  }

  delay(500);
}

// NHIET DO VA DO AM
// #include <DHT.h>
// #define DHTPIN 2  // Chân DATA của DHT11 nối với D2 trên Arduino
// #define DHTTYPE DHT11

// #define ENA 5
// #define IN1 6
// #define IN2 7

// DHT dht(DHTPIN, DHTTYPE);

// const int Thuan_speed = 255;
// const int Nghich_speed = 255;


// void setup() {
//   pinMode(ENA, OUTPUT);
//   pinMode(IN1, OUTPUT);
//   pinMode(IN2, OUTPUT);
 
//   dht.begin();
//   Serial.begin(9600);
// }

// void loop() {
//   float temperature = dht.readTemperature();
//   Serial.print("Nhiệt độ: ");
//   Serial.print(temperature);
//   Serial.println(" °C");

//   if (temperature > 34) {
//     Serial.println("Quay nghich");
//     // Quay ngược
//     digitalWrite(IN1, LOW);
//     digitalWrite(IN2, HIGH);
//     analogWrite(ENA, Nghich_speed);
//   } else {
//     // Quay thuận
//     Serial.println("Quay thuan");
//     digitalWrite(IN1, HIGH);
//     digitalWrite(IN2, LOW);
//     analogWrite(ENA, Thuan_speed);
//   }
//   delay(50);
// }



// JOYSTICK
// #define ENA 5  // Chân PWM điều chỉnh tốc độ
// #define IN1 6
// #define IN2 7
// #define TRIG_PIN 9
// #define ECHO_PIN 10

// #define JOYSTICK_X_PIN A0  // Chân trục X của joystick
// #define JOYSTICK_Y_PIN A1  // Chân trục Y của joystick

// #define Thuan_speed 255
// #define Nghich_speed 255

// void setup() {
//   pinMode(ENA, OUTPUT);
//   pinMode(IN1, OUTPUT);
//   pinMode(IN2, OUTPUT);
//   pinMode(ECHO_PIN, INPUT);
//   pinMode(TRIG_PIN, OUTPUT);
//   pinMode(JOYSTICK_X_PIN, INPUT);
//   pinMode(JOYSTICK_Y_PIN, INPUT);
//   Serial.begin(9600);
// }

// void loop() {
//   int xValue = analogRead(JOYSTICK_X_PIN);  // Đọc giá trị trục X
//   int yValue = analogRead(JOYSTICK_Y_PIN);  // Đọc giá trị trục Y

//   // Điều khiển động cơ theo joystick
//   if (xValue > 600) {
//     // Kéo sang phải -> quay thuận chiều
//     quayThuan();
//   } else if (xValue < 400) {
//     // Kéo sang trái -> quay ngược chiều
//     quayNghich();
//   } else {
//     // Joystick ở vị trí trung tâm -> dừng động cơ
//     dungDongCo();
//   }

//   Serial.print("X: "); Serial.print(xValue);
//   Serial.print(" | Y: "); Serial.print(yValue);
//   Serial.println();


// }

// // Hàm quay thuận chiều
// void quayThuan() {
//   digitalWrite(IN1, HIGH);
//   digitalWrite(IN2, LOW);
//   analogWrite(ENA, Thuan_speed);
// }

// // Hàm quay ngược chiều
// void quayNghich() {
//   digitalWrite(IN1, LOW);
//   digitalWrite(IN2, HIGH);
//   analogWrite(ENA, Nghich_speed);
// }

// // Hàm dừng động cơ
// void dungDongCo() {
//   digitalWrite(IN1, LOW);
//   digitalWrite(IN2, LOW);
//   analogWrite(ENA, 0);
// }

// CAM BIEN ANH SANG
// #define ENA 5
// #define IN1 6
// #define IN2 7
// #define LIGHT A0
// const int Thuan_speed = 255;
// const int Nghich_speed = 255;


// void setup() {
//   pinMode(ENA, OUTPUT);
//   pinMode(IN1, OUTPUT);
//   pinMode(IN2, OUTPUT);
//   pinMode(LIGHT, INPUT);
//   Serial.begin(9600);
// }

// void loop() {
//   long light = analogRead(LIGHT);
//   Serial.print(light);
//   Serial.print("  ");
//   if (light > 500) {
//     Serial.println("Quay nghich");
//     // Quay ngược
//     digitalWrite(IN1, LOW);
//     digitalWrite(IN2, HIGH);
//     analogWrite(ENA, Nghich_speed);
//   } else {
//     // Quay thuận
//     Serial.println("Quay thuan");
//     digitalWrite(IN1, HIGH);
//     digitalWrite(IN2, LOW);
//     analogWrite(ENA, Thuan_speed);
//   }

//   delay(500);
// }



// CAM BIEN KHOANG CACH
// #define ENA 5  // Chân PWM điều chỉnh tốc độ
// #define IN1 6
// #define IN2 7
// #define TRIG_PIN 9
// #define ECHO_PIN 10

// #define Thuan_speed 255
// #define Nghich_speed 20
// #define default_distance 10

// long getDistance() {
//   digitalWrite(TRIG_PIN, LOW);
//   delayMicroseconds(2);
//   digitalWrite(TRIG_PIN, HIGH);
//   delayMicroseconds(10);
//   digitalWrite(TRIG_PIN, LOW);

//   long duration = pulseIn(ECHO_PIN, HIGH, 30000);
//   if(duration == 0) {
//     return 100;
//   }
//   return duration * 0.0343 / 2;

// }

// void setup() {
//   pinMode(ENA, OUTPUT);
//   pinMode(IN1, OUTPUT);
//   pinMode(IN2, OUTPUT);
//   pinMode(ECHO_PIN, INPUT);
//   pinMode(TRIG_PIN, OUTPUT);
//   Serial.begin(9600);
// }

// void loop() {
//   long distance = getDistance();
//   Serial.print(distance);
//   Serial.print("  ");
//   if (distance < default_distance) {
//     Serial.println("Quay nghich");
//     // Quay ngược
//     digitalWrite(IN1, LOW);
//     digitalWrite(IN2, HIGH);
//     analogWrite(ENA, Nghich_speed);
//   } else {
//     // Quay thuận
//     Serial.println("Quay thuan");
//     digitalWrite(IN1, HIGH);
//     digitalWrite(IN2, LOW);
//     analogWrite(ENA, Thuan_speed);
//   }

//   delay(500);
// }


// KHONG CAM BIEN
// #define ENA 5  // Chân PWM điều chỉnh tốc độ
// #define IN1 6
// #define IN2 7

// #define Thuan_speed 255
// #define Nghich_speed 20


// void setup() {
//   pinMode(ENA, OUTPUT);
//   pinMode(IN1, OUTPUT);
//   pinMode(IN2, OUTPUT);
//   Serial.begin(9600);
// }

// void loop() {

//     Serial.println("Quay nghich");
//     // Quay ngược
//     digitalWrite(IN1, LOW);
//     digitalWrite(IN2, HIGH);
//     analogWrite(ENA, Nghich_speed);
//     delay(2000);

//     // Quay thuận
//     Serial.println("Quay thuan");
//     digitalWrite(IN1, HIGH);
//     digitalWrite(IN2, LOW);
//     analogWrite(ENA, Thuan_speed);
//     delay(2000);

// }
