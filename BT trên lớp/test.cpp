#define LED_PIN 2  // Chân GPIO2 của ESP32 kết nối với LED

void setup() {
  pinMode(LED_PIN, OUTPUT);  // Thiết lập LED_PIN là đầu ra
}

void loop() {
  digitalWrite(LED_PIN, HIGH);  // Bật LED
  delay(1000);                  // Chờ 1 giây
  digitalWrite(LED_PIN, LOW);   // Tắt LED
  delay(1000);                  // Chờ 1 giây
}