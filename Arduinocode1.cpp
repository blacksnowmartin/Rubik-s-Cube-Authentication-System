#include <Wire.h>
#include <Adafruit_TCS34725.h>

Adafruit_TCS34725 colorSensor = Adafruit_TCS34725(TCS34725_INTEGRATIONTIME_50MS, TCS34725_GAIN_4X);

void setup() {
  Serial.begin(9600);
  if (!colorSensor.begin()) {
    Serial.println("Color sensor not found!");
    while (1);
  }
}

void loop() {
  uint16_t clear, red, green, blue;

  colorSensor.getRawData(&red, &green, &blue, &clear);

  // Use the RGB values to determine the color of the sensed face
  // Implement logic to compare with the expected passcode
  // If the passcode is detected, grant access
}
