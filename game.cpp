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
		}
	//game code start here
	//giving directions for player
		if (game::directionNum < 5) 
		{
		game::guidePlayer(game::directionTable[game::directionNum],1);
		}
		if (game::directionNum == 4 && game::movesCount < 5)
		{
			game::guidePlayer(4,0);
			game::readControllerValue();
      
			//Serial.println(game::playerReturn[game::movesCount]);
		}

	//Setting answer for debug
	//game::answer(1);
	//game finished after entering here
	//if ( debug == HIGH && game::buttonRelease == 0)       
	//This game is finished
		if (debug == HIGH && game::buttonRelease == 0 || game::directionTable[0] == game::playerReturn[0] && game::directionTable[1] == game::playerReturn[1] && game::directionTable[2] == game::playerReturn[2] && game::directionTable[3] == game::playerReturn[3])
		{
  			game::buttonRelease = 1;
  			game::playNumber = 4;
  			game::locks = 0;      //game finished update amount of locks
  			game::updateLocks(); //update locks in screen
  			game::roundNum = 3; //next game roundnumbers
		}
   //wrong answer
	if (game::directionTable[0] == game::playerReturn[0] && game::movesCount == 4 || game::directionTable[1] != game::playerReturn[1] && game::movesCount == 4 || game::directionTable[2] != game::playerReturn[2] && game::movesCount == 4 || game::directionTable[3] != game::playerReturn[3] && game::movesCount == 4)
 {
  game::directionNum = 0;
  game::movesCount = 0;
  //wrong answer code here
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
        	game::tempTable[0] = game::lcdObjekti.screenTable[0][0];
        	game::tempTable[1] = game::lcdObjekti.screenTable[0][1];
        	game::tempTable[2] = game::lcdObjekti.screenTable[0][2];
        	game::tempTable[3] = game::lcdObjekti.screenTable[0][3];
        	game::tempTable[4] = game::lcdObjekti.screenTable[0][4];
        	game::tempTable[5] = game::lcdObjekti.screenTable[0][5];
	        game::tempTable[6] = game::lcdObjekti.screenTable[0][6];

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
        game::lcdObjekti.screenTable[0][0] = game::tempTable[0];
        game::lcdObjekti.screenTable[0][1] = game::tempTable[1];
        game::lcdObjekti.screenTable[0][2] = game::tempTable[2];
        game::lcdObjekti.screenTable[0][3] = game::tempTable[3];
        game::lcdObjekti.screenTable[0][4] = game::tempTable[4];
        game::lcdObjekti.screenTable[0][5] = game::tempTable[5];
        game::lcdObjekti.screenTable[0][6] = game::tempTable[6];

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
int game::rotate()
{
  	//sensorValueX jne. lukee mitä anturin X, Y ja Z näyttää
  	int sensorValueX = analogRead(A1);
  	int sensorValueY = analogRead(A2);
  	int sensorValueZ = analogRead(A3);
	float Ax = 0.0;
        float Ay = 0.0;
        float Az = 0.0;
        float DegX = 0.0;
        float DegY = 0.0;
        float DegZ = 0.0;
                 
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
  //Serial.println(DegX);
  //Serial.println(DegY);
  	if(DegX > 30 && DegY < 15 && DegY > -15) 
	{
   	 	//left      
		game::controllerOccy = 1;
    game::setDirection = 1;
   Serial.println("left");
		return 3;
  	}
  	if(DegX < -30 && DegY < 15 && DegY > -15) 
	{
		//right
		game::controllerOccy = 1;
		game::setDirection = 1;
		Serial.println("right");
		return 1;
 	}
  	if(DegY > 30 && DegX < 15 && DegX > -15) 
  	{
    		//Down
		game::controllerOccy = 1;
    game::setDirection = 1;
   Serial.println("down");
		return 2;
 	}
  	if(DegY < -30 && DegX < 15 && DegX > -15) 
  	{
    		//Up
        Serial.println("up");
		game::controllerOccy = 1;
    game::setDirection = 1;
        	return 0;
 	}
  if (DegY > -10 && DegY < 10 && DegX > -10 && DegX < 10 && game::setDirection == 1)
  {
    game::controllerOccy = 1;
    game::setDirection = 0;
    return 4;
  }
  else return 5;
  
}

void game::readControllerValue()
{
  
	if (game::controllerOccy == 0)
	{
		game::value = game::rotate();
   Serial.println(game::value);
		if (game::movesCount < 5 && game::value != 4 && game::value != 5 && game::setDirection == 1) {
		game::playerReturn[game::movesCount] = game::value;
   Serial.print("readControllerValue: ");
   Serial.println(game::playerReturn[game::movesCount]);
   
		}
	}
 if (game::controllerOccy == 1 && setDirection == 1)
 {
  game::value = game::rotate();
 }
	if (game::controllerOccy == 1 && game::value == 4)
	{
		game::movesCount += 1;
		game::controllerOccy = 0;
	}
}



void game::guidePlayer(int a, int b)
{
	//set direction in table
	int tableUp[7] = {0x55,0x50,0x20,0x20,0x20,0x20,0x20};
	int tableRight[7] ={0x52,0x49,0x47,0x48,0x54,0x20,0x20};
	int tableDown[7] ={0x44,0x4F,0x57,0x4E,0x20,0x20,0x20};
	int tableLeft[7] ={0x4C,0x45,0x46,0x54,0x20,0x20,0x20};
	//clear dispaly
	//save old information
	if (b == 1)
	{
	if (game::reserved == 0)
	{
		game::tempTable[0] = game::lcdObjekti.screenTable[0][0];
        	game::tempTable[1] = game::lcdObjekti.screenTable[0][1];
        	game::tempTable[2] = game::lcdObjekti.screenTable[0][2];
        	game::tempTable[3] = game::lcdObjekti.screenTable[0][3];
        	game::tempTable[4] = game::lcdObjekti.screenTable[0][4];
        	game::tempTable[5] = game::lcdObjekti.screenTable[0][5];
        	game::tempTable[6] = game::lcdObjekti.screenTable[0][6];
		game::reserved = 1;
	}
	if (a == 0 && game::reserved == 1 && game::aikaInDisplay == 99)
	{
		game::lcdObjekti.screenTable[0][0] = tableUp[0];
		game::lcdObjekti.screenTable[0][1] = tableUp[1];
		game::lcdObjekti.screenTable[0][2] = tableUp[2];
		game::lcdObjekti.screenTable[0][3] = tableUp[3];
		game::lcdObjekti.screenTable[0][4] = tableUp[4];
		game::lcdObjekti.screenTable[0][5] = tableUp[5];
		game::lcdObjekti.screenTable[0][6] = tableUp[6];
		game::lcdObjekti.printInScreen(1);
		game::setTime();
	}

	if (a == 1 && game::reserved == 1 && game::aikaInDisplay == 99)
	{
		game::lcdObjekti.screenTable[0][0] = tableRight[0];
		game::lcdObjekti.screenTable[0][1] = tableRight[1];
		game::lcdObjekti.screenTable[0][2] = tableRight[2];
		game::lcdObjekti.screenTable[0][3] = tableRight[3];
		game::lcdObjekti.screenTable[0][4] = tableRight[4];
		game::lcdObjekti.screenTable[0][5] = tableRight[5];
		game::lcdObjekti.screenTable[0][6] = tableRight[6];
		game::lcdObjekti.printInScreen(1);
		game::setTime();
	}

	if (a == 2 && game::reserved == 1 && game::aikaInDisplay == 99)
	{
		game::lcdObjekti.screenTable[0][0] = tableDown[0];
		game::lcdObjekti.screenTable[0][1] = tableDown[1];
		game::lcdObjekti.screenTable[0][2] = tableDown[2];
		game::lcdObjekti.screenTable[0][3] = tableDown[3];
		game::lcdObjekti.screenTable[0][4] = tableDown[4];
		game::lcdObjekti.screenTable[0][5] = tableDown[5];
		game::lcdObjekti.screenTable[0][6] = tableDown[6];
		game::lcdObjekti.printInScreen(1);
		game::setTime();
	}

	if (a == 3 && game::reserved == 1 && game::aikaInDisplay == 99)
	{
		game::lcdObjekti.screenTable[0][0] = tableLeft[0];
		game::lcdObjekti.screenTable[0][1] = tableLeft[1];
		game::lcdObjekti.screenTable[0][2] = tableLeft[2];
		game::lcdObjekti.screenTable[0][3] = tableLeft[3];
		game::lcdObjekti.screenTable[0][4] = tableLeft[4];
		game::lcdObjekti.screenTable[0][5] = tableLeft[5];
		game::lcdObjekti.screenTable[0][6] = tableLeft[6];
		game::lcdObjekti.printInScreen(1);
		game::setTime();
	}
	//release for next direction after 2 seconds
	if (game::aikaInDisplay >= game::aikaObjekti.aikaSec && game::aikaInDisplay != 99 )
	{
		game::aikaInDisplay = 99;
		game::directionNum += 1;
	}
	}
	//return screen information
	if (b == 0 && a == 4)
	{

	        game::lcdObjekti.screenTable[0][0] = game::tempTable[0];
	        game::lcdObjekti.screenTable[0][1] = game::tempTable[1];
	        game::lcdObjekti.screenTable[0][2] = game::tempTable[2];
	        game::lcdObjekti.screenTable[0][3] = game::tempTable[3];
	        game::lcdObjekti.screenTable[0][4] = game::tempTable[4];
	        game::lcdObjekti.screenTable[0][5] = game::tempTable[5];
	        game::lcdObjekti.screenTable[0][6] = game::tempTable[6];
		game::lcdObjekti.printInScreen(1);
    game::reserved = 0;
    game::aikaInDisplay = 99;
	}
}
void game::setTime()
{
	if (game::aikaInDisplay == 99)
	{
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
}
