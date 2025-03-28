
// bài ni học 

int ALARM = 4; // Chân buzzer
int LM35 = A0; // Cảm biến nhiệt độ LM35 kết nối với chân A0
float tmprVal = 0; // Giá trị nhiệt độ
float sinVal;
int toneVal;
unsigned long tepTimer;


void setup() {
    Serial.begin(9600); // Cấu hình baud rate 9600 bps
    pinMode(ALARM, OUTPUT); // Cấu hình chân buzzer là OUTPUT
}

void loop() {
    int val = analogRead(LM35); // Đọc giá trị từ cảm biến LM35
    tmprVal = (float) val * (5.0 / 10.24); // Chuyển đổi giá trị điện áp thành nhiệt độ

    if (tmprVal > 30) { // Nếu nhiệt độ > 27°C, bật buzzer
        for (int x = 0; x < 180; x++) {
            // Chuyển đổi sin function sang radian
            sinVal = sin(x * (3.1412 / 180));
            // Dùng sin function để tạo tần số âm thanh
            toneVal = 2000 + (int)(sinVal * 1000);
            // Phát tín hiệu từ buzzer
            tone(ALARM, toneVal);
            delay(2);
        }
    } else { 
        noTone(ALARM); // Nếu nhiệt độ ≤ 27°C, tắt buzzer
    }

    // Cứ mỗi 50ms, gửi giá trị nhiệt độ ra Serial Monitor
    if (millis() - tepTimer > 50) {
        tepTimer = millis();
        Serial.print("Temperature: ");
        Serial.print(tmprVal);
        Serial.println(" °C");
    }
}



// int ALARM = 4; // Chân buzzer (hoặc loa nhỏ)
// int LM35 = A0; // Cảm biến nhiệt độ LM35 kết nối với chân A0
// float tmprVal = 0; // Giá trị nhiệt độ
// unsigned long tepTimer;

// // Bảng giá trị sin để tạo sóng PWM
// const int sinTable[100] = {
//   127, 135, 143, 151, 159, 167, 175, 182, 190, 197, 203, 210, 216, 221, 226, 231, 235, 239, 242, 245,
//   247, 249, 250, 251, 251, 251, 250, 249, 247, 245, 242, 239, 235, 231, 226, 221, 216, 210, 203, 197,
//   190, 182, 175, 167, 159, 151, 143, 135, 127, 119, 111, 103, 95, 87, 79, 72, 64, 57, 50, 44, 37, 32,
//   27, 22, 18, 14, 11, 8, 6, 4, 3, 2, 2, 2, 3, 4, 6, 8, 11, 14, 18, 22, 27, 32, 37, 44, 50, 57,
//   64, 72, 79, 87, 95, 103, 111, 119
// };

// void setup() {
//     Serial.begin(9600); // Cấu hình baud rate 9600 bps
//     pinMode(ALARM, OUTPUT); // Cấu hình chân buzzer là OUTPUT
// }

// void loop() {
//     int val = analogRead(LM35); // Đọc giá trị từ cảm biến LM35
//     tmprVal = (float) val * (5.0 / 10.24); // Chuyển đổi giá trị điện áp thành nhiệt độ

//     if (tmprVal > 29) { // Nếu nhiệt độ > 27°C, phát âm thanh sóng sin
//         for (int i = 0; i < 100; i++) {
//             analogWrite(ALARM, sinTable[i]); // Xuất PWM theo giá trị sin
//             delayMicroseconds(100); // Điều chỉnh tần số âm thanh (có thể thay đổi)
//         }
//     } else { 
//         analogWrite(ALARM, 0); // Nếu nhiệt độ ≤ 27°C, tắt âm thanh
//     }

//     // Cứ mỗi 50ms, gửi giá trị nhiệt độ ra Serial Monitor
//     if (millis() - tepTimer > 50) {
//         tepTimer = millis();
//         Serial.print("Temperature: ");
//         Serial.print(tmprVal);
//         Serial.println(" °C");
//     }
// }

