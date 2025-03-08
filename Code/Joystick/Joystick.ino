int JoyStick_X = A0; 
int JoyStick_Y = A1;
int JoyStick_Z = 6; 

void setup() {
    pinMode(JoyStick_Z, INPUT_PULLUP); 
    Serial.begin(9600); 
}

void loop() {
    int x, y, z;

    x = analogRead(JoyStick_X);
    y = analogRead(JoyStick_Y);
    z = digitalRead(JoyStick_Z);

    Serial.print(x, DEC);
    Serial.print(",");
    Serial.print(y, DEC);
    Serial.print(",");
    Serial.println(z, DEC);
    delay(100); 
}
// pinMode(JoyStick_Z, INPUT); 
// int LED = 13;
// pinMode(LED, OUTPUT);
// bật điện trở nội bộ của arduino, nếu chỉ để INPUT thì SW bị không ổn định (giao động 0, 1)
    // không có thì phải nối SW với 1 điện trở > 10kOm vào GND, INPUT_PULLUP mặc định là high = 5V, nhấn thì qua GND = low
// if (z == 0) {
//       digitalWrite(13, HIGH);
//     } else {
//       digitalWrite(13, LOW);
//     }

