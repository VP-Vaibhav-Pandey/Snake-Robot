#include <Bluepad32.h>
#include <ESP32Servo.h>
#include <Wire.h>
#include <VL53L0X.h>

Servo servos[11];
int offsets[] = {0, 45, 90, 135, 180, 225, 270, 315, 360, 405, 450};
int value;
VL53L0X sensor;
VL53L0X sensor2;
VL53L0X sensor3;
VL53L0X sensor4;
VL53L0X sensor5;

int a;
int b;
int c;
int d;
int e;
char command;


GamepadPtr myGamepads[BP32_MAX_GAMEPADS];


void onConnectedGamepad(GamepadPtr gp) {
  bool foundEmptySlot = false;
  for (int i = 0; i < BP32_MAX_GAMEPADS; i++) {
    if (myGamepads[i] == nullptr) {
      Serial.printf("CALLBACK: Gamepad is connected, index=%d\n", i);

      GamepadProperties properties = gp->getProperties();
      Serial.printf("Gamepad model: %s, VID=0x%04x, PID=0x%04x\n",
                    gp->getModelName().c_str(), properties.vendor_id,
                    properties.product_id);
      myGamepads[i] = gp;
      foundEmptySlot = true;
      break;
    }
  }
  if (!foundEmptySlot) {
    Serial.println(
        "CALLBACK: Gamepad connected, but could not found empty slot");
  }
}

void onDisconnectedGamepad(GamepadPtr gp) {
  bool foundGamepad = false;

  for (int i = 0; i < BP32_MAX_GAMEPADS; i++) {
    if (myGamepads[i] == gp) {
      Serial.printf("CALLBACK: Gamepad is disconnected from index=%d\n", i);
      myGamepads[i] = nullptr;
      foundGamepad = true;
      break;
    }
  }

  if (!foundGamepad) {
    Serial.println(
        "CALLBACK: Gamepad disconnected, but not found in myGamepads");
  }
}

int lx =0;
int ly =0;
int lbup = 0;
int lbdown = 0;
int lbleft = 0;
int lright = 0;
int dpad = 0;
int ldpad = 0;
int lry = 0;
int lrx = 0;

void setup() {
  Serial.begin(9600);
  pinMode(17, OUTPUT);
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
  pinMode(15, OUTPUT);
  pinMode(2, OUTPUT);
  pinMode(18, OUTPUT);
  pinMode(23, OUTPUT);
  digitalWrite(15, LOW);
  digitalWrite(2, LOW);
  digitalWrite(18, LOW);
  digitalWrite(23, LOW);
  delay(500);
  Wire.begin(4,5);


  digitalWrite(15, HIGH);
  delay(150);
  Serial.println("00");
  sensor.init(true);

  Serial.println("01");
  delay(100);
  sensor.setAddress((uint8_t)01);
  Serial.println("02");

  digitalWrite(2, HIGH);
    delay(150);
  sensor2.init(true);
  Serial.println("03");
  delay(100);
  sensor2.setAddress((uint8_t)02);
  Serial.println("04");
  
  digitalWrite(18, HIGH);
  delay(150);
  sensor3.init(true);
  Serial.println("05");
  delay(100);
  sensor3.setAddress((uint8_t)03);
  Serial.println("06");
  
  digitalWrite(23, HIGH);
  delay(150);
  Serial.println("07");
  sensor4.init(true);

  Serial.println("08");
  delay(100);
  sensor4.setAddress((uint8_t)04);
  Serial.println("09");
  
  digitalWrite(15, HIGH);
  delay(150);
  Serial.println("10");
  


  Serial.println("addresses set");

  sensor.startContinuous();
  sensor2.startContinuous();
  sensor3.startContinuous(); 
  sensor4.startContinuous();

  BP32.setup(&onConnectedGamepad, &onDisconnectedGamepad);

  BP32.forgetBluetoothKeys();

}


void loop() {

  if (Serial.available() > 0) {
    command = Serial.read();

    switch (command) {
      case 'w':
        while (Serial.read() != 'q') {
          Serial.println("sin sensor on");
          sen();
        }
        break;
      case 'e':
        while (Serial.read() != 'q') {
          Serial.println("controller on");
          digitalWrite(17, HIGH);
          BP32.update();
          for (int i = 0; i < BP32_MAX_GAMEPADS; i++) {
            GamepadPtr myGamepad = myGamepads[i];

            if (myGamepad && myGamepad->isConnected()) {

              lx = myGamepad->axisX();
              ly = myGamepad->axisY();
              lrx = myGamepad->axisRX();
              lry = myGamepad->axisRY();
              lbup = 0;
              lbdown = 0;
              lbleft = 0;
              lright = 0;
              dpad = myGamepad->buttons();
              ldpad = myGamepad->dpad();
              
              
              Serial.print(dpad);
              if(dpad==4){
                Serial.print("down");
                move();

              }
              if(dpad==8){
                Serial.print("cmu");
                cmu();
              }
              if(dpad==32){
                Serial.print("nin");
                nin();

              }
              if(dpad==128){
                Serial.print("sin");
                sin();

              }
              if(dpad==16){
                Serial.print("left up");

              }
              if(dpad==64){
                Serial.print("left down");

              }

              if(dpad==1){
                Serial.print("rolling");
                rolling();

              }
              if(ly<-200){
                forward();
              }
              if(ly>200){
                backward();
              }
              if(lry<-200){

                tunnel();
              }
              
              Serial.println(dpad);
            }
          }

          delay(15);
        }
        break;
      case 'r':
        Serial.println("sensor ploting on");
        while (Serial.read() != 'q') {
          Serial.print("HELLO");
        }
        break;
    }
  }
  four_sen();
}


