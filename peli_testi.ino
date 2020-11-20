
#include "aika.h"
#include "lcd.h"
#include "game.h"
game testi;
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
  TCCR0A |= (1 << WGM01);
  OCR0A = 249;
  TIMSK0 |= (1 << OCIE0A);
  TCCR0B |= (1 << CS01) | (1 << CS00);
  sei();


pinMode(testi.LCDOlio->clockPin, OUTPUT);
pinMode(testi.LCDOlio->SRCLR, OUTPUT);
pinMode(testi.LCDOlio->RCLK,OUTPUT);
pinMode(testi.LCDOlio->SER, OUTPUT);
pinMode(testi.LCDOlio->OE, OUTPUT);
pinMode(testi.LCDOlio->enablePin, OUTPUT);
pinMode(testi.LCDOlio->rsPin, OUTPUT);


}

ISR (TIMER0_COMPA_vect) 
{
 // if(testi.aikaObjekti.yleinenAika == true) {
   // testi.aikaObjekti.keskeytysMillis++;
  }
//}


int kymmin = 0;
int minuutit = 1;
int kymsek = 0;
int sekunnit = 0;

unsigned int i = 0x00;
int roundNumber = 0;
int upd = 0;
void loop() {
  

testi.gameBegin();

//if(testi.aikaObjekti.yleinenAika == true) {
 // testi.aikaObjekti.yleinenAikaFunktio(testi.LCDOlio);
}

/*

    delay(500);
  if (sekunnit > 0)
  {
    sekunnit--;
  }
  else if (sekunnit == 0 && kymsek > 0)
  {
    sekunnit = 9;
    kymsek--;
  }
  else if (kymsek == 0 && minuutit > 0)
  {
  kymsek = 5;
  minuutit--;  
  }
  else if (minuutit == 0 && kymmin >0)
  {
    kymmin--;
    minuutit = 9;
    kymsek = 5;
    sekunnit = 9;
  }
  else if (kymmin == 0 && minuutit == 0 && kymsek == 0 && sekunnit == 0)
  {
    kymmin = 1;
  }
  testi.LCDOlio->updateTime(kymmin, minuutit, kymsek, sekunnit);

*/
//  }
