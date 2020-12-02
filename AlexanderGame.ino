//LED pinnien asetus
const int ledOut1 = 30;
const int ledOut2 = 32;
const int ledOut3 = 34;
const int ledOut4 = 36;
//const int loseLed = 10;

//led tarkistus
int led1 = 0;
int led2 = 0;
int led3 = 0;
int led4 = 0;

//Random
int randomArvo = random(1, 5);
int timerRANDOM;

//BUTTON pinnien asetus
const int nappi1 = 31;
const int nappi2 = 33;
const int nappi3 = 35;
const int nappi4 = 37;
//BUTTON stop painalus
int nappi1Stop = 1;
int nappi2Stop = 1;
int nappi3Stop = 1;
int nappi4Stop = 1;


//Taulukko ja muuttujat
int randomTable[5];
int buttonTable[5];
int randomVariable  = 1;
int buttonVariable  = 1;

//Game difficulty
int vaikeus = 0;
int vaikeusAika = 0;  //<-- if (vaikeus == 0) {vaikeusAika = 500}, if (vaikeus == 1) {vaikeusAika = 400} etc.
int vaikeusTarkistus = 0;
int game1Rounds = 0;

bool timerStopON = true; // <-- if true- timer doesn't work, false- start timer


//Keskeytyksen muuttujat
volatile unsigned long int timerMillis1RANDOM       = 0;
//volatile unsigned long int timerMillis1BUTTON     = 0;
//volatile unsigned long int timerMillis1LEDLOW     = 0;


