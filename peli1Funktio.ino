//LED pinnien asetus
const int ledOut1 = 2;
const int ledOut2 = 3;
const int ledOut3 = 4;
const int ledOut4 = 5;
const int loseLed = 10;


//BUTTON pinnien asetus
const int nappi1 = 6;
const int nappi2 = 7;
const int nappi3 = 8;
const int nappi4 = 9;


//Taulukko ja muuttujat 
int randomTaulukkoTest[1][5];
int nappiTaulukkoTest[1][5];
int randomTaulukko   = 1;
int nappiTaulukko   = 1;

int vaikeus = 0;
int vaikeusTarkistus = 0;


//Tarkistukset, onko peli ja tarkoitetut funktiot päällä
bool peli1ON    = false;
bool peli1LedON   = false;
bool peli1ButtonON  = false;
//Ei käytetty vielä



//Keskeytyksen muuttujat
volatile unsigned long int timerMillis1RANDOM     = 0;
volatile unsigned long int timerMillis1BUTTON     = 0;
volatile unsigned long int timerMillis1LedUPDATE  = 0;



//Keskeytys funktio
ISR(TIMER0_COMPA_vect) {
  
    timerMillis1RANDOM++;
    timerMillis1BUTTON++;
    timerMillis1LedUPDATE++;
  
}


void setup() {
    //Keskeytys asetukset
    TCCR0A |= (1 << WGM01);
    OCR0A = 249;
    TIMSK0 |= (1 << OCIE0A);
    TCCR0B |= (1 << CS01) | (1 << CS00);
    sei();
  
  
  
    //Pinnien määrittely
    //1
    pinMode(ledOut1, OUTPUT);
    digitalWrite(ledOut1, LOW);
  
    //2
    pinMode(ledOut2, OUTPUT);
    digitalWrite(ledOut2, LOW);
  
    //3
    pinMode(ledOut3, OUTPUT);
    digitalWrite(ledOut3, LOW);
  
    //4
    pinMode(ledOut4, OUTPUT);
    digitalWrite(ledOut4, LOW);
  
    //LoseLed
    pinMode(loseLed, OUTPUT);
    digitalWrite(loseLed, LOW);
  
    //Nappit
    pinMode(nappi1, INPUT);
    pinMode(nappi2, INPUT);
    pinMode(nappi3, INPUT);
    pinMode(nappi4, INPUT);
  
    randomSeed(analogRead(0));
    Serial.begin(9600);
}



void loop() 
{
  peli1Funktio();
}



