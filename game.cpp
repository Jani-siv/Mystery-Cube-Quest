#include "game.h"
#include "lcd.h"
#include "aika.h"
#include <Arduino.h>

void game::updateLocks()                                                                   
{                                   

                                      
        for (int k = 6; k <9; k++)                                          
        {                                                                   
               game::lcdObjekti.screen[1][k] = 0xA0;  //clear locks from screen
              Serial.print("k:n arvo:  ");
              Serial.println(k);
        }                                                                                 
                                                                               
        for (int i = 6; i < game::locks+6; i++)                               
        {                                                                   
        game::lcdObjekti.screen[1][i] = 0xF2;                       //set locks to screen
        }                                                                             
        game::lcdObjekti.printInScreen();                           //update screen               
}
/*
void game::gameFinished(LCD* LCDObjekti)
{
	game::locks -= 1;
	game::updateLocks(LCDOlio);
}
*/
void game::gameBegin()
{
  if (game::init != 1)
  {
  game::lcdObjekti.lcd_init();
  game::updateLocks();
  game::aikaObjekti.yleinenAika = true;
  game::init = 1;

  }
}
