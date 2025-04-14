// Định nghĩa chân cảm biến
#define GAS_SENSOR A0
#define TRIG_PIN 2
#define ECHO_PIN 3

#define MAX_STEPS 2048

const int stepper_pins[4] = { 8, 9, 10, 11 };  // Mảng chứa chân điều khiển động cơ
int step_number = 0;
bool direction = true;
float degree = 90;
int steps = (int)(MAX_STEPS * degree / 360);

// Ma trận trạng thái của các bước sử dụng HIGH và LOW
const int step_sequence[4][4] = {
    {HIGH, LOW,  LOW, LOW},  
    {LOW,  HIGH, LOW, LOW},  
    {LOW,  LOW, HIGH,  LOW},  
    {LOW, LOW,  LOW,  HIGH}   
};

void setup() {
  for (int i = 0; i < 4; i++) pinMode(stepper_pins[i], OUTPUT);
  // pinMode(LIGHT_SENSOR, INPUT);
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  Serial.begin(9600);
}

void oneStepWaveDrive(bool dir) {
  step_number = (step_number + (dir ? 1 : -1) + 4) % 4;
  for (int i = 0; i < 4; i++) digitalWrite(stepper_pins[i], step_sequence[step_number][i]);
}

void loop() {
  direction = checkDistanceSensor();
  for (int i = 0; i < steps; i++) {
    oneStepWaveDrive(direction);
    delay(5);  // Điều chỉnh tốc độ bước
  }

  delay(300);  // Dừng lại một chút trước khi chạy lại
}


// // Đọc cảm biến khí gas
// void checkGasSensor() {
//     int val = analogRead(GAS_SENSOR);
//     Serial.print("Gas: "); Serial.println(val);
//     if (val > 500) quayNghich();
//     else quayThuan();
// }

// // Đọc cảm biến nhiệt độ & độ ẩm
// void checkDHTSensor() {
//     float temperature = dht.readTemperature();
//     Serial.print("Nhiệt độ: "); Serial.print(temperature); Serial.println(" °C");
//     if (temperature > 34) quayNghich();
//     else quayThuan();
// }

// // Đọc cảm biến ánh sáng
// void checkLightSensor() {
//     int light = analogRead(LIGHT_SENSOR);
//     Serial.print("Ánh sáng: "); Serial.println(light);
//     if (light > 500) quayNghich();
//     else quayThuan();
// }

// Đọc cảm biến khoảng cách
long getDistance() {
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);
  long duration = pulseIn(ECHO_PIN, HIGH, 30000);
  if (duration == 0) return 100;
  return duration * 0.0343 / 2;
}

bool checkDistanceSensor() {
  long distance = getDistance();
  Serial.print("Khoảng cách: ");
  Serial.println(distance);
  if (distance < 20) {
    return true;
  } else {
    return false;
  }
}

// // Đọc cảm biến joystick
// void checkJoystick() {
//     int xValue = analogRead(JOYSTICK_X_PIN);
//     int yValue = analogRead(JOYSTICK_Y_PIN);
//     Serial.print("X: "); Serial.print(xValue);
//     Serial.print(" | Y: "); Serial.println(yValue);

//     if (xValue > 600) quayThuan();
//     else if (xValue < 400) quayNghich();
//     else dungDongCo();
// }

// void checkLineSensor() {
//     int leftValue = analogRead(LINE_SENSOR_LEFT);
//     int rightValue = analogRead(LINE_SENSOR_RIGHT);
//     Serial.print("Line Left: "); Serial.print(leftValue);
//     Serial.print(" | Line Right: "); Serial.println(rightValue);

//     if (leftValue < 500 && rightValue < 500) quayThuan(); // Cả hai trên đường
//     else if (leftValue > 500 && rightValue < 500) { // Lệch trái
//         digitalWrite(IN1, LOW);
//         digitalWrite(IN2, HIGH);
//         analogWrite(ENA, Thuan_speed / 2);
//     }
//     else if (leftValue < 500 && rightValue > 500) { // Lệch phải
//         digitalWrite(IN1, HIGH);
//         digitalWrite(IN2, LOW);
//         analogWrite(ENA, Thuan_speed / 2);
//     }
//     else dungDongCo(); // Không có đường
// }












#define MAX_STEPS 2048
#define DELAY_STEPS_MIN 1  // Thời gian delay nhỏ nhất (tốc độ nhanh nhất)
#define DELAY_STEPS_MAX 10 // Thời gian delay lớn nhất (tốc độ chậm nhất)

