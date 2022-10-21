#include <WiFi.h>
#include <WiFiClient.h>
#include <WebServer.h>

#include "index.h" 

#define ADC_VREF_mV    5000.0 
#define ADC_RESOLUTION 4096.0
#define PIN_LM35       36 

WebServer server(80);

const char* ssid = "Ifal";
const char* password = "ifal0a009";

void handleRoot() {
 String s = MAIN_page; 
 server.send(200, "text/html", s); 
}
 
void handleADC() {

    int adcVal = analogRead(36);
    float milliVolt = adcVal * (ADC_VREF_mV / ADC_RESOLUTION);
    float tempC = milliVolt / 10;
 
    String adcValue = String(adcVal);
 
    server.send(200, "text/plane", adcValue); 
}

void setup(void){
  Serial.begin(115200);
  Serial.println();
  Serial.println("Booting Sketch...");

  WiFi.mode(WIFI_STA); 
  WiFi.begin(ssid, password);

  Serial.println("Connecting to ");
  Serial.print(ssid);

  while(WiFi.waitForConnectResult() != WL_CONNECTED){      
      Serial.print(".");
    }
    
  Serial.println("");
  Serial.print("Connected to ");
  Serial.println(ssid);
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());  
 
  server.on("/", handleRoot);      
  server.on("/readADC", handleADC);
 
  server.begin();                 
  Serial.println("HTTP server started");
}

void loop(void){
  server.handleClient();
  delay(1);
}