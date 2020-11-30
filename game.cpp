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
        game::locks -= 1;
        game::updateLocks();
}

void game::gameBegin()
{
  	if (game::init != 1)
  		{
			//game initialization
  			game::lcdObjekti.lcd_init();
  			game::updateLocks();
  			game::lcdObjekti.printInScreen(2);
  			game::aikaObjekti.yleinenAika = true;
  			game::init = 1;
  		}
}

void game::outOfTime()
{
  	unsigned int gameEnd[2][16] = {{0x47,0x41,0x4D,0x45,0xA0,0x4F,0x56,0x45,0x52,0x21,0xA0,0xA0,0xA0,0xA0,0xA0,0xA0},
                                     {0x4F,0x55,0x54,0xA0,0x4F,0x46,0xA0,0x54,0x49,0x4D,0x45,0x21,0x21,0x21,0xA0,0xA0}};
	//runnin out of memory :D init table to end of game :D :D
	//first screen first line 
	game::lcdObjekti.screenTable[0][0] = 0x47;
	game::lcdObjekti.screenTable[0][1] = 0x41;
	game::lcdObjekti.screenTable[0][2] = 0x4D;
	game::lcdObjekti.screenTable[0][3] = 0x45;
	game::lcdObjekti.screenTable[0][4] = 0xA0;
	game::lcdObjekti.screenTable[0][5] = 0x4F;
	game::lcdObjekti.screenTable[0][6] = 0x56;
	game::lcdObjekti.screenTable[0][7] = 0x45;
	game::lcdObjekti.screenTable[0][8] = 0x52;
	game::lcdObjekti.screenTable[0][9] = 0x21;
	game::lcdObjekti.screenTable[0][10] = 0xA0;
	game::lcdObjekti.screenTable[0][11] = 0xA0;
	game::lcdObjekti.screenTable[0][12] = 0xA0;
	game::lcdObjekti.screenTable[0][13] = 0xA0;
	game::lcdObjekti.screenTable[0][14] = 0xA0;
	game::lcdObjekti.screenTable[0][15] = 0xA0;

	//Fist screen Second line
	game::lcdObjekti.screenTable[1][0] = 0x4F;
	game::lcdObjekti.screenTable[1][1] = 0x55;
	game::lcdObjekti.screenTable[1][2] = 0x54;
	game::lcdObjekti.screenTable[1][3] = 0xA0;
	game::lcdObjekti.screenTable[1][4] = 0x4F;
	game::lcdObjekti.screenTable[1][5] = 0x46;
	game::lcdObjekti.screenTable[1][6] = 0xA0;
	game::lcdObjekti.screenTable[1][7] = 0x54;
	game::lcdObjekti.screenTable[1][8] = 0x49;
	game::lcdObjekti.screenTable[1][9] = 0x4D;
	game::lcdObjekti.screenTable[1][10] = 0x45;
	game::lcdObjekti.screenTable[1][11] = 0x21;
	game::lcdObjekti.screenTable[1][12] = 0x21;
	game::lcdObjekti.screenTable[1][13] = 0x21;
	game::lcdObjekti.screenTable[1][14] = 0xA0;
	game::lcdObjekti.screenTable[1][15] = 0xA0;
	//second screen first line  
	game::lcdObjekti.screenTable2[0][0] = 0x47;
	game::lcdObjekti.screenTable2[0][1] = 0x41;
	game::lcdObjekti.screenTable2[0][2] = 0x4D;
	game::lcdObjekti.screenTable2[0][3] = 0x45;
	game::lcdObjekti.screenTable2[0][4] = 0xA0;
	game::lcdObjekti.screenTable2[0][5] = 0x4F;
	game::lcdObjekti.screenTable2[0][6] = 0x56;
	game::lcdObjekti.screenTable2[0][7] = 0x45;
	game::lcdObjekti.screenTable2[0][8] = 0x52;
	game::lcdObjekti.screenTable2[0][9] = 0x21;
	game::lcdObjekti.screenTable2[0][10] = 0xA0;
	game::lcdObjekti.screenTable2[0][11] = 0xA0;
	game::lcdObjekti.screenTable2[0][12] = 0xA0;
	game::lcdObjekti.screenTable2[0][13] = 0xA0;
	game::lcdObjekti.screenTable2[0][14] = 0xA0;
	game::lcdObjekti.screenTable2[0][15] = 0xA0;
	//second screen Second line
	game::lcdObjekti.screenTable2[1][0] = 0x4F;
	game::lcdObjekti.screenTable2[1][1] = 0x55;
	game::lcdObjekti.screenTable2[1][2] = 0x54;
	game::lcdObjekti.screenTable2[1][3] = 0xA0;
	game::lcdObjekti.screenTable2[1][4] = 0x4F;
	game::lcdObjekti.screenTable2[1][5] = 0x46;
	game::lcdObjekti.screenTable2[1][6] = 0xA0;
	game::lcdObjekti.screenTable2[1][7] = 0x54;
	game::lcdObjekti.screenTable2[1][8] = 0x49;
	game::lcdObjekti.screenTable2[1][9] = 0x4D;
	game::lcdObjekti.screenTable2[1][10] = 0x45;
	game::lcdObjekti.screenTable2[1][11] = 0x21;
	game::lcdObjekti.screenTable2[1][12] = 0x21;
	game::lcdObjekti.screenTable2[1][13] = 0x21;
	game::lcdObjekti.screenTable2[1][14] = 0xA0;
	game::lcdObjekti.screenTable2[1][15] = 0xA0;
	
 	//print screen
  	game::lcdObjekti.printInScreen(1);
  	game::lcdObjekti.printInScreen(2);
  	cli();
}


