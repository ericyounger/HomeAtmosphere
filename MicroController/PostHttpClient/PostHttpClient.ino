/**
   PostHTTPClient.ino

    Created on: 21.11.2016

*/

#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>

/* this can be run with an emulated server on host:
        cd esp8266-core-root-dir
        cd tests/host
        make ../../libraries/ESP8266WebServer/examples/PostServer/PostServer
        bin/PostServer/PostServer
   then put your PC's IP address in SERVER_IP below, port 9080 (instead of default 80):
*/
//#define SERVER_IP "10.0.1.7:9080" // PC address with emulation on host
#define SERVER_IP "192.168.10.119:3000"

#ifndef STASSID
#define STASSID "SSID"
#define STAPSK  "PASSWORD"
#endif

void setup() {

  Serial.begin(115200);

  Serial.println();
  Serial.println();
  Serial.println();

  WiFi.begin(STASSID, STAPSK);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.print("Connected! IP address: ");
  Serial.println(WiFi.localIP());

}

void loop() {
  // wait for WiFi connection
  if ((WiFi.status() == WL_CONNECTED)) {

    WiFiClient client;
    HTTPClient http;

    Serial.print("[HTTP] begin...\n");
    
    // Connect to server
    http.begin(client, "http://" SERVER_IP "/atmosphere"); //HTTP
    
    //Set content-type
    http.addHeader("Content-Type", "application/json");

    Serial.print("[HTTP] POST...\n");


    // start connection and send HTTP header and body
    int humidity = 66;
    int temperature = 20;
    
    int httpCode = http.POST("{\"temperature\":" + String(temperature) + ", \"humidity\" : " +  String(humidity) +"}");

    // httpCode will be negative on error
    if (httpCode > 0) {
      // HTTP header has been send and Server response header has been handled
      Serial.printf("[HTTP] POST : Status Code: %d\n", httpCode);

      // file found at server
      if (httpCode == HTTP_CODE_CREATED) {
        Serial.println("Post succesfull");
      }
    } else {
      Serial.printf("[HTTP] POST... failed, error: %s\n", http.errorToString(httpCode).c_str());
    }

    http.end();
  }

  delay(10000);
}
