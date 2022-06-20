#include"TFT_eSPI.h"

TFT_eSPI tft;

void setup(){
  tft.begin();
  pinMode(WIO_KEY_A, INPUT_PULLUP);
  pinMode(WIO_5S_RIGHT, INPUT_PULLUP);
  tft.fillScreen(0x21F);

}



void loop(){

  if ((digitalRead(WIO_KEY_A) == LOW && digitalRead(WIO_5S_RIGHT) == LOW)) {
    tft.fillScreen(0x0);
    tft.drawString((String)"ciao",100,100);
    tft.setTextColor(0xF841);
  } else {
    tft.fillScreen(0x21F);
  }

}
