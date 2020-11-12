# Mystery-Cube-Quest
coder Jani Sivonen

code is one part of bigger program for school project. 

Board in project is Arduino Mega 2560

lcd.cpp + lcd.h is driver for 2x16 lcd display
aika.cpp + aika.h is for time management in project

main.cpp is this moment only for testing valid c++ language in files

inside .ino file is:
#include "lcd.h"

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
}

void loop() {
 LCD testi;
 
 if (testi.reset == 0)
  {
  testi.lcd_init();
  }
// put your main code here, to run repeatedly:

}
