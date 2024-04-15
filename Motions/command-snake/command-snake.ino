#include <ESP32Servo.h>

Servo servo1; 
Servo servo2; 
Servo servo3;
Servo servo4;
Servo servo5;
Servo servo6;
Servo servo7;
Servo servo8;
Servo servo9;
Servo servo10;
Servo servo11;


void setup() {
  Serial.begin(9600); 
  servo1.attach(13);
  servo2.attach(12);
  servo3.attach(14);
  servo4.attach(27);
  servo5.attach(26);
  servo6.attach(25);
  servo7.attach(33);
  servo8.attach(32);
  servo9.attach(21);
  servo10.attach(19);
  servo11.attach(22);

}



void loop() {
  char command;

  if (Serial.available() > 0) {
    command = Serial.read();

    switch (command) {
      case 'w':
        while (Serial.read() != 'q') {
          moveServo();
        }
        break;
      case 'd':
        while (Serial.read() != 'q') {
          moveServo2();
        }
        break;
      case 'q':
      stopServos();
      break;

      case 'r':
      right();
      break;

      case 'l':
      left();
      break;

      case 's':
      sin();
      break;
    }
  }
}

void moveServo() {
  int c = 60;
  servo1.write(120);
  delay(c);
  servo2.write(40);
  delay(c);
  servo3.write(120);
  delay(c);
  servo4.write(40);
  delay(c);
  servo5.write(120);
  delay(c);
  servo6.write(40);
  delay(c);
  servo7.write(120);
  delay(c);
  servo8.write(40);
  delay(c);
  servo9.write(120);
  delay(c);
  servo10.write(40);
  delay(c);
  servo11.write(120);
  delay(c);
  servo1.write(40);
  delay(c);
  servo2.write(120);
  delay(c);
  servo3.write(40);
  delay(c);
  servo4.write(120);
  delay(c);
  servo5.write(40);
  delay(c);
  servo6.write(120);
  delay(c);
  servo7.write(40);
  delay(c);
  servo8.write(120);
  delay(c);
  servo9.write(40);
  delay(c);
  servo10.write(120);
  delay(c);
  servo11.write(40);
  delay(c);
}

void moveServo2() {
  int a =110;
  int b =70;
  int c = 30;
  servo1.write(a);
  delay(c);
  servo2.write(a);
  delay(c);
  servo3.write(a);
  delay(c);
  servo4.write(a);
  delay(c);
  servo5.write(a);
  delay(c);
  servo6.write(a);
  delay(c);
  servo7.write(a);
  delay(c);
  servo8.write(a);
  delay(c);
  servo9.write(a);
  delay(c);
  servo10.write(a);
  delay(c);
  servo11.write(a);
  delay(c);
  servo1.write(b);
  delay(c);
  servo2.write(b);
  delay(c);
  servo3.write(b);
  delay(c);
  servo4.write(b);
  delay(c);
  servo5.write(b);
  delay(c);
  servo6.write(b);
  delay(c);
  servo7.write(b);
  delay(c);
  servo8.write(b);
  delay(c);
  servo9.write(b);
  delay(c);
  servo10.write(b);
  delay(c);
  servo11.write(b);
  delay(c);
}

void stopServos() {
  int a = 90;
  servo1.write(a);
  servo2.write(a);
  servo3.write(a);
  servo4.write(a);
  servo5.write(a);
  servo6.write(a);
  servo7.write(a);
  servo8.write(a);
  servo9.write(a);
  servo10.write(a);
  servo11.write(a);
}

void right() {
  int a = 90;
  servo1.write(a);
  servo2.write(0);
  servo3.write(90);
  servo4.write(190);
  servo5.write(0);
  servo6.write(90);
  servo7.write(a);
  servo8.write(5);
  servo9.write(50);
  servo10.write(a);
  servo11.write(160);
  delay(100);
  servo3.write(130);
}

void left() {
  int a = 90;
  servo1.write(a);
  servo2.write(0);
  servo3.write(90);
  servo4.write(190);
  servo5.write(160);
  servo6.write(90);
  servo7.write(a);
  servo8.write(5);
  servo9.write(50);
  servo10.write(a);
  servo11.write(160);
  delay(100);
  servo3.write(130);
}

void sin() {
  int a = 115;
  servo1.write(a);
  servo2.write(a);
  servo3.write(a);
  servo4.write(a);
  servo5.write(a);
  servo6.write(a);
  servo7.write(a);
  servo8.write(a);
  servo9.write(a);
  servo10.write(a);
  servo11.write(a);
}

