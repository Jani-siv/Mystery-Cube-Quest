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
int randomTable[5];
int buttonTable[5];
int randomVariable  = 1;
int buttonVariable  = 1;

//Ei käytetty vielä
int vaikeus = 0;
int vaikeusAika = 0;  //<-- if (vaikeus == 0) {vaikeusAika = 500}, if (vaikeus == 1) {vaikeusAika = 400} etc.
int vaikeusTarkistus = 0;


//Tarkistukset, onko peli ja tarkoitetut funktiot päällä
bool peli1ON        = false;
bool peli1LedON     = false;
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
  //Check game difficulty
  if(vaikeus == 1) 
  {
    vaikeusAika = 500;
  }
  else if(vaikeus == 2)
  {
    vaikeusAika = 400;
  }
  else if(vaikeus == 3)
  {
    vaikeusAika = 300;
  }
  else if(vaikeus > 3)
  {
    vaikeusAika = 500;
    Serial.println("Something wrong with game difficulty");
    vaikeus = 0;
  }
  
  
  //Kopioidan keskeytyksen muuttujat, koska me tarvitaan oikeat arvot. Jos ne käytetään heti, tulee väärit arvot ja sekoitaa kaikki
  cli();
  int randomAika = timerMillis1RANDOM;
  int buttonAika = timerMillis1BUTTON;
  int ledUpdate  = timerMillis1LedUPDATE;
  sei();


  //In table sets random numbers
  int randomArvo = random(1, 5);
  randomTable[randomVariable] = randomArvo;
  
  
  if(randomAika >= vaikeusAika && randomVariable < 5) 
  {
    
    //If button 1 pressed: LED 1 lights up
    if(randomArvo == 1 && digitalRead(ledOut1) == LOW) 
    {
      digitalWrite(ledOut1, HIGH);
      randomVariable++;
      
      cli();
      timerMillis1RANDOM = 0;
      sei();
    }
    
    //If button 2 pressed: LED 2 lights up
    else if(randomArvo == 2 && digitalRead(ledOut2) == LOW) 
    {
      digitalWrite(ledOut2, HIGH);
      randomVariable++;
      
      cli();
      timerMillis1RANDOM = 0;
      sei();
    }
    
    //If button 3 pressed: LED 3 lights up
    else if(randomArvo == 3 && digitalRead(ledOut3) == LOW) 
    {
      digitalWrite(ledOut3, HIGH);
      randomVariable++;
      
      cli();
      timerMillis1RANDOM = 0;
      sei();
    }
    
    //If button 4 pressed: LED 4 lights up
    else if(randomArvo == 4 && digitalRead(ledOut4) == LOW)
    {
      digitalWrite(ledOut4, HIGH);    
      randomVariable++;
      
      cli();
      timerMillis1RANDOM = 0;
      sei();
    }
  }
  
  
  //If time 500ms, previously table is full and next table empty, then set all LED get LOW
  if(ledUpdate >= 500 && randomVariable == 5 && buttonVariable == 1) 
  {
    digitalWrite(ledOut1, LOW);
    digitalWrite(ledOut2, LOW);
    digitalWrite(ledOut3, LOW);
    digitalWrite(ledOut4, LOW);
    
    cli();
    timerMillis1LedUPDATE = 0;
    sei();
  }
  
  
  
  //If time is 150ms and previously table (randomTable) is full->
  //-> Button position checking
  //-> e.g if pressed button 2 and it's right, then it adds a +1 to the variable to continue table checking
  //-> If pressed button was not right then sets LED to LOW if it was HIGH, sets all variables = 0, and start again randomTable
  if(randomAika >= 150 && randomVariable == 5) 
  {
    
    //Test-text on serial monitor
    Serial.print(randomTable[1]);
    Serial.print(randomTable[2]);
    Serial.print(randomTable[3]);
    Serial.print(randomTable[4]);
    
    //If pressed button 1:
    if(digitalRead(nappi1) == HIGH) 
    {
        buttonTable[buttonVariable] = 1;
        digitalWrite(ledOut1, HIGH);
      
        if(buttonTable[buttonVariable] != buttonTable[buttonVariable]) 
        {
          if(vaikeus = 0) {vaikeusTarkistus = 0;}
          if(vaikeus > 0) {vaikeus--; vaikeusTarkistus = 0;}
          
          buttonVariable   = 1;
          randomVariable  = 1;
          
          digitalWrite(ledOut1, LOW);
          digitalWrite(ledOut2, LOW);
          digitalWrite(ledOut3, LOW);
          digitalWrite(ledOut4, LOW);
          
        }
    
        if(buttonTable[buttonVariable] == randomTable[buttonVariable]) 
        {
          buttonVariable++;
          vaikeusTarkistus++;
        }
     }
    
    
    
    //If pressed button 2:
    else if(digitalRead(nappi2) == HIGH) 
    {
      buttonTable[buttonVariable] = 2;
      digitalWrite(ledOut2, HIGH);
      
            
        if(buttonTable[buttonVariable] != randomTable[randomVariable]) 
        {
          if(vaikeus = 0) {vaikeusTarkistus = 0;}
          if(vaikeus > 0) {vaikeus--; vaikeusTarkistus = 0;}
          
          buttonVariable   = 1;
          randomVariable  = 1;
          
          digitalWrite(ledOut1, LOW);
          digitalWrite(ledOut2, LOW);
          digitalWrite(ledOut3, LOW);
          digitalWrite(ledOut4, LOW);
          
          
        }
      
        if(buttonTable[buttonVariable] == randomTable[buttonVariable]) 
        {
          buttonVariable++;
          vaikeusTarkistus++;
        }
     }
    
    
    
    
    
    //If pressed button 3:
    else if(digitalRead(nappi3) == HIGH) 
    {
      buttonTable[buttonVariable] = 3;
      digitalWrite(ledOut3, HIGH);
      
        if(buttonTable[buttonVariable] != randomTable[buttonVariable]) 
        {
          if(vaikeus = 0) {vaikeusTarkistus = 0;}
          if(vaikeus > 0) {vaikeus--; vaikeusTarkistus = 0;}
          
          buttonVariable  = 1;
          randomVariable  = 1;
          
          digitalWrite(ledOut1, LOW);
          digitalWrite(ledOut2, LOW);
          digitalWrite(ledOut3, LOW);
          digitalWrite(ledOut4, LOW);
          
        }
      
        if(buttonTable[buttonVariable] == randomTable[buttonVariable]) 
        {
          buttonVariable++;
          vaikeusTarkistus++;
        }
     }
    
    
    
    
    
    //If pressed button 4:
    else if(digitalRead(nappi4) == HIGH) 
    {
      buttonTable[buttonVariable] = 4;
      digitalWrite(ledOut4, HIGH);
      
        if(buttonTable[buttonVariable] != randomTable[buttonVariable]) 
        {
          if(vaikeus = 0) {vaikeusTarkistus = 0;}
          if(vaikeus > 0) {vaikeus--; vaikeusTarkistus = 0;}
          
          buttonVariable   = 1;
          randomVariable   = 1;
          
          digitalWrite(ledOut1, LOW);
          digitalWrite(ledOut2, LOW);
          digitalWrite(ledOut3, LOW);
          digitalWrite(ledOut4, LOW);
          
        }
      
        if(buttonTable[buttonVariable] == randomTable[buttonVariable]) 
        {
          buttonVariable++;
          vaikeusTarkistus++;
        }
     }
    
    
    //If buttonTable last position is same that last position randomTable ->
    //-> Set table variables = 1, and all LED's to LOW
    //-> And increases the difficulty of the game (not ready yet)
    if(buttonTable[4] == randomTable[4] && vaikeusTarkistus == 4) 
    {
      vaikeus++;
      vaikeusTarkistus = 0;
      randomVariable = 1;
      buttonVariable = 1;
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
