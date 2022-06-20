#include"TFT_eSPI.h"

TFT_eSPI tft;

void setup(){
  tft.begin();
  pinMode(WIO_KEY_A, INPUT_PULLUP);
  tft.fillScreen(0xF800);

}



void loop(){

  if (digitalRead(WIO_KEY_A) == LOW) {
    tft.fillScreen(0x0);
  } else {
    tft.fillScreen(0xF800);
  }

}
