#include"TFT_eSPI.h"

TFT_eSPI tft;

void setup() {
  tft.begin();
  pinMode(WIO_LIGHT, INPUT);
  Serial.begin(9600);
  tft.setRotation(3);
  tft.fillScreen(0xF800);

}



void loop() {

  tft.fillScreen(0xFFFF);
  //delay(1000);
  tft.setTextColor(0x0);
  tft.setTextSize(9);
  Serial.println(analogRead(WIO_LIGHT));
  tft.drawString((String)analogRead(WIO_LIGHT), 100, 120);

}
