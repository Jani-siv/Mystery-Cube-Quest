#include "aika.h"
#include <Arduino.h>
/*
void aika::yleinenAika()
{
  if (aika::sekunnit > 0)
  	{
    		aika::sekunnit--;
  	}
  else if (aika::sekunnit == 0 && aika::kymsek > 0)
  	{
    		aika::sekunnit = 9;
    		aika::kymsek--;
  	}
  else if (aika::kymsek == 0 && aika::minuutit > 0)
  	{
  		aika::kymsek = 5;
  		aika::minuutit--;  
  	}
  else if (aika::minuutit == 0 && aika::kymmin >0)
  	{
    		aika::kymmin--;
    		aika::minuutit = 9;
    		aika::kymsek = 5;
    		aika::sekunnit = 9;
  	}
  else if (aika::kymmin == 0 && aika::minuutit == 0 && aika::kymsek == 0 && aika::sekunnit == 0)
  	{
    		aika::gameOver = 1;
  	}
  objekti->updateTime(aika::kymmin, aika::minuutit, aika::kymsek, aika::sekunnit);
}
*/


void aika::yleinenAikaFunktio(LCD* objekti) {
  cli();             
  aika::millisFunktiossa = aika::keskeytysMillis;
  sei();                                  
  if(aika::millisFunktiossa >= 1000) {    
                                          
    int minuttinen    = aikaMin%10;
    int sekuntinen    = aikaSec%10;
    int minuttinen10  = aikaMin/10;
    int sekuntinen10  = aikaSec/10;
                     
    aikaSec--;       
    if(aika::aikaMin >= 1 && aika::aikaSec == -1) {
            aika::aikaMin--;                
            aika::aikaSec = 59;             
    }                
                 
    objekti->updateTime(minuttinen10,minuttinen,sekuntinen10,sekuntinen);
                  
    if(aika::aikaMin == 0 && aika::aikaSec == -1) {
      cli();                                
      //game over
      yleinenAika = false;                  
      keskeytysMillis = 0;  
      sei();                
    }                       
                            
    cli();                  
    aika::keskeytysMillis = 0;
    sei();                  
                            
  }                         
}  
