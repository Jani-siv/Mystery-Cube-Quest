#ifndef GAME_H
#define GAME_H
#include "lcd.h"
#include "aika.h"
class game
{
        public:
                int init = 0;                                   //is game initialized 1 = yes
                int gameOver = 0;                               //game is over if 1
                int startGame = 0;                              //push button to start game
                int locks = 3;                                  //Amount of locks
                int gameButton = 10;
                int gameNumber[6] = {0x47,0x41,0x4D,0x45,0x20,0x30};    //game 
                LCD lcdObjekti;                                 //instance of LCD class 
                LCD* LCDOlio = &lcdObjekti;                     //pointer for lcdObjekti
                aika aikaObjekti;                               //instance of aika class
                void updateLocks();                             //setting amount of locks in screen
                void gameFinished();                            //one game finished
                void gameBegin();                               //init screens
                void initGame();                                //game start function
                void outOfTime();                               //out of time print screen
                int buttonRelease = 1;                          // if button is realeased
                void answer(int a);                             // 1 correct 0 wrong
                int reserved = 0;                               //display occypyed 1
                int aikaInDisplay = 99;                         //show answer in seconds
                int tempTable[7];                      //saving temporary info in table
		void saveTempTable();				//saving screen 7 first letter
		void returnTempTable();				//return screen 7 first letter
                void winner();                                   //winning game
                void setNumberInScreen(int num);                //Jonin game desimal in screen
                void printGameNumber(int num);            //print game number in screen
                void game1();                                   //jonin game                                                                
                int roundNum = 3;                               //round number for games
                int randNum = 15;
                int playNumber = 1;
                void game2();                                   //Alexander game                                                            
                void game3();                                   //Jani game       
		// 3. game controller
		int rotate();					//return value of direction
		const int analogInPinX = A0;			//pin setup
		const int analogInPinY = A1;
		const int analogInPinZ = A2; 
		int sensorValueX = 0;
		int sensorValueY = 0;
		int sensorValueZ = 0;
		float Ax = 0.0;     
		float Ay = 0.0;     
		float Az = 0.0;     
		float DegX = 0.0;   
		float DegY = 0.0;   
		float DegZ = 0.0; 


                                                                                                                                            
};                                                                                                                                          
#endif          
