#ifndef GAME_H
#define GAME_H
#include "lcd.h"
#include "aika.h"
class game
{
	public:
		int init = 0;					//is game initialized 1 = yes
		int gameOver = 0;				//game is over if 1
		int locks = 3;					//Amount of locks
    		LCD lcdObjekti;					//instance of LCD class	
		LCD* LCDOlio = &lcdObjekti;			//pointer for lcdObjekti
		aika aikaObjekti;				//instance of aika class
		void updateLocks();				//setting amount of locks in screen
		void gameFinished();				//one game finished
		void gameBegin();

};
#endif
