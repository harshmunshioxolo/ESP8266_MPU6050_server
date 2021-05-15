#include <ESP8266WiFi.h>

// Define a port
int port = 80;

// Initialize a server
WiFiServer server(port);

// Connection details
const char* ssid = "";
const char* password = "";

// Setup
void setup() {
  Serial.begin(9600);
  WiFi.mode(WIFI_STA);

  // Connect to the WiFi
  WiFi.begin(ssid, password);

  // Wait for the connection
  while (WiFi.status() != WL_CONNECTED) {   
    delay(500);
    Serial.print(".");
    delay(500);
  }

  // Network Details
  Serial.println("");
  Serial.print("Connected to ");
  Serial.println(ssid);

  // Device Details
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());  
  
}

void loop() {
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());
}
