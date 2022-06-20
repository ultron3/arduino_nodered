#include"TFT_eSPI.h"

TFT_eSPI tft;

void setup(){
  tft.begin();
  pinMode(WIO_LIGHT, INPUT);
  tft.fillScreen(0xF800);

}



void loop(){

  if ((analogRead(WIO_LIGHT) < 333)) {
    tft.fillScreen(0x0);
    tft.drawString((String)"valore luce", 100, 100);
    tft.println(Serial.readString());
  }
  if ((((analogRead(WIO_LIGHT) >= 334)) || ((analogRead(WIO_LIGHT) <= 900)))) {
    tft.fillScreen(0xFFFF);
    tft.drawString((String)"valore luce", 100, 100);
    tft.println(Serial.readString());
  } else {
    tft.fillScreen(0x301F);
  }

}