//Keskeytys funktio
ISR(TIMER0_COMPA_vect) {
  if(timerStopON == false) {
    timerMillis1RANDOM++;
  }
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
    //pinMode(loseLed, OUTPUT);
//    digitalWrite(loseLed, LOW);
  
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


//Set all tables and table variables to low
void tableSet0()
{
  randomTable[0] = 0;
  randomTable[1] = 0;
  randomTable[2] = 0;
  randomTable[3] = 0;
  randomTable[4] = 0;
  
  buttonTable[0] = 0;
  buttonTable[1] = 0;
  buttonTable[2] = 0;
  buttonTable[3] = 0;
  buttonTable[4] = 0;
}

//Set all led to low
void ledSetLow() 
{
  digitalWrite(ledOut1, LOW);
  led1 = 0;
  digitalWrite(ledOut2, LOW);
  led2 = 0;
  digitalWrite(ledOut3, LOW);
  led3 = 0;
  digitalWrite(ledOut4, LOW);
  led4 = 0;
}

void peli1Funktio() 
{

  //Game difficulty
  if(vaikeus == 0)
  {
    vaikeusAika = 500;
  }
  else if(vaikeus == 1)
  {
    vaikeusAika = 400;
  }
  else if(vaikeus == 2)
  {
    vaikeusAika = 300;
  }
  
  
  
  //Kopioidan keskeytyksen muuttujat, koska me tarvitaan oikeat arvot. Jos ne käytetään heti, tulee väärit arvot ja sekoitaa kaikki
  cli();
  timerRANDOM = timerMillis1RANDOM;
  sei();
  

  //In table sets random numbers
  int randomArvo = random(1, 5);
  randomTable[randomVariable] = randomArvo;
  
  if(randomVariable < 5) {
    cli();
    timerStopON = false;
    sei();
  }
  
  //Starting give random numbers to randomTable
  if(timerRANDOM >= vaikeusAika 
     && randomVariable < 5
     && game1Rounds < 4 
     && led1 == 0
     && led2 == 0
     && led3 == 0
     && led4 == 0) 
  {
    
    //If random number = 1
    if(randomArvo == 1) 
    {
      digitalWrite(ledOut1, HIGH);
      led1 = 1;
      randomVariable++;
      
      cli();
      timerMillis1RANDOM = 0;
      sei();
    }
    
    //If random number = 2
    else if(randomArvo == 2) 
    {
      digitalWrite(ledOut2, HIGH);
      led2 = 1;
      randomVariable++;
      
      cli();
      timerMillis1RANDOM = 0;
      sei();
    }
    
    //If random number = 3
    else if(randomArvo == 3) 
    {
      digitalWrite(ledOut3, HIGH);
      led3 = 1;
      randomVariable++;
      
      cli();
      timerMillis1RANDOM = 0;
      sei();
    }
    
    //If random number = 4
    else if(randomArvo == 4)
    {
      digitalWrite(ledOut4, HIGH);
      led4 = 1;
      randomVariable++;
      
      cli();
      timerMillis1RANDOM = 0;
      sei();
    }
  }


  else if(timerRANDOM >= vaikeusAika)
  {
      if(randomVariable < 5) 
      {
        
        ledSetLow();
        cli();
        timerMillis1RANDOM = 0;
        sei();
      }
      
      if(randomVariable == 5) 
      {
        ledSetLow();
        Serial.println("HI");
        cli();
        timerMillis1RANDOM = 0;
        timerStopON = true;
        sei();
      }
  }
  
    
  Serial.println(timerRANDOM);

  
    //-> Button position checking
    //-> e.g if pressed button 2 and it's right, then it adds a +1 to the variable to continue table checking
    //-> If pressed button was not right then sets all variables = 1, and start again randomTable
    
    
    //If pressed button 1:
    if(digitalRead(nappi1) == LOW && nappi1Stop == 1) 
    {
      ledSetLow();
      nappi1Stop = 0;
    }
    
    if(digitalRead(nappi1) == HIGH && nappi1Stop == 0) 
    {
        buttonTable[buttonVariable] = 1;
        digitalWrite(ledOut1, HIGH);
        led1 = 1;
        nappi1Stop = 1;

        if(buttonTable[buttonVariable] == randomTable[buttonVariable]) 
        {
          buttonVariable++;
          vaikeusTarkistus++;
        }
        
        else if(buttonTable[buttonVariable] != randomTable[buttonVariable]) 
        {
          if(vaikeus > 0) {vaikeus--; vaikeusTarkistus = 0;}
          if(vaikeus == 0) {vaikeusTarkistus = 0;}
          if(vaikeusTarkistus > 0) {vaikeusTarkistus--;}
          if(vaikeusTarkistus == 0) {vaikeusTarkistus = 0;}
          
          cli();
          timerStopON = false;
          timerMillis1RANDOM = 0;
          sei();
          
          buttonVariable   = 1;
          randomVariable   = 1;
          
          tableSet0();
          if(game1Rounds > 0) {
            game1Rounds--;
          }
        }
    }
    
    
    
    //If pressed button 2:
    if(digitalRead(nappi2) == LOW && nappi2Stop == 1) 
    {
      ledSetLow();
      nappi2Stop = 0;
      
    }
    else if(digitalRead(nappi2) == HIGH && nappi2Stop == 0) 
    {
        buttonTable[buttonVariable] = 2;
        digitalWrite(ledOut2, HIGH);
        led2 = 1;
        nappi2Stop = 1;

        if(buttonTable[buttonVariable] == randomTable[buttonVariable]) 
        {
          buttonVariable++;
          vaikeusTarkistus++;
        }
        
        else if(buttonTable[buttonVariable] != randomTable[buttonVariable]) 
        {
          if(vaikeus = 0) {vaikeusTarkistus = 0;}
          if(vaikeus > 0) {vaikeus--; vaikeusTarkistus = 0;}
          if(vaikeusTarkistus > 0) {vaikeusTarkistus--;}
          if(vaikeusTarkistus == 0) {vaikeusTarkistus = 0;}

          cli();
          timerStopON = false;
          timerMillis1RANDOM = 0;
          sei();
          
          buttonVariable   = 1;
          randomVariable  = 1;
          
          tableSet0();
          if(game1Rounds > 0) {
            game1Rounds--;
          }
        }
     }
    
    
    
    //If pressed button 3:
    if(digitalRead(nappi3) == LOW && nappi3Stop == 1) 
    {
        nappi3Stop = 0;
        ledSetLow();
    }
    
    else if(digitalRead(nappi3) == HIGH && nappi3Stop == 0) 
    {
        buttonTable[buttonVariable] = 3;
        digitalWrite(ledOut3, HIGH);
        led3 = 1;
        nappi3Stop = 1;

              
        if(buttonTable[buttonVariable] == randomTable[buttonVariable]) 
        {
          buttonVariable++;
          vaikeusTarkistus++;
        }
        
        else if(buttonTable[buttonVariable] != randomTable[buttonVariable]) 
        {
          if(vaikeus = 0) {vaikeusTarkistus = 0;}
          if(vaikeus > 0) {vaikeus--; vaikeusTarkistus = 0;}
          if(vaikeusTarkistus > 0) {vaikeusTarkistus--;}
          if(vaikeusTarkistus == 0) {vaikeusTarkistus = 0;}
          
          cli();
          timerStopON = false;
          timerMillis1RANDOM = 0;
          sei();
          
          buttonVariable  = 1;
          randomVariable  = 1;
          
          tableSet0();
          if(game1Rounds > 0) {
            game1Rounds--;
          }
        }
     }
    
    
    
    
    
    
    //If pressed button 4:
    if(digitalRead(nappi4) == LOW && nappi4Stop == 1) 
    {
        nappi4Stop = 0;
        ledSetLow();
    }
    else if(digitalRead(nappi4) == HIGH && nappi4Stop == 0) 
    {
        buttonTable[buttonVariable] = 4;
        digitalWrite(ledOut4, HIGH);
        led4=1; 
        nappi4Stop = 1;
      
        if(buttonTable[buttonVariable] == randomTable[buttonVariable]) 
        {
          buttonVariable++;
          vaikeusTarkistus++;
        }
        
        else if(buttonTable[buttonVariable] != randomTable[buttonVariable]) 
        {
          if(vaikeus = 0) {vaikeusTarkistus = 0;}
          if(vaikeus > 0) {vaikeus--; vaikeusTarkistus = 0;}
          if(vaikeusTarkistus > 0) {vaikeusTarkistus--;}
          if(vaikeusTarkistus == 0) {vaikeusTarkistus = 0;}
          
          cli();
          timerStopON = false;
          timerMillis1RANDOM = 0;
          sei();
          
          buttonVariable   = 1;
          randomVariable   = 1;
          
          tableSet0();
          if(game1Rounds > 0) {
            game1Rounds--;
          }
        }
     }
    
    
    //If buttonTable last position is same that last position randomTable ->
    //-> Set table variables = 1, and all LED's to LOW
    //-> And increases the difficulty of the game
    if(vaikeusTarkistus == 4)
    {
      vaikeus++;
      game1Rounds++;
      vaikeusTarkistus = 0;
      randomVariable = 1;
      buttonVariable = 1;
      ledSetLow();
      tableSet0();
      
      cli();
      timerStopON = false;
      timerMillis1RANDOM = 0;
      sei();
    }
}
