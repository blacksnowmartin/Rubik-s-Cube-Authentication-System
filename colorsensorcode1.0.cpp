#include <Wire.h>
#include <Adafruit_TCS34725.h>

// Define the pins for the color sensors
#define SENSOR_1_ADDRESS 0x29
#define SENSOR_2_ADDRESS 0x30
#define SENSOR_3_ADDRESS 0x41
#define SENSOR_4_ADDRESS 0x39
#define SENSOR_5_ADDRESS 0x49
#define SENSOR_6_ADDRESS 0x52

Adafruit_TCS34725 sensor1 = Adafruit_TCS34725(TCS34725_INTEGRATIONTIME_700MS, TCS34725_GAIN_1X);
Adafruit_TCS34725 sensor2 = Adafruit_TCS34725(TCS34725_INTEGRATIONTIME_700MS, TCS34725_GAIN_1X);
Adafruit_TCS34725 sensor3 = Adafruit_TCS34725(TCS34725_INTEGRATIONTIME_700MS, TCS34725_GAIN_1X);
Adafruit_TCS34725 sensor4 = Adafruit_TCS34725(TCS34725_INTEGRATIONTIME_700MS, TCS34725_GAIN_1X);
Adafruit_TCS34725 sensor5 = Adafruit_TCS34725(TCS34725_INTEGRATIONTIME_700MS, TCS34725_GAIN_1X);
Adafruit_TCS34725 sensor6 = Adafruit_TCS34725(TCS34725_INTEGRATIONTIME_700MS, TCS34725_GAIN_1X);

void setup() {
  Serial.begin(9600);

  // Initialize each color sensor
  initializeSensor(sensor1, SENSOR_1_ADDRESS);
  initializeSensor(sensor2, SENSOR_2_ADDRESS);
  initializeSensor(sensor3, SENSOR_3_ADDRESS);
  initializeSensor(sensor4, SENSOR_4_ADDRESS);
  initializeSensor(sensor5, SENSOR_5_ADDRESS);
  initializeSensor(sensor6, SENSOR_6_ADDRESS);
}

void loop() {
  // Read color values from each sensor
  readColor(sensor1, "Sensor 1");
  readColor(sensor2, "Sensor 2");
  readColor(sensor3, "Sensor 3");
  readColor(sensor4, "Sensor 4");
  readColor(sensor5, "Sensor 5");
  readColor(sensor6, "Sensor 6");

  delay(1000); // Adjust the delay as needed
}

void initializeSensor(Adafruit_TCS34725 &sensor, uint8_t address) {
  if (sensor.begin(address)) {
    Serial.println("Color sensor initialized");
  } else {
    Serial.println("Error initializing color sensor");
    while (1);
  }
}

void readColor(Adafruit_TCS34725 &sensor, const char *sensorName) {
  uint16_t red, green, blue, clear;

  sensor.getRawData(&red, &green, &blue, &clear);
  
  Serial.print(sensorName);
  Serial.print(" - Red: "); Serial.print(red);
  Serial.print(" Green: "); Serial.print(green);
  Serial.print(" Blue: "); Serial.print(blue);
  Serial.print(" Clear: "); Serial.println(clear);
}
