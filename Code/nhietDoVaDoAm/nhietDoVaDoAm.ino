#include <DHT.h>  // Thư viện DHT

#define DHTPIN 2       // Chân DATA của DHT11 nối với D2 trên Arduino
#define DHTTYPE DHT11  // Loại cảm biến là DHT11
int LED = 13;
float humidity;       
float temperature;
int ALARM = 4;
float sinVal;
float toneVal;

DHT dht(DHTPIN, DHTTYPE);  // Khởi tạo đối tượng DHT

void setup() {
  Serial.begin(9600);  // Bật Serial Monitor
  dht.begin();         // Khởi động cảm biến DHT11
  pinMode(LED, OUTPUT);
}

void loop() {
  humidity = dht.readHumidity();  // Đọc độ ẩm
  temperature = dht.readTemperature();  // Đọc nhiệt độ (°C)
  // Kiểm tra nếu có lỗi đọc dữ liệu
  if (isnan(humidity) || isnan(temperature)) {
    Serial.println("Lỗi! Không thể đọc dữ liệu từ DHT11.");
    return;
  }

  // In kết quả ra Serial Monitor
  Serial.print("Độ ẩm: ");
  Serial.print(humidity);
  Serial.print(" %RH\t");

  Serial.print("Nhiệt độ: ");
  Serial.print(temperature);
  Serial.println(" °C");

  // if (temperature > 28.3) {
  //   digitalWrite(LED, HIGH);
  //   Serial.println("LED: ON (Nhiệt độ cao!)");
  // } else {
  //   digitalWrite(LED, LOW);
  //   Serial.println("LED: OFF (Nhiệt độ bình thường)");
  // }

  if (humidity > 78) { // Nếu nhiệt độ > 27°C, bật buzzer
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

  // delay(1000);
}
