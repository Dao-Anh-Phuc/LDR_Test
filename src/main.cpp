#include <Arduino.h>

#define LDR_PIN 36 
#define LED_PIN 5 

const long BAUD_RATE = 115200;

void setup() {
  Serial.begin(BAUD_RATE);
  
  // Đợi Serial khởi tạo
  while(!Serial) {
    delay(10);
  }
  
  analogReadResolution(12); 
  
  pinMode(LED_PIN, OUTPUT);
  digitalWrite(LED_PIN, LOW); 
  
  Serial.println("LDR Light Sensor - Real-time Plot Ready");
  Serial.println("Format: >light:value");
}

void loop() {
  int ldrValue = analogRead(LDR_PIN);
  
  // Format cho Teleplot extension (cần dấu > ở đầu)
  Serial.print(">light:");
  Serial.println(ldrValue);
  
  // Điều khiển LED theo độ sáng
  if (ldrValue < 1500) { 
    digitalWrite(LED_PIN, LOW);   // Tối thì tắt LED
  } else {
    digitalWrite(LED_PIN, HIGH);  // Sáng thì bật LED
  }

  delay(100);  // 100ms sampling rate
}