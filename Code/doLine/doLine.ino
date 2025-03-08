// #define LINE 2
// int val = 0;
// int LED = 13;

// void setup() {
//     pinMode(LED, OUTPUT);
//     pinMode(LINE, INPUT);
// }

// void loop() {
//     val = digitalRead(LINE);
    
//     if (val == 1) {
//         digitalWrite(LED, HIGH); // Bật LED nếu LINE có tín hiệu HIGH
//     } else {
//         digitalWrite(LED, LOW);  // Tắt LED nếu LINE có tín hiệu LOW
//     }
// }

// line đen -> không phản xạ -> bật đèn
// line trắng -> phản xạ -> tắt đèn
#define LINE 2
int val = 0;
int LED = 13;
float toneVal;
float sinVal;
int ALARM = 4;

void setup() {
    pinMode(LED, OUTPUT);
    pinMode(LINE, INPUT);
    
    Serial.begin(9600); // Khởi động Serial Monitor với baud rate 9600
}

void loop() {
    val = digitalRead(LINE);
    
    Serial.print("Trạng thái LINE: ");
    Serial.println(val); // In giá trị đọc từ LINE (0 hoặc 1)
    
    if (val == 1) {
        digitalWrite(LED, HIGH); // Bật LED nếu LINE có tín hiệu HIGH
        Serial.println("LED: ON"); // In trạng thái LED
    } else {
        digitalWrite(LED, LOW);  // Tắt LED nếu LINE có tín hiệu LOW
        Serial.println("LED: OFF"); // In trạng thái LED
    }

    // if (val==0) { // gặp vật cản 
    //     for (int x = 0; x < 180; x++) {
    //         // Chuyển đổi sin function sang radian
    //         sinVal = sin(x * (3.1412 / 180));
    //         // Dùng sin function để tạo tần số âm thanh
    //         toneVal = 2000 + (int)(sinVal * 1000);
    //         // Phát tín hiệu từ buzzer
    //         tone(ALARM, toneVal);
    //         delay(2);
    //     }
    // } else { 
    //     noTone(ALARM); 
    // }
    
}
