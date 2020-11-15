#include "lcd.h"
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
  digitalWrite(LCD::enablePin, LOW);
  digitalWrite(LCD::OE,HIGH);
  delay(1000);
  unsigned int init_table[6] = {0x30,0x30,0x30,0x38,0x0D,0x06};
  Serial.print("INIT LCD\n");
  digitalWrite(LCD::rsPin,LOW);
  digitalWrite(LCD::enablePin,LOW);
  for (int i = 0; i < 6; i++)
  {
	  LCD::sendData(init_table[i],0);
}

  Serial.print("INIT DONE\n");
  digitalWrite(LCD::rsPin,LOW);
  //init done
  LCD::reset = 1;
}

//write to bus and enable LCD read
void LCD::dataToLCD(int command)
{

		if (command != 0)
			{
  			digitalWrite(LCD::rsPin,HIGH);
			}
		if (command == 0)
			{
  			digitalWrite(LCD::rsPin,LOW);
			}
	digitalWrite(LCD::RCLK,HIGH);
	digitalWrite(LCD::RCLK,LOW);
	digitalWrite(LCD::OE, LOW);
	delay(10);
	digitalWrite(LCD::enablePin, HIGH);
	delay(10);
	digitalWrite(LCD::enablePin, LOW);
	digitalWrite(LCD::rsPin,LOW);
	digitalWrite(LCD::OE, HIGH);
	resetShiftRegister();
}
