#include <Arduino.h>
#include <WiFi.h>  // Thư viện bị lỗi (chưa cài đúng cách)
#include <LiquidCrystal_I2C.h>

const char* ssid = "your_SSID";   // Chưa thay đổi thành SSID thực tế
const char* password = "your_PASSWORD";  // Chưa thay đổi thành mật khẩu thực tế

LiquidCrystal_I2C lcd(0x27, 16, 2);  // Địa chỉ LCD có thể sai

void setup() {
    Serial.begin(115200);
    lcd.begin();
    lcd.backlight();
    lcd.print("Connecting...");

    WiFi.begin(ssid, password);
    
    while (WiFi.status() != WL_CONNECTED) {
        delay(500);
        Serial.print(".");
    }

    lcd.clear();
    lcd.print("Connected!");
}

void loop() {
    lcd.setCursor(0, 1);
    lcd.print("IP: ");
    lcd.print(WiFi.localIP());  // Có thể lỗi nếu WiFi chưa kết nối đúng cách
    delay(1000);
}
