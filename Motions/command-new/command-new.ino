#include <ESP32Servo.h>

Servo servos[11];

int a = 120;
int f = 60;
int g = 60;

float pi=3.14159;
int TotalNumberofServos=10; //change as required 
int ServosPerSide=TotalNumberofServos/2;
float shift = 2*pi/ServosPerSide; // Phase lag between segments
int amplitude = 50;
int offset = 0;
float rads;
float Speed=2;
float Wavelengths=1.5;
int Multiplier = 0;


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
  char command;

  if (Serial.available() > 0) {
    command = Serial.read();

    switch (command) {
      case 't':
        while (Serial.read() != 'q') {
          moveServo();
        }
        break;
      case 'd':
        while (Serial.read() != 'q') {
          moveServo2();
        }
        break;
    }
  }
}

void moveServo() {
  int c = 60;
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

void moveServo2() {
  int a =110;
  int b =70;
  int c = 30;
  servos[0].write(a);
  delay(c);
  servos[1].write(a);
  delay(c);
  servos[2].write(a);
  delay(c);
  servos[3].write(a);
  delay(c);
  servos[4].write(a);
  delay(c);
  servos[5].write(a);
  delay(c);
  servos[6].write(a);
  delay(c);
  servos[7].write(a);
  delay(c);
  servos[8].write(a);
  delay(c);
  servos[9].write(a);
  delay(c);
  servos[10].write(a);
  delay(c);
  servos[0].write(b);
  delay(c);
  servos[1].write(b);
  delay(c);
  servos[2].write(b);
  delay(c);
  servos[3].write(b);
  delay(c);
  servos[4].write(b);
  delay(c);
  servos[5].write(b);
  delay(c);
  servos[6].write(b);
  delay(c);
  servos[7].write(b);
  delay(c);
  servos[8].write(b);
  delay(c);
  servos[9].write(b);
  delay(c);
  servos[10].write(b);
  delay(c);
}

void stopServos() {
  int a = 90;
  servos[0].write(a);
  servos[1].write(a);
  servos[2].write(a);
  servos[3].write(a);
  servos[4].write(a);
  servos[5].write(a);
  servos[6].write(a);
  servos[7].write(a);
  servos[8].write(a);
  servos[9].write(a);
  servos[10].write(a);
}

void right() {
  int a = 90;

  servos[0].write(a);
  servos[1].write(0);
  servos[2].write(90);
  servos[3].write(190);
  servos[4].write(0);
  servos[5].write(90);
  servos[6].write(a);
  servos[7].write(5);
  servos[8].write(50);
  servos[9].write(a);
  servos[10].write(160);
  delay(100);
  servos[2].write(130);
}

void left() {
  int a = 90;
  servos[0].write(a);
  servos[1].write(0);
  servos[2].write(90);
  servos[3].write(190);
  servos[4].write(160);
  servos[5].write(90);
  servos[6].write(a);
  servos[7].write(5);
  servos[8].write(50);
  servos[9].write(a);
  servos[10].write(160);
  delay(100);
  servos[2].write(130);
}

void sin() {
  int a = 130;
  servos[0].write(a);
  servos[1].write(a);
  servos[2].write(a);
  servos[3].write(a);
  servos[4].write(a);
  servos[5].write(a);
  servos[6].write(a);
  servos[7].write(a);
  servos[8].write(a);
  servos[9].write(a);
  servos[10].write(a);
}

void s_sin() {
  int a = 50;
  servos[0].write(a);
  servos[1].write(a);
  servos[2].write(a);
  servos[3].write(a);
  servos[4].write(a);
  servos[5].write(a);
  servos[6].write(a);
  servos[7].write(a);
  servos[8].write(a);
  servos[9].write(a);
  servos[10].write(a);
}


void t_move(){
  for(int a = 50; a<140; a++){
    servos[0].write(a);
    servos[1].write(a);
    servos[2].write(a);
    servos[3].write(90);
    servos[4].write(a);
    servos[5].write(a);
    servos[6].write(90);
    servos[7].write(a);
    servos[8].write(a);
    servos[9].write(90);
    servos[10].write(a);
    delay(15);
  }

  for(int a = 140; a>50; a--){
    servos[0].write(a);
    servos[1].write(a);
    servos[2].write(a);
    servos[3].write(90);
    servos[4].write(a);
    servos[5].write(a);
    servos[6].write(90);
    servos[7].write(a);
    servos[8].write(a);
    servos[9].write(90);
    servos[10].write(a);
    delay(15);
  }
}

void cmu(){
  for(int i=0; i<360; i++){
   rads=i*pi/180.0;     //convert from degrees to radians
   for(int j=0; j<5; j++){  
      servos[2*j].write(90+offset+amplitude*sin(Speed*rads+j*Wavelengths*shift-(Multiplier-1)*pi/4));   //moves servos in vertical plane
      servos[2*j+3].write(90+offset+amplitude*sin(Speed*rads+j*Wavelengths*shift+(Multiplier+1)*pi/4)); //moves servos in horizontal plane
   }
   delay(13);
  }
}