void move() {
  int a = 120;
  int b= 40;
  int c = 100;

  for (int i = 0; i < 11; i++) {
    servos[i].write(a);
    delay(c);
  }
  for (int i = 0; i < 11; i++) {
    servos[i].write(b);
    delay(c);
  }
}

void cmu(){

  unsigned long t = millis();

  // Move each servo in a sine wave pattern
  for (int i = 0; i < 11; i++) {
    int angle = 90 + 45 * sin(2 * PI * t / 1000 + offsets[i]);  // Adjust the parameters as needed
    servos[i].write(angle);
  }

  delay(200);  // Wait a short time before the next update

}


void sen(){
  a=sensor.readRangeContinuousMillimeters();
  digitalWrite(17, HIGH);

  if(a<300){
    value = map(a,0,300,80,130);
    Serial.println(value);
    servos[0].write(map(a,0,300,85,120));
    servos[1].write(90);
    servos[2].write(map(a,0,300,70,130));
    servos[3].write(180-(map(a,0,300,70,130)));
    servos[4].write(map(a,0,300,70,130));
    servos[5].write(180-(map(a,0,300,70,130)));
    servos[6].write(map(a,0,300,70,130));
    servos[7].write(180-(map(a,0,300,70,130)));
    servos[8].write(map(a,0,300,70,130));
    servos[9].write(180-(map(a,0,300,70,130)));
    servos[10].write(map(a,0,300,70,130));
  }
  digitalWrite(17, LOW);
}

void four_sen(){
  digitalWrite(17, HIGH);
  a=sensor.readRangeContinuousMillimeters();
  b=sensor2.readRangeContinuousMillimeters();
  c=sensor3.readRangeContinuousMillimeters();
  d=sensor4.readRangeContinuousMillimeters();
  if(a<200){
    Serial.print(a);
    Serial.print(",");
  }
  else{
    Serial.print(200);
    Serial.print(",");
  }
  if(b<200){
    Serial.print(b);
    Serial.print(",");
  }
  else{
    Serial.print(200);
    Serial.print(",");
  }
  if(c<200){
    Serial.print(c);
    Serial.print(",");
  }
  else{
    Serial.print(200);
    Serial.print(",");
  }
  if(d<200){
    Serial.println(d);
  }
  else{
    Serial.println(200);
  }
    digitalWrite(17, LOW);
    delay(300);
}

void nin(){
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
void sin(){
  int a = 135;
  int b = 45;
  servos[0].write(a);
  servos[1].write(b);
  servos[2].write(a);
  servos[3].write(b);
  servos[4].write(a);
  servos[5].write(b);
  servos[6].write(a);
  servos[7].write(b);
  servos[8].write(a);
  servos[9].write(b);
  servos[10].write(a);
}

void rolling(){
  int offsets[] = {0, 45, 90, 135, 180, 225, 270, 315, 360, 405, 450};
  unsigned long t = millis();
  for (int i = 0; i < 11; i++) {
    int angle;
    if (i % 2 == 0) {
      angle = 90 + 45 * sin(2 * PI * t / 1000 + offsets[i]);  
    } else {
      angle = 90 + 45 * sin(2 * PI * t / 1000 + offsets[i] + PI / 2);  
    }
    servos[i].write(angle);
  }

  delay(20); 
  
}

void forward(){
  for (int i = 0; i < 11; i++) {
    int angle;
    if (i % 2 == 0) {
      angle = 120;  
    } else {
      angle = 60;  
    }
    servos[i].write(angle);
    delay(100);
  }
  for (int i = 0; i < 11; i++) {
    int angle;
    if (i % 2 == 0) {
      angle = 60;  
    } else {
      angle = 120;  
    }
    servos[i].write(angle);
    delay(100);
  }

}

void backward(){
  int angles[11] = {45, 45, 45, 45, 45, 45, 45, 45, 45, 45, 45};
  for (int i = 0; i < 11; i++) {
    int angle = angles[i] + sin(millis() / 200.0 + i) * 45; 
    servos[i].write(angle);  
    delay(15);  
  }
}

void tunnel(){
  for (int i = 0; i < 11; i++) {
    int angle;
    if (i % 2 == 0) {
      angle = 120;  
    } else {
      angle = 180-40;  
    }
    servos[i].write(angle);
    delay(60);
  }
  for (int i = 0; i < 11; i++) {
    int angle;
    if (i % 2 == 0) {
      angle = 40;  
    } else {
      angle = 180-120;  
    }
    servos[i].write(angle);
    delay(60);
  }

}
