#include "nRF24L01.h"
#include "RF24.h"
int veri[3];
RF24 radio(8,7);
const uint64_t eslesme = 0xE8E8F0F0E1LL;
#define joysticksol_x A0  
//#define joysticksol_y A1 
#define pot A2
//#define joysticksag_x A4 
#define joysticksag_y A5
//#define butonsol A6
//#define butonsag A7

void setup() {
radio.begin();
radio.openWritingPipe(eslesme);
}

void loop() {
veri[0]=analogRead(joysticksag_y);
veri[1]=analogRead(pot); 
veri[2]=analogRead(joysticksol_x);
//veri[3]=analogRead(joysticksag_x);
//veri[4]=analogRead(joysticksol_y); 
//veri[5]=analogRead(butonsag);
//veri[6]=analogRead(butonsol);  
radio.write(veri ,sizeof(veri));
}
