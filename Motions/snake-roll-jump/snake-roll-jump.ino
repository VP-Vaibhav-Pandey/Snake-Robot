#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>
#include <ESP32Servo.h>

Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();

#define SERVOMIN  125 // this is the 'minimum' pulse length count (out of 4096)
#define SERVOMAX  575 // this is the 'maximum' pulse length count (out of 4096)

void setup() {
  Serial.begin(9600);
  pwm.begin();
  pwm.setPWMFreq(50);  // Analog servos run at ~50 Hz updates
}

void loop() {
  int a = 30;
  int f = 110;
  int g = 70;
  pwm.setPWM(0, 0,angleToPulse(f));
  delay(a);
  pwm.setPWM(1, 0,angleToPulse(f));
  delay(a);
  pwm.setPWM(2, 0,angleToPulse(f));
  delay(a);
  pwm.setPWM(3, 0,angleToPulse(f));
  delay(a);
  pwm.setPWM(4, 0,angleToPulse(f));
  delay(a);
  pwm.setPWM(5, 0,angleToPulse(f));
  delay(a);
  pwm.setPWM(6, 0,angleToPulse(f));
  delay(a);
  pwm.setPWM(7, 0,angleToPulse(f));
  delay(a);
  pwm.setPWM(8, 0,angleToPulse(f));
  delay(a);
  pwm.setPWM(0, 0,angleToPulse(g));
  delay(a);
  pwm.setPWM(1, 0,angleToPulse(g));
  delay(a);
  pwm.setPWM(2, 0,angleToPulse(g));
  delay(a);
  pwm.setPWM(3, 0,angleToPulse(g));
  delay(a);
  pwm.setPWM(4, 0,angleToPulse(g));
  delay(a);
  pwm.setPWM(5, 0,angleToPulse(g));
  delay(a);
  pwm.setPWM(6, 0,angleToPulse(g));
  delay(a);
  pwm.setPWM(7, 0,angleToPulse(g));
  delay(a);
  pwm.setPWM(8, 0,angleToPulse(g));
  delay(a);
  
}



int angleToPulse(int ang){
   int pulse = map(ang,0, 180, SERVOMIN,SERVOMAX);// map angle of 0 to 180 to Servo min and Servo max 
   Serial.print("Angle: ");Serial.print(ang);
   Serial.print(" pulse: ");Serial.println(pulse);
   return pulse;
}