//game 1 desimal in screen
void game::setNumberInScreen(int num)
{
        int temp = num / 10;
        game::lcdObjekti.screenTable[0][6] = 0x30+temp;
        num %= 10;
        game::lcdObjekti.screenTable[0][7] = 0x30 +num;
        game::lcdObjekti.printInScreen(1);
}
//game number in screen
void game::printGameNumber(int num)
{
 	//testing is screen occupyed
	if (game::reserved==0) 
	{
        	game::gameNumber[5] = 0x30 + num;
        	game::lcdObjekti.screenTable[0][0] = game::gameNumber[0];
        	game::lcdObjekti.screenTable[0][1] = game::gameNumber[1];
        	game::lcdObjekti.screenTable[0][2] = game::gameNumber[2];
        	game::lcdObjekti.screenTable[0][3] = game::gameNumber[3];
        	game::lcdObjekti.screenTable[0][4] = game::gameNumber[4];
        	game::lcdObjekti.screenTable[0][4] = game::gameNumber[5];
	}
}
//game 1 code
void game::game1()
{
        if (game::playNumber == 1) //game number what to play
        {
		//game number in screen
		game::printGameNumber(1);
        	//random number funktion in here and saved that to game::randNum
		game::setNumberInScreen(game::randNum);
        	//button for whole game start up using only debug reason
		int pushButton = digitalRead(game::gameButton);
        	if (pushButton == LOW && game::buttonRelease == 1)
        	{
          		game::buttonRelease = 0;
        	}
		//testing is button released once before entry here
          	if (pushButton == HIGH && game::buttonRelease == 0)
          	{
			//game correct less rounds new random number and setting button to stop
            		game::roundNum--;
            		randNum -= 5;
            		game::buttonRelease = 1;
            	}
        
	}
	//finishing game
	if (game::roundNum <= 0 && game::playNumber == 1)
	{
		//setting next game number
  		game::playNumber = 2;
 		//game finished update amount of locks
  		game::locks--;       		
		//clear display game information
  		game::lcdObjekti.screenTable[0][6] = 0x20;
  		game::lcdObjekti.screenTable[0][7] = 0x20;
		//update locks in screen
 	 	game::updateLocks();
		//setting next game round numbers
  		game::roundNum = 3;
		//refresh screen 1
  		game::lcdObjekti.printInScreen(1);
	}
}