// Mảng chứa các chân điều khiển động cơ
const int stepper_pins[4] = {8, 9, 10, 11};

// Ma trận trạng thái của các bước sử dụng HIGH và LOW
const int step_sequence[4][4] = {
  {HIGH, LOW, LOW, LOW},
  {LOW, HIGH, LOW, LOW},
  {LOW, LOW, HIGH, LOW},
  {LOW, LOW, LOW, HIGH}
};

// Cấu hình chân joystick
const int joystick_x_pin = A0; // Chân analog cho trục X của joystick

int step_number = 0;
bool direction = true;
int delay_steps = DELAY_STEPS_MAX; // Thời gian delay ban đầu

void setup() {
  // Cấu hình các chân điều khiển động cơ
  for (int i = 0; i < 4; i++) {
    pinMode(stepper_pins[i], OUTPUT);
  }
  
  // Khởi tạo giao tiếp Serial
  Serial.begin(9600);
  delay(500);
}

void oneStepWaveDrive(bool dir) {
  step_number = (step_number + (dir ? 1 : -1) + 4) % 4;
  for (int i = 0; i < 4; i++) {
    digitalWrite(stepper_pins[i], step_sequence[step_number][i]);
  }
}

void loop() {
  // Đọc giá trị trục X của joystick
  int joystick_x = analogRead(joystick_x_pin);
  
  // In giá trị joystick ra Serial Monitor để debug
  Serial.print("Joystick X: ");
  Serial.print(joystick_x);
  
  // Xác định hướng quay và tốc độ dựa trên giá trị joystick
  if (joystick_x < 512) {
    // Quay ngược
    direction = false;
    // Tính thời gian delay dựa trên giá trị joystick
    // Joystick càng xa trung tâm (512), tốc độ càng nhanh (delay nhỏ hơn)
    delay_steps = map(joystick_x, 0, 512, DELAY_STEPS_MIN, DELAY_STEPS_MAX);
    Serial.print(" | Hướng: Ngược | Delay: ");
    Serial.println(delay_steps);
    
    // Thực hiện một bước quay
    oneStepWaveDrive(direction);
    delay(delay_steps);
  }
  else if (joystick_x > 512) {
    // Quay thuận
    direction = true;
    delay_steps = map(joystick_x, 512, 1023, DELAY_STEPS_MAX, DELAY_STEPS_MIN);
    Serial.print(" | Hướng: Thuận | Delay: ");
    Serial.println(delay_steps);
    
    // Thực hiện một bước quay
    oneStepWaveDrive(direction);
    delay(delay_steps);
  }
  else {
    // Joystick ở vị trí trung tâm, không quay
    Serial.println(" | Động cơ dừng");
    delay(100); // Delay nhỏ để tránh đọc joystick quá nhanh
  }
}

























// const int motorPin1 = 8;
// const int motorPin2 = 9;
// const int motorPin3 = 10;
// const int motorPin4 = 11;
// const int delayTime = 10;

// void setup() {
//   pinMode(motorPin1, OUTPUT);
//   pinMode(motorPin2, OUTPUT);
//   pinMode(motorPin3, OUTPUT);
//   pinMode(motorPin4, OUTPUT);
// }

// void step1() {
//   digitalWrite(motorPin1, HIGH);
//   digitalWrite(motorPin2, LOW);
//   digitalWrite(motorPin3, LOW);
//   digitalWrite(motorPin4, LOW);
//   delay(delayTime);
// }

// void step2() {
//   digitalWrite(motorPin1, HIGH);
//   digitalWrite(motorPin2, HIGH);
//   digitalWrite(motorPin3, LOW);
//   digitalWrite(motorPin4, LOW);
//   delay(delayTime);
// }

// void step3() {
//   digitalWrite(motorPin1, LOW);
//   digitalWrite(motorPin2, HIGH);
//   digitalWrite(motorPin3, LOW);
//   digitalWrite(motorPin4, LOW);
//   delay(delayTime);
// }

// void step4() {
//   digitalWrite(motorPin1, LOW);
//   digitalWrite(motorPin2, HIGH);
//   digitalWrite(motorPin3, HIGH);
//   digitalWrite(motorPin4, LOW);
//   delay(delayTime);
// }
// void step5() {
//   digitalWrite(motorPin1, LOW);
//   digitalWrite(motorPin2, LOW);
//   digitalWrite(motorPin3, HIGH);
//   digitalWrite(motorPin4, LOW);
//   delay(delayTime);
// }

