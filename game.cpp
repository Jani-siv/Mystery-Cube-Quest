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
   if(game::reserved == 0) 
   { 
		game::printGameNumber(1);
		}

        	//button for whole game start up using only debug reason
		int pushButton = digitalRead(game::gameButton);
        	if (pushButton == LOW && game::buttonRelease == 1)
        	{
          		game::buttonRelease = 0;
         		//set randNum
			game::randNum = random(1,15);
			//random number funktion in here and saved that to game::randNum
			game::setNumberInScreen(game::randNum);       	
		}
		//testing is button released once before entry here
          	if (pushButton == HIGH && game::buttonRelease == 0)
          	{
			//game code
			game::vipu1_muuttuja = digitalRead(game::vipu1);
        		game::vipu2_muuttuja = digitalRead(game::vipu2);
        		game::vipu3_muuttuja = digitalRead(game::vipu3);
        		game::vipu4_muuttuja = digitalRead(game::vipu4);

        		if (game::vipu1_muuttuja == HIGH)
        		{
                		game::vipu1_muuttuja = 1;
        		}
        		if (game::vipu2_muuttuja == HIGH)
        		{
                		game::vipu2_muuttuja = 2;
        		}
        		if (game::vipu3_muuttuja == HIGH)
        		{
                		game::vipu3_muuttuja = 4;
        		}
        		if (game::vipu4_muuttuja == HIGH)
        		{
                		game::vipu4_muuttuja = 8;
        		}
        	game::total = game::vipu1_muuttuja + game::vipu2_muuttuja + game::vipu3_muuttuja + game::vipu4_muuttuja;
        	//set all vipu to 0
		game::vipu1_muuttuja = 0;
		game::vipu2_muuttuja = 0;
		game::vipu3_muuttuja = 0;
		game::vipu4_muuttuja = 0;
		//checking is answer correct
		if (game::total == game::randNum)
        		{
                		Serial.println("Oikein");
				game::answer(1);
                		game::kysymys = random(1,15);
                		game::vastaus = 0;
                          //game correct less rounds new random number and setting button to stop
                game::roundNum--;
                //game::randNum -= 5;
                game::buttonRelease = 1;
                Serial.println(game::total);
        		}
        		else if (game::total != game::randNum)
        		{
                		Serial.println("väärin, Aseta vipu kytkimet uudelleen");
                    Serial.println(game::total);
                    Serial.println(game::randNum);
                		game::vastaus = 0;
				game::answer(0);
        		}
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
      game::reserved = 0;
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

   //game code here!!!
     if(game::game1Rounds < 3) {
    peli1Funktio();
  }

   
		if ( debug == HIGH && game::buttonRelease == 0 || game::game1Rounds == 3)
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
    game::ledSetLow(); //if jump set all led low

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
	if (game::aikaInDisplay == 99 && game::reserved == 0)      //first time pass setting values
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
          Serial.println("saving screen");

		//set timing for display resevation
		game::aikaInDisplay = game::aikaObjekti.aikaSec;
		if ( game::aikaInDisplay < 2) 
		{
      if (game::aikaInDisplay == 1) {
  			game::aikaInDisplay = 59;
      }
      if (game::aikaInDisplay == 0); {
        game::aikaInDisplay = 58;
      }
  		
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
    		game::lcdObjekti.screenTable[0][3] = 0x4E;  //N
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
  Serial.println("Setting back original screen");
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
  // Serial.println("left");
		return 3;
  	}
  	if(DegX < -30 && DegY < 15 && DegY > -15) 
	{
		//right
		game::controllerOccy = 1;
		game::setDirection = 1;
//		Serial.println("right");
		return 1;
 	}
  	if(DegY > 30 && DegX < 15 && DegX > -15) 
  	{
    		//Down
		game::controllerOccy = 1;
    game::setDirection = 1;
  // Serial.println("down");
		return 2;
 	}
  	if(DegY < -30 && DegX < 15 && DegX > -15) 
  	{
    		//Up
    //    Serial.println("up");
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
	if (game::aikaInDisplay >= game::aikaObjekti.aikaSec && game::aikaInDisplay != 99 && game::aikaObjekti.aikaSec > 2)
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
  Serial.print("ennen if: ");
  Serial.println(game::aikaObjekti.aikaSec);
  Serial.println(game::aikaInDisplay);
	if (game::aikaInDisplay == 99)
	{
  Serial.println(game::aikaObjekti.aikaSec);
		game::aikaInDisplay = game::aikaObjekti.aikaSec;

     
			if (game::aikaInDisplay >=2 && game::aikaInDisplay < 60)
			{
  				game::aikaInDisplay = game::aikaObjekti.aikaSec;
  				game::aikaInDisplay -=2;
			}
          if ( game::aikaInDisplay < 2) 
      {
          game::aikaInDisplay = 58;
        Serial.println(game::aikaInDisplay);

      }
     
	}
 Serial.println("If jälkeen");
   Serial.println(game::aikaInDisplay);
  Serial.println(game::aikaObjekti.aikaSec);

}

void game::tableSet0()
{
  for(int i = 0; i < game::toistoja; i++) {
  	game::randomTable[i] = 0;
	game::buttonTable[i] = 0;
  }
}

void game::ledSetLow() 
{
  digitalWrite(game::ledOut1, LOW);
  game::led1 = 0;
  digitalWrite(game::ledOut2, LOW);
  game::led2 = 0;
  digitalWrite(game::ledOut3, LOW);
  game::led3 = 0;
  digitalWrite(game::ledOut4, LOW);
  game::led4 = 0;
}

void game::ledSetHigh()
{
  digitalWrite(game::ledOut1, HIGH);
  game::led1 = 1;
  digitalWrite(game::ledOut2, HIGH);
  game::led2 = 1;
  digitalWrite(game::ledOut3, HIGH);
  game::led3 = 1;
  digitalWrite(game::ledOut4, HIGH);
  game::led4 = 1;
}

void game::peli1Funktio() 
{

  //Game difficulty
  if(game::vaikeus == 0)
  {
    game::vaikeusAika = 500;
  }
  else if(game::vaikeus == 1)
  {
    game::vaikeusAika = 400;
  }
  else if(game::vaikeus == 2)
  {
    game::vaikeusAika = 300;
  }
  else if(game::vaikeus == 3)
  {
    game::vaikeusAika = 200;
  }
  
  


//Kopioidan keskeytyksen muuttujat, koska me tarvitaan oikeat arvot. Jos ne käytetään heti, tulee väärit arvot ja sekoitaa kaikki
  cli();
  game::timerRANDOM = game::timerMillis1RANDOM;
  game::timerUPDATE = game::timerMillis1UPDATE;
  sei();
  

  //In table sets random numbers
  game::randomArvo = random(1, 5);
  game::randomTable[game::randomVariable] = game::randomArvo;
  
  if(game::randomVariable < game::toistoja) {
    cli();
    game::timerON = true;
    sei();
  }
  
  //Starting give random numbers to randomTable
  if(game::timerRANDOM >= game::vaikeusAika 
     && game::randomVariable < game::toistoja
     && game::game1Rounds < 4 
     && game::led1 == 0
     && game::led2 == 0
     && game::led3 == 0
     && game::led4 == 0) 
  { 
    
    //If random number = 1
    if(game::randomArvo == 1)
    {
      digitalWrite(game::ledOut1, HIGH);
      game::led1 = 1;
      game::randomVariable++;
      
      cli();
      game::timerMillis1RANDOM = 0;
      sei();
    }
    
    //If random number = 2  
    else if(game::randomArvo == 2)
    {
      digitalWrite(game::ledOut2, HIGH);
      game::led2 = 1;
      game::randomVariable++;
      
      cli();
      game::timerMillis1RANDOM = 0;
      sei();
    }
    
    //If random number = 3  
    else if(game::randomArvo == 3)
    {
      digitalWrite(game::ledOut3, HIGH);
      game::led3 = 1;
      game::randomVariable++;
      
      cli();
      game::timerMillis1RANDOM = 0;
      sei();
    }
    
    //If random number = 4  
    else if(game::randomArvo == 4)
    {
      digitalWrite(game::ledOut4, HIGH);
      game::led4 = 1;
      game::randomVariable++;

      cli();
      game::timerMillis1RANDOM = 0;
      sei();
    }
  }


  else if(game::timerRANDOM >= game::vaikeusAika && game::pauseBeforeRounds == false)
  {
      if(game::randomVariable < game::toistoja)
      {

        game::ledSetLow();
        cli();
        game::timerMillis1RANDOM = 0;
        sei();
      }

      if(game::randomVariable == game::toistoja)
      {
        game::ledSetLow();


        cli();
        game::timerON = false;
        game::timerMillis1RANDOM = 0;
        game::timerUpdateON = true;
        sei();
      }
  }


//does not work as it should
  if(game::timerUPDATE >= 10000) {
    if(game::game1Rounds > 0) {
      game::game1Rounds--;
    }
    if(game::vaikeus > 0) {
      game::vaikeus--;
    }

    cli();
    game::timerUpdateON = false;
    game::timerMillis1RANDOM = 0;
    game::timerON = true;
    sei();

    game::vaikeusTarkistus = 0;
    game::randomVariable = 1;
    game::buttonVariable = 1;

    game::ledSetLow();
    game::tableSet0();
  }
//does not work as it should


 Serial.println(game::timerUPDATE);

    //-> Button position checking
    //-> e.g if pressed button 2 and it's right, then it adds a +1 to the variable to continue table checking
    //-> If pressed button was not right then sets all variables = 1, and start again randomTable


    //If pressed button 1:
    if(digitalRead(game::nappi1) == LOW && game::nappi1Stop == 1 && game::wrongRound == false)
    {
      game::ledSetLow();
      game::nappi1Stop = 0;
    }

    else if(digitalRead(game::nappi1) == HIGH && game::nappi1Stop == 0)
    {
        game::buttonTable[game::buttonVariable] = 1;
        digitalWrite(game::ledOut1, HIGH);
        game::led1 = 1;
 	game::nappi1Stop = 1;

        if(game::buttonTable[game::buttonVariable] == game::randomTable[game::buttonVariable]) 
        {
          game::buttonVariable++;
          game::vaikeusTarkistus++;
        }
        
        else if(game::buttonTable[game::buttonVariable] != game::randomTable[game::buttonVariable]) 
        {
          
	  game::ledSetHigh();
	  game::pauseBeforeRounds	= true;
	  game::wrongRound 		= true;
          
          cli();
          game::timerON = true;
	  game::timerMillis1RANDOM = 0;
          sei();

        }
     }

    //If pressed button 2:
    if(digitalRead(game::nappi2) == LOW && game::nappi2Stop == 1 && game::wrongRound == false) 
    {
      game::ledSetLow();
      game::nappi2Stop = 0;
      
    }
    else if(digitalRead(game::nappi2) == HIGH && game::nappi2Stop == 0) 
    {
        game::buttonTable[game::buttonVariable] = 2;
        digitalWrite(game::ledOut2, HIGH);
        game::led2 = 1;
        game::nappi2Stop = 1;

        if(game::buttonTable[game::buttonVariable] == game::randomTable[game::buttonVariable]) 
        {
          game::buttonVariable++;
          game::vaikeusTarkistus++;
        }
        
        else if(game::buttonTable[game::buttonVariable] != game::randomTable[game::buttonVariable]) 
        {
          
	  game::pauseBeforeRounds	= true;
	  game::wrongRound		= true;
	  game::ledSetHigh();

          cli();
          game::timerON = true;
          game::timerMillis1RANDOM = 0;
          sei();
        }
     }



    


    //If pressed button 3:
    if(digitalRead(game::nappi3) == LOW && game::nappi3Stop == 1 && game::wrongRound == false)
    {
        game::nappi3Stop = 0;
        game::ledSetLow();
    }

    else if(digitalRead(game::nappi3) == HIGH && game::nappi3Stop == 0)
    {
        game::buttonTable[game::buttonVariable] = 3;
        digitalWrite(game::ledOut3, HIGH);
        game::led3 = 1;
        game::nappi3Stop = 1;


        if(game::buttonTable[game::buttonVariable] == game::randomTable[game::buttonVariable])
        {
          game::buttonVariable++;
          game::vaikeusTarkistus++;
        }

        else if(game::buttonTable[game::buttonVariable] != game::randomTable[game::buttonVariable])
        {
          
	  game::pauseBeforeRounds	= true;
	  game::wrongRound		= true;
	  game::ledSetHigh();

          cli();
          game::timerON = true;
          game::timerMillis1RANDOM = 0;
          sei();

        }
     }




    //If pressed button 4:
    if(digitalRead(game::nappi4) == LOW && game::nappi4Stop == 1 && game::wrongRound == false)
    {
        game::nappi4Stop = 0;
        game::ledSetLow();
    }
    else if(digitalRead(game::nappi4) == HIGH && game::nappi4Stop == 0)
    {
        game::buttonTable[buttonVariable] = 4;
        digitalWrite(game::ledOut4, HIGH);
        game::led4 = 1;
        game::nappi4Stop = 1;

        if(game::buttonTable[game::buttonVariable] == game::randomTable[game::buttonVariable])
        {
          game::buttonVariable++;
          game::vaikeusTarkistus++;
        }

        else if(game::buttonTable[game::buttonVariable] != game::randomTable[game::buttonVariable])
        {
          
	  game::pauseBeforeRounds	= true;
	  game::wrongRound		= true;
	  game::ledSetHigh();
	  
          cli();
          game::timerON = true;
          game::timerMillis1RANDOM = 0;
          sei();
        }
     }

    
    //If buttonTable last position is same that last position randomTable ->
    //-> Set table variables = 1, and all LED's to LOW
    //-> And increases the difficulty of the game
    if(game::vaikeusTarkistus == game::toistoja - 1)
    {
      	game::vaikeusTarkistus = 0;
	game::pauseBeforeRounds = true;
	game::winRound		= true;
	
	cli();
	game::timerON = true;
	game::timerMillis1RANDOM = 0;
      	sei();
    }

    if(game::pauseBeforeRounds == true && game::timerRANDOM >= 2000) {
    	if(game::wrongRound == true) {
		if(game::vaikeus > 0) {game::vaikeus--;}
		if(game::game1Rounds > 0) {game::game1Rounds--;}
	}
	else if(game::winRound == true) {
		game::vaikeus++;
		game::game1Rounds++;
	}
	
	game::ledSetLow();
	game::tableSet0();
	game::vaikeusTarkistus = 0;
	game::randomVariable = 1;
	game::buttonVariable = 1;
	game::wrongRound 	= false;
	game::winRound	 	= false;
	game::pauseBeforeRounds = false;
	
	cli();
	game::timerMillis1RANDOM = 0;
	sei();
    }
    if(game::game1Rounds == 3) {
      cli();
      game::timerON = false;
      game::timerMillis1RANDOM = 0;
      sei();
    }
}

void game::resetGame()
{
                 game::init = 0;                                   //is game initialized 1 = yes
                 game::gameOver = 0;                               //game is over if 1
                 game::startGame = 0;                              //push button to start game
                 game::locks = 3;                                  //Amount of locks
                 game::gameButton = 10; 
                 game::buttonRelease = 1;                          // if button is realeased
                 game::reserved = 0;                               //display occypyed 1
                 game::aikaInDisplay = 99;                         //show answer in seconds
                 game::roundNum = 3;                               //round number for games
                 game::randNum = 15;
                 game::playNumber = 1;
                 game::led1 = 0;         //led check
                 game::led2 = 0;  
                 game::led3 = 0;
                 game::led4 = 0;
                 game::nappi1Stop = 1;       //button check
                 game::nappi2Stop = 1;
                 game::nappi3Stop = 1;
                 game::nappi4Stop = 1;
    game::randomVariable  = 1;
    game::buttonVariable  = 1;
    game::game1Rounds = 0;
    game::timerON       = false; // <-- if true- timer doesn't work, false- start timer
    game::timerUpdateON = false; // <-- In truth that don't work how it need to be, but it good working for timerON update :/
    game::timerMillis1RANDOM       = 0;
    game::timerMillis1UPDATE       = 0;
    game::pauseBeforeRounds  = false;  //Pieni taukko ennen seurava kierros
    game::wrongRound   = false;  //Jos kierros on väärin
    game::winRound   = false;  //Jos kierros on oikein
    game::directionNum = 0;
    game::controllerOccy = 0;       //reading value
    game::movesCount = 0;
    game::setDirection = 0;         //check
    game::value = 0;                //check
    game::lcdObjekti.screenTable[0][5] = 0xA0;
    game::aikaObjekti.aikaMin = 5;
    game:: aikaObjekti.aikaSec = 0;
    game::playerReturn[0] = 9;
    game::playerReturn[1] = 9;
    game::playerReturn[2] = 9;
    game::playerReturn[3] = 9;
    game::playerReturn[4] = 9;
    game::lcdObjekti.screenTable[1][0] = 0x4C;
    game::lcdObjekti.screenTable[1][1] = 0x4F;
    game::lcdObjekti.screenTable[1][2] = 0x43; 
    game::lcdObjekti.screenTable[1][3] = 0x4B;
    game::lcdObjekti.screenTable[1][4] = 0x53;
    game::lcdObjekti.screenTable[1][5] = 0x3A;
    game::lcdObjekti.screenTable[1][6] = 0xA0;
    game::lcdObjekti.screenTable[1][7] = 0xA0;
    game::lcdObjekti.screenTable[1][8] = 0xA0;
    game::lcdObjekti.screenTable[1][9] = 0xA0;
    game::lcdObjekti.screenTable[1][10] = 0xA0;
    game::lcdObjekti.screenTable[1][11] = 0xA0;
    game::lcdObjekti.screenTable[1][12] = 0xA0;
    game::lcdObjekti.screenTable[1][13] = 0xA0;
}
