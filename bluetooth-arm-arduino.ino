#include <SoftwareSerial.h>
#include <Servo.h>
 
const int pinoRX = 10; //2 (RX)
const int pinoTX = 11; //3 (TX)
const int servoa = 9;
const int servob = 8;
const int servoc = 7;
const int servod = 6;
const int led = 5;
int dadoBluetooth = 0;
boolean loopLED = false;

Servo sa;
Servo sb;
Servo sc;
Servo sd;
int pa = 90;
int pb = 120;
int pc = 100;
int pd = 140;
 
SoftwareSerial bluetooth(pinoRX, pinoTX);
 
void setup(){
  Serial.begin(9600);
  bluetooth.begin(9600);
  bluetooth.print("$");
  bluetooth.print("$");
  bluetooth.print("$");
  delay(100);
  pinMode (led, OUTPUT);
  spa(true);
  spb(true);
  spc(true);
  spd(true);
  Serial.print("Setup");
  TIMSK0=0;
}

void ledi(){
      digitalWrite(led, HIGH);
      delay(200);
      digitalWrite(led, LOW);
      delay(200);
}
 
void loop(){
  if(bluetooth.available()){
       dadoBluetooth = bluetooth.read();
       Serial.print("Connected");
    if(dadoBluetooth == 'w'){
      Serial.println("W");
     if(pa < 180) {
        pa = pa + 30;
        spa(false);
      ledi();
      }
    }
    if(dadoBluetooth == 's'){
      Serial.println("S");
      if(pa >= 0) {
      pa = pa - 30;
      spa(false);
      ledi();
      }
    }
    if(dadoBluetooth == 'a'){
      Serial.println("A");
      if(pb < 180) {
        pb = pb + 20;
        spb(false);
      ledi();
      }
    }
    if(dadoBluetooth == 'd'){
      Serial.println("D");
      if(pb >= 100) {
      pb = pb - 20;
      spb(false);
      ledi();
      }
    }
    if(dadoBluetooth == 't'){
      Serial.println("T");
     if(pc < 180) {
        pc = pc + 20;
        spc(false);
      ledi();
      }
    }
    if(dadoBluetooth == 'g'){
      Serial.println("G");
      if(pc >= 100) {
      pc = pc - 20;
      spc(false);
      ledi();
      }
    }
    if(dadoBluetooth == 'f'){
      Serial.println("F");
      if(pd < 140) {
        pd = pd + 20;
        spd(false);
      ledi();
      }
    }
    if(dadoBluetooth == 'h'){
      Serial.println("H");
      if(pd >= 60) {
      pd = pd - 20;
      spd(false);
      ledi();
      }
    }
  }
  
}

void spa(bool set) {
    if (set) {
      sa.attach(servoa);
      delay(100);
    }
    sa.write(pa); // 90
    delay(100);
    sa.detach();
    delay(100);
    sa.attach(servoa);
    delay(100);
    sa.write(pa); // 90
  }

  void spb(bool set) {
    if (set) {
      sb.attach(servob);
      delay(100);
    }
    sb.write(pb); //90 180
    delay(100);
    sb.detach();
    delay(100);
    sb.attach(servob);
    delay(100);
    sb.write(pb); //90 180
  }

  void spc(bool set) {
    if (set) {
      sc.attach(servoc);
      delay(100);
    }
    sc.write(pc); //30
    delay(100);
    sc.detach();
    delay(100);
    sc.attach(servoc);
    delay(100);
    sc.write(pc); //30
  }

  void spd(bool set) {
    if (set) {
      sd.attach(servod);
      delay(100);
    }
    sd.write(pd); //0
    delay(100);
    sd.detach();
    delay(100);
    sd.attach(servod);
    delay(100);
    sd.write(pd); //0
  }
