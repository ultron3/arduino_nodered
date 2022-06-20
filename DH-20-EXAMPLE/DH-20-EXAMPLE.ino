// distanza

#include <Ultrasonic.h>
Ultrasonic ult(0);

// schermo
#include"TFT_eSPI.h"
TFT_eSPI tft;

// DHT
#include "Wire.h"
#include "DHT.h"
#define DHTTYPE DHT20   // DHT 20
/*Notice: The DHT10 and DHT20 is different from other DHT* sensor ,it uses i2c interface rather than one wire*/
/*So it doesn't require a pin.*/
DHT dht(DHTTYPE);         //   DHT10 DHT20 don't need to define Pin

#if defined(ARDUINO_ARCH_AVR)
#define debug  Serial

#elif defined(ARDUINO_ARCH_SAMD) ||  defined(ARDUINO_ARCH_SAM)
#define debug  SerialUSB
#else
#define debug  Serial
#endif

void setup() {

  // schermo
  tft.begin();
  tft.setRotation(3); // schermo dritto

  // luce
  pinMode(WIO_LIGHT, INPUT);

  // DHT
  debug.begin(115200);
  debug.println("DHTxx test!");
  Wire.begin();


  dht.begin();
}

void loop() {

  // crea variabile distanza
  int distanza =   (long)ult.MeasureInCentimeters();

  // crea variabile luce
  int luce = analogRead(WIO_LIGHT);


  // setta schermo
  tft.fillScreen(0x0);
  tft.setTextSize(3);
  tft.setTextColor(0xFFFF);


  float temp_hum_val[2] = {0};
  // Reading temperature or humidity takes about 250 milliseconds!
  // Sensor readings may also be up to 2 seconds 'old' (its a very slow sensor)



  if (!dht.readTempAndHumidity(temp_hum_val)) {
    debug.print("Humidity: ");
    tft.drawString((String)"Humidity: ", 10, 10);
    debug.print(temp_hum_val[0]);
    tft.drawString((String)temp_hum_val[0], 220, 10);
    debug.print(" %\t");
    debug.print("Temperature: ");
    tft.drawString((String)"Temperature: ", 10, 50);
    debug.print(temp_hum_val[1]);
    tft.drawString((String)temp_hum_val[1], 220, 50);

    tft.drawString((String)"Distance: ", 10, 90);
    tft.drawString((String)distanza, 220, 90);

    tft.drawString((String)"Light: ", 10, 130);
    tft.drawString((String)luce, 220, 130);

    debug.println(" *C");

  } else {
    debug.println("Failed to get temprature and humidity value.");
  }

  delay(1500);
}
