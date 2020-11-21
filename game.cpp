#include "game.h"
#include "lcd.h"
#include "aika.h"
#include <Arduino.h>

void game::updateLocks()                                                                   
{                                   

                                      
        for (int k = 6; k <9; k++)                                          
        {                                                                   
        	game::lcdObjekti.screenTable[1][k] = 0xA0;  //clear locks from screen
        }                                                                                 
                                                                               
        for (int i = 6; i < game::locks+6; i++)                               
        {                                                                   
        game::lcdObjekti.screenTable[1][i] = 0xF2;                       //set locks to screen
        }                                                                             
        game::lcdObjekti.printInScreen(1);                           //update screen               
}

void game::gameFinished()
{
	game::locks -= 1;					// decreace amount of locks
	// make test is lock > 0 for ending the game
	game::updateLocks();					//update locks to screen
}

void game::gameBegin()
{
  if (game::init != 1)
  {
  game::lcdObjekti.lcd_init();			//initializin both displays
  game::updateLocks();				//write locks in main screen
  game::lcdObjekti.printInScreen(2);		//setting view of second screen
  game::aikaObjekti.yleinenAika = true; 	//setting time interrupts on
  game::init = 1;				//init done never coming back to set this up

  }
}
