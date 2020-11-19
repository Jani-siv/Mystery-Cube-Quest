#ifndef GAME_H
#define GAME_H
#include "lcd.h"
#include "aika.h"
class game
{
	public:
		int gameOver = 0;				//game is over if 1
		int locks = 3;					//Amount of locks
		LCD* LCDObjekti;				//instance of LCD class	
		aika* aikaObjekti;				//instance of aika class
		void updateLocks(LCD* LCDObjekti);		//setting amount of locks in screen
		void gameFinished(LCD* LCDObjekti);		//one game finished
		void gameBegin(LCD* LCDObjekti);
};
#endif

