#include <ESP8266WiFi.h>
#include <Adafruit_MPU6050.h>
#include <Adafruit_Sensor.h>
#include <Wire.h>

// Define the mpu object
Adafruit_MPU6050 mpu;

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
  // Pause the nodemcu pins for warmup
  while (!Serial) {
    delay(10);
  }

  Serial.println("Sensors warmed up!");

  // MPU setup
  if(!mpu.begin()) {
    Serial.println("Failed to find MOU6050");
  }

  Serial.println("MPU6050 Found");
  // Set accelerometer range
  mpu.setAccelerometerRange(MPU6050_RANGE_8_G);
  // Set Gyro range
  mpu.setGyroRange(MPU6050_RANGE_500_DEG);
  // Set filter bandwidth
  mpu.setFilterBandwidth(MPU6050_BAND_5_HZ);

  // WiFi settings
  
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
  // Monitor Sensor events
  sensors_event_t a, g, temp;
  mpu.getEvent(&a, &g, &temp);

  // Make a basic server to send a very simple number
  // We have already defined a host IP
  WiFiClient client;

  if(!client.connect(host, port)) {
    Serial.println("Connection failed");
    delay(1000);
    return;
  }

  Serial.println("Connected!");
  client.print(a.acceleration.x);

  Serial.println("Sent the 1st text, now Disconnecting....");
  client.stop();
  delay(1000);
}
