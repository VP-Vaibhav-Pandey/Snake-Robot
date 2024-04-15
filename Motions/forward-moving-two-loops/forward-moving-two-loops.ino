#include <ESP32Servo.h>
Servo servos[11];
int c = 200;


void setup() {
  Serial.begin(9600); 

  servos[0].attach(13);
  servos[1].attach(12);
  servos[2].attach(14);
  servos[3].attach(27);
  servos[4].attach(26);
  servos[5].attach(25);
  servos[6].attach(33);
  servos[7].attach(32);
  servos[8].attach(21);
  servos[9].attach(19);
  servos[10].attach(22);

}



void loop() {
  servos[0].write(120);
  delay(c);
  servos[1].write(40);
  delay(c);
  servos[2].write(120);
  delay(c);
  servos[3].write(40);
  delay(c);
  servos[4].write(120);
  delay(c);
  servos[5].write(40);
  delay(c);
  servos[6].write(120);
  delay(c);
  servos[7].write(40);
  delay(c);
  servos[8].write(120);
  delay(c);
  servos[9].write(40);
  delay(c);
  servos[10].write(120);
  delay(c);
  servos[0].write(40);
  delay(c);
  servos[1].write(120);
  delay(c);
  servos[2].write(40);
  delay(c);
  servos[3].write(120);
  delay(c);
  servos[4].write(40);
  delay(c);
  servos[5].write(120);
  delay(c);
  servos[6].write(40);
  delay(c);
  servos[7].write(120);
  delay(c);
  servos[8].write(40);
  delay(c);
  servos[9].write(120);
  delay(c);
  servos[10].write(40);
  delay(c);
}



