#include <ESP32Servo.h>
//back
Servo servos[11];  // create servo objects to control the servos
int angles[11] = {45, 45, 45, 45, 45, 45, 45, 45, 45, 45, 45};  // the initial angles for each segment

void setup() {
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
  for (int i = 0; i < 11; i++) {
    int angle = angles[i] + sin(millis() / 200.0 + i) * 45;  // create a wave pattern
    servos[i].write(angle);  // tell servo to go to position in variable 'angle'
    delay(15);  // waits 15ms for the servo to reach the position
  }
}
