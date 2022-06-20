#include"TFT_eSPI.h"

TFT_eSPI tft;
float x;
float y;
float speed;

void setup(){
  tft.begin();
  pinMode(WIO_5S_UP, INPUT_PULLUP);
  pinMode(WIO_5S_DOWN, INPUT_PULLUP);
  pinMode(WIO_5S_LEFT, INPUT_PULLUP);
  pinMode(WIO_5S_RIGHT, INPUT_PULLUP);
  tft.fillScreen(0x2800);
  speed = 10;
  x = 100;
  y = 100;

}



void loop(){

  tft.drawCircle(x,y,10,0xF800);
  tft.fillCircle(x,y,10,0xF800);
  if (digitalRead(WIO_5S_UP) == LOW) {
    tft.drawCircle(x,y,10,0xF800);
    tft.fillCircle(x,y,10,0xF800);
    y = y + (speed * -1);
  }
  if (digitalRead(WIO_5S_DOWN) == LOW) {
    tft.drawCircle(x,y,10,0xF800);
    x = x + (speed * 1);
  }
  if (digitalRead(WIO_5S_LEFT) == LOW) {
    tft.drawCircle(x,y,10,0xF800);
    y = y + (speed * -1);
  }
  if (digitalRead(WIO_5S_DOWN) == LOW) {
    tft.drawCircle(x,y,10,0xF800);
    speed = speed + (speed * 1);
  }
  x = x + speed;
  if (digitalRead(WIO_5S_RIGHT) == LOW) {
    tft.drawCircle(x,y,10,0xF800);
    y = y + (speed * -1);
  }

}
