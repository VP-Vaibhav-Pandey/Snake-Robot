#include <ESP32Servo.h>

Servo myServos[11];

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

  myServos[0].attach(13);
  myServos[1].attach(12);
  myServos[2].attach(14);
  myServos[3].attach(27);
  myServos[4].attach(26);
  myServos[5].attach(25);
  myServos[6].attach(33);
  myServos[7].attach(32);
  myServos[8].attach(21);
  myServos[9].attach(19);
  myServos[10].attach(22);

}



void loop() {


  for(int i=0; i<360; i++){
   rads=i*pi/180.0;     //convert from degrees to radians
   for(int j=0; j<5; j++){  
      myServos[2*j].write(90+offset+amplitude*sin(Speed*rads+j*Wavelengths*shift-(Multiplier-1)*pi/4));   //moves servos in vertical plane
      myServos[2*j+3].write(90+45+amplitude*sin(Speed*rads+j*Wavelengths*shift+(Multiplier+1)*pi/4)); //moves servos in horizontal plane
   }
   delay(13);
  }

}