void game::game2()
{
	if (game::playNumber == 2)
	{
		game::printGameNumber(2);
		//debug
		int debug = digitalRead(game::gameButton);
		//stop program running with pressed button
		if (debug == LOW && game::buttonRelease == 1)
		{
  			game::buttonRelease = 0;
		}
		if ( debug == HIGH && game::buttonRelease == 0)
		{
  			//fast ending game
  			game::buttonRelease = 1;
  			game::playNumber = 3;
  			game::locks--;      //game finished update amount of locks
  			game::updateLocks(); //update locks in screen
  			game::roundNum = 3; //next game roundnumbers
		}

	}
}

void game::game3()
{
	if (game::playNumber == 3)
	{
	  	//test is screen avaible
  		if (game::aikaInDisplay == 99 && game::reserved == 0)
  		{
			game::printGameNumber(3);
 		 }
		//debug
		int debug = digitalRead(game::gameButton);
		if (debug == LOW && game::buttonRelease == 1)  //Stop going foward without relaesing button 
		{
			game::buttonRelease = 0;
			Serial.println("low");
		}
	//game code start here
	//Setting answer for debug
	game::answer(1);
	//game finished after entering here
	if ( debug == HIGH && game::buttonRelease == 0)       //This game is finished
		{
  			game::buttonRelease = 1;
  			game::playNumber = 4;
  			game::locks = 0;      //game finished update amount of locks
  			game::updateLocks(); //update locks in screen
  			game::roundNum = 3; //next game roundnumbers
		}
	}
}

void game::answer(int a)
{
	if (game::aikaInDisplay == 99)      //first time pass setting values
  	{
  		//reserved display
		game::reserved = 1;
  		//store in temporary table what is in screen before answer
  		game::saveTempTable();
  		//set timing for display resevation
		game::aikaInDisplay = game::aikaObjekti.aikaSec;
		if ( game::aikaInDisplay < 2) 
		{
  			game::aikaInDisplay = 61 - game::aikaObjekti.aikaSec;
  			game::aikaInDisplay -= 2;
		}
		if (game::aikaInDisplay >1 && game::aikaInDisplay < 60)
		{
  			game::aikaInDisplay = game::aikaObjekti.aikaSec;
  			game::aikaInDisplay -=2;
		}
	}


  	if (a == 0)
  	{
    		game::lcdObjekti.screenTable[0][0] = 0x57;  //W
    		game::lcdObjekti.screenTable[0][1] = 0x52;  //R
    		game::lcdObjekti.screenTable[0][2] = 0x4F;  //O
    		game::lcdObjekti.screenTable[0][3] = 0x4D;  //N
    		game::lcdObjekti.screenTable[0][4] = 0x47;  //G
    		if (game::aikaInDisplay != game::aikaObjekti.aikaSec && game::aikaInDisplay != 99)
		{ 
    			game::lcdObjekti.printInScreen(1);
		}  
    	}
  	if (a == 1)
  	{
    		game::lcdObjekti.screenTable[0][0] = 0x43; //C
    		game::lcdObjekti.screenTable[0][1] = 0x4F; //O
    		game::lcdObjekti.screenTable[0][2] = 0x52; //R
    		game::lcdObjekti.screenTable[0][3] = 0x52; //R
    		game::lcdObjekti.screenTable[0][4] = 0x45; //E
    		game::lcdObjekti.screenTable[0][4] = 0x43; //C
    		game::lcdObjekti.screenTable[0][4] = 0x54; //T
 		if (game::aikaInDisplay != game::aikaObjekti.aikaSec && game::aikaInDisplay != 99)
		{ 
    			game::lcdObjekti.printInScreen(1);
		}
  	}
  
  	if (game::aikaInDisplay >= game::aikaObjekti.aikaSec && game::aikaInDisplay != 99 )
	{
  	//set screen back original
  	game::aikaInDisplay = 99;
  	//return saved screen setup
  	game::returnTempTable();
	game::lcdObjekti.printInScreen(1);
	//free display
	game::reserved = 0;
	}
//	game::lcdObjekti.printInScreen(1); //is this really important
}
void game::winner() 
{
	game::lcdObjekti.screenTable[0][0] = 0x57;
  	game::lcdObjekti.screenTable[0][1] = 0x49;
  	game::lcdObjekti.screenTable[0][2] = 0x4E;
  	game::lcdObjekti.screenTable[0][3] = 0x4E;
  	game::lcdObjekti.screenTable[0][4] = 0x45;
  	game::lcdObjekti.screenTable[0][5] = 0x52;
  	Serial.println("winner");
  	game::lcdObjekti.printInScreen(1);
}

