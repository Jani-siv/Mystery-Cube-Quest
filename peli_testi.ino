
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
pinMode(testi.LCDOlio->enablePin2,OUTPUT);
pinMode(testi.gameButton,INPUT);

}

ISR (TIMER0_COMPA_vect) 
{
  if(testi.aikaObjekti.yleinenAika == true) {
    testi.aikaObjekti.keskeytysMillis++;
  }
}


void loop() {
  

testi.initGame();
Serial.println("game begins");
int button = digitalRead(testi.gameButton);
if (button == HIGH)
{
while (testi.gameOver != 1)
{
if(testi.aikaObjekti.yleinenAika == true) {
  testi.aikaObjekti.yleinenAikaFunktio(testi.LCDOlio);
}
//peli funktiot tähän ja jokaiselle oma numerointi ettei yritä kahta peliä yhtäaikaa käyntiin
testi.game1();
testi.game2();
testi.game3();
if (testi.playNumber == 4)
{
  //game over you win
  sei();
}
}
if (testi.aikaObjekti.yleinenAika == false)
{
  Serial.println("TIME UP");
  testi.outOfTime();
  unsigned int kokeilu = testi.LCDOlio->screenTable[0][1];

}
}
}

