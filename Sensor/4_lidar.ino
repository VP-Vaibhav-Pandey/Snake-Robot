#include "Adafruit_VL53L0X.h"
#include <Wire.h>

Adafruit_VL53L0X lox1 = Adafruit_VL53L0X();
Adafruit_VL53L0X lox2 = Adafruit_VL53L0X();


#define LOX1_XSHUT 23
#define LOX2_XSHUT 22


void setID() {
  digitalWrite(LOX1_XSHUT, LOW);
  digitalWrite(LOX2_XSHUT, LOW);
  delay(10);
  digitalWrite(LOX1_XSHUT, HIGH);
  delay(10);
  lox1.begin(0x30);
  digitalWrite(LOX2_XSHUT, HIGH);
  delay(10);
  lox2.begin(0x31);

}

void readRange() {
  VL53L0X_RangingMeasurementData_t measure1;
  VL53L0X_RangingMeasurementData_t measure2;

  lox1.rangingTest(&measure1, false);
  lox2.rangingTest(&measure2, false);

  // Send the data over the serial port
  Serial.print(measure1.RangeMilliMeter);
  Serial.print(", ");
  Serial.println(measure2.RangeMilliMeter);

}

void setup() {
  Wire.begin(4,5);
  Serial.begin(9600);
  pinMode(LOX1_XSHUT, OUTPUT);
  pinMode(LOX2_XSHUT, OUTPUT);

  setID();
}

void loop() {
  readRange();
  delay(500);
}
