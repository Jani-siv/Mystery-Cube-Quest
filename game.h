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
                void setNumberInScreen(int num);                //Jonin game desimal in screen
                void printGameNumber(int num);            //print game number in screen
                void game1();                                   //jonin game                                                                
                int roundNum = 3;                               //round number for games
                int randNum = 15;
                int playNumber = 1;
                void game2();                                   //Alexander game                                                            
                void game3();                                   //Jani game                                                                 
                                                                                                                                            
};                                                                                                                                          
#endif           
