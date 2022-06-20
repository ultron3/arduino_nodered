#include "rpcWiFi.h"
#include <MQTT.h>

const char ssid[] = "Its-guest";
const char pass[] = "eet6Euru";

WiFiClient net;
MQTTClient client;

unsigned long lastMillis = 0;

void connect() {
  tft.setTextSize(2);
  tft.setCursor((320 - tft.textWidth("checking wifi...")) / 2, 120);

  tft.print("checking wifi...");
  Serial.print("checking wifi...");

  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(1000);
  }
  String con = "\nconnecting...";
  tft.setCursor((320 - tft.textWidth(con)) / 2, 120);
  tft.print(con);


  Serial.print("\nconnecting...");
  //while (!client.connect("arduino", "public", "public")) {
  while (!client.connect("AlexG")) {
    Serial.print(".");
    delay(1000);
  }

  Serial.println("\nconnected!");

  client.subscribe("/dddd-test-out");
  // client.unsubscribe("/hello");
}
}


void loop() {


  if (!client.connected()) {
    reconnect();
  }
  client.loop();

  long now = millis();
  if (now - lastMsg > 2000) {
    lastMsg = now;
    ++value;
    snprintf (msg, 50, "Wio Terminal #%ld", value);
    Serial.print("Publish message: ");
    Serial.println(msg);
    client.publish("WTout", msg);
  }
}
