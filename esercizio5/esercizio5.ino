#include"TFT_eSPI.h"

TFT_eSPI tft;
float x;
float y;
float speed;
float dirX;
float dirY;

void setup(){
  tft.begin();
  tft.setRotation(3);
  speed = 5;
  x = 160;
  y = 120;
  dirX = 1;
  dirY = -1;

  pinMode(WIO_5S_UP, INPUT_PULLUP);
  pinMode(WIO_5S_DOWN, INPUT_PULLUP);
  pinMode(WIO_5S_RIGHT, INPUT_PULLUP);
  pinMode(WIO_5S_LEFT, INPUT_PULLUP);
}



void loop(){

  tft.fillScreen(0x0);
  tft.drawCircle(x,y,10,0xF800);
  tft.fillCircle(x,y,10,0xF800);
  x = x + (dirX * speed);
  y = y + (dirY * speed);

}
