void setup()
{
  for (int pin = 4; pin <= 13; pin++)
  {
    pinMode(pin, OUTPUT);
  }
}

void loop()
{
  // Sáng lần lượt từ trái qua phải
  for (int pin = 4; pin <= 13; pin++)
  {
    digitalWrite(pin, HIGH);
    delay(200); // Thời gian giữa mỗi lần sáng (200ms)
    digitalWrite(pin, LOW);
  }

  // Sáng lần lượt từ phải qua trái
  for (int pin = 13; pin >= 4; pin--)
  {
    digitalWrite(pin, HIGH);
    delay(200); // Thời gian giữa mỗi lần sáng (200ms)
    digitalWrite(pin, LOW);
  }
}