# Mystery-Cube-Quest
coder Jani Sivonen

code is one part of bigger program for school project. 

Board in project is Arduino Mega 2560

lcd.cpp + lcd.h is driver for 2x16 lcd display
aika.cpp + aika.h is for time management in project

main.cpp is this moment only for testing valid c++ language in files

inside .ino file is:
#include "lcd.h"

LCD testi;
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
pinMode(testi.resetPin, OUTPUT);
pinMode(testi.dataShift1, OUTPUT);
pinMode(testi.dataShift2, OUTPUT);
pinMode(testi.dataShift1, OUTPUT);
pinMode(testi.rsPin, OUTPUT);
pinMode(testi.rwPin, OUTPUT);
pinMode(testi.clockPin, OUTPUT);


}

void loop() {


// put your main code here, to run repeatedly:
testi.sendData(0x00,1);
delay(100);
testi.sendData(0xFF,1);
}
// put your main code here, to run repeatedly:

}
