//LED pinnien asetus
const int ledOut1 = 2;
const int ledOut2 = 3;
const int ledOut3 = 4;
const int ledOut4 = 5;
const int loseLed = 10;

//led tarkistus
int led1 = 0;
int led2 = 0;
int led3 = 0;
int led4 = 0;


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
int vaikeusAika = 0;  //<-- if (vaikeus == 0) {vaikeusAika = 300}, if (vaikeus == 1) {vaikeusAika = 200} etc.
int vaikeusTarkistus = 0;
int game1Rounds = 0;

//Tarkistukset, onko peli ja tarkoitetut funktiot päällä
bool peli1ON        = false;
bool peli1RandomON  = false;
bool peli1ButtonON  = false;
//Ei käytetty vielä



//Keskeytyksen muuttujat
volatile unsigned long int timerMillis1RANDOM     = 0;
volatile unsigned long int timerMillis1BUTTON     = 0;


//Keskeytys funktio
ISR(TIMER0_COMPA_vect) {
  
    timerMillis1RANDOM++;
    timerMillis1BUTTON++;
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
  if(game1Rounds < 3) {
    peli1Funktio();
  }
  else {
    Serial.println("HI");
  }
  
}



void peli1Funktio() 
{
  
  if(vaikeus == 0) 
  {
    vaikeusAika = 300;
  }
  else if(vaikeus == 1)
  {
    vaikeusAika = 200;
  }
  else if(vaikeus == 2)
  {
    vaikeusAika = 100;
  }
  
  
  
  
  
  //Kopioidan keskeytyksen muuttujat, koska me tarvitaan oikeat arvot. Jos ne käytetään heti, tulee väärit arvot ja sekoitaa kaikki
  cli();
  int timer = timerMillis1RANDOM;
  int timerButton = timerMillis1BUTTON;
  sei();


  //In table sets random numbers
  int randomArvo = random(1, 5);
  randomTable[randomVariable] = randomArvo;
  
  
  if(timer >= vaikeusAika && randomVariable < 5) 
  {
    
    //If button 1 pressed: LED 1 lights up
    if(randomArvo == 1 && led1 == 0) 
    {
      digitalWrite(ledOut1, HIGH);
      led1 = 1;
      randomVariable++;
      
      cli();
      timerMillis1RANDOM = 0;
      sei();
    }
    
    //If button 2 pressed: LED 2 lights up
    else if(randomArvo == 2 && led == 0) 
    {
      digitalWrite(ledOut2, HIGH);
      randomVariable++;
      
      cli();
      timerMillis1RANDOM = 0;
      sei();
    }
    
    //If button 3 pressed: LED 3 lights up
    else if(randomArvo == 3 && led3 == 0) 
    {
      digitalWrite(ledOut3, HIGH);
      randomVariable++;
      
      cli();
      timerMillis1RANDOM = 0;
      sei();
    }
    
    //If button 4 pressed: LED 4 lights up
    else if(randomArvo == 4 && led4 == 0)
    {
      digitalWrite(ledOut4, HIGH);    
      randomVariable++;
      
      cli();
      timerMillis1RANDOM = 0;
      timerMillis1BUTTON = 0;
      sei();
    }
  }
  
  
  //If time is 150ms and previously table (randomTable) is full->
  //-> Button position checking
  //-> e.g if pressed button 2 and it's right, then it adds a +1 to the variable to continue table checking
  //-> If pressed button was not right then sets LED to LOW if it was HIGH, sets all variables = 0, and start again randomTable
  
  
  if(timerButton >= 150)
  {
    
    
    //Test-text on serial monitor
    Serial.print(buttonTable[1]);
    Serial.print(buttonTable[2]);
    Serial.print(buttonTable[3]);
    Serial.println(buttonTable[4]);
    
    //If pressed button 1:
    if(digitalRead(nappi1) == HIGH) 
    {
        buttonTable[buttonVariable] = 1;
        digitalWrite(ledOut1, LOW);
      led1 = 0;
        if(buttonTable[buttonVariable] != buttonTable[buttonVariable]) 
        {
          if(vaikeus = 0) {vaikeusTarkistus = 0;}
          if(vaikeus > 0) {vaikeus--; vaikeusTarkistus = 0;}
          
          buttonVariable   = 1;
          randomVariable   = 1;
          
          digitalWrite(ledOut1, LOW);
	  led1 = 0;
          digitalWrite(ledOut2, LOW);
	  led2 = 0;
          digitalWrite(ledOut3, LOW);
	  led3 = 0;
          digitalWrite(ledOut4, LOW);
          led4 = 0;
      	  buttonTable[1] = 0;
          buttonTable[2] = 0;
      	  buttonTable[3] = 0;
      	  buttonTable[4] = 0;
          
          game1Rounds--;
          
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
      digitalWrite(ledOut2, LOW);
      led2 = 0;
            
        if(buttonTable[buttonVariable] != randomTable[randomVariable]) 
        {
          if(vaikeus = 0) {vaikeusTarkistus = 0;}
          if(vaikeus > 0) {vaikeus--; vaikeusTarkistus = 0;}
          
          buttonVariable   = 1;
          randomVariable  = 1;
           
          digitalWrite(ledOut1, LOW);
	  led1 = 0;
          digitalWrite(ledOut2, LOW);
	  led2 = 0;
          digitalWrite(ledOut3, LOW);
	  led3 = 0;
          digitalWrite(ledOut4, LOW);
          led4 = 0;
          
          
      	  buttonTable[1] = 0;
          buttonTable[2] = 0;
      	  buttonTable[3] = 0;
      	  buttonTable[4] = 0;
          
          game1Rounds--;
          
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
      digitalWrite(ledOut3, LOW);
    led3 = 0;  
        if(buttonTable[buttonVariable] != randomTable[buttonVariable]) 
        {
          if(vaikeus = 0) {vaikeusTarkistus = 0;}
          if(vaikeus > 0) {vaikeus--; vaikeusTarkistus = 0;}
          
          buttonVariable  = 1;
          randomVariable  = 1;
            
          digitalWrite(ledOut1, LOW);
	  led1 = 0;
          digitalWrite(ledOut2, LOW);
	  led2 = 0;
          digitalWrite(ledOut3, LOW);
	  led3 = 0;
          digitalWrite(ledOut4, LOW);
          led4 = 0;
         
         
          buttonTable[1] = 0;
          buttonTable[2] = 0;
          buttonTable[3] = 0;
          buttonTable[4] = 0;
          
          game1Rounds--;
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
      digitalWrite(ledOut4, LOW);
     led4=0; 
        if(buttonTable[buttonVariable] != randomTable[buttonVariable]) 
        {
          if(vaikeus = 0) {vaikeusTarkistus = 0;}
          if(vaikeus > 0) {vaikeus--; vaikeusTarkistus = 0;}
          
          buttonVariable   = 1;
          randomVariable   = 1;
             
          digitalWrite(ledOut1, LOW);
	  led1 = 0;
          digitalWrite(ledOut2, LOW);
	  led2 = 0;
          digitalWrite(ledOut3, LOW);
	  led3 = 0;
          digitalWrite(ledOut4, LOW);
          led4 = 0;
        
          
          buttonTable[1] = 0;
          buttonTable[2] = 0;
          buttonTable[3] = 0;
          buttonTable[4] = 0;
          
          game1Rounds--;
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
    else if(vaikeusTarkistus == 4)
    {
      
      vaikeus++;
      game1Rounds++;
      vaikeusTarkistus = 0;
      randomVariable = 1;
      buttonVariable = 1;

      buttonTable[1] = 0;
      buttonTable[2] = 0;
      buttonTable[3] = 0;
      buttonTable[4] = 0;
      
      digitalWrite(ledOut1, LOW);
   led1=0;
   	digitalWrite(ledOut2, LOW);
      led2=0;
      digitalWrite(ledOut3, LOW);
      led3=0;
      digitalWrite(ledOut4, LOW);
      led4=0;
    }
    
    
    cli();
    timerMillis1BUTTON = 0;
    timerMillis1RANDOM = 0;
    sei();
  }
}
