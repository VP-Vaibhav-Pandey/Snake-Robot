#include <ESP32Servo.h>
#include <math.h>

Servo servo1;
Servo servo2;
Servo servo3;
Servo servo4;
Servo servo5;
Servo servo6;
int a =0;
int b=0;
int c=0;

void setup() {
  servo1.attach(13);
  servo2.attach(12);
  servo3.attach(14);
  servo4.attach(27);
  servo5.attach(26);
  servo6.attach(25);
  Serial.begin(9600);

}

void loop() {
  c = 300;
  int d = 20;
  if (Serial.available() > 0) {
    b = Serial.parseInt();
    if (b != 0){
      Serial.print("Updated value of a: ");
      Serial.println(b);
      a=b;
    }
  }
  servo1.write(100);
  delay(a);
  servo2.write(40);
  delay(a);
  servo3.write(120);
  delay(a);
  servo4.write(40);
  delay(a);
  servo5.write(140);
  delay(a);
  servo6.write(90);
  delay(c);
  servo1.write(90);
  delay(10);
  servo2.write(90);
  delay(10);
  servo3.write(90);
  delay(10);
  servo4.write(90);
  delay(10);
  servo5.write(90);
  delay(10);
  servo6.write(90);
  delay(10);
  servo1.write(80);
  delay(a);
  servo2.write(140);
  delay(a);
  servo3.write(60);
  delay(a);
  servo4.write(140);
  delay(a);
  servo5.write(40);
  delay(a);
  servo6.write(150);
  delay(c);
  servo1.write(90);
  delay(d);
  servo2.write(90);
  delay(d);
  servo3.write(90);
  delay(d);
  servo4.write(90);
  delay(d);
  servo5.write(90);
  delay(d);
  servo6.write(90);
  delay(d);
  servo1.write(80);
  delay(c);
}
