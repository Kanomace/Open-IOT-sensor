#include <SSD1306Wire.h>
#include <Adafruit_NeoPixel.h>                  // 操作WS2812B需要使用的库

#define PIN         2     //GPIO0接口
#define NUMPIXELS   1    //彩灯个数

Adafruit_NeoPixel led(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);


const int I2C_ADDR = 0x3c;  
#define SDA_PIN 22                  
#define SCL_PIN 21
SSD1306Wire oled(I2C_ADDR, SDA_PIN, SCL_PIN);
void setup() {
 led.begin();
 led.setBrightness(50); //设置亮度 (0~255)
 Serial.begin(115200);
 oled.init();
 oled.flipScreenVertically();
 oled.setContrast(255);  
       
}

void loop() {
  // put your main code here, to run repeatedly:
  oled.clear();
  delay(5000);
  oled.setFont(ArialMT_Plain_16);   
  oled.drawString(0,0, "Temp: 25C");
  oled.drawString(0,20, "Humidity: 54%");
  oled.drawString(0,40, "Co2: 0.04%");
  oled.display();
  led.setPixelColor(0,led.Color(0, 255, 0)); //红色
  led.show();   //刷新显示
  delay(5000);
  oled.clear(); 
  oled.drawString(0,0, "Temp: 25C");
  oled.drawString(0,20, "Humidity: 53%");
  oled.drawString(0,40, "Co2: 0.03%");
  oled.display();
  delay(5000);
  oled.clear(); 
  oled.drawString(0,0, "Temp: 25C");
  oled.drawString(0,20, "Humidity: 52%");
  oled.drawString(0,40, "Co2: 0.04%");
  oled.display();
  delay(5000);
}
