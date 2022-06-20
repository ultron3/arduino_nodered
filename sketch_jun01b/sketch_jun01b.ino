#include"TFT_eSPI.h"

TFT_eSPI tft;
float luce;

void setup(){
  tft.begin();
  tft.fillScreen(0xF800);

}



void loop(){

  if ((luce < 50)) {
    tft.setTextColor(0x0);
    tft.drawString((String)"on", 100, 100);
  } else {
    tft.setTextColor(0x0);
    tft.drawString((String)"of", 100, 100);
  }

}
