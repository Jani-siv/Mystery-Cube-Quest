#ifndef GAME_H
#define GAME_H
#include "lcd.h"
#include "aika.h"
class game
{
        public:
                //global settings
		//LED pinnien asetus
		const int ledOut1 = 30;				//Game 2
		const int ledOut2 = 32;
		const int ledOut3 = 34;
		const int ledOut4 = 36;
		//BUTTON pinnien asetus
		const int nappi1 = 31;
		const int nappi2 = 33;
		const int nappi3 = 35;
		const int nappi4 = 37;	

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
                void winner();                                   //winning game
                void setNumberInScreen(int num);                //Jonin game desimal in screen
                void printGameNumber(int num);            //print game number in screen
                
		void game1();                                   //jonin game
		int roundNum = 3;                               //round number for games
                int randNum = 15;
                int playNumber = 1;
                
		void game2();                                   //Alexander game 
		//led tarkistus
		int led1 = 0;					//led check
		int led2 = 0;
		int led3 = 0;
		int led4 = 0;
		//BUTTON stop painalus
		int nappi1Stop = 1;				//button check
		int nappi2Stop = 1;
		int nappi3Stop = 1;
		int nappi4Stop = 1;
		//Random number
		int randomArvo;
		int timerRANDOM;
		int timerUPDATE;
		//Taulukko ja muuttujat
		int randomTable[7];
		int buttonTable[7];
		int randomVariable  = 1;
		int buttonVariable  = 1;
		//Game difficulty
		int vaikeus = 0;
		int vaikeusAika = 0;  //<-- if (vaikeus == 0) {vaikeusAika = 500}, if (vaikeus == 1) {vaikeusAika = 400} etc.
		int vaikeusTarkistus = 0;
		int game1Rounds = 0;
		bool timerON       = false; // <-- if true- timer doesn't work, false- start timer
		bool timerUpdateON = false; // <-- In truth that don't work how it need to be, but it good working for timerON update :/
		//Keskeytyksen muuttujat
		volatile unsigned long int timerMillis1RANDOM       = 0;
		volatile unsigned long int timerMillis1UPDATE       = 0; 

                void game3();                                   //Jani game       
		// 3. game controller
		int rotate();					//return value of direction
		void guidePlayer(int a, int b);			//direction to second screen
		void setTime();					//setting time to display on direction
		int directionNum = 0;
		int directionTable[5] = {0,2,0,1,3};	//directions for player
		int playerReturn[5] =   {9,9,9,9,9};				//return value from player
		int controllerOccy = 0;				//reading value
		int movesCount = 0;
    void readControllerValue();   //reading value from controller
    int setDirection = 0;         //check
    int value = 0;                //check
};                                                                                                                                          
#endif          
