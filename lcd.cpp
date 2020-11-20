#include "lcd.h"
#include "debug.h"
#include <Arduino.h>
void LCD::resetShiftRegister()
{
  digitalWrite(LCD::SRCLR,LOW);
  delay(10);
  digitalWrite(LCD::SRCLR,HIGH);
}

//function conver hex to bin and set bit to shift register
void LCD::sendData(unsigned int information, int command)
{
	unsigned int result;
	unsigned int bitTable[8];
	unsigned int temp;
	//setting shiftRegister and clock pulse
	resetShiftRegister();

	//setting bit to table from hex
for (int i = 8; i >= 0; i--)
                {
                  temp =(information>>(i-1));
                  if (temp & 1)
                  {
                    bitTable[i] = 1;
                  }
                  else
                  bitTable[i] = 0;
          
                }
	for (int k = 8; k > 0; k--)
		{
			//by pass first round
			if ( k != 0) 
				{ 
					digitalWrite(LCD::RCLK,HIGH);
                                    	digitalWrite(LCD::RCLK,LOW);
                                }
			digitalWrite(LCD::clockPin, LOW);

			if (bitTable[k] & 1)
				{
				digitalWrite(LCD::SER,HIGH);
				}
			else
				{
				digitalWrite(LCD::SER,LOW);
				}
		
			digitalWrite(LCD::clockPin, HIGH);
		}
	//save bit to register
	digitalWrite(LCD::RCLK,HIGH);
	digitalWrite(LCD::RCLK,LOW);
	//open bus for LCD and enable LCD read
	LCD::dataToLCD(command);

}
//lcd init command
void LCD::lcd_init()
{
 
  if (LCD::reset != 1)
  {
  digitalWrite(LCD::enablePin, LOW);
  digitalWrite(LCD::OE,HIGH);
   for (long int p = 0; p < 4000000; p++)
  {
    
  }
  unsigned int init_table[8] = {0x30,0x30,0x30,0x3C,0x08,0x01,0x06,0x0C};
  Serial.print("INIT LCD\n");
  digitalWrite(LCD::rsPin,LOW);
  digitalWrite(LCD::enablePin,LOW);
  for (int i = 0; i < 8; i++)
  {	
	  
	  LCD::sendData(init_table[i],0);
    LCD::variable->debugInt(init_table[i]);
   if(i == 7)
   {
    break;
   }
}

  Serial.print("INIT DONE\n");
  digitalWrite(LCD::rsPin,LOW);
  //init done
  LCD::reset = 1;
  
  }

}

//write to bus and enable LCD read
void LCD::dataToLCD(int command)
{

		if (command != 0)
			{
  			digialWrite(LCD::rsPin,HIGH);
			}
		if (command == 0)
			{
  			digitalWrite(LCD::rsPin,LOW);
			}
	digitalWrite(LCD::RCLK,HIGH);
	digitalWrite(LCD::RCLK,LOW);
	
	digitalWrite(LCD::enablePin, HIGH);
	
	digitalWrite(LCD::OE, LOW);
	
	digitalWrite(LCD::enablePin, LOW);
	digitalWrite(LCD::rsPin,LOW);
	digitalWrite(LCD::OE, HIGH);
	resetShiftRegister();
}

void LCD::printInScreen()
{

for (int k = 0; k < 2; k++)
{
  //debug
  LCD::variable->debugInt(k);
 
for (int i = 0; i <16; i++)
{

  LCD::sendData(LCD::screen[k][i],1);
    //debug
  LCD::variable->debugInt(i);
  LCD::variable->debugInt(screen[k][i]);
  }
  for (int j=0; j <24; j++)
  {
      //debug
  LCD::variable->debugInt(j);
    Serial.println("jumittaako");
    LCD::sendData(0x20,1);
    LCD::variable->debugInt(j);
    
  }
  
}

}

void LCD::updateTime(int kymmin, int minuutit, int kymsek,int sekunnit) //time interrupt updata screen table
{
LCD::screen[0][11] = 0x30 + kymmin;
LCD::screen[0][12] = 0x30 + minuutit;
LCD::screen[0][14] = 0x30 + kymsek;
LCD::screen[0][15] = 0x30 + sekunnit;
LCD::printInScreen();
}t
