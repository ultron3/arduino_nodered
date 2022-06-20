#include"TFT_eSPI.h"

TFT_eSPI tft;
int x_start;
int y_start;

void setup(){
  tft.begin();
  pinMode(WIO_5S_UP, INPUT_PULLUP);
  pinMode(WIO_5S_DOWN, INPUT_PULLUP);
  pinMode(WIO_5S_LEFT, INPUT_PULLUP);
  pinMode(WIO_5S_RIGHT, INPUT_PULLUP);
  pinMode(WIO_5S_PRESS, INPUT_PULLUP);
  tft.setRotation(3);
  tft.fillScreen(0x0);
  x_start = 160;
  y_start = 120;
  tft.drawCircle(x_start,y_start,5,0xF800);
  tft.fillCircle(x_start,y_start,5,0xF800);

}



void loop(){

  if (digitalRead(WIO_5S_UP) == LOW) {
    switch (y_start) {
      case 0:
        y_start += 2;
        tft.fillScreen(0x0);
        tft.drawCircle(x_start,y_start,5,0xF800);
        tft.fillCircle(x_start,y_start,5,0xF800);
        break;
      default:
        y_start -= 2;
        tft.fillScreen(0x0);
        tft.drawCircle(x_start,y_start,5,0xF800);
        tft.fillCircle(x_start,y_start,5,0xF800);
}
  } else {
    if (digitalRead(WIO_5S_DOWN) == LOW) {
      switch (y_start) {
        case 240:
          y_start -= 2;
          tft.drawCircle(x_start,y_start,5,0xF800);
          tft.fillCircle(x_start,y_start,5,0xF800);
          break;
        default:
          y_start += 2;
          tft.fillScreen(0x0);
          tft.drawCircle(x_start,y_start,5,0xF800);
          tft.fillCircle(x_start,y_start,5,0xF800);
      }
    } else {
      if (digitalRead(WIO_5S_LEFT) == LOW) {
        switch (x_start) {
          case 0:
            x_start += 2;
            tft.fillScreen(0x0);
            tft.drawCircle(x_start,y_start,5,0xF800);
            tft.fillCircle(x_start,y_start,5,0xF800);
            break;
          default:
            x_start -= 2;
            tft.fillScreen(0x0);
            tft.drawCircle(x_start,y_start,5,0xF800);
            tft.fillCircle(x_start,y_start,5,0xF800);
        }
              } else {
        if (digitalRead(WIO_5S_RIGHT) == LOW) {
          switch (x_start) {
            case 320:
              x_start -= 2;
              tft.fillScreen(0x0);
              tft.drawCircle(x_start,y_start,5,0xF800);
              tft.fillCircle(x_start,y_start,5,0xF800);
              break;
            default:
              x_start += 2;
              tft.fillScreen(0x0);
              tft.drawCircle(x_start,y_start,5,0xF800);
              tft.fillCircle(x_start,y_start,5,0xF800);
          }
        } else {
          if (digitalRead(WIO_5S_PRESS) == LOW) {
            x_start = 160;
            y_start = 120;
            tft.fillScreen(0x0);
            tft.drawCircle(x_start,y_start,5,0xF800);
            tft.fillCircle(x_start,y_start,5,0xF800);
          }
        }
      }
    }
  }

}
