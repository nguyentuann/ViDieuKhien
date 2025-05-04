#include <IRremote.h>

const int IR_SEND_PIN = 3;
const int IR_RECV_PIN = 2;
const int LED_PIN = 13;

const unsigned long CODE_ON = 0xA90;
const unsigned long CODE_OFF = 0x690;

unsigned long lastSendTime = 0;
bool sendOn = true;

void setup() {
  Serial.begin(9600);

  // Khởi động IR gửi và nhận
  IrSender.begin(IR_SEND_PIN);
  IrReceiver.begin(IR_RECV_PIN, ENABLE_LED_FEEDBACK);

  pinMode(LED_PIN, OUTPUT);
  digitalWrite(LED_PIN, LOW);
}

void loop() {
  // ----- GỬI MÃ mỗi 1 giây -----
  if (millis() - lastSendTime >= 1000) {
    if (sendOn) {
      IrSender.sendNEC(CODE_ON, 32);
      Serial.println("Sent CODE_ON");
    } else {
      IrSender.sendNEC(CODE_OFF, 32);
      Serial.println("Sent CODE_OFF");
    }
    sendOn = !sendOn;
    lastSendTime = millis();
  }

  // ----- NHẬN MÃ và xử lý -----
    unsigned long code = IrReceiver.decodedIRData.decodedRawData;
    Serial.print("Received code: ");
    Serial.println(code, HEX);

    if (code == CODE_ON) {
      digitalWrite(LED_PIN, HIGH);
      Serial.println("LED ON");
    } else if (code == CODE_OFF) {
      digitalWrite(LED_PIN, LOW);
      Serial.println("LED OFF");
    }

    IrReceiver.resume();
}
