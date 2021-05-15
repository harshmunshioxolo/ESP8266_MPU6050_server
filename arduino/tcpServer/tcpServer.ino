#include <ESP8266WiFi.h>

// Define a port
const uint16_t port = 8888;

// Host to connect to (or send data to)
const char* host = "192.168.178.37";

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
  // Make a basic server to send a very simple number
  // We have already defined a host IP 
  WiFiClient client;

  if(!client.connect(host, port)) {
    Serial.println("Connection failed");
    delay(1000);
    return;
  }

  Serial.println("Connected!");
  client.print("Hello from my nodeMCU");

  Serial.println("Sent the 1st text, now Disconnecting....");
  client.stop();
  delay(1000);
}
