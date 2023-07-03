#include <Arduino.h>
#include <U8g2lib.h>

#include <SPI.h>

#define OLED_DC  23
#define OLED_CS  4
#define OLED_RST 5

//U8G2_SSD1306_128X64_NONAME_1_4W_SW_SPI u8g2(U8G2_R0, /* clock=*/ 13, /* data=*/ 11, /* cs=*/ 10, /* dc=*/ 9, /* reset=*/ 8);
//U8G2_SSD1305_128X32_ADAFRUIT_1_4W_SW_SPI u8g2(U8G2_R0, 13, 11, 10, 9, 8);
U8G2_SSD1309_128X64_NONAME2_1_4W_HW_SPI u8g2(/* rotation=*/U8G2_R0, /* cs=*/ OLED_CS, /* dc=*/ OLED_DC,/* reset=*/OLED_RST);


void setup(void)
{
  u8g2.begin();
  u8g2.setFontPosTop();
  Serial.println("setup complete");
}


void loop(void)
{
   u8g2.firstPage();
   u8g2.clear();
   u8g2.setFont(u8g2_font_open_iconic_all_4x_t );
   while (u8g2.nextPage()) {
     u8g2.clear();
     // draws encoding in random place on screen
     u8g2.drawGlyph(/* x=*/ random(128), /* y=*/ random(64), /* encoding=*/ 64);
     delay(2000);
   }
}