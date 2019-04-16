#include "nRF24L01.h"
#include "RF24.h"
#include "Servo.h"
Servo motor;
int ENMotopin1 = 5;
int motor1ileri=2;
int motor1geri=3;
int ENMotopin2 = 6;
int motor2ileri=4;
int motor2geri=10;
int veri[3];
RF24 radio(8,7);
const uint64_t eslesme = 0xE8E8F0F0E1LL;
void setup() {
pinMode(ENMotopin1, OUTPUT);
pinMode(motor1ileri, OUTPUT); 
pinMode(motor1geri, OUTPUT);
pinMode(ENMotopin2, OUTPUT); 
pinMode(motor2ileri, OUTPUT);
pinMode(motor2geri, OUTPUT); 
motor.attach(9);
radio.begin();
radio.openReadingPipe(1, eslesme);
radio.startListening();
}
void loop() {
if (radio.available()){
bool done=false;
while (!done){
done=radio.read(veri, sizeof(veri));
veri[0]= map(veri[0],0,1023,0,180);
motor.write(veri[0]);
veri[2]= map(veri[2],0,1024,0,10);
int PotDeger=map(veri[1],0,1024,0,255);

if(veri[2]<5){
analogWrite(ENMotopin1,PotDeger);
analogWrite(ENMotopin2,PotDeger);
digitalWrite(2,0);
digitalWrite(3,1);
digitalWrite(4,0);
digitalWrite(10,1);
}
if(veri[2]>5){
analogWrite(ENMotopin2,PotDeger);
analogWrite(ENMotopin1,PotDeger);
digitalWrite(2,1);
digitalWrite(3,0);
digitalWrite(4,1);
digitalWrite(10,0);
}
else if(veri[2]==5){
analogWrite(ENMotopin2, 0);
analogWrite(ENMotopin1, 0);
digitalWrite(2,0);
digitalWrite(3,0);
digitalWrite(4,0);
digitalWrite(10,0);
}
}
}
}
