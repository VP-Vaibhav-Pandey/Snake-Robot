#include <ESP32Servo.h>
Servo servos[11];
int o = 180;
//t-move

int a = 120;
int f = 60;
int g = 60;

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
  for(int a = 50; a<140; a++){
    servos[0].write(a);
    servos[1].write(o-a);
    servos[2].write(a);
    servos[3].write(o-90);
    servos[4].write(a);
    servos[5].write(o-a);
    servos[6].write(90);
    servos[7].write(o-a);
    servos[8].write(a);
    servos[9].write(o-90);
    servos[10].write(a);
    delay(15);
  }

  for(int a = 140; a>50; a--){
    servos[0].write(a);
    servos[1].write(o-a);
    servos[2].write(a);
    servos[3].write(o-90);
    servos[4].write(a);
    servos[5].write(o-a);
    servos[6].write(90);
    servos[7].write(o-a);
    servos[8].write(a);
    servos[9].write(o-90);
    servos[10].write(a);
    delay(15);
  }
}
