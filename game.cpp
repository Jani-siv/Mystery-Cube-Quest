#include "game.h"
#include "lcd.h"
#include "aika.h"
void game::updateLocks(LCD* LCDObjekti)                                                                   
{                                   

                                      
        for (int k = 0; k <3; k++)                                          
        {                                                                   
                LCDObjekti->screen[1][k] = 0xA0;               //clear locks from screen
        }                                                                                 
                                                                               
        for (int i = 0; i < game::locks; i++)                               
        {                                                                   
        LCDObjekti->screen[1][i] = 0x04;                       //set locks to screen
        }                                                                             
        LCDObjekti->printInScreen();                           //update screen               
}

void game::gameFinished(LCD* LCDObjekti)
{
	game::locks -= 1;
	game::updateLocks(LCDObjekti);
}

void game::gameBegin(LCD* LCDObjekti)
{
	LCDObjekti->lcd_init();
}