// void step6() {
//   digitalWrite(motorPin1, LOW);
//   digitalWrite(motorPin2, LOW);
//   digitalWrite(motorPin3, HIGH);
//   digitalWrite(motorPin4, HIGH);
//   delay(delayTime);
// }

// void step7() {
//   digitalWrite(motorPin1, LOW);
//   digitalWrite(motorPin2, LOW);
//   digitalWrite(motorPin3, LOW);
//   digitalWrite(motorPin4, HIGH);
//   delay(delayTime);
// }

// void step8() {
//   digitalWrite(motorPin1, HIGH);
//   digitalWrite(motorPin2, LOW);
//   digitalWrite(motorPin3, LOW);
//   digitalWrite(motorPin4, HIGH);
//   delay(delayTime);
// }


// /////////////////////////


// void step11() {
//   digitalWrite(motorPin1, HIGH);
//   digitalWrite(motorPin2, HIGH);
//   digitalWrite(motorPin3, LOW);
//   digitalWrite(motorPin4, LOW);
//   delay(delayTime);
// }

// void step22() {
//   digitalWrite(motorPin1, LOW);
//   digitalWrite(motorPin2, HIGH);
//   digitalWrite(motorPin3, HIGH);
//   digitalWrite(motorPin4, LOW);
//   delay(delayTime);
// }

// void step33() {
//   digitalWrite(motorPin1, LOW);
//   digitalWrite(motorPin2, LOW);
//   digitalWrite(motorPin3, HIGH);
//   digitalWrite(motorPin4, HIGH);
//   delay(delayTime);
// }

// void step44() {
//   digitalWrite(motorPin1, HIGH);
//   digitalWrite(motorPin2, LOW);
//   digitalWrite(motorPin3, LOW);
//   digitalWrite(motorPin4, HIGH);
//   delay(delayTime);
// }


// void direction1() {
//   step1();
//   step2();
//   step3();
//   step4();
//   step5();
//   step6();
//   step7();
//   step8();
// }

// void direction2() {
//   step44();
//   step33();
//   step22();
//   step11();
// }

// void loop() {
//   for (int i = 0; i < 512; i++) {  // 512 chu kì = 1 vòng, 1 chu kì = 4 bước, bước là 1 lần thay đổi trạng thái, code này mỗi lần chỉ quay nửa bước
//     direction1();
//   }
//   delay(2000);
//   for (int i = 0; i < 512; i++) {  // 512 chu kì = 1 vòng, 1 chu kì = 4 bước, bước là 1 lần thay đổi trạng thái, code này mỗi lần  quay 1 bước
//     direction2();
//   }
//   delay(2000);
// }






// #include <Stepper.h>

// #define STEPS 2048 // số bước trong một vòng quay

// // Stepper stepper(STEPS, in1, in3, in2, in4);
// Stepper stepper(STEPS, 8, 10, 9, 11);

// void setup() {
//   // không cần làm gì cả, thư viện Stepper sẽ lo setup động cơ cho ta
// }

// // thứ tự BC CD DA AB

// void loop() {
//   stepper.setSpeed(15); // 3 rpm
//   stepper.step(STEPS); // quay một vòng cùng chiều đồng hồ
//   delay(1000);

//   stepper.setSpeed(15); // 6 rpm
//   stepper.step(-STEPS); // quay một vòng ngược chiều đồng hồ
//   delay(1000);
// }


// ------------------------------------------

// Full-step (Two-phase-ON)
// bước	 IN1 	IN2	    IN3	  IN4	  Góc quay
// 1	    1	   0/1	  1/0	    0	     0°
// 2	    0	   1	    1	      0	     90°
// 3	    0	   1/0	  0/1	    1	     180°
// 4	    1	   0	    0	      1	     270°


// Half-step (One-phase-ON & Two-phase-ON)
// Bước	  IN1	  IN2	  IN3	  IN4	  Góc quay
// 1	     1	   0	   0	   0	    0°
// 2	     1	   1	   0	   0	    45°
// 3	     0	   1	   0	   0	    90°
// 4	     0	   1	   1	   0	    135°
// 5	     0	   0	   1	   0	    180°
// 6	     0	   0	   1	   1	    225°
// 7	     0	   0	   0	   1	    270°
// 8	     1	   0	   0	   1	    315°
