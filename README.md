# Mystery-Cube-Quest
coder Jani Sivonen

code is one part of bigger program for school project. 

******COMPONENTS FOR PROJECT********

****Board in project is Arduino Mega 2560
PIN setup
look lcd.h shift register pin out for lcd screen

****Shift register before LCD screen is CD74HC595N
PIN setup
15 && 1-7 output
8 GND
10 SRCLR LOW clear register
11 SRCLK rising edge of clock data stored in register
12 RCKL rising edge of RCKL data srored in the storage register
if setting both clock tight together shift register going one step ahead.
13 OE LOW all OUTPUTS are enabled HIGH all OUTPUTS are disabled
14 SER data input

************FILES FOR PROJECT***********
lcd.cpp + lcd.h is driver for 2x16 lcd display
aika.cpp + aika.h is for time management in project


inside .ino file is:
#include "lcd.h"

LCD testi;
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
pinMode(testi.resetPin, OUTPUT);
pinMode(testi.dataShift1, OUTPUT);
pinMode(testi.dataShift2, OUTPUT);
pinMode(testi.enablePin, OUTPUT);
pinMode(testi.rsPin, OUTPUT);
pinMode(testi.rwPin, OUTPUT);
pinMode(testi.clockPin, OUTPUT);


}

void loop() {


// put your main code here, to run repeatedly:
if (testi.reset == 0)
{ testi.lcd_init();
}

