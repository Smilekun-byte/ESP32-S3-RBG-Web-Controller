#include <WiFi.h>
#include <WebServer.h>
#include <Adafruit_NeoPixel.h>

#define LED_PIN 38
#define LED_COUNT 1

Adafruit_NeoPixel strip(LED_COUNT, LED_PIN, NEO_GRB + NEO_KHZ800);

const char* ssid = "ESP32-S3";
const char* password = "12345678";

WebServer server(80);

void handleRoot() {
  String html = "<html><body>";
  html += "<h1>ESP32 RGB Control</h1>";
  html += "<button onclick=\"location.href='/red'\">Red</button><br><br>";
  html += "<button onclick=\"location.href='/green'\">Green</button><br><br>";
  html += "<button onclick=\"location.href='/blue'\">Blue</button><br><br>";
  html += "<button onclick=\"location.href='/off'\">Off</button>";
  html += "</body></html>";
  server.send(200, "text/html", html);
}

void setColor(uint8_t r, uint8_t g, uint8_t b) {
  strip.setPixelColor(0, strip.Color(r, g, b));
  strip.show();
}

void setup() {
  strip.begin();
  strip.show();

  WiFi.mode(WIFI_AP);
  WiFi.softAP(ssid, password);

  server.on("/", handleRoot);
  server.on("/green", []() {
    setColor(255, 0, 0);
    handleRoot();
  });
  server.on("/red", []() {
    setColor(0, 255, 0);
    handleRoot();
  });
  server.on("/blue", []() {
    setColor(0, 0, 255);
    handleRoot();
  });
  server.on("/off", []() {
    setColor(0, 0, 0);
    handleRoot();
  });

  server.begin();
}

void loop() {
  server.handleClient();
}