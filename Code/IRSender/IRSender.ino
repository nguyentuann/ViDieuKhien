#include <IRremote.h>

const int IR_SEND_PIN = 3;

const unsigned long CODE_ON = 0xA90;  // Mã bật (tùy bạn)
const unsigned long CODE_OFF = 0x690; // Mã tắt (tùy bạn)


void setup() {
  IrSender.begin(IR_SEND_PIN);
  Serial.begin(9600);
}

void loop() {
  // Gửi mã bật
  Serial.println("Sending ON code");
  IrSender.sendNEC(CODE_ON, 32);
  delay(1000);

  // Gửi mã tắt
  Serial.println("Sending OFF code");
  IrSender.sendNEC(CODE_OFF, 32);
  delay(1000);
}


// light đi với động cơ dc
// khoảng cách đi với động cơ bước
// 