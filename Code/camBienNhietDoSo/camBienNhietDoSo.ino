#include <OneWire.h>
#include <DallasTemperature.h>

#define DS18B20_PIN 2  // Chân kết nối cảm biến DS18B20
#define BUZZER_PIN 4   // Chân điều khiển còi báo động

OneWire oneWire(DS18B20_PIN);
DallasTemperature sensors(&oneWire);

const float TEMP_THRESHOLD = 30.0; // Ngưỡng nhiệt độ để bật còi
const float HYSTERESIS = 0.5;      // Giảm dao động còi (hysteresis)
bool buzzerOn = false;             // Trạng thái còi báo

void setup() {
    Serial.begin(9600);
    sensors.begin();               // Khởi động cảm biến DS18B20
    pinMode(BUZZER_PIN, OUTPUT);
}

void loop() {
    sensors.requestTemperatures(); // Gửi lệnh đo nhiệt độ
    float temperature = sensors.getTempCByIndex(0); // Lấy nhiệt độ theo độ C

    Serial.print("Nhiệt độ: ");
    Serial.print(temperature);
    Serial.println(" °C");

    // Điều khiển còi báo động với hysteresis
    if (temperature > TEMP_THRESHOLD + HYSTERESIS) {
        buzzerOn = true;
    } else if (temperature < TEMP_THRESHOLD - HYSTERESIS) {
        buzzerOn = false;
    }

    if (buzzerOn) {
        tone(BUZZER_PIN, 2000); // Bật còi với tần số 2000Hz
    } else {
        noTone(BUZZER_PIN); // Tắt còi
    }

    delay(1000); // Đọc nhiệt độ mỗi giây
}
