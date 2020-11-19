#include "game.h"
#include "lcd.h"
#include "aika.h"
#include <Arduino.h>

void game::updateLocks()                                                                   
{                                   

                                      
        for (int k = 0; k <3; k++)                                          
        {                                                                   
               game::lcdObjekti.screen[1][k] = 0xA0;			//clear locks from screen
              Serial.print("k:n arvo:  ");
              Serial.println(k);
        }                                                                                 
                                                                               
        for (int i = 0; i <= game::locks; i++)                               
        {                                                                   
        game::lcdObjekti.screen[1][i] = 0x04;				//set locks to screen
        }                                                                             
        game::lcdObjekti.printInScreen();				//update screen               
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

  game::lcdObjekti.lcd_init();
 // game::updateLocks();						//arduino broke in loop

}
