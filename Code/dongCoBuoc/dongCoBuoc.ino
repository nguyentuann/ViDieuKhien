
const int motorPin1 = 8;
const int motorPin2 = 9;
const int motorPin3 = 10;
const int motorPin4 = 11;
const int delayTime = 10;

void setup() {
  pinMode(motorPin1, OUTPUT);
  pinMode(motorPin2, OUTPUT);
  pinMode(motorPin3, OUTPUT);
  pinMode(motorPin4, OUTPUT);
}

void step1() {
  digitalWrite(motorPin1, HIGH);
  digitalWrite(motorPin2, LOW);
  digitalWrite(motorPin3, LOW);
  digitalWrite(motorPin4, LOW);
  delay(delayTime);
}

void step2() {
  digitalWrite(motorPin1, HIGH);
  digitalWrite(motorPin2, HIGH);
  digitalWrite(motorPin3, LOW);
  digitalWrite(motorPin4, LOW);
  delay(delayTime);
}

void step3() {
  digitalWrite(motorPin1, LOW);
  digitalWrite(motorPin2, HIGH);
  digitalWrite(motorPin3, LOW);
  digitalWrite(motorPin4, LOW);
  delay(delayTime);
}

void step4() {
  digitalWrite(motorPin1, LOW);
  digitalWrite(motorPin2, HIGH);
  digitalWrite(motorPin3, HIGH);
  digitalWrite(motorPin4, LOW);
  delay(delayTime);
}
void step5() {
  digitalWrite(motorPin1, LOW);
  digitalWrite(motorPin2, LOW);
  digitalWrite(motorPin3, HIGH);
  digitalWrite(motorPin4, LOW);
  delay(delayTime);
}

void step6() {
  digitalWrite(motorPin1, LOW);
  digitalWrite(motorPin2, LOW);
  digitalWrite(motorPin3, HIGH);
  digitalWrite(motorPin4, HIGH);
  delay(delayTime);
}

void step7() {
  digitalWrite(motorPin1, LOW);
  digitalWrite(motorPin2, LOW);
  digitalWrite(motorPin3, LOW);
  digitalWrite(motorPin4, HIGH);
  delay(delayTime);
}

void step8() {
  digitalWrite(motorPin1, HIGH);
  digitalWrite(motorPin2, LOW);
  digitalWrite(motorPin3, LOW);
  digitalWrite(motorPin4, HIGH);
  delay(delayTime);
}


/////////////////////////


void step11() {
  digitalWrite(motorPin1, HIGH);
  digitalWrite(motorPin2, HIGH);
  digitalWrite(motorPin3, LOW);
  digitalWrite(motorPin4, LOW);
  delay(delayTime);
}

void step22() {
  digitalWrite(motorPin1, LOW);
  digitalWrite(motorPin2, HIGH);
  digitalWrite(motorPin3, HIGH);
  digitalWrite(motorPin4, LOW);
  delay(delayTime);
}

void step33() {
  digitalWrite(motorPin1, LOW);
  digitalWrite(motorPin2, LOW);
  digitalWrite(motorPin3, HIGH);
  digitalWrite(motorPin4, HIGH);
  delay(delayTime);
}

void step44() {
  digitalWrite(motorPin1, HIGH);
  digitalWrite(motorPin2, LOW);
  digitalWrite(motorPin3, LOW);
  digitalWrite(motorPin4, HIGH);
  delay(delayTime);
}


void direction1() {
  step1();
  step2();
  step3();
  step4();
  step5();
  step6();
  step7();
  step8();
}

void direction2() {
  step44();
  step33();
  step22();
  step11();
}

void loop() {
  for (int i = 0; i < 512; i++) {  // 512 chu kì = 1 vòng, 1 chu kì = 4 bước, bước là 1 lần thay đổi trạng thái, code này mỗi lần chỉ quay nửa bước
    direction1();
  }
  delay(2000);
  for (int i = 0; i < 512; i++) {  // 512 chu kì = 1 vòng, 1 chu kì = 4 bước, bước là 1 lần thay đổi trạng thái, code này mỗi lần  quay 1 bước
    direction2();
  }
  delay(2000);
}






// #include <Stepper.h>

// #define STEPS 2048 // số bước trong một vòng quay


// // Stepper stepper(STEPS, in1, in3, in2, in4);
// Stepper stepper(STEPS, 8, 10, 9, 11);

// void setup() {
//   // không cần làm gì cả, thư viện Stepper sẽ lo setup động cơ cho ta
// }

// // thứ tự BC CD DA AB

// void loop() {
//   stepper.setSpeed(10); // 3 rpm
//   stepper.step(STEPS); // quay một vòng cùng chiều đồng hồ
//   delay(1000);

//   stepper.setSpeed(15); // 6 rpm
//   stepper.step(-STEPS); // quay một vòng ngược chiều đồng hồ
//   delay(1000);
// }



// Full-step (Two-phase-ON)
// bước	 IN1 	IN2	    IN3	  IN4	  Góc quay
// 1	    1	   0/1	  1/0	    0	     0°
// 2	    0	   1	    1	      0	     90°
// 3	    0	   1/0	  0/1	    1	     180°
// 4	    1	   0	    0	      1	     270°


// Half-step (One-phase-ON & Two-phase-ON)
// Bước	IN1	  IN2	  IN3	  IN4	  Góc quay
// 1	     1	   0	   0	   0	    0°
// 2	     1	   1	   0	   0	    45°
// 3	     0	   1	   0	   0	    90°
// 4	     0	   1	   1	   0	    135°
// 5	     0	   0	   1	   0	    180°
// 6	     0	   0	   1	   1	    225°
// 7	     0	   0	   0	   1	    270°
// 8	     1	   0	   0	   1	    315°
