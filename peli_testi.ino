
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
pinMode(A1,INPUT);
pinMode(A2,INPUT);
pinMode(A3,INPUT);

}

ISR (TIMER0_COMPA_vect) 
{
  if(testi.aikaObjekti.yleinenAika == true) {
    testi.aikaObjekti.keskeytysMillis++;
  }
}


void loop() {
  
if (testi.init == 0)
{
testi.gameBegin();
}

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
  if (testi.aikaObjekti.aikaSec > 0 || testi.aikaObjekti.aikaMin > 0)
  {
testi.game1();
testi.game2();
testi.game3();
//Serial.println(testi.aikaObjekti.aikaSec);
  }
if (testi.playNumber == 4)
{
 testi.aikaObjekti.yleinenAika = false;
 testi.gameOver = 1;
}


  if (testi.aikaObjekti.aikaSec <= 0 && testi.aikaObjekti.aikaMin <= 0)
  {
  Serial.println("TIME UP");
  testi.aikaObjekti.yleinenAika = false;
  testi.outOfTime();
  }
    if (testi.aikaObjekti.aikaSec > 0 && testi.gameOver == 1|| testi.aikaObjekti.aikaMin > 0 && testi.gameOver == 1)
  {
    Serial.println("WINNER");
//    testi.lcdObjekti.winner();
  }
}


}
if (testi.gameOver == 1)
{
  testi.winner();
 
}
}
