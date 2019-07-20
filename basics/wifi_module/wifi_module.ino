#include <ESP8266WiFi.h>

#include <WiFiClient.h>

#include <ESP8266WebServer.h>

const char *ssid = "test";

const char *password = "passwordd";
int ledPin = 2;

ESP8266WebServer server(80);

void handleLed() {

  if (digitalRead(ledPin) == LOW) {


    server.send(200, "text/json", "ledOn");
    GPOS = (1 << ledPin);
  } else if (digitalRead(ledPin) == HIGH) {

    server.send(200, "text/json", "ledOff");
    GPOC = (1 << ledPin);
  }

}

void setup() {


  Serial.begin(115200);

  Serial.println();
  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, LOW);

  Serial.print("Configuring access point...");

  WiFi.softAP(ssid, password);

  IPAddress myIP = WiFi.softAPIP();

  Serial.print("AP IP address: ");

  Serial.println(myIP);

  server.on("/myinfo", handleLed);


  server.begin();

  Serial.println("HTTP server started");

}

void loop() {

  server.handleClient();

}