void peli1Funktio() 
{
  
  //Kopioidan keskeytyksen muuttujat, koska me tarvitaan oikeat arvot. Jos ne käytetään heti, tulee väärit arvot ja sekoitaa kaikki
  cli();
  int randomAika = timerMillis1RANDOM;
  int buttonAika = timerMillis1BUTTON;
  int ledUpdate  = timerMillis1LedUPDATE;
  sei();


  //
  int randomArvo = random(1, 5);
  randomTaulukkoTest[0][randomTaulukko] = randomArvo;
  
  
  if(randomAika >= 500 && randomTaulukko < 5) {
    
    if(randomArvo == 1 && digitalRead(ledOut1) == LOW) {
      digitalWrite(ledOut1, HIGH);
        randomTaulukko++;
      cli();
      timerMillis1RANDOM = 0;
        sei();
    }
    else if(randomArvo == 2 && digitalRead(ledOut2) == LOW) {
      digitalWrite(ledOut2, HIGH);
      randomTaulukko++;
        cli();
      timerMillis1RANDOM = 0;
      sei();
    } 
    else if(randomArvo == 3 && digitalRead(ledOut3) == LOW) {
      digitalWrite(ledOut3, HIGH);
      randomTaulukko++;
        cli();
      timerMillis1RANDOM = 0;
      sei();
    }
    else if(randomArvo == 4 && digitalRead(ledOut4) == LOW){
      digitalWrite(ledOut4, HIGH);    
      randomTaulukko++;
        cli();
      timerMillis1RANDOM = 0;
      sei();
    }
    
    Serial.print(randomTaulukkoTest[0][1]);
    Serial.print(randomTaulukkoTest[0][2]);
    Serial.print(randomTaulukkoTest[0][3]);
    Serial.println(randomTaulukkoTest[0][4]);
  }
  
  if(ledUpdate >= 500 && randomTaulukko == 5 && nappiTaulukko == 1) {
    digitalWrite(ledOut1, LOW);
    digitalWrite(ledOut2, LOW);
    digitalWrite(ledOut3, LOW);
    digitalWrite(ledOut4, LOW);
    cli();
    timerMillis1LedUPDATE = 0;
    sei();
  }
  
  if(randomAika >= 150 && randomTaulukko == 5) {
    
  Serial.print(nappiTaulukkoTest[0][1]);
    Serial.print(nappiTaulukkoTest[0][2]);
    Serial.print(nappiTaulukkoTest[0][3]);
    Serial.println(nappiTaulukkoTest[0][4]);
    
    
    
    if(digitalRead(nappi1) == HIGH) {
        nappiTaulukkoTest[0][nappiTaulukko] = 1;
        digitalWrite(ledOut1, HIGH);
      
        if(nappiTaulukkoTest[0][nappiTaulukko] != randomTaulukkoTest[0][nappiTaulukko]) {
          if(vaikeus = 0) {vaikeusTarkistus = 0;}
          if(vaikeus > 0) {vaikeus--; vaikeusTarkistus = 0;}
          
          nappiTaulukko   = 1;
          randomTaulukko  = 1;
        }
        if(nappiTaulukkoTest[0][nappiTaulukko] == randomTaulukkoTest[0][nappiTaulukko]) {
          nappiTaulukko++;
          vaikeusTarkistus++;
        }
    }
    
    
    
    
    
    else if(digitalRead(nappi2) == HIGH) {
      nappiTaulukkoTest[0][nappiTaulukko] = 2;
      digitalWrite(ledOut2, HIGH);
      
            
        if(nappiTaulukkoTest[0][nappiTaulukko] != randomTaulukkoTest[0][nappiTaulukko]) {
          if(vaikeus = 0) {vaikeusTarkistus = 0;}
          if(vaikeus > 0) {vaikeus--; vaikeusTarkistus = 0;}
          
          nappiTaulukko   = 1;
          randomTaulukko  = 1;
          
        }
        if(nappiTaulukkoTest[0][nappiTaulukko] == randomTaulukkoTest[0][nappiTaulukko]) {
          nappiTaulukko++;
          vaikeusTarkistus++;
        }
    }
    
    
    
    
    
    
    else if(digitalRead(nappi3) == HIGH) {
      nappiTaulukkoTest[0][nappiTaulukko] = 3;
      digitalWrite(ledOut3, HIGH);
      
        if(nappiTaulukkoTest[0][nappiTaulukko] != randomTaulukkoTest[0][nappiTaulukko]) {
          if(vaikeus = 0) {vaikeusTarkistus = 0;}
          if(vaikeus > 0) {vaikeus--; vaikeusTarkistus = 0;}
          
          nappiTaulukko   = 1;
          randomTaulukko  = 1;
        }
        if(nappiTaulukkoTest[0][nappiTaulukko] == randomTaulukkoTest[0][nappiTaulukko]) {
          nappiTaulukko++;
          vaikeusTarkistus++;
        }
    }
    
    
    
    
    
    
    else if(digitalRead(nappi4) == HIGH) {
      nappiTaulukkoTest[0][nappiTaulukko] = 4;
      digitalWrite(ledOut4, HIGH);
      
        if(nappiTaulukkoTest[0][nappiTaulukko] != randomTaulukkoTest[0][nappiTaulukko]) {
          if(vaikeus = 0) {vaikeusTarkistus = 0;}
          if(vaikeus > 0) {vaikeus--; vaikeusTarkistus = 0;}
          
          nappiTaulukko   = 1;
          randomTaulukko  = 1;
        }
        if(nappiTaulukkoTest[0][nappiTaulukko] == randomTaulukkoTest[0][nappiTaulukko]) {
          nappiTaulukko++;
          vaikeusTarkistus++;
        }
    }
    
    
    
    if(nappiTaulukkoTest[0][4] == randomTaulukkoTest[0][4] && vaikeusTarkistus == 4) {
      vaikeus++;
      vaikeusTarkistus = 0;
      randomTaulukko = 1;
      nappiTaulukko = 1;
      digitalWrite(ledOut1, LOW);
      digitalWrite(ledOut2, LOW);
      digitalWrite(ledOut3, LOW);
      digitalWrite(ledOut4, LOW);
    }
    
    cli();
    timerMillis1RANDOM = 0;
    sei();
  }
}