//3. game controller
int rotate()
{
  	//sensorValueX jne. lukee mitä anturin X, Y ja Z näyttää
  	sensorValueX = analogRead(analogInPinX);
  	sensorValueY = analogRead(analogInPinY);
  	sensorValueZ = analogRead(analogInPinZ);
                         
  	//ohjelma laskee sensoriarvoa vastaavan kiihtyvyyden
  	//Tai selkkokielillä anturin kalibrointi :)
  	Ax = 0.1307*sensorValueX - 45.519;
  	Ay = 0.1306*sensorValueY - 45.277;
  	Az = 0.1532*sensorValueZ - 55.368;
  	Ax = min(9.81, Ax);    
  	Ay = min(9.81, Ay);    
  	Az = min(9.81, Az);    
  	Ax = max(-9.81, Ax);   
  	Ay = max(-9.81, Ay);   
  	Az = max(-9.81, Az);   
                         
  	DegX = asin(Ax / 9.81) * 180 / 3.141593;
  	DegY = asin(Ay / 9.81) * 180 / 3.141593;
  	DegZ = asin(Az / 9.81) * 180 / 3.141593;
                                                
  	//Sen jälkeen kaikki arvot viedään näyttölle. Aika ja X,Y,Z akselit.
                         
  	if(DegX > 30) 
	{
   	 	//left      
        	return 1;
  	}
  	if(DegX < -30) 
	{
		//right
	     	return 2;
 	}
  	if(DegY > 30) 
  	{
    		//Down
        	return 3;
 	}
  	if(DegY < -30) 
  	{
    		//Up
        	return 4;
 	}
}
void saveTempTable()
{
  	game::tempTable[0] = game::lcdObjekti.screenTable[0][0];
  	game::tempTable[1] = game::lcdObjekti.screenTable[0][1];
  	game::tempTable[2] = game::lcdObjekti.screenTable[0][2];
  	game::tempTable[3] = game::lcdObjekti.screenTable[0][3];
  	game::tempTable[4] = game::lcdObjekti.screenTable[0][4];
  	game::tempTable[5] = game::lcdObjekti.screenTable[0][5];
  	game::tempTable[6] = game::lcdObjekti.screenTable[0][6];
}

void returnTempTable()
{
	game::lcdObjekti.screenTable[0][0] = game::tempTable[0];
	game::lcdObjekti.screenTable[0][1] = game::tempTable[1];
	game::lcdObjekti.screenTable[0][2] = game::tempTable[2];
	game::lcdObjekti.screenTable[0][3] = game::tempTable[3];
	game::lcdObjekti.screenTable[0][4] = game::tempTable[4];
	game::lcdObjekti.screenTable[0][5] = game::tempTable[5];
	game::lcdObjekti.screenTable[0][6] = game::tempTable[6];
}
